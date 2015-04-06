#include <stdio.h>

#define Max 2001

int main(){
	int i, j;
	double a[Max], b[Max], coff;
	int expo, n, cnt = 0;

	for(i=0; i<Max; i++){
		a[i] = b[i] = 0;
	}
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%d%lf", &expo, &coff);
		a[expo] += coff;
	}
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%d%lf", &expo, &coff);
		for(j=0; j<Max; j++){
			if(a[j] != 0){
				b[j+expo] += a[j] * coff;
			}
		}
	}
	for(i=0; i<Max; i++){
		if(b[i] != 0){
			cnt++;
		}
	}
	printf("%d", cnt);
	for(i=Max-1; i>=0; i--){
		if(b[i] != 0)
			printf(" %d %.1lf", i, b[i]);
	}
}
