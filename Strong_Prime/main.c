//
//  main.c
//  Strong_Prime
//
//  Created by xieyuanfeng on 2021/10/21.
//

#include "strong_prime.h"

int main(void){
//    printf("%lu",sizeof(unsigned long));
    printf("%lu",sizeof(unsigned long));
    srand((unsigned int)time(NULL));
//    printf("hello world!\n");
    input();
//    ull number = Random_Search(input_length, 15);
    ull* prime_array = (ull*)malloc(4*(sizeof(ull)));
    int* bit_prime = (int*)malloc(4*sizeof(int));
    prime_generate(prime_array,bit_prime,input_length);
    printf("s:%llu %d\n",prime_array[0],is_prime_test(prime_array[0]));
    printf("t:%llu %d\n",prime_array[1],is_prime_test(prime_array[1]));
    printf("r:%llu %d\n",prime_array[2],is_prime_test(prime_array[2]));
//    printf("p:%llu %d\n",prime_array[3],is_prime_test(prime_array[3]));
    printf("s:%llu;t:%llu;r:%llu;p:%llu\n",prime_array[0],prime_array[1],prime_array[2],prime_array[3]);
    printf("s:%d;t:%d;r:%d;p:%d\n",bit_prime[0],bit_prime[1],bit_prime[2],bit_prime[3]);
    free(prime_array);
    free(bit_prime);
    // 4294967000
    return 0;
}
