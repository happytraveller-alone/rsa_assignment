编译命令：
Mac xcode 可直接运行
windows编译： 进入rsa_assignment文件夹 gcc -g rsa_assignment.c rsa_basic.c rsa_attack.c rsa_public.c -o test.exe
windows运行： ./test.exe
Linux编译：进入rsa_assignment文件夹 gcc -g rsa_assignment.c rsa_basic.c rsa_attack.c rsa_public.c -o test
Linux运行：./test


输入数据：
2357,2551,3674911,5234673
885320963,238855417,116402471153538991,113535859035722866
3,763813,828083,720761,352596,408368,6728


完整的程序输出参考：
Please input four factor(format:p,q,e,m):2357,2551,3674911,5234673
p:2357,q:2551,e:3674911,m:5234673
prime check succeed!!!
n:6012707 
f:6007800 
e check succeed!!!
d:422191
message to encrypt:5234673
message encrypted:3650502
message decrypted:5234673
encrypt and decrypt succeed!!!
Please input four factor(format:p,q,d,c):
885320963,238855417,116402471153538991,113535859035722866
p:885320963,q:238855417,d:116402471153538991,c:113535859035722866
prime check succeed!!!
n:211463707796206571 
f:211463706672030192 
d check succeedmessage decrypted:30120
Please input seven factors(format:e,n1,n2,n3,c1,c2,c3):
3,763813,828083,720761,352596,408368,6728
e:3,n1:763813,n2:828083,n3:720761,c1:352596,c2:408368,c3:6728
1881640295202816
123456
Program ended with exit code: 0