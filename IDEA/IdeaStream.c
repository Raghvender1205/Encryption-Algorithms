#include "IdeaStream.h"
#include <stdlib.h>
#include "IdeaCore.h"

typedef struct {
    uint16_t subKey[56];
    uint64_t nonce;
} StreamInternalStatus;

IdeaEncryptStreamStatus IdeaStreamEncryptInit(uint64_t* key, uint64_t nonce) {
    StreamInternalStatus* status = (StreamInternalStatus*) malloc(sizeof(StreamInternalStatus));
    EncryptKeyCreate(key, status->subKey);
    status->nonce = nonce;
    IdeaEncryptStreamStatus s = {.privateData = status};
    return s;
}

IdeaDecryptStreamStatus IdeaStreamDecryptInit(uint64_t *key, uint64_t nonce) {
    StreamInternalStatus *status = (StreamInternalStatus *)malloc(sizeof(StreamInternalStatus));
    DecryptKeyCreate(key, status->subKey);
    status->nonce = nonce;
    IdeaDecryptStreamStatus s = {.privateData = status};
    return s;
}

IdeaEncryptStreamStatus IdeaStreamCTRRandomAccessInit(uint64_t *key, uint64_t nonce, uint64_t position) {
    return IdeaStreamEncryptInit(key, nonce + position);
}

void IdeaStreamEncryptDelete(IdeaEncryptStreamStatus status) {
    SecureMemoryWipe(status.privateData, sizeof(StreamInternalStatus));
    free(status.privateData);
}

void IdeaStreamDecryptDelete(IdeaDecryptStreamStatus status) {
    SecureMemoryWipe(status.privateData, sizeof(StreamInternalStatus));
    free(status.privateData);
}

void IdeaStreamCBCEncrypt(uint64_t *message, IdeaEncryptStreamStatus status) {
    StreamInternalStatus *iStatus = (StreamInternalStatus *)status.privateData;
    *message ^= iStatus->nonce;
    IdeaRoutine((uint16_t *)message, iStatus->subKey);
    iStatus->nonce = *message;
}

void IdeaStreamCBCDecrypt(uint64_t *message, IdeaDecryptStreamStatus status) {
    StreamInternalStatus *iStatus = (StreamInternalStatus *)status.privateData;
    uint64_t temp = *message;
    IdeaRoutine((uint16_t *)message, iStatus->subKey);
    *message ^= iStatus->nonce;
    iStatus->nonce = temp;
}

void IdeaStreamPCBCEncrypt(uint64_t *message, IdeaEncryptStreamStatus status) {
    StreamInternalStatus *iStatus = (StreamInternalStatus *)status.privateData;
    uint64_t temp = *message;
    *message ^= iStatus->nonce;
    IdeaRoutine((uint16_t *)message, iStatus->subKey);
    iStatus->nonce = *message ^ temp;
}

void IdeaStreamPCBCDecrypt(uint64_t *message, IdeaDecryptStreamStatus status) {
    StreamInternalStatus *iStatus = (StreamInternalStatus *)status.privateData;
    uint64_t temp = *message;
    IdeaRoutine((uint16_t *)message, iStatus->subKey);
    *message ^= iStatus->nonce;
    iStatus->nonce = temp ^ *message;
}

void IdeaStreamCFBEncrypt(uint64_t *message, IdeaEncryptStreamStatus status) {
    StreamInternalStatus *iStatus = (StreamInternalStatus *)status.privateData;
    IdeaRoutine((uint16_t *)&(iStatus->nonce), iStatus->subKey);
    *message ^= iStatus->nonce;
    iStatus->nonce = *message;
}

void IdeaStreamCFBDecrypt(uint64_t *message, IdeaEncryptStreamStatus status) {
    StreamInternalStatus *iStatus = (StreamInternalStatus *)status.privateData;
    IdeaRoutine((uint16_t *)&(iStatus->nonce), iStatus->subKey);
    uint64_t temp = *message ^ iStatus->nonce;
    iStatus->nonce = *message;
    *message = temp;
}

void IdeaStreamOFB(uint64_t *message, IdeaEncryptStreamStatus status) {
    StreamInternalStatus *iStatus = (StreamInternalStatus *)status.privateData;
    IdeaRoutine((uint16_t *)&(iStatus->nonce), iStatus->subKey);
    *message ^= iStatus->nonce;
}

void IdeaStreamCTR(uint64_t *message, IdeaEncryptStreamStatus status) {
    StreamInternalStatus *iStatus = (StreamInternalStatus *)status.privateData;
    IdeaRoutine((uint16_t *)&(iStatus->nonce), iStatus->subKey);
    *message ^= iStatus->nonce;
    iStatus->nonce++;
}
