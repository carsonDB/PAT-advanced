#include <stdio.h>
#include <stdlib.h>

int main(){
	int a, b, sum, i, flag=1;
	int stack[5], n;
	scanf("%d%d", &a, &b);
	sum = a+b;
	if(sum < 0){
		sum =- sum;
		flag = -1;
	}
	n=0;
	while( sum >=1000 ){
		stack[n++] = sum % 1000;
		sum /= 1000;
	}
	if(flag==-1)
		printf("-");
	printf("%d", sum);
	for(i=n-1; i>=0; i--){
		printf(",%03d", abs(stack[i]));
	}
	return 0;
}
