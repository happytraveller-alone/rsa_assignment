//
//  rsa_assignment.c
//  rsa_assignment
//
//  Created by xieyuanfeng on 2021/10/15.
//

#include "rsa_public.h"
#include "rsa_basic.h"
#include "rsa_attack.h"

int main(void){

//    printf("%lu\n",sizeof(long long)); // long long size : 8
//    printf("%lu\n",sizeof(ul)); // unsigned long size : 8
//    printf("%lu\n",sizeof(long double)); // long double size : 8
//    printf("%lu\n",mul_reverse_get(3, 5)); // mul_reverse_get test succeed
//    ul x,y;
//    printf("%lu\n",extend_gcd(201,268,&x,&y)); // extend_gcd test succeed
//    printf("%lu\n",modal_power_calculation(3, 4, 5));
//    modal_power_calculation and number_to_array and quick_mul test succeed
//    create_prime_store(10000); // create_prime_store test succeed
    rsa_encrypt_and_decrypt();
    rsa_attack();
    return 0;
    
}
