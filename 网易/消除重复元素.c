/*
小易有一个长度为n序列，小易想移除掉里面的重复元素，但是小易想是对于每种元素保留最后出现的那个。小易遇到了困难,希望你来帮助他。 

输入描述:
	输入包括两行：
	第一行为序列长度n(1 ≤ n ≤ 50)
	第二行为n个数sequence[i](1 ≤ sequence[i] ≤ 1000)，以空格分隔


输出描述:
	输出消除重复元素之后的序列，以空格分隔，行末无空格

输入例子:
	9
	100 100 100 99 99 99 100 100 100

输出例子:
	99 100
*/

#include <stdio.h>
#include <stdlib.h>

int n = 0;
int a[50];

int b[50];
int count = 0;

int isexist(int a){
	for (int i = 0; i < count; i++){
		if (a == b[i])
			return 1;
	}
	return 0;
}

int main(void){
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	for (int i = n - 1; i >= 0; i--){
		if (!isexist(a[i])){
			b[count] = a[i];
			count++;
		}
	}
	for (int i = count - 1; i >= 0; i--){
		printf("%d", b[i]);
		if (i != 0){
			printf(" ");
		}
	}
	//system("PAUSE");
	return 0;
}