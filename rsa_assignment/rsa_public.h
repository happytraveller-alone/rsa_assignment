/*
 * 文件名：rsa_public.h
 * 作者：谢远峰
 * 描述：公共程序宏定义，函数声明
 * 最近修改时间：2021/10/14
 * 修改内容：完成公共函数的书写和测试
 */

#ifndef rsa_public_h
#define rsa_public_h

#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ul unsigned long
#define ull unsigned long long
#define ll long long

ul extend_gcd(ul a, ul b, ul* x, ul* y);           // 扩展欧几里得测试
ull mul_reverse_get(ull e, ull phi);               // 获取乘法逆元
ull modal_power_calculation(ull a, ull b, ull c);  // a^(b) mod c
ull quick_mul(ull a, ull b, ull c);                // (a*b)%c
int number_to_array(ull number, int* array, int radix,int reverse);  // 整数转数组
int number_length_get(ul number, int length);
#endif /* rsa_public_h */
