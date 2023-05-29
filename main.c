#include "func.h"
#include "key.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    
    //char plain_txt[9];
    //char cipher_txt[9];
    uint64_t plain, cipher, key;
    printf("Masukkan Plain (Hex): ");
    scanf("%llx", &plain);
    printf("Masukkan Cipher (Hex): ");
    scanf("%llx", &cipher);
    
    clock_t start_time, end_time;
    start_time = clock();
    bool not_found = true;
    for(int i=0; (i<26) & not_found; i++){
        for(int j=0; (j<26) &not_found; j++){
            for(int k=0; (k<26)&not_found; k++){
                for(int l=0; (l<26)&not_found; l++){
                    for(int m=0; (m<26)&not_found; m++){
                        for(int n=0; (n<26)&not_found; n++){
                            for(int o=0; (o<26)&not_found; o++){
                                for(int p=0; (p<26)&not_found; p++){
                                    key = generateKey(i, j, k, l, m, n, o, p);
                                    if(plain == decrypt(cipher, key)){
                                        not_found=false;
                                        end_time=clock();
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    if(not_found){
        printf("KEY tidak ditemukan");
    }else{
        double elapsed_time = (double) (end_time-start_time)/CLOCKS_PER_SEC;
        printf("KEY: %llx\nElapsed time: %lf", key, elapsed_time);
    }

    return 0;
}