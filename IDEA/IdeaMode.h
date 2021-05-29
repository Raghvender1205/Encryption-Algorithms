#ifndef __IdeaLib__IdeaLib__
#define __IdeaLib__IdeaLib__
#include <stdint.h>
#include <stddef.h>

//return number of block processed
size_t IdeaCBCEncrypt(uint64_t *message, uint64_t *key, uint64_t nonce, size_t messageLength);

//return number of block processed
size_t IdeaCBCDecrypt(uint64_t *message, uint64_t *key, uint64_t nonce, size_t messageLength);

//return number of block processed
size_t IdeaPCBCEncrypt(uint64_t *message, uint64_t *key, uint64_t nonce, size_t messageLength);

//return number of block processed
size_t IdeaPCBCDecrypt(uint64_t *message, uint64_t *key, uint64_t nonce, size_t messageLength);

//return number of block processed
size_t IdeaCFBEncrypt(uint64_t *message, uint64_t *key, uint64_t nonce, size_t messageLength);

//return number of block processed
size_t IdeaCFBDecrypt(uint64_t *message, uint64_t *key, uint64_t nonce, size_t messageLength);

//return number of block processed
size_t IdeaOFB(uint64_t *message, uint64_t *key, uint64_t nonce, size_t messageLength);

//return number of block processed
size_t IdeaCTR(uint64_t *message, uint64_t *key, uint64_t nonce, size_t messageLength);

//return a pointer to blocks processed or NULL
uint64_t *IdeaCTRRandomAccess(const uint64_t *ciphertext, uint64_t *key, uint64_t nonce, size_t position, size_t length);

//return the block decrypted
uint64_t IdeaCTRRandomAccessSingle(uint64_t *ciphertext, uint64_t *key, uint64_t nonce, size_t position);

#endif /* defined(__IdeaLib__IdeaLib__) */