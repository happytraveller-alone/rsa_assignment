//
//  main.c
//  window_modular_exponentiation
//
//  Created by xieyuanfeng on 2021/10/30.
//

#include "modular_exponentiation.h"

int main(void) {
    uint64_t e = 0;
    uint16_t k = 0;
    factor_input(&e,&k);
    uint16_t* e_array = (uint16_t*)malloc(binary_size*sizeof(uint16_t));
    uint16_t array_size = binary_array_convert(e_array,&e);
    printf("array_size:%d\n",array_size);
    array_print(array_size, e_array);
    k_ary_method_process(array_size, e_array, &k);
    window_decode_method_process(array_size, e_array, &k);
    return 0;
}
