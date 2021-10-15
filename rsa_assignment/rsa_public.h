//
//  rsa_public.h
//  rsa_assignment
//
//  Created by xieyuanfeng on 2021/10/15.
//

#ifndef rsa_public_h
#define rsa_public_h

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define ul unsigned long
#define ll long long

// int prime_check(ul number);
void create_prime_store(int number);

int prime_prove(ul number);
int prime_check(ul number);
int fermat_check(ul number);
ul extend_gcd(ul a,ul b,ul* x,ul* y);
int number_to_array(ul number,int* array,int radix,int reverse);

int number_length_get(ul number);
ul rsa_encrypt(ul m,ul e,ul n);
ul rsa_encrypt(ul c,ul d,ul n);

ul bignumber_sum(ul* array_c,ul* array_M,ul* array_M_reverse,ul p);
#endif /* rsa_public_h */
