#include <stdio.h>

int main(){
	int i;
	int N, now = 0, next, sum = 0;
	scanf("%d", &N);
	for(i=0; i<N; i++){
		scanf("%d", &next);
		if(next >= now){
			sum += (next - now) * 6 + 5;
		}
		else if(next < now){
			sum += (now - next) * 4 + 5;
		}
		now = next;
	}
	printf("%d", sum);
}
