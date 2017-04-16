#include <stdio.h>
#include <string.h>

int queue[1000];
int top = 0;
int array[1000];
int thiscount = 0;
int mission[1000][2];
int thisM[1000][2];
int flag = 0;

int isOK(int thiscount, int thisM[1000][2], int check[2]){
	for (int i = 0; i <= thiscount; i++){
		if (!(check[0] >= thisM[i][1] || check[1] <= thisM[i][0]))
			return 0;
	}
	return 1;
}

void comb(int s, int n, int m)
{
	int i;
	if (s > n)
		return;
	if (top == m)     {
		if (flag == 1)
			return;
		flag = 1;
		thiscount = 0;
		memset(&thisM, 0, sizeof(thisM));
		for (i = 0; i < m; i++)
		{
			if (isOK(thiscount, thisM, mission[queue[i]]) == 0){
				flag = 0;
				break;
			}
			else{
				thiscount++;
				thisM[thiscount][0] = mission[queue[i]][0];
				thisM[thiscount][1] = mission[queue[i]][1];
			}
		}
		return;
	}
	queue[top++] = array[s];
	comb(s + 1, n, m);
	top--;
	comb(s + 1, n, m);
}

int main(){
	int n;
	scanf("%d", &n);
	int max = n;
	for (int i = 0; i < n; i++){
		scanf("%d", &mission[i][0]);
		scanf("%d", &mission[i][1]);
	}
	for (int i = 0; i < n; i++){
		array[i] = i;
	}

	for (int i = n; i >= 1; i--){
		comb(0, n, i);
		if (flag == 1)
			break;
		max--;
	}
	printf("%d", max);
	return 0;
}