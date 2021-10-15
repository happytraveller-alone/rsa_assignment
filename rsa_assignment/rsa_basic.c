//
//  rsa_basic.c
//  rsa_assignment
//
//  Created by xieyuanfeng on 2021/10/15.
//

#include "rsa_basic.h"

// 质数判定  测试成功
int is_prime(ul number){
    if(number == 2){return 1;}
    for(int i = sqrt(number);i > 1;i--){
        if(number % i == 0){return 0;}
    }
    return 1;
}

// 创建指定素数库 测试成功
int create_prime_store(ul number,int* array){
//    int prime_store[10000] = {0}; // todo:存在风险
    int j = 0;
    for(int i = 2;i <= number;){
        if(is_prime(i)){
            array[j] = i;
            j++;
            i++;
            continue;
        }
        i++;
    }
    return j;
}

// 对于指定数进行费马定理测试和遍历素数测试
int prime_test(ul number_p,ul number_q){
    int p_check = 0, q_check = 0,res = 0;
    p_check=(fermat_check(number_p))? 1:0;
    q_check=(fermat_check(number_q))? 1:0;
    res = (p_check << 1 | q_check);
    if(res != 3){return res;}
    
    p_check=(prime_check(number_p))? 1:0;
    q_check=(prime_check(number_q))? 1:0;
    res = (p_check << 1 | q_check);
    return res;
}

// 传统的素数判定
int prime_check(ul number){
    int i = 0;
    int array[10000] = {0};
    int size = create_prime_store(10000,array);
    for(i = size - 1;i >= 0;){
        if(array[i] >= number){i--;continue;}
        else if(number % array[i] == 0){return 0;}
        i--;
    }
    return 1;
}

// 斐马素性测试
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
int e_check(ul e,ul phi){
    ul x,y;
    return ((int)extend_gcd(e, phi, &x, &y));
}


// rsa加密
ul rsa_encrypt(ul m,ul e,ul n){
    return (modal_power_calculation(m, e, n));
}

// rsa解密
ul rsa_decrypt(ul c,ul d,ul n){
    return (modal_power_calculation(c, d, n));
}

// 算法1
void rsa_encrypt_and_decrypt(void){
    ul p = 0,q = 0;
    ul n = 0,fai = 0;
    ul e = 0,d = 0;
    ul m = 0,c = 0,out = 0;
    
    //    假定输入数据都属于unsigned long类型范围
    //    2357,2551,3674911,5234673
    //    103,193,7,19000
    printf("Please input four factor(format:p,q,e,m):");
    scanf("%lu,%lu,%lu,%lu",&p,&q,&e,&m);
    printf("p:%lu,q:%lu,e:%lu,m:%lu\n",p,q,e,m);
    switch(prime_test(p, q)){
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
    n = p * q;
    fai = (p-1) * (q-1);
    printf("n:%lu \n",n);
    printf("f:%lu \n",fai);
    if(e_check(e,n)){printf("e check succeed!!!\n");}
    else{printf("e check failed!!!\n");}
    d = mul_reverse_get(e, fai);
    printf("d:%lu\n",d);
    printf("message to encrypt:%lu\n",m);
    c = rsa_encrypt(m, e, n);
    printf("message encrypted:%lu\n",c);
    out = rsa_decrypt(c, d, n);
    printf("message decrypted:%lu\n",out);
    if(out == m){
        printf("encrypt and decrypt succeed!!!\n");
    }
    else{
        printf("error,try to debug!!!\n");
    }
    
    // 885320963,238855417,116402471153538991,113535859035722866
    // 大整数运算
    printf("Please input four factor(format:p,q,d,c):\n");
    scanf("%lu,%lu,%lu,%lu",&p,&q,&d,&c);
    printf("p:%lu,q:%lu,d:%lu,c:%lu\n",p,q,d,c);
    switch(prime_test(p, q)){
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
    n = p * q;
    fai = (p-1) * (q-1);
    printf("n:%lu \n",n);
    printf("f:%lu \n",fai);
    out = rsa_decrypt(c, d, n);
    printf("message decrypted:%lu\n",out);
//    if(d_check(d,n)){printf("e check succeed!!!\n");}
//    else{printf("e check failed!!!\n");}
    return;
}
