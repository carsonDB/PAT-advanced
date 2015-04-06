#include <stdio.h>
#include <malloc.h>

typedef struct node{//a[0]->average  a[1]->c programme a[2]->mathematics a[3]->English
	int id, a[4], rank, flag;
}node;

int N, M;
node **lst;
char dict[] = { 'A', 'C', 'M', 'E' };

void bucketSort(int flag){
	int i, j;
	node *t;
	for(i=1; i<N; i++){
		t = lst[i];
		for(j=i-1; j >= 0 && t->a[flag] > lst[j]->a[flag]; j--)
			lst[j+1] = lst[j];
		lst[j+1] = t;
	}
	int rank = 1;
	int grade = lst[0]->a[flag];
	for(i=0; i<N; i++){
		if(lst[i]->a[flag] < grade){
			rank = i + 1;
			grade = lst[i]->a[flag];
		}
		if(lst[i]->rank > rank){
			lst[i]->rank = rank;
			lst[i]->flag = flag;
		}
	}
}

int main(){
	int i, j, *query;
	scanf("%d%d", &N, &M);
	lst = (node**)malloc(sizeof(node*) * N);
	query = (int*)malloc(sizeof(query) * M);
	for(i=0; i<N; i++){
		lst[i] = (node*)malloc(sizeof(node));
		scanf("%d%d%d%d", &lst[i]->id, &lst[i]->a[1], &lst[i]->a[2], &lst[i]->a[3]);
		lst[i]->a[0] = lst[i]->a[1] + lst[i]->a[2] + lst[i]->a[3];
		lst[i]->rank = N + 1;
	}
	for(i=0; i<4; i++)
		bucketSort(i);
	for(i=0; i<M; i++){
		scanf("%d", &query[i]);
	}
	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			if(lst[j]->id == query[i]){
				printf("%d %c\n", lst[j]->rank, dict[lst[j]->flag]);
				break;
			}
		}
		if(j == N)
			printf("N/A\n");
	}
	return 0;
} 
