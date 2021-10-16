/*
 * 文件名：rsa_basic.c
 * 作者：谢远峰
 * 描述：rsa算法1程序定义
 * 最近修改时间：2021/10/16
 * 修改内容：完成算法1函数的书写和测试
 */

#include "rsa_basic.h"

// 质数判定  测试成功
int is_prime(ul number){
    for(int i=sqrt(number);i>1;i--){if(number % i == 0){return 0;}}
    return 1;
}

// 创建指定素数库 测试成功
int create_prime_store(ul number,int* array){
    int j = 0;
    for(int i = 2;i <= number;i++){
        if(is_prime(i)){
            array[j] = i;
            j++;
            continue;
        }
    }
    return j;
}

// 判定结果输出
void prime_test_out(ul number_p,ul number_q){
    switch(prime_test(number_p, number_q)){
        case 0:
            printf("both p and q are not prime!!!\n");
            break;
        case 1:
            printf("p is not prime!!!\n");
            break;
        case 2:
            printf("q is not prime!!!\n");
            break;
        case 3:
            printf("prime check succeed!!!\n");
            break;
        default:
            printf("unkonw error?!\n");
            break;
    }
    return;
}

// 对于指定数进行费马定理测试和遍历素数测试
int prime_test(ul number_p,ul number_q){
    int p_check = 0, q_check = 0;
    p_check=(fermat_check(number_p) & prime_check(number_p))? 1:0;
    q_check=(fermat_check(number_q) & prime_check(number_q))? 1:0;
    return(p_check << 1 | q_check);
}

// 传统的素数判定
int prime_check(ul number){
    int array[10000] = {0};
    int size = create_prime_store(10000,array);
    for(int i = size - 1;i >= 0;i--){
        if(array[i] >= number){continue;}
        else if(number % array[i] == 0){return 0;}
    }
    return 1;
}

// 费马素性测试
int fermat_check(ul number){
    srand((unsigned int)number);
    ul test_num,x,y;
    int k = 20;
    while(k){
        test_num = 2 + (rand() << 4 | rand()) % (number - 4);
        if(extend_gcd(number, test_num, &x, &y) != 1){return 0;}
        if(modal_power_calculation(test_num, number-1, number) != 1){return 0;}
        k--;
    }
    return 1;
}

// e参数检查
int e_check(ul e,ul phi){ul x,y;return ((int)extend_gcd(e, phi, &x, &y));}
// d参数检查
int d_check(ul d,ul phi){return ((ll)d >= (ll)phi)? 0:1;}
// rsa加密
ul rsa_encrypt(ul m,ul e,ul n){return (modal_power_calculation(m, e, n));}
// rsa解密
ul rsa_decrypt(ul c,ul d,ul n){return (modal_power_calculation(c, d, n));}

void test1(ul p,ul q,ul e,ul m){
    printf("Please input four factor(format:p,q,e,m):");
    scanf("%lu,%lu,%lu,%lu",&p,&q,&e,&m);
    printf("p:%lu,q:%lu,e:%lu,m:%lu\n",p,q,e,m);
    prime_test_out(p,q);
    ul n = p * q;
    ul fai = (p-1) * (q-1);
    printf("n:%lu \n",n);
    printf("f:%lu \n",fai);
    (e_check(e,n))? printf("e check succeed!!!\n"):printf("e check failed!!!\n");
    ul d = mul_reverse_get(e, fai);
    printf("d:%lu\n",d);
    printf("message to encrypt:%lu\n",m);
    ul c = rsa_encrypt(m, e, n);
    printf("message encrypted:%lu\n",c);
    ul out = rsa_decrypt(c, d, n);
    printf("message decrypted:%lu\n",out);
    (out == m)? printf("encrypt and decrypt succeed!!!\n"):printf("error,try to debug!!!\n");
    return;
}

void test2(ul p,ul q,ul d,ul c){
    printf("Please input four factor(format:p,q,d,c):");
    scanf("%lu,%lu,%lu,%lu",&p,&q,&d,&c);
    printf("p:%lu,q:%lu,d:%lu,c:%lu\n",p,q,d,c);
    prime_test_out(p,q);
    ul n = p * q;
    ul fai = (p-1) * (q-1);
    printf("n:%lu \n",n);
    printf("f:%lu \n",fai);
    d_check(d, fai)? printf("d check succeed"):printf("d check failed");
    ul out = rsa_decrypt(c, d, n);
    printf("message decrypted:%lu\n",out);
    return;
}

// 算法1
void rsa_encrypt_and_decrypt(void){
    ul p = 0,q = 0;
    ul e = 0,m = 0;
    ul d = 0,c = 0;

    // 2357,2551,3674911,5234673 \ 103,193,7,19000
    test1(p,q,e,m); 
    // 885320963,238855417,116402471153538991,113535859035722866
    test2(p,q,d,c);
    return;
}
