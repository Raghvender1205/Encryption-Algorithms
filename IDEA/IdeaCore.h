// Core Functionalities of IdeaLib
#ifndef IdeaCore_h
#define IdeaCore_h
#include <stdint.h>


// Key generation function, generate subkeys from the key
void EncryptKeyCreate(uint64_t* key, uint16_t* subKey);
void DecryptKeyCreate(uint64_t* key, uint16_t* subKey);

// Single Encryption, return 0 in case of error
int IdeaEncrypt(uint64_t* message, uint64_t* key);

// Single Decryption, return 0 in case of error
int IdeaDecrypt(uint64_t* message, uint64_t* key);

// Process single block of data, use encryption subkey to encrypt or decryption subkey to decrypt
void IdeaRoutine(uint16_t* message, uint16_t* subKey);

// Aux function to clean sensitive information, take size in bytes
void SecureMemoryWipe(void* ptr, uint64_t size);

// return 1 if the key is a valid key to be used with IDEA
int KeyCheck(uint64_t* key);


#endif /* __IdeaCore_h */