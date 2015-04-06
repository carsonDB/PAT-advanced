#include <stdio.h>
#include <string.h>

char N[2][11];
long long n = -1;

int parseChar(char ch){
	int num;
	if(ch >= '0' && ch <= '9')
		num = ch - '0';
	else if(ch >= 'a' && ch <= 'z'){
		num = ch - 'a' + 10;
	}	
	return num;
}

long long parseInt(char *s, long long radix){
	int i = 0;
	long long sum = 0;
	while(s[i] != '\0'){
		sum = sum * radix + parseChar(s[i]);
		if(sum > n && n != -1)
			return n + 1;
		i++;
	}
	return sum;
}

int binaryFind(char *s, long min, long long max){
	long long mid;
	long long m;
	while(min <= max){
		mid = (min + max) / 2;
		m = parseInt(s, mid);
		if(m < n)
			min = mid + 1;
		else if(m > n)
			max = mid - 1 ;
		else
			return mid;
	}
	return 0;
}

int isUnidigit(char *s){
	int i = 0;
	int digit = 0;
	while(s[i] == '0')
		i++;
	while(s[i] != '\0'){
		digit++;
		i++;
	}
	if(digit <= 1)
		return	parseChar(s[i-1]);
	else
		return -1;
}

int main(){
	int i, t, tag;
	long long radix, result = 0; 
	long long min_radix = 2, max_radix = 2;
	scanf("%s%s%d%d", N[0], N[1], &tag, &radix);
	tag--;
	n = parseInt(N[tag], radix);
	tag = (tag == 1) ? 0 : 1;
	//one digit only
	if((t = isUnidigit(N[tag])) != -1){
		t == n ? printf("%d", t+1) : printf("Impossible");
		return 0;
	}
	//multi-digit
	for(i=0; N[tag][i] != '\0'; i++){
		t = parseChar(N[tag][i]);
		if( t >= min_radix)
			min_radix = t + 1;
	}
	while(parseInt(N[tag], max_radix) < n)
		max_radix <<= 1;
	result = binaryFind(N[tag], min_radix, max_radix);
	result <= 0 ? printf("Impossible") : printf("%d", result);
	return 0;
}
