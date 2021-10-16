/*
 * 文件名：rsa_attack.c
 * 作者：谢远峰
 * 描述：算法2函数定义
 * 最近修改时间：2021/10/16
 * 修改内容：完成算法2函数的书写和测试
 */

#include "rsa_attack.h"

// 大数相加
ul bignumber_sum(ul* array_c,ul* array_M,ul* array_M_reverse,ul p){
    ul res = 0;
    for(int i=0;i<3;i++){
        res = (res + multi_number_mul(array_c[i], array_M[i], array_M_reverse[i], p)) % p;
    }
    return res;
}

// 大数相乘
ul multi_number_mul(ul c,ul M,ul M_reverse,ul p){return (quick_mul(quick_mul(c, M, p), M_reverse, p));}


// 算法2
void rsa_attack(void){
    // 3,763813,828083,720761,352596,408368,6728
    ul e = 0,n1,n2,n3;
    ul x,n0;
    ul M1,M2,M3,M1_,M2_,M3_;
    ul c1,c2,c3;
    printf("Please input seven factors(format:e,n1,n2,n3,c1,c2,c3):\n");
    scanf("%lu,%lu,%lu,%lu,%lu,%lu,%lu",&e,&n1,&n2,&n3,&c1,&c2,&c3);
    printf("e:%lu,n1:%lu,n2:%lu,n3:%lu,c1:%lu,c2:%lu,c3:%lu\n",e,n1,n2,n3,c1,c2,c3);
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
    printf("%lu\n",x);
    double res = 1.0;
    for(;fabs(res*res*res-x)>1e-7;res=(2*res+x/res/res)/3){;}
    printf("%d\n",(int)res);
    return;
}
