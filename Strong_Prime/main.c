//
//  main.c
//  Strong_Prime
//
//  Created by xieyuanfeng on 2021/10/21.
//

#include "strong_prime.h"

int main(void){
    srand((unsigned int)time(NULL));
    input();
    actual_length = 0;
    while(input_length != actual_length){
        ull* prime_array = (ull*)malloc(4*(sizeof(ull)));
        int* bit_prime = (int*)malloc(4*sizeof(int));
        prime_generate(prime_array,bit_prime,input_length);
//    printf("s:%llu %d\n",prime_array[0],is_prime_test(prime_array[0]));
//    printf("t:%llu %d\n",prime_array[1],is_prime_test(prime_array[1]));
//    printf("r:%llu %d\n",prime_array[2],is_prime_test(prime_array[2]));
        actual_length = bit_prime[3];
        if(input_length != actual_length){free(prime_array);free(bit_prime);continue;}
        printf("\ns:%llu;t:%llu;r:%llu;p:%llu\n",prime_array[0],prime_array[1],prime_array[2],prime_array[3]);
        printf("s:%d;t:%d;r:%d;p:%d\n",bit_prime[0],bit_prime[1],bit_prime[2],bit_prime[3]);
        free(prime_array);
        free(bit_prime);
        break;
    }
    return 0;
}

//2的13次方：8192
//2的14次方：16384
//2的15次方：32768
//2的16次方：65536
//2的17次方：131072
//2的18次方：262144
//2的31次方：2147483648
//2的32次方：4294967296
//2的33次方：8589934592
//2的34次方：17179869184
//2的35次方：34359738368
//2的64次方：18446744073709551616
