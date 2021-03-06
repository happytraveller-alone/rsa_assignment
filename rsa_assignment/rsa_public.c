/*
 * 文件名：rsa_public.c
 * 作者：谢远峰
 * 描述：公共程序定义，包括扩展欧几里得算法，乘法逆元获取，模幂计算，数字转数组，快速乘
 * 最近修改时间：2021/10/16
 * 修改内容：完成公共函数的书写和测试
 */

#include "rsa_public.h"

// 扩展欧几里得测试 测试成功
ul extend_gcd(ul a, ul b, ul* x, ul* y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }
    ul r = extend_gcd(b, a % b, x, y);
    ul t = *y;
    *y = *x - (a / b) * (*y);
    *x = t;
    return r;
}

// 获取乘法逆元 测试成功
ull mul_reverse_get(ull e, ull phi) {
    ull a = e, b = phi;
    ll x0 = 1, y0 = 0;
    ll x = 0, y = 1, q, temp;
    while (b != 0) {
        q = a / b;
        temp = a % b;
        a = b;
        b = temp;
        temp = x;
        x = x0 - q * x;
        x0 = temp;
        temp = y;
        y = y0 - q * y;
        y0 = temp;
    }
    if (x0 < 0) x0 += phi;
    return x0;
}

// a^(b) mod c 测试成功
ull modal_power_calculation(ull a, ull b, ull c) {
    int array[1000];
    int size = number_to_array(b, array, 2, 1);
    ull res = 1;
    for (int i = 0; i < size; i++) {
        res = quick_mul(res, res, c);

        if (array[i]) {
            res = quick_mul(res, a, c);
        }
    }
    return res;
}

// 整数转数组 测试成功
int number_to_array(ull number, int* array, int radix, int reverse) {
    int i = 0;
    while (number != 0) {
        array[i] = number % radix;
        number /= radix;
        i++;
    }
    int size = i;
    if (reverse == 1) {
        int temp[1000];  // 二进制数组极限
        for (i = 0; i < size; i++) {
            temp[i] = array[i];
        }
        for (i = 0; i < size; i++) {
            array[size - i - 1] = temp[i];
        }
    }
    return size;
}

// (a*b)%c 测试成功
ull quick_mul(ull a, ull b, ull c) {
    ull res = 0;  //加法初始化
    while (b) {
        if (b & 1) res = (res + a) % c;  //模仿二进制
        a = (a << 1) % c;
        b >>= 1;  //将x不断乘2达到二进制
    }
    return res;
}

int number_length_get(ul number, int length) {
    while (number != 0) {
        number /= 10;
        length++;
    }
    return length;
}
