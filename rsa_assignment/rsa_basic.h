//
//  rsa_basic.h
//  rsa_assignment
//
//  Created by xieyuanfeng on 2021/10/15.
//

#ifndef rsa_basic_h
#define rsa_basic_h

#include "rsa_public.h"

int create_prime_store(ul number,int* array); // 创建指定素数库
int prime_test(ul number_p,ul number_q); // 对于指定数进行费马定理测试和遍历素数测试
int prime_check(ul number); // 传统的素数判定
int fermat_check(ul number); // 斐马素性测试
int e_check(ul e,ul n);
int is_prime(ul number);
ul rsa_encrypt(ul m,ul e,ul n); // rsa加密
ul rsa_decrypt(ul c,ul d,ul n); // rsa解密
void rsa_encrypt_and_decrypt(void); // 算法1
#endif /* rsa_basic_h */
