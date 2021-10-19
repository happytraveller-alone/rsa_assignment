/*
 * 文件名：rsa_assignment.c
 * 作者：谢远峰
 * 描述：主程序调用
 * 最近修改时间：2021/10/16
 * 修改内容：完成分函数调用
 */

#include "rsa_public.h"
#include "rsa_basic.h"
#include "rsa_attack.h"

int main(void){
    // rsa算法加密和解密
    // 2357,2551,3674911,5234673 \ 103,193,7,19000
    // 885320963,238855417,116402471153538991,113535859035722866
    rsa_encrypt_and_decrypt();
    // rsa小加密指数攻击
    // 3,763813,828083,720761,352596,408368,6728
//    rsa_attack();
    return 0;
}
