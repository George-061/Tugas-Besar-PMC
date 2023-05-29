#include "func.h"
#include <stdio.h>
#include <stdint.h>
    
const uint8_t compressionPermutePosition[48]=
    {
        14, 17, 11, 24, 1, 5,
        3, 28, 15, 6, 21, 10,
        23, 19, 12, 4, 26, 8,
        16, 7, 27, 20, 13, 2,
        41, 52, 31, 37, 47, 55,
        30, 40, 51, 45, 33, 48,
        44, 49, 39, 56, 34, 53,
        46, 42, 50, 36, 29, 32 
    };

const uint8_t boxPC1[56]=
    {
            57, 49, 41, 33, 25, 17, 9,
            1, 58, 50, 42, 34, 26, 18,
            10, 2, 59, 51, 43, 35, 27,
            19, 11, 3, 60, 52, 44, 36,
            63, 55, 47, 39, 31, 23, 15,
            7, 62, 54, 46, 38, 30, 22,
            14, 6, 61, 53, 45, 37, 29,
            21, 13, 5, 28, 20, 12, 4
    };

const uint8_t leftShiftConst[16]={1, 2, 4, 6, 8, 10, 12, 14, 15, 17, 19, 21, 23, 25, 27, 28};

uint64_t permuteChoice1(uint64_t initialKey){
    uint64_t out = 0;
    for(int i=0; i<56; i++){
        uint64_t bit = (initialKey >> (64 - boxPC1[i])) & 0x1;
        out = out | (bit << (55-i));
    }
    return out;
}

uint64_t compressionPermutation(uint64_t key){
    uint64_t out=0;
    for(int i=0; i<48; i++){
        uint64_t bit = (key >> (56-compressionPermutePosition[i])) &0x1;
        out = out | (bit<<(47-i));
    }
    return out;
}

uint64_t keySchedule(int n, uint64_t permutedKey){
    uint64_t out;
    uint64_t c= permutedKey>>28;
    uint64_t d= permutedKey&0xfffffff;
    c= (c<<leftShiftConst[n-1] | c>>(28-leftShiftConst[n-1]))&0xfffffff;
    d= (d<<leftShiftConst[n-1] | d>>(28-leftShiftConst[n-1]))&0xfffffff;
    out = (c<<28) | d;
    out = compressionPermutation(out);
    return out;
}

uint64_t generateKey(uint8_t first, uint8_t second, uint8_t third, uint8_t fourth, uint8_t fifth, uint8_t sixth, uint8_t seventh, uint8_t eighth) {
    uint64_t key = (0x61+(uint64_t)first)<<56 | (0x61 + (uint64_t)second)<<48 | (0x61 + (uint64_t)third)<<40 | (0x61 + (uint64_t)fourth)<<32 | (0x61 + (uint64_t)fifth)<<24 | (0x61 + (uint64_t)sixth)<<16 | (0x61 + (uint64_t)seventh)<<8 | (0x61 + (uint64_t)eighth);
    return key;
}