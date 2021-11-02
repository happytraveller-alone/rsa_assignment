//
//  w_naf.c
//  w_NAF_decode
//
//  Created by xieyuanfeng on 2021/10/31.
//

#include "w_naf.h"

void factor_input(uint64_t* const k,uint16_t* const w){
    printf("please input two factors(format:k,w):\n");
    scanf("%llu,%hd",k,w);
    printf("e:%llu,k:%hd\n",*k,*w);
    return;
}

uint16_t w_naf(uint64_t* const k,uint16_t* const w,int16_t* array){
    uint16_t i = 0;
    int64_t temp = 0;
    uint64_t iteration = *k;
    while(iteration >= 1){
        if(iteration % 2 == 1){
            temp = mod(iteration,*w);
            array[i] = (int16_t)temp;
            iteration -= temp;
        }
        else{array[i] = 0;}
        iteration /= 2;
        i++;
    }
    return i;
}

void array_print(const uint16_t size,const int16_t* const array,const uint16_t* w){
    int16_t count = 0;
    printf("w_naf_array with %d:\n",*w);
    for(count = size - 1;count >= 0;count--){
        if(array[count] >= 10 || array[count] < 0){
            printf("(%d)",array[count]);
        }
        else{printf("%d",array[count]);}
    }
    printf("\n");
    return;
}


int64_t mod(uint64_t input,uint16_t w){
    int64_t compare1 = input % power(2,w);
    int64_t compare2 = power(2,w-1);
    int64_t result = (compare1 <= compare2)? compare1:compare1 - (int64_t)power(2,w);
    return result;
}

uint64_t power(uint64_t base,uint16_t exponent){
    if (exponent != 0)
        return (base*power(base, exponent-1));
    else
        return (uint64_t)1;
}

