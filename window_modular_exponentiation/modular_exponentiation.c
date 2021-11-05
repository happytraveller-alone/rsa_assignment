//
//  modular_exponentiation.c
//  window_modular_exponentiation
//
//  Created by xieyuanfeng on 2021/10/30.
//

#include "modular_exponentiation.h"

void factor_input(uint64_t* const e,uint16_t* const k){
    printf("please input two factors(format:e,k):\n");
    scanf("%llu,%hd",e,k);
    printf("e:%llu,k:%hd\n",*e,*k);
    return;
}

uint16_t binary_array_convert(uint16_t* array,const uint64_t* e){
    uint16_t count = 1;
    uint64_t temp = *e;
    while(temp){
        array[count] = temp % 2;
        temp /= 2;
        count++;
    }
    return (count - 1);
}

void array_print(const uint16_t size,const uint16_t* const array){
    uint16_t count = 1;
    printf("e_binary_array:");
    for(count = size;count > 0;count--){
        printf("%d",array[count]);
    }
    printf("\n");
    return;
}

void k_ary_method_process(const uint16_t size, uint16_t* array,uint16_t* k){
    uint16_t k_ary_size = (size % (*k) == 0)? size: ((size / (*k) + 1) * (*k));
    if(size % (*k) != 0){
        for(uint16_t count = size + 1;count <= k_ary_size;count++){array[count] = 0;}
    }
    printf("k_ary method process:");
    uint16_t window_count = 1;
    for(int16_t count = k_ary_size;count > 0;count--,window_count++){
        printf("%d",array[count]);
        if(window_count == (*k)){printf(" ");window_count = 0;}
    }
    printf("\n");
    return;
}


void window_decode_method_process(const uint16_t size,const uint16_t* array,const uint16_t* k){
    printf("window_decode_method_process:");
    int16_t count = size;
    int16_t window_count = 0;
    int16_t base_count = 0;
    for(;count > 0;){
        if(array[count] == 0){
            printf("%d",array[count]);
            if(array[count-1] == 1){printf(" ");}
            count--;
        }
        else{
            for(window_count = (*k) - 1;window_count >=0;window_count--){
                if(array[count - window_count] == 1){break;}
                if(count - window_count < 0){continue;}
            }
            for(base_count = 0;base_count <= window_count;base_count++){
                printf("%d",array[count-base_count]);
            }
            printf(" ");
            count -= (window_count + 1);
        }
    }
    printf("\n");
    return;
}
