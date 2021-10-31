//
//  strong_prime.c
//  Strong_Prime
//
//  Created by xieyuanfeng on 2021/10/21.
//

#include "strong_prime.h"

void input(){
    printf("please input a number(length of strong prime):");
    scanf("%d",&input_length);
    printf("the number offered  is : %d\n",input_length);
    int s,r,t = 0;
    s = r = t = (input_length % 2 == 1)? ((input_length + 1) / 2):(input_length / 2);
}

// a^(b) mod c
ull modal_power_calculation(ull a,ull b,ull c){
    int array_size = bit_lenght_get(b,0) + 1;
    ul* array = (ul*)malloc(array_size * sizeof(ul));
    int size = number_to_array((ull)b, array, 2, 1);
    ull res = 1;
    for(int i = 0;i < size;i++){
        res = quick_mul(res, res, c);
        if(array[i]){res = quick_mul(res, a, c);}
    }
    return res;
}

// 整数转数组 测试成功
int number_to_array(ull number,ul* array,int radix,int reverse){
    ul i = 0;
    while(number!=0){
        array[i] = number % radix;
        number /= radix;
        i++;
    }
    ul size = i;
    if(reverse == 1){
        ul* temp = (ul*)malloc((size)*sizeof(ul));
        for(i = 0;i < size;i++){temp[i]=array[i];}
        for(i = 0;i < size;i++){array[size - i - 1]=temp[i];}
        free(temp);
    }
    return size;
}

// (a*b)%c 测试成功
ull quick_mul(ull a,ull b,ull c){
    ull res=0;//加法初始化
    while(b){
        if(b & 1) res = (res + a) % c;//模仿二进制
        a = (a << 1) % c;
        b >>= 1;//将x不断乘2达到二进制
    }
    return res;
}

Bool Miller_Rabin(ull number,int Security_Parameter){
    if(number < 3) return false;
//    srand((unsigned int)number);
    ull temp = 0,r = 0;
    int s = 0;
    for(temp = number - 1;(temp & 1) == 0;s++){temp /= 2;}
    r = temp;
    ul a = 0;
    ll y = 0;
    for(int i = 0,j = 0;i < Security_Parameter;i++){
        a = rand() % (number - 4) + 2;
        y = modal_power_calculation(a, r, number);
        if((y != 1) && (y != number - 1)){
            j = 1;
            while((j <= s - 1) && (y != number - 1)){
                y = quick_mul(y, y, number);
                if(y == 1)return false;
                j++;
            }
            if(y != number - 1)return false;
        }
    }
    return true;
}

ul Random_Search(int k, int Security_Parameter){
    ul result = 0;
    int cnt = 0;
    ul temp = 1;
    ull low_bound = (ull)pow(2.0,k-1);
//    for(cnt = 0;cnt < k;cnt++){low_bound *= 2;}
    while(true){
        temp = 1;
        result = 0;
        for(cnt = 0;cnt < k;cnt++){
            result += ((rand() % 2) == 1)? temp:0;
            temp *= 2;
        }
        result += low_bound;
        result=(result % 2 == 1)?  result:result - 1;
        if(result >= low_bound * 1.3){continue;}
        if(!prime_check(result, upp_bound)){continue;}
        if(!Miller_Rabin(result, Security_Parameter)){continue;}
        break;
    }
    return result;
}

// 质数判定  测试成功
Bool is_prime(ul number){
    for(int i=sqrt(number);i>1;i--){if(number % i == 0){return 0;}}
    return 1;
}

// 创建指定素数库 测试成功
ul create_prime_store(ul number,ul* array){
    ul j = 0;
    for(ul i = 2;i <= number;i++){
        if(is_prime(i)){
            array[j] = i;
            j++;
            continue;
        }
    }
    return j;
}

// 传统的素数判定
Bool prime_check(ull number,int upper_bound){
    ul* array = (ul*)malloc((ul)(upper_bound) * (ul)sizeof(int));
    ul size = create_prime_store(upper_bound,array);
    for(int i = size - 1;i >= 0;i--){
        if(array[i] >= number){continue;}
        else if(number % array[i] == 0){return false;}
    }
    return true;
}

void prime_generate(ull* prime_array,int* bit_length_array,int length){
    ul s = 0,t = 0,r = 0;
    ull p = 0;
    int half_length = (length % 2 == 1)? ((length + 1)/ 2):length /2;
    prime_array[0] = s = Random_Search(half_length - 1, 20);
    bit_length_array[0] = bit_lenght_get(s, 0);
    prime_array[1] = t = Random_Search(half_length - 1, 20);
    bit_length_array[1] = bit_lenght_get(t, 0);
    for(ul i = 1;;i++){
        if(prime_check((ul)(2*i*t+1),upp_bound)){
            prime_array[2] = r = (ull)2*i*t+1;
            bit_length_array[2] = bit_lenght_get(r, 0);
            printf("i:%d\n",i);
            break;
        }
    }
    
    ull p0 = (modal_power_calculation((ull)s, (ull)(r-2), (ull)r) * 2 * s) - 1;
//    printf("p0:%llu;2*r*s:%llu\n",p0,(ull)2*r*s);
//    printf("p0:%d;2*r*s:%d\n",bit_lenght_get(p0, 0),bit_lenght_get(2*r*s, 0));
    for(ull j = 0;;j++){
        if(prime_check((p0+(ull)2*j*(ull)r*(ull)s),(ull)upp_bound)){
            prime_array[3] = p = (ull)(2*j*r*s+p0);
            bit_length_array[3] = bit_lenght_get(p, 0);
            printf("j:%llu\n",j);
            break;
        }
//        else{printf("false!!\n");}
    }
    return;
}

int bit_lenght_get(ull number,int cnt){
    while(number){number /= 2;cnt++;}
    return (cnt);
}

//// 测试程序
//Bool is_prime_test(ul number){
//    ul* array = (ul*)malloc((number / 175) * sizeof(int));
//    ul size = create_prime_store(number,array);
//    for(int i = size - 1;i >= 0;i--){
//        if(array[i] >= number){continue;}
//        else if(number % array[i] == 0){return false;}
//    }
//    free(array);
//    return true;
//}


