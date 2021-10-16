/*
 * 文件名：rsa_basic.h
 * 作者：谢远峰
 * 描述：rsa算法1程序声明
 * 最近修改时间：2021/10/14
 * 修改内容：完成算法1函数的定义
 */

#ifndef rsa_basic_h
#define rsa_basic_h

#include "rsa_public.h"

int create_prime_store(ul number,int* array); // 创建指定素数库
int prime_test(ul number_p,ul number_q); // 对于指定数进行费马定理测试和遍历素数测试
int prime_check(ul number); // 传统的素数判定
int fermat_check(ul number); // 斐马素性测试
int e_check(ul e,ul n); // e的参数检查
int d_check(ul d,ul phi); // d的参数检查
int is_prime(ul number); // 素数判定
ul rsa_encrypt(ul m,ul e,ul n); // rsa加密
ul rsa_decrypt(ul c,ul d,ul n); // rsa解密
void rsa_encrypt_and_decrypt(void); // 算法1
void test1(ul p,ul q,ul e,ul m); //子程序测试1
void test2(ul p,ul q,ul d,ul c); //子程序测试2

#endif /* rsa_basic_h */
