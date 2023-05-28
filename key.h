#ifndef key_h
#define key_h

#include <stdint.h>

uint32_t permuteChoice1(int mode, uint64_t key, int shiftNumber);
uint64_t permuteChoice2(uint64_t cd);
uint64_t keySchedule(int n, uint64_t key);
uint64_t generateKey(uint8_t first, uint8_t second, uint8_t third, uint8_t fourth, uint8_t fifth, uint8_t sixth, uint8_t seventh, uint8_t eighth);
#endif