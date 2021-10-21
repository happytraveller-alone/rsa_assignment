/*
 * 文件名：rsa_attack.h
 * 作者：谢远峰
 * 描述：算法2函数声明
 * 最近修改时间：2021/10/14
 * 修改内容：完成算法2的函数定义
 */

#ifndef rsa_attack_h
#define rsa_attack_h

#include "rsa_public.h"

ul bignumber_sum(ul* array_c,ul* array_M,ul* array_M_reverse,ul p); // 大数相加
ul multi_number_mul(ul c,ul M,ul M_reverse,ul p); // 大数相乘
int validation(ul* array_n);
void rsa_attack(void); // 算法2
#endif /* rsa_attack_h */
