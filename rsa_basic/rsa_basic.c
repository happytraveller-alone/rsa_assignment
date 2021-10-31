//
//  rsa_basic.c
//  rsa_basic
//
//  Created by xieyuanfeng on 2021/10/26.
//

#include "rsa_basic.h"

uint32_t p = 0;
uint32_t q = 0;
uint32_t e = 0;
uint32_t m = 0;
uint16_t* n_array;
uint16_t* c_array;

void factor_input(uint32_t* factor_array){
    srand((uint16_t)time(NULL));
    for(_Bool input_check = 0;input_check == 0;){
        printf("Please input four factor(format:p,q,e,m):");
        scanf("%u,%u,%u,%u", &p, &q, &e, &m);
        printf("p:%u,q:%u,e:%u,m:%u\n", p, q, e, m);
        if (p_and_q_prime_check(p, q) == 0) {
            printf("prime test failed, try again!\n");
            continue;
        }
        n_array = n_caculate(p, q);
        if (e_check(e, p-1,q-1) == 0) {
            printf("e check failed!!!\n");
            printf("e test failed, try again!\n");
            continue;
        } else {
            printf("e check succeed!!!\n");
        }
        input_check = 1;
    }
    factor_array[0] = p;
    factor_array[1] = q;
    factor_array[2] = e;
    factor_array[3] = m;
    c_array = rsa_encrypt(m, e, p, q);
//    for(uint16_t i = 0;c_array[i] )
    // 输出
    return;
}
// 扩展欧几里德测试
uint32_t extend_gcd(uint32_t a,uint32_t b,uint32_t* x,uint32_t* y){
    if(b == 0){
        *x = 1;
        *y = 0;
        return a;
    }
    uint32_t r = extend_gcd(b, a%b, x, y);
    uint32_t t = *y;
    *y = *x - (a / b) * (*y);
    *x = t;
    return r;
}
//// 获取乘法逆元
//uint32_t mul_reverse_get(uint32_t e,uint32_t phi){
//    return 0;
//}
// 模幂计算
uint32_t model_power_calculation(uint32_t a,uint32_t b,uint32_t c){
    uint16_t* array = (uint16_t*)malloc(number_length_get(b, 0)*sizeof(uint16_t));
    uint16_t size = number_to_array(b, array, 2, 1);
    uint32_t result = 1;
    for(uint16_t i = 0;i < size;i++){
        result = quick_multiple(result, result, c);
        if(array[i]){result = quick_multiple(result, a, c);}
    }
    free(array);
    return 0;
}
// 快速乘
uint32_t quick_multiple(uint32_t a,uint32_t b,uint32_t c){
    return 0;
}
// 整数转数组
uint16_t number_to_array(uint32_t number,uint16_t* array,uint16_t radix,_Bool reverse){
    return 0;
}

// 数字长度获取
uint16_t number_length_get(uint32_t number,uint16_t length){
    while(number != 0){
        number /= 10;
        length++;
    }
    return length;
}

// e参数检查
_Bool e_check(uint32_t e,uint32_t a,uint32_t b){
    return 0;
}

// 数组处理
uint16_t* array_process(uint16_t* a,uint16_t a_length,uint16_t* b,uint16_t b_length,uint16_t* c,uint16_t oprator){
    // p,q的长度需要知道，创建结果数组，将运算结果进行存储
    uint16_t* result_array = (uint16_t*)malloc((a_length+b_length)*sizeof(uint16_t));
    return result_array;
}
// n数组的计算
uint16_t* n_caculate(uint32_t p,uint32_t q){
    uint16_t p_length = number_length_get(p, 0);
    uint16_t q_length = number_length_get(q, 0);
    uint16_t* n_array = (uint16_t*)malloc((p_length+q_length)*sizeof(uint16_t));
    uint16_t* p_array = (uint16_t*)malloc(p_length*sizeof(uint16_t));
    uint16_t* q_array = (uint16_t*)malloc(q_length*sizeof(uint16_t));
    uint16_t* result = array_process(p_array,p_length,q_array,q_length,n_array,2);
    free(p_array);
    free(q_array);
    return result;
}

// 素数判定
_Bool prime_check_easy(uint32_t number){
    for(uint32_t i = sqrt(number);i > 1;i--){
        if(number % i == 0){return 0;}
    }
    return 1;
}

// 素数判定库
uint16_t create_prime_store(uint32_t number,uint32_t* array){
    uint16_t j = 0;
    for(uint16_t i = 2;i < number;i++){
        if(prime_check_easy(i)){
            array[j] = i;
            j++;
            continue;
        }
    }
    return j;
}

// fermat测试实现
_Bool fermat_check(uint32_t number){
    uint32_t test_num,x,y;
    uint16_t k = 20;
    while(k){
        test_num = 2 + (rand() << 4 | rand()) % (number - 4);
        if(extend_gcd(number, test_num, &x, &y)){return 0;}
        if(model_power_calculation(test_num, number - 1, number) != 1){return 0;}
        k--;
    }
    return 1;
}

// 暴力测试实现
_Bool brute_check(uint32_t number){
    uint32_t* prime_array = (uint32_t*)malloc(number/10 * sizeof(uint32_t));
    uint16_t size = create_prime_store(number, prime_array);
    for(uint16_t i = size - 1;i >= 0;i--){
        if(prime_array[i] >= number){continue;}
        if(number % prime_array[i] == 0){
            free(prime_array);
            return 0;
        }
    }
    free(prime_array);
    return 1;
}


// fermat测试+暴力测试
uint16_t fermat_check_plus_brute_check(uint32_t p,uint32_t q,uint16_t p_check,uint16_t q_check){
    p_check = (number_length_get(p, 0) <= 2)? 2:0;
    q_check = (number_length_get(q, 0) <= 2)? 2:0;
    if(((p_check << 2) | (q_check << 1)) > 0){
        return ((p_check << 2 | q_check << 1));
    }
    p_check = (fermat_check(p) & brute_check(p))? 1:0;
    q_check = (fermat_check(q) & brute_check(q))? 1:0;
    return (p_check << 1 | q_check);
}

// p和q的素数判定
_Bool p_and_q_prime_check(uint32_t p,uint32_t q){
    switch(fermat_check_plus_brute_check(p, q, 0, 0)){
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 1;
        case 4:
            return 0;
        case 8:
            return 0;
        case 12:
            return 0;
        default:
            return 0;
    }
    return 0;
}

// rsa加密计算
uint16_t* rsa_encrypt(uint32_t m, uint32_t e, uint32_t p, uint32_t q){
    uint16_t* n = (uint16_t*)malloc(32*sizeof(uint16_t));
    return n;
}
