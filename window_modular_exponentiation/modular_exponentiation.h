//
//  modular_exponentiation.h
//  window_modular_exponentiation
//
//  Created by xieyuanfeng on 2021/10/30.
//

#ifndef modular_exponentiation_h
#define modular_exponentiation_h

#include <stdio.h>
#include <stdlib.h>

#define binary_size 65
void factor_input(uint64_t* const e,uint16_t* const k);
uint16_t binary_array_convert(uint16_t* array,const uint64_t* e);
void array_print(const uint16_t size,const uint16_t* const array);
void k_ary_method_process(const uint16_t size, uint16_t* array,uint16_t* k);
void window_decode_method_process(const uint16_t size,const uint16_t* array,const uint16_t* k);

#endif /* modular_exponentiation_h */


