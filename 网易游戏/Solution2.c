#include <stdio.h>
#include <string.h>

int n;
int a[100002];
int time[100002];	//剩余比赛次数
int depth[100002];

int main(){
	scanf("%d",&n);
	a[0] = 0;
	a[1] = 0;
	for (int i = 2; i <= n; i++){
		scanf("%d",&a[i]);
	}
	for (int i = 2; i <= n; i++){
		time[a[i]]++;
	}
	for (;;){
		if (time[1] == 0)
			break;
		for (int i = 2; i <= n; i++){
			if (time[i] == 0){
				if (depth[i] > depth[a[i]]){
					depth[a[i]] = depth[i];
				}
				depth[a[i]]++;
				time[i]--;
				time[a[i]]--;
			}
		}
	}
	printf("%d",depth[1]);
	return 0;
}