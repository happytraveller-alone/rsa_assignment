/*
 * 文件名：rsa_attack.c
 * 作者：谢远峰
 * 描述：算法2函数定义
 * 最近修改时间：2021/10/16
 * 修改内容：完成算法2函数的书写和测试
 */

#include "rsa_attack.h"

// 大数相加
ull bignumber_sum(ul* array_c, ull* array_M, ull* array_M_reverse, ull p) {
    ull res = 0;
    for (int i = 0; i < 3; i++) {
        res = (res + multi_number_mul((ull)array_c[i], array_M[i],array_M_reverse[i], p)) % p;
    }
    return res;
}

// 大数相乘
ull multi_number_mul(ull c, ull M, ull M_reverse, ull p) {
    return (quick_mul(quick_mul(c, M, p), M_reverse, p));
}

int validation(ul* array_n) {
    ul x1, x2, x3, y1, y2, y3;
    if (extend_gcd(array_n[0], array_n[1], &x1, &y1) != 1) {return 0;}
    if (extend_gcd(array_n[1], array_n[2], &x2, &y2) != 1) {return 0;}
    if (extend_gcd(array_n[2], array_n[0], &x3, &y3) != 1) {return 0;}
    return 1;
}

// 算法2
void rsa_attack(void) {
    // 3,763813,828083,720761,352596,408368,6728
    ul e = 0, n1, n2, n3;
    ull x, n0;
    ull M1, M2, M3, M1_, M2_, M3_;
    ul c1, c2, c3;
    while (1) {
        printf("Please input seven factors(format:e,n1,n2,n3,c1,c2,c3):\n");
        scanf("%lu,%lu,%lu,%lu,%lu,%lu,%lu", &e, &n1, &n2, &n3, &c1, &c2, &c3);
        printf("e:%lu,n1:%lu,n2:%lu,n3:%lu,c1:%lu,c2:%lu,c3:%lu\n", e, n1, n2,
               n3, c1, c2, c3);
        ul array_n[3] = {n1, n2, n3};
        if (validation(array_n) == 1) {
            printf("validate succeed!!\n");
        } else {
            printf("validate failed!!try again!!\n");
            continue;
        }
        n0 = (ull)n1 * (ull)n2 * (ull)n3;
        M1 = (ull)n2 * (ull)n3;
        M2 = (ull)n1 * (ull)n3;
        M3 = (ull)n1 * (ull)n2;
        printf("M1_:%llu,M2_:%llu,M3_:%llu\n", M1, M2, M3);
        M1_ = mul_reverse_get(M1, n1);
        M2_ = mul_reverse_get(M2, n2);
        M3_ = mul_reverse_get(M3, n3);
        printf("M1_:%llu,M2_:%llu,M3_:%llu\n", M1_, M2_, M3_);
        ul array_c[3] = {c1, c2, c3};
        ull array_M[3] = {M1, M2, M3};
        ull array_M_reverse[3] = {M1_, M2_, M3_};
        x = bignumber_sum(array_c, array_M, array_M_reverse, n0);
        double res = 1.0;
        printf("x:%llu\n", x);
        for (; fabs(res * res * res - x) > 1e-7;res = (2 * res + x / res / res) / 3) {;}
        printf("result:%d\n", (int)res);
        break;
    }

    return;
}
