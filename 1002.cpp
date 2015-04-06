#include <stdio.h>

#define MAX_EXPO 1001

double a[MAX_EXPO];

void get(){
	int i, K, expo;
	double coef;
	scanf("%d", &K);
	for(i=0; i<K; i++){
		scanf("%d%lf", &expo, &coef);
		a[expo]+=coef;
	}
}

int main(){
	int i, cnt=0;

	for(i=0; i<MAX_EXPO; i++){
		a[i]=0;
	}
	get();
	get();
	
	for(i=0; i<MAX_EXPO; i++){
		if(a[i] != 0){
			cnt++;
		}
	}
	printf("%d", cnt);
	for(i=MAX_EXPO-1; i>=0; i--){
		if(a[i] != 0){
			printf(" %d %.1lf", i, a[i]);
		}
	}
	return 0;
}
