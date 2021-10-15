//
//  rsa_attack.c
//  rsa_assignment
//
//  Created by xieyuanfeng on 2021/10/15.
//

#include "rsa_attack.h"

// 大数相加
ul bignumber_sum(ul* array_c,ul* array_M,ul* array_M_reverse,ul p){
    int i;
    ll res = 0;
    for(i=0;i<3;i++){
        res = (res + multi_number_mul(array_c[i], array_M[i], array_M_reverse[i], p)) % p;
    }
    return res;
}

//// 大数相乘
ul multi_number_mul(ul c,ul M,ul M_reverse,ul p){
    return (modal_power_calculation(modal_power_calculation(M, M_reverse, p), c, p));
}


// 算法2
void rsa_attack(void){
    ul e = 0,n1,n2,n3;
    ul x,n0;
    ul M1,M2,M3,M1_,M2_,M3_;
    ul c1 = 0,c2 = 0,c3 = 0;
    printf("Please input seven factors(format:e,n1,n2,n3,c1,c2,c3):\n");
    scanf("%lu,%lu,%lu,%lu,%lu,%lu,%lu",&e,&n1,&n2,&n3,&c1,&c2,&c3);
    printf("e:%lu,n1:%lu,n2:%lu,n3:%lu,c1:%lu,c2:%lu,c3:%lu",e,n1,n2,n3,c1,c2,c3);
    
    n0 = n1 * n2 * n3;
    M1 = n2 * n3;
    M2 = n1 * n3;
    M3 = n1 * n2;
    M1_ = mul_reverse_get(M1, n1);
    M2_ = mul_reverse_get(M2, n2);
    M3_ = mul_reverse_get(M3, n3);
    ul array_c[3] = {c1,c2,c3};
    ul array_M[3] = {M1,M2,M3};
    ul array_M_reverse[3] = {M1_,M2_,M3_};
    x = bignumber_sum(array_c, array_M, array_M_reverse, n0);
    long double temp = 1.0;
    for(;fabsl(x*x*x-temp)>1e-7;x=(2*x+temp/x/x)/3){;}

    
}
