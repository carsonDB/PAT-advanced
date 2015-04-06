#include <stdio.h>
#include <malloc.h>

int main(){
	int i, sum = 0;
	int nStack, stack[1000];
	char ch;
	char *dict[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

	while((ch=getchar()) != '\n'){
		sum += ch - '0';
	}
	nStack = 0;
	while(sum/10 != 0){
		stack[nStack++] = sum % 10;
		sum /= 10;
	}
	printf("%s", dict[sum]);
	for(i=nStack-1; i>=0; i--){
		printf(" %s", dict[ stack[i] ]);
	}
	return 0;
}
