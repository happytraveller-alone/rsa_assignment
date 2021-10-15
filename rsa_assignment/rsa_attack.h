//
//  rsa_attack.h
//  rsa_assignment
//
//  Created by xieyuanfeng on 2021/10/15.
//

#ifndef rsa_attack_h
#define rsa_attack_h

#include "rsa_public.h"

ul bignumber_sum(ul* array_c,ul* array_M,ul* array_M_reverse,ul p); // 大数相加
ul multi_number_mul(ul c,ul M,ul M_reverse,ul p); // 大树相乘
void rsa_attack(void); // 算法2
#endif /* rsa_attack_h */
