#include "func.h"
#include "key.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(){

    printf("%llx\n", encrypt(0xabcdef1234567890, 0xabcdabcdabcdabcd));
    printf("%llx\n", encrypt(0x04d03e58188b0258, 0xabcdabcdabcdabcd));

    return 0;
}