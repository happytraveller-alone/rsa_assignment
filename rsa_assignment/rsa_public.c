//
//  rsa_public.c
//  rsa_assignment
//
//  Created by xieyuanfeng on 2021/10/15.
//

#include "rsa_public.h"

// 扩展欧几里得测试 测试成功
ul extend_gcd(ul a,ul b,ul* x,ul* y){
    if(b==0){
        *x=1;
        *y=0;
        return a;
    }
    ul r=extend_gcd(b, a%b, x, y);
    ul t= *y;
    *y = *x - (a / b) * (*y);
    *x = t;
    return r;
}

// 获取乘法逆元 测试成功
ul mul_reverse_get(ul e,ul phi){
    ul a = e, b = phi;
    ll x0 = 1, y0 = 0;
    ll x = 0, y = 1, q, temp;
    while(b != 0) {
        q = a / b;
        temp = a % b;
        a = b;
        b = temp;
        temp = x; x = x0 - q * x; x0 = temp;
        temp = y; y = y0 - q * y; y0 = temp;
    }
    if(x0 < 0) x0 += phi;
    return x0;
    
}

// a^(b) mod c 测试成功
ul modal_power_calculation(ul a,ul b,ul c){
    int array[1000];
    int size = number_to_array(b, array, 2, 1);
    ul res = 1;
    for(int i = 0;i < size;i++){
        res = quick_mul(res, res, c);
        if(array[i]){res = quick_mul(res, a, c);}
    }
    return res;
}

// 整数转数组 测试成功
int number_to_array(ul number,int* array,int radix,int reverse){
    int i = 0;
    while(number!=0){
        array[i] = number % radix;
        number /= radix;
        i++;
    }
    int size = i;
    if(reverse == 1){
        int temp[1000]; // 二进制数组极限
        for(i = 0;i < size;i++){temp[i]=array[i];}
        for(i = 0;i < size;i++){array[size - i - 1]=temp[i];}
    }
    return size;
}

// (a*b)%c 测试成功
ul quick_mul(ul a,ul b,ul c){
    ul res=0;//加法初始化
    while(b){
        if(b & 1) res = (res + a) % c;//模仿二进制
        a = (a << 1) % c;
        b >>= 1;//将x不断乘2达到二进制
    }
    return res;
}
