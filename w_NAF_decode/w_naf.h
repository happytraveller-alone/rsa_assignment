//
//  w_naf.h
//  w_NAF_decode
//
//  Created by xieyuanfeng on 2021/10/31.
//

#ifndef w_naf_h
#define w_naf_h

#include <stdio.h>
#include <stdlib.h>

#define array_size 65

void factor_input(uint64_t* const e,uint16_t* const k);
void array_print(const uint16_t size,const int16_t* const array,const uint16_t* w);
uint16_t w_naf(uint64_t* const k,uint16_t* const w,int16_t* array);
int64_t mod(uint64_t input,uint16_t w);
uint64_t power(uint64_t base,uint16_t exponent);
//uint16_t binary_array_convert(int16_t* array,const uint64_t* e);
#endif /* w_naf_h */
