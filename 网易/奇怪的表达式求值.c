/*
常规的表达式求值，我们都会根据计算的优先级来计算。比如*和\的优先级就高于+-。但是小易所生活的世界的表达式规则很简单，从左往右依次计算即可，而且小易所在的世界没有除法，意味着表达式中没有/，只有(+, - 和 *)。现在给出一个表达式，需要你帮忙计算出小易所在的世界这个表达式的值为多少 

输入描述:
	输入为一行字符串，即一个表达式。其中运算符只有-,+,*。参与计算的数字只有0~9.
	保证表达式都是合法的，排列规则如样例所示。

输出描述:
	输出一个数，即表达式的值

输入例子:
	3+5*7

输出例子:
	56
*/

#include <stdio.h>
#include <string.h>

int result=0;
int x = 0;

char a[100];

int chartoint(char a){
	switch (a){
	case '0': return 0;
	case '1': return 1;
	case '2': return 2;
	case '3': return 3;
	case '4': return 4;
	case '5': return 5;
	case '6': return 6;
	case '7': return 7;
	case '8': return 8;
	case '9': return 9;
        default:return -1;
	}
}

int main(void){
	gets(a);
	result = chartoint(a[0]);
	for (int i = 1; i < strlen(a);i=i+2 ){
		if (a[i] == '+'){
			result += chartoint(a[i + 1]);
		}
		else if (a[i] == '-'){
			result -= chartoint(a[i + 1]);
		}
		else if (a[i] == '*'){
			result = result*chartoint(a[i + 1]);
		}else{
            break;
        }
	}
	printf("%d",result);
	return 0;
}