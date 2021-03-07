/**
 * Copyright 2020 curoky(cccuroky@gmail.com).
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once
#include <openssl/evp.h>
#include <openssl/md5.h>

class RC4Handler {
 public:
  RC4Handler(const unsigned char* key, const unsigned char* iv) {
    unsigned char data[32];
    unsigned char real_key[16];

    memcpy(data, key, 16);
    memcpy(data + 16, iv, 16);

    MD5(data, 32, real_key);

    // realKey.resize(key.size());
    // const unsigned char *rkey = reinterpret_cast<const unsigned char *>(realKey.data());

    if (!(encryptor_ctx_ = EVP_CIPHER_CTX_new())) {
      // handleErrors();
    }
    if (1 != EVP_EncryptInit_ex(encryptor_ctx_, EVP_rc4(), NULL, real_key, NULL)) {
      // handleErrors();
    }

    if (!(decryptor_ctx_ = EVP_CIPHER_CTX_new())) {
      // handleErrors();
    }

    if (1 != EVP_DecryptInit_ex(decryptor_ctx_, EVP_rc4(), NULL, real_key, NULL)) {
      // handleErrors();
    }
  }

  ~RC4Handler() {
    EVP_CIPHER_CTX_free(encryptor_ctx_);
    EVP_CIPHER_CTX_free(decryptor_ctx_);
  }

  int encrypt(const unsigned char* plaintext, int plaintext_len, unsigned char* ciphertext) {
    int len;
    int ciphertext_len;
    if (1 != EVP_EncryptUpdate(encryptor_ctx_, ciphertext, &len, plaintext, plaintext_len)) {
      // handleErrors();
    }
    ciphertext_len = len;

    // if (1 != EVP_EncryptFinal_ex(encryptor_ctx_, ciphertext + len, &len)) {
    //     //handleErrors();
    // }
    // ciphertext_len += len;
    return ciphertext_len;
  }
  int decrypt(const unsigned char* ciphertext, int ciphertext_len, unsigned char* plaintext) {
    int len;
    int plaintext_len;
    if (1 != EVP_DecryptUpdate(decryptor_ctx_, plaintext, &len, ciphertext, ciphertext_len)) {
      // handleErrors();
    }
    plaintext_len = len;
    // if (1 != EVP_DecryptFinal_ex(decryptor_ctx_, plaintext + len, &len)) {
    //     //handleErrors();
    // }
    // plaintext_len += len;
    return plaintext_len;
  }

 private:
  EVP_CIPHER_CTX* encryptor_ctx_;
  EVP_CIPHER_CTX* decryptor_ctx_;
};