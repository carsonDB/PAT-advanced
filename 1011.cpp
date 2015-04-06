#include <stdio.h>

char dict[] = { 'W', 'T', 'L' };
int flag[3];

double max(double a, double b, double c, int i){
	flag[i] = 0;
	if(a < b){
		a = b;
		flag[i] = 1;
	}
	if(a < c){
		a = c;
		flag[i] = 2;
	}
	return a;
}

int main(){
	int i;
	double W, T, L;
	double odd = 1;
	for(i = 0; i < 3; i++){
		scanf("%lf%lf%lf", &W, &T, &L);
		odd *= max(W, T, L, i);
	}
	for(i=0; i<3; i++){
		printf("%c ", dict[flag[i]]);
	}
	printf("%.2lf", (odd*0.65 - 1) * 2);
	return 0;
} 
