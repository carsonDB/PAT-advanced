#include <stdio.h>

struct sub{
	int sum, head, tail;
}max, now;

int main(){
	int i;
	int K, a[10000];

	scanf("%d", &K);
	for(i=0; i<K; i++){
		scanf("%d", &a[i]);
	}
	max.sum = now.sum = 0;
	max.head = 0;
	max.tail = K;
	now.head = now.tail = 0;
	for(i=0; i<K; i++){
		now.sum += a[i];
		now.tail++;
		if(now.sum >= max.sum){
			if(now.sum == 0 || now.sum > max.sum)
			max = now;
		}
		else if(now.sum < 0){
			now.sum = 0;
			now.head = now.tail;
		}
	}
	printf("%d %d %d", max.sum, a[max.head], a[max.tail-1]);
	return 0;
}
