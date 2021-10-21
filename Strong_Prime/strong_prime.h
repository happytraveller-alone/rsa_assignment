//
//  strong_prime.h
//  Strong_Prime
//
//  Created by xieyuanfeng on 2021/10/21.
//

#ifndef strong_prime_h
#define strong_prime_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

typedef unsigned long long ull;
typedef unsigned long ul;
typedef long long ll;
typedef int Bool;
#define true 1
#define false 0
#define upp_bound 150
int input_length;

ull strong_prime;
ull s;
ull r;
ul t;

void input(void); // 输入一个数，指定强素数的比特长度
ull modal_power_calculation(ull a,ull b,ull c); // a^(b) mod c
ul quick_mul(ul a,ul b,ul c); // (a*b)%c
int number_to_array(ul number,int* array,int radix,int reverse); // 整数转数组
Bool Miller_Rabin(ull number,int Security_Parameter); // Miller_Rabin测试
ull Random_Search(int k, int Security_Parameter); // k比特概率素数输出
Bool prime_check(ull number,ull upper_bound); // 传统的素数判定
int create_prime_store(ul number,int* array); // 创建指定素数库
Bool is_prime(ul number); // 素数判定
void prime_generate(ull* prime_array,int* bit_length_array,int length);
int bit_lenght_get(ull number,int cnt);
//Bool direct_divison(ull number); // 大素数直接除判定

Bool is_prime_test(ull number); // 素数判定
#endif /* strong_prime_h */
