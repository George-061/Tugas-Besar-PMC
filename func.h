#ifndef func_h
#define func_h

#include <stdint.h>

uint64_t initialPermutation(uint64_t input);
uint64_t inversePermutation(uint64_t input);
uint32_t pBoxPermutation(uint32_t in);
uint32_t sBoxSubstitution(uint64_t in);
uint64_t expansionPermutation(uint32_t R);
uint32_t functionF(uint32_t R, uint64_t key);
uint64_t encrypt(uint64_t plain_text, uint64_t key);
uint64_t decrypt(uint64_t cipher_text, uint64_t key);
uint64_t stringToASCII(char* string);
void asciiToString(uint64_t hex ,char* string);
#endif