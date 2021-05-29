#ifndef IdeaStream_h
#define IdeaStream_h

#include <stdint.h>
/*These functions provides the encryption modes on singles blocks from a stream*/

//Internal status of the stream processor
typedef struct
{
    void *privateData;
} IdeaEncryptStreamStatus;
typedef struct
{
    void *privateData;
} IdeaDecryptStreamStatus;

IdeaEncryptStreamStatus IdeaStreamEncryptInit(uint64_t *key, uint64_t nonce);

IdeaDecryptStreamStatus IdeaStreamDecryptInit(uint64_t *key, uint64_t nonce);

//initializes a stream status for CTR mode to start from a block != 0
IdeaEncryptStreamStatus IdeaStreamCTRRandomAccessInit(uint64_t *key, uint64_t nonce, uint64_t position);

void IdeaStreamEncryptDelete(IdeaEncryptStreamStatus status);
void IdeaStreamDecryptDelete(IdeaDecryptStreamStatus status);

void IdeaStreamCBCEncrypt(uint64_t *message, IdeaEncryptStreamStatus status);

void IdeaStreamCBCDecrypt(uint64_t *message, IdeaDecryptStreamStatus status);

void IdeaStreamPCBCEncrypt(uint64_t *message, IdeaEncryptStreamStatus status);

void IdeaStreamPCBCDecrypt(uint64_t *message, IdeaDecryptStreamStatus status);

void IdeaStreamCFBEncrypt(uint64_t *message, IdeaEncryptStreamStatus status);

void IdeaStreamCFBDecrypt(uint64_t *message, IdeaEncryptStreamStatus status);

void IdeaStreamOFB(uint64_t *message, IdeaEncryptStreamStatus status);

void IdeaStreamCTR(uint64_t *message, IdeaEncryptStreamStatus status);

#endif /* IdeaStream_h */