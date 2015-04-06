#include <stdio.h>
#include <math.h>

int isPrime(int n){
	int i;
	if(n == 2 || n == 3)
		return 1;
	if(n == 1 || n % 2 == 0)
		return 0;
	for(i = 3; i < (int)sqrt(n) + 1; i += 2){
		if(n % i == 0)
			return 0;
	}
	return 1;
}

int reverse(int n, int radix){
	int m = 0;
	while(n / radix > 0){
		m = m * radix + n % radix;
		n /= radix;
	}
	m = m * radix + n;
	return m;
}

int main(){
	int n, radix;
	while(1){
		scanf("%d", &n);
		if(n < 0)
			break;
		scanf("%d", &radix);
		if(isPrime(n) == 1 && isPrime(reverse(n, radix)) == 1)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
} 
