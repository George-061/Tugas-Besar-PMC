#ifndef key_h
#define key_h

#include <stdint.h>

uint64_t permuteChoice1(uint64_t initialKey);
uint64_t compressionPermutation(uint64_t key);
uint64_t keySchedule(int n, uint64_t key);
uint64_t generateKey(uint8_t first, uint8_t second, uint8_t third, uint8_t fourth, uint8_t fifth, uint8_t sixth, uint8_t seventh, uint8_t eighth);
#endif