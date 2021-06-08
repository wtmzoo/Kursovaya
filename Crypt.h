#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <windows.h>
#include <Wincrypt.h>

using namespace std;

string rusToEngl(string s);

#pragma comment (lib, "Crypt32.lib")

BYTE* Crypt(const string& _str, DWORD* _outLength);

BYTE* Decrypt(BYTE* _encryptedData, DWORD* _length);

const char* szPemPrivKey =
"-----BEGIN RSA PRIVATE KEY-----"
"MIICWwIBAAKBgQCn7fL/1qsWkJkUtXKZIJNqYfnVByVhK/LzQecPhVR7r+4ng1nZ"
"Bxg44SexS63iYlnodqDWkH/Hi82Uc0UmugY/Ow39uEGeoiYqWl5BLM8pfRAGqzxb"
"h600Qd/Oc5kYdg8hP0D/gAHXwutL74fygpB6xb8EZl2BHKvpDR80GYFlrQIDAQAB"
"AoGAZ4ZHsfTTEFwgIyYg+cmdV44DCJMZNihz5AcSvPzDMmUo+m79as/23MnhQGmZ"
"TuC28JqBWQVH4OqM2CGf1doEkuLZ/rcgxDipRqbLkEW3T/q+kJ2m9A652ePbHUKX"
"ayozDQrWtL4wkvAQQ9Il6vx+AJUzT41hv1PKZ5KWxONiJDkCQQDRsObUVVc6exb+"
"YUWVgN0pivHudKIwGUN3js09MjHoen9LbUcvupO3seAUhnNQ17t+1XxsrnPKabQQ"
"OimcPK3XAkEAzQQEI++NdoLYJv1oKYADzOUbDAmfoZ/szN6z//53h8zt5ni+6Q0n"
"k7nyrVXWuLeP0rEvD0hMOzI0mfUMwbtwGwJAMUYId8y1+qAB/zSMTV1CmwhzYT02"
"/2ZwXB/KSp8I60AduXOsTqLhI0FBDpGpd026WUuBOWik/ONp1IZWUMhRcQJAHI+U"
"rBTxVjNAPZ5L5owo+2BndjPZA0EuUhQsa1td95M7CUKFBh6JBvF+t1sgALfB145L"
"igt+YzjJTzFuR4b/RQJATgZuFyBiuLHrMES2vAtmLRlF6uTzsrNZLLUko2Rfzkzh"
"qR4inQOWWZLFzjqp3ha9rzCSVY+nBw+xD+B9hBlsNw=="
"-----END RSA PRIVATE KEY-----";

const char* szPemPublicKey =
"-----BEGIN PUBLIC KEY-----"
"MIGfMA0GCSqGSIb3DQEBAQUAA4GNADCBiQKBgQCn7fL/1qsWkJkUtXKZIJNqYfnV"
"ByVhK/LzQecPhVR7r+4ng1nZBxg44SexS63iYlnodqDWkH/Hi82Uc0UmugY/Ow39"
"uEGeoiYqWl5BLM8pfRAGqzxbh600Qd/Oc5kYdg8hP0D/gAHXwutL74fygpB6xb8E"
"Zl2BHKvpDR80GYFlrQIDAQAB"
"-----END PUBLIC KEY-----";


void start_crypt()
{
    string str;
    string str_for_copy;
    string main_path = "db_students.txt";

    string path = "main.txt";
    string crypt = "encrypted.txt";
    string decrypt = "decrypted.txt";

    try
    {
        remove("main.txt");
        remove("encrypted.txt");
        remove("decrypted.txt");
    }
    catch (...) {}

    ofstream create1(path);
    create1.close();
    ofstream create2(crypt);
    create2.close();
    ofstream create3(decrypt);
    create3.close();

    fstream main_file(main_path);
    fstream file(path);
    fstream crypted_file(crypt);
    fstream dec_file(decrypt);


    while (getline(main_file, str_for_copy))
    {
        file << str_for_copy << endl;
    }
    file.close();

    fstream file1(path);
    while (getline(file1, str))
    {
        string str_res;
        DWORD encryptedDataLen;
        BYTE* encrytedData = Crypt(str, &encryptedDataLen);
        crypted_file << encrytedData << endl;


        BYTE* decryptedData = Decrypt(encrytedData, &encryptedDataLen);
        string str_crypt((char*)decryptedData);
        
        if (str_crypt.size() != 0) str_crypt.resize(str_crypt.size() - 4);

        dec_file << str_crypt << endl;

        delete(encrytedData);
        delete(decryptedData);
    }
    main_file.close();
    file1.close();
    crypted_file.close();
    dec_file.close();
}



string rusToEngl(string s) {
    const string rus = "éöóêåíãøùçõúôûâàïðîëäæýÿ÷ñìèòüáþ";
    const string eng = "qwertyuiop[]asdfghjkl;'zxcvbnm,.";
    for (size_t i = 0; i < s.length(); i++)
    {
        size_t pos = rus.find(s[i]);
        if (pos != string::npos)
            s[i] = eng[pos];
    }
    return (s);
}


BYTE* Crypt(const string& _str, DWORD* _outLength)
{
    char            pemPubKey[2048];
    memcpy((void*)pemPubKey, szPemPublicKey, strlen(szPemPublicKey));
    char            derPubKey[2048];
    DWORD           derPubKeyLen = 2048;
    CERT_PUBLIC_KEY_INFO* publicKeyInfo;
    DWORD           publicKeyInfoLen;
    HCRYPTPROV      hProv = 0;
    HCRYPTKEY       hKey = 0;


    if (!CryptStringToBinaryA(pemPubKey, 0, CRYPT_STRING_BASE64HEADER, (BYTE*)derPubKey, &derPubKeyLen, NULL, NULL))
    {
        fprintf(stderr, "CryptStringToBinary failed. Err: %d\n", GetLastError());
        return NULL;
    }

    if (!CryptDecodeObjectEx(X509_ASN_ENCODING, X509_PUBLIC_KEY_INFO, (BYTE*)derPubKey, derPubKeyLen,
        CRYPT_ENCODE_ALLOC_FLAG, NULL, &publicKeyInfo, &publicKeyInfoLen))
    {
        fprintf(stderr, "CryptDecodeObjectEx 1 failed. Err: %p\n", GetLastError());
        return NULL;
    }

    if (!CryptAcquireContext(&hProv, NULL, NULL, PROV_RSA_FULL, CRYPT_VERIFYCONTEXT))
    {
        {
            printf("CryptAcquireContext failed - err=0x%x.\n", GetLastError());
            return NULL;
        }
    }

    if (!CryptImportPublicKeyInfo(hProv, X509_ASN_ENCODING, publicKeyInfo, &hKey))
    {
        fprintf(stderr, "CryptImportPublicKeyInfo failed. error: %d\n", GetLastError());
        return NULL;
    }

    DWORD strLen = _str.length() * sizeof(char);
    DWORD bufLen = strLen;
    if (!CryptEncrypt(hKey, 0, true, 0, 0, &bufLen, strLen))
    {
        cout << "CryptEncrypt() failed with error " << GetLastError() << endl;
        return NULL;
    }


    BYTE* cipherBlock = new BYTE[bufLen];
    memset((void*)cipherBlock, 0, bufLen);
    memcpy((void*)cipherBlock, _str.c_str(), strLen);
    if (!CryptEncrypt(hKey, 0, TRUE, 0, cipherBlock, &strLen, bufLen))
    {
        cout << "CryptEncrypt() failed with error " << GetLastError() << endl;
        return NULL;
    }

    *_outLength = bufLen;
    return cipherBlock;
}

BYTE* Decrypt(BYTE* _encryptedData, DWORD* _length)
{
    DWORD dwBufferLen = 0, cbKeyBlob = 0, cbSignature = 0;
    LPBYTE pbBuffer = NULL, pbKeyBlob = NULL, pbSignature = NULL;
    HCRYPTPROV hProv = NULL;
    HCRYPTKEY hKey = NULL;
    HCRYPTHASH hHash = NULL;

    if (!CryptStringToBinaryA(szPemPrivKey, 0, CRYPT_STRING_BASE64HEADER, NULL, &dwBufferLen, NULL, NULL))
    {
        cout << "Failed to convert BASE64 private key. Error " << GetLastError() << endl;
        return NULL;
    }

    pbBuffer = (LPBYTE)LocalAlloc(0, dwBufferLen);
    if (!CryptStringToBinaryA(szPemPrivKey, 0, CRYPT_STRING_BASE64HEADER, pbBuffer, &dwBufferLen, NULL, NULL))
    {
        cout << "Failed to convert BASE64 private key. Error " << GetLastError() << endl;
        return NULL;
    }

    if (!CryptDecodeObjectEx(X509_ASN_ENCODING | PKCS_7_ASN_ENCODING, PKCS_RSA_PRIVATE_KEY, pbBuffer, dwBufferLen, 0, NULL, NULL, &cbKeyBlob))
    {
        cout << "Failed to parse private key. Error " << GetLastError() << endl;
        return NULL;
    }

    pbKeyBlob = (LPBYTE)LocalAlloc(0, cbKeyBlob);
    if (!CryptDecodeObjectEx(X509_ASN_ENCODING | PKCS_7_ASN_ENCODING, PKCS_RSA_PRIVATE_KEY, pbBuffer, dwBufferLen, 0, NULL, pbKeyBlob, &cbKeyBlob))
    {
        cout << "Failed to parse private key. Error " << GetLastError() << endl;
        return NULL;
    }

    if (!CryptAcquireContext(&hProv, NULL, MS_DEF_PROV, PROV_RSA_FULL, 0))
    {
        if (GetLastError() == NTE_BAD_KEYSET)
        {
            if (!CryptAcquireContext(&hProv, NULL, MS_DEF_PROV, PROV_RSA_FULL, CRYPT_NEWKEYSET))
            {
                cout << "CryptAcquireContext() failed with error " << GetLastError() << endl;
                return NULL;
            }
        }
        else
        {
            cout << "CryptAcquireContext() failed with error " << GetLastError() << endl;
            return NULL;
        }
    }

    if (!CryptImportKey(hProv, pbKeyBlob, cbKeyBlob, NULL, 0, &hKey))
    {
        cout << "CryptImportKey() failed with error " << GetLastError() << endl;
        return NULL;
    }


    DWORD bufLen = *_length + 1;
    BYTE* cipherBlock = new BYTE[bufLen];
    memset((void*)cipherBlock, 0, bufLen);
    memcpy((void*)cipherBlock, _encryptedData, *_length);
    if (!CryptDecrypt(hKey, 0, TRUE, 0, cipherBlock, _length))
    {
        cout << "CryptDecrypt() failed with error " << GetLastError() << endl;
        return NULL;
    }

    BYTE* decryptedData = new BYTE[*_length];
    memset((void*)decryptedData, 0, *_length);
    memcpy((void*)decryptedData, cipherBlock, *_length);

    delete[] cipherBlock;
    if (pbBuffer) LocalFree(pbBuffer);
    if (pbKeyBlob) LocalFree(pbKeyBlob);
    if (pbSignature) LocalFree(pbSignature);
    if (hHash) CryptDestroyHash(hHash);
    if (hKey) CryptDestroyKey(hKey);
    if (hProv) CryptReleaseContext(hProv, 0);

    return decryptedData;
}


