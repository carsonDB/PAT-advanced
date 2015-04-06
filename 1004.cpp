#include <stdio.h>
#include <malloc.h>
#define MAX 102

typedef struct node{
	int num, *kids;
}Node;
typedef struct queue{
	int head, size, a[MAX];
}Q;

int N, M;
Q *q;
Node *list;

void Qinit(){
	q = (Q*)malloc(sizeof(Q));
	q->head = q->size = 0;
}
void Qadd(int id){
	q->a[q->head + q->size] = id;
	q->size++;
}
int Qremove(){
	int id = -1;
	if(q->size > 0){
		q->size--;
		id = q->a[q->head++];
	}
	return id;
}

void listInit(){
	int i, j, t;
	list = (Node*)malloc(sizeof(Node) * (N+1));
	for(i=1; i<=N; i++){
		list[i].num = 0;
		list[i].kids = NULL;
	}
	for(i=0; i<M; i++){
		scanf("%d", &t);
		scanf("%d", &list[t].num);
		list[t].kids = (int*)malloc(sizeof(int) * list[t].num);
		for(j=0; j<list[t].num; j++){
			scanf("%d", &list[t].kids[j]);
		}
	}
}

int main(){
	int i, j, flag = 0;
	int now, sumPer, numPer;
	scanf("%d%d", &N, &M);
	Qinit();
	listInit();

	Qadd(1);
	sumPer = 0;
	numPer = q->size;
	while(1){
		for(j=0; j<numPer; j++){
			now = Qremove();
			if(list[now].num == 0){
				sumPer++;
			}
			for(i=0; i<list[now].num; i++){
				Qadd(list[now].kids[i]);
			}
		}
		flag == 0 ? printf("%d", sumPer) : printf(" %d", sumPer);
		flag = 1;
		if(q->size == 0)
			break;
		numPer = q->size;
		sumPer = 0;
	}
	return 0;
}
