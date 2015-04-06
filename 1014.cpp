#include <stdio.h>
#include <malloc.h>

#define Max 20
#define Mass 2000 

typedef struct queue{
	int a[Max], head, size;
}Queue;

int N, M, K, Q;
int query[Mass];
int order = 0;
int now = 8 * 60, end = 17 * 60;
int proc[Mass];
int finish[Mass];

Queue *que;
void Qadd(Queue *q, int index){
	q->a[(q->head + q->size) % Max] = index;
	q->size++;
}
int Qremove(Queue *q){
	if(q->size == 0)
		return -1;
	int t = q->a[q->head];
	q->head = (q->head + 1) % Max;
	q->size--;
	return t;
}

void cover(){
	int i;
	int line, num;
	while(1){
		line = 0;
		num = que[0].size;
		for(i=1; i<N; i++){
			if(que[i].size < num){
				line = i;
				num = que[i].size;
			}
		}
		if(num >= M)
			break;
		else{
			Qadd(que + line, order++);
			if(order >= K)
				return;
		}
	}
}

int process(){
	int i, t;
	int line = -1;
	int time = 0;
	for(i=0; i<N; i++){
		t = que[i].a[que[i].head];
		if(que[i].size > 0 && (line == -1 || time > proc[t])){
			line = i;
			time = proc[t];
		}
	}
	now += time;
	for(i=0; i<N; i++){
		if(que[i].size > 0){
			t = que[i].a[que[i].head];
			proc[t] -= time;
			finish[t] = now;
			if(proc[que[i].a[que[i].head]] == 0){
				t = Qremove(que + i);
			}
		}
	}
	if(line == -1)
		return -1;
	return 1;
}

void clear(){
	int i, t;
	for(i=0; i<N; i++){
		if(que[i].size > 0){
			t = que[i].a[que[i].head];
			if(finish[t] > 0){
				finish[t] = now + proc[t];
			}
		}
	}
}

int main(){
	int i, t;
	scanf("%d%d%d%d", &N, &M, &K, &Q);
	que = (Queue*)malloc(sizeof(Queue) * N);
	for(i=0; i<N; i++){
		que[i].head = que[i].size = 0;
	}
	for(i=0; i<K; i++){
		scanf("%d", proc + i);
		finish[i] = -1;
	}
	cover();
	for(i=0; i<N; i++){
		t = que[i].a[que[i].head];
		finish[i] = now;
	}
	while(now < end){
		if(process() == -1)
			break;
		if(order < K)
			cover();
	}
	clear();
	for(i=0; i<Q; i++){
		scanf("%d", query + i);
	}
	for(i=0; i<Q; i++){
		t = --query[i];
		if(finish[t] == -1)
			printf("Sorry\n");
		else{
			printf("%02d:%02d\n", finish[t] / 60, finish[t] % 60);
		}
	}
	return 0;
}
