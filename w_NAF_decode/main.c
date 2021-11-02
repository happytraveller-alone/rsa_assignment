//
//  main.c
//  w_NAF_decode
//
//  Created by xieyuanfeng on 2021/10/31.
//

#include "w_naf.h"

int main(int argc, const char * argv[]) {
    uint64_t k = 1122334455;
    uint16_t w = 0;
    for(uint16_t i = 2;i <= 6;i++){
        w = i;
        int16_t* array = (int16_t*)malloc(array_size * sizeof(int16_t));
    //    factor_input(&k,&w);
        uint16_t size = w_naf(&k, &w, array);
        array_print(size, array, &w);
        free(array);
    }
//    int16_t* array = (int16_t*)malloc(array_size * sizeof(int16_t));
////    factor_input(&k,&w);
//    uint16_t size = w_naf(&k, &w, array);
//    array_print(size, array);
    return 0;
}
