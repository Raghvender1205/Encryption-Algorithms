#ifndef IdeaGenerators_h
#define IdeaGenerators_h

#include <stdint.h>
#include <stddef.h>

//Internal status of IdeaCounterGen and IdeaIterativeGen random number generators.
//These generator are different, use a different instance of status for different generator;
typedef struct
{
    void *privateData;
} IdeaGeneratorStatus;

//initializes the status of the generator
//keyUpdatePeriod = number of iteration before key update
IdeaGeneratorStatus IdeaGeneratorInit(uint64_t *key, uint64_t seed, uint64_t keyUpdatePeriod);

void IdeaGeneratorDelete(IdeaGeneratorStatus status);

//Return a cryptography safe random 64 bit integer
uint64_t IdeaIterativeGenInteger(IdeaGeneratorStatus status);

//Return a random 64 bit integer, this function is more efficient of IdeaIterativeGenInteger but it exposes
//a part of internal state of the generator.
//Use it for statistic application, not for cryptography.
uint64_t IdeaIterativeGenUnsafe(IdeaGeneratorStatus status);

//Fill a buffer of cryptography safe random bytes. Returns the number of random number generated.
size_t IdeaIterativeGenFill(IdeaGeneratorStatus status, uint8_t *buffer, size_t length);

//Return a cryptography safe random 64 bit integer
uint64_t IdeaCounterGenInteger(IdeaGeneratorStatus status);

//Fill a buffer of cryptography safe random 64 bit integer. Returns the number of random number generated.
size_t IdeaCounterGenFill(IdeaGeneratorStatus status, uint64_t *buffer, size_t length);

#endif /* IdeaGenerators_h */