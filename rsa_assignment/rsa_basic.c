/*
 * 文件名：rsa_basic.c
 * 作者：谢远峰
 * 描述：rsa算法1程序定义
 * 最近修改时间：2021/10/16
 * 修改内容：完成算法1函数的书写和测试
 */

#include "rsa_basic.h"

// 质数判定  测试成功
int is_prime(ul number) {
    for (int i = sqrt(number); i > 1; i--) {
        if (number % i == 0) {
            return 0;
        }
    }
    return 1;
}

// 创建指定素数库 测试成功
int create_prime_store(ul number, int* array) {
    int j = 0;
    for (int i = 2; i <= number; i++) {
        if (is_prime(i)) {
            array[j] = i;
            j++;
            continue;
        }
    }
    return j;
}

// 判定结果输出
int prime_test_out(ul number_p, ul number_q) {
    switch (prime_test(number_p, number_q, 0, 0)) {
        case 0:
            printf("both p and q are not prime!!!\n");
            return 0;

        case 1:
            printf("p is not prime!!!\n");
            return 0;
        case 2:
            printf("q is not prime!!!\n");
            return 0;
        case 3:
            printf("prime check succeed!!!\n");
            return 1;
        case 4:
            printf("q is too short!!!\n");
            return 0;
        case 8:
            printf("p is too short!!!\n");
            return 0;
        case 12:
            printf("p and q are too short\n");
            return 0;
        default:
            printf("unkonw error?!\n");
            return 0;
    }
    return -1;
}

// 对于指定数进行费马定理测试和遍历素数测试
int prime_test(ul number_p, ul number_q, int p_check, int q_check) {
    p_check = (number_length_get(number_p, 0) <= 2) ? 2 : 0;
    q_check = (number_length_get(number_q, 0) <= 2) ? 2 : 0;
    if (((p_check << 2) | (q_check << 1)) > 0)
        return ((p_check << 2) | (q_check << 1));
    p_check = (fermat_check(number_p) & prime_check(number_p)) ? 1 : 0;
    q_check = (fermat_check(number_q) & prime_check(number_q)) ? 1 : 0;
    return (p_check << 1 | q_check);
}

// 传统的素数判定
int prime_check(ul number) {
    int array[10000] = {0};
    int size = create_prime_store(10000, array);
    for (int i = size - 1; i >= 0; i--) {
        if (array[i] >= number) {
            continue;
        } else if (number % array[i] == 0) {
            return 0;
        }
    }
    return 1;
}

// 费马素性测试
int fermat_check(ul number) {
    srand((unsigned int)number);
    ul test_num, x, y;
    int k = 20;
    while (k) {
        test_num = 2 + (rand() << 4 | rand()) % (number - 4);
        if (extend_gcd(number, test_num, &x, &y) != 1) {
            return 0;
        }
        if (modal_power_calculation(test_num, number - 1, number) != 1) {
            return 0;
        }
        k--;
    }
    return 1;
}

// e参数检查
int e_check(ul e, ul phi) {
    ul x, y;
    return ((int)extend_gcd(e, phi, &x, &y));
}
// d参数检查
int d_check(ull d, ull phi) { return (d >= phi) ? 0 : 1; }
// rsa加密
ul rsa_encrypt(ul m, ul e, ul n) { return (modal_power_calculation(m, e, n)); }
// rsa解密
ul rsa_decrypt(ull c, ull d, ull n) {
    return (modal_power_calculation(c, d, n));
}

void test1(ul p, ul q, ul e, ul m) {
    ul n = 0;
    ul fai = 0;
    for (int input_check = 0; input_check == 0;) {
        printf("Please input four factor(format:p,q,e,m):");
        scanf("%lu,%lu,%lu,%lu", &p, &q, &e, &m);
        printf("p:%lu,q:%lu,e:%lu,m:%lu\n", p, q, e, m);
        if (prime_test_out(p, q) == 0) {
            printf("prime test failed, try again!\n");
            continue;
        }
        n = p * q;
        fai = (p - 1) * (q - 1);
        printf("n:%lu \n", n);
        printf("f:%lu \n", fai);
        if (e_check(e, n) == 0) {
            printf("e check failed!!!\n");
            printf("e test failed, try again!\n");
            continue;
        } else {
            printf("e check succeed!!!\n");
        }
        input_check = 1;
    }

    ul d = mul_reverse_get(e, fai);
    printf("d:%lu\n", d);
    printf("message to encrypt:%lu\n", m);
    ul c = rsa_encrypt(m, e, n);
    printf("message encrypted:%lu\n", c);
    ul out = rsa_decrypt(c, d, n);
    printf("message decrypted:%lu\n", out);
    (out == m) ? printf("encrypt and decrypt succeed!!!\n")
               : printf("error,try to debug!!!\n");
    return;
}

void test2(ull p, ull q, ull d, ull c) {
    ull n = 0;
    ull fai = 0;
    for (int input_check = 0; input_check == 0;) {
        printf("Please input four factor(format:p,q,d,c):\n");
        scanf("%llu,%llu,%llu,%llu", &p, &q, &d, &c);
        printf("p:%llu,q:%llu,d:%llu,c:%llu\n", p, q, d, c);
        if (prime_test_out(p, q) == 0) {
            printf("prime test failed, try again!\n");
            continue;
        }
        n = ((ull)(p) * (ull)(q));
        fai = (ull)(p - 1) * (ull)(q - 1);
        printf("n:%llu \n", n);
        printf("f:%llu \n", fai);
        if (d_check(d, fai) == 0) {
            printf("d check failed, try again!\n");
        } else {
            printf("d check succeed\n");
            input_check = 1;
        }
    }

    ull out = rsa_decrypt(c, d, n);
    printf("message decrypted:%llu\n", out);
    return;
}

// 算法1
void rsa_encrypt_and_decrypt(void) {
    ull p = 0, q = 0;
    ull e = 0, m = 0;
    ull d = 0, c = 0;

    // 2357,2551,3674911,5234673 \ 103,193,7,19000
    test1(p, q, e, m);
    // 885320963,238855417,116402471153538991,113535859035722866
    test2(p, q, d, c);
    return;
}
