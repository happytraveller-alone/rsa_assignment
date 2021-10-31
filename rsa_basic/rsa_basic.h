//
//  rsa_basic.h
//  rsa_basic
//
//  Created by xieyuanfeng on 2021/10/26.
//

#ifndef rsa_basic_h
#define rsa_basic_h

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>




// uint32_t unsigned long 4字节
// int32_t long 4字节
// _Bool true false

// n数组的计算
uint16_t* n_caculate(uint32_t p,uint32_t q);
// 参数输入
void factor_input(uint32_t* factor_array);
// 扩展欧几里德测试
uint32_t extend_gcd(uint32_t a,uint32_t,uint32_t* x,uint32_t* y);
// 获取乘法逆元
//uint32_t mul_reverse_get(uint32_t e,uint32_t phi);
// 模幂计算
uint32_t model_power_calculation(uint32_t a,uint32_t b,uint32_t c);
// 快速乘
uint32_t quick_multiple(uint32_t a,uint32_t b,uint32_t c);
// 整数转数组
uint16_t number_to_array(uint32_t number,uint16_t* array,uint16_t radix,_Bool reverse);
// 数字长度获取
uint16_t number_length_get(uint32_t number,uint16_t length);
// 素数判定
_Bool prime_check_easy(uint32_t number);
// 素数判定库
uint16_t create_prime_store(uint32_t number,uint32_t* array);
// q和q的素数判定
_Bool p_and_q_prime_check(uint32_t p,uint32_t q);
// fermat测试+暴力测试
uint16_t fermat_check_plus_brute_check(uint32_t p,uint32_t q,uint16_t p_check,uint16_t q_check);
//// 代码测试
//_Bool code_test(uint32_t p,uint32_t q,uint32_t e,uint32_t m);
// 数组处理
uint16_t* array_process(uint16_t* a,uint16_t a_length,uint16_t* b,uint16_t b_length,uint16_t* c,uint16_t oprator);
// fermat测试实现
_Bool fermat_check(uint32_t number);
// 暴力测试实现
_Bool brute_check(uint32_t number);
// e参数检查
_Bool e_check(uint32_t e,uint32_t a,uint32_t b);
// rsa加密计算
uint16_t* rsa_encrypt(uint32_t m, uint32_t e, uint32_t p, uint32_t q);
#endif /* rsa_basic_h */


