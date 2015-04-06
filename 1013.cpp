#include <stdio.h>

typedef struct queue{
	int a[10000], head, size;
}Q;

int link[1000][1000];
int N, M, K;
int visited[1000];

Q q;
void Qadd(int city){
	q.a[q.head + q.size] = city;
	q.size++;
}
int Qremove(){
	if(q.size == 0)
		return -1;
	int t = q.a[q.head];
	q.head++;
	q.size--;
	return t;
}

void infect(int city){
	int now, i;
	visited[city] = 1;
	Qadd(city);
	while(1){
		now = Qremove();
		if(now == -1)
			break;
		for(i=0; i<N; i++){
			if(link[now][i] == 1 && visited[i] == 0){
				visited[i] = 1;
				Qadd(i);
			}
		}
	}
} 

int main(){
	int i, j, c1, c2, lost;
	int repair[1000];
	//initial
	q.head = q.size = 0;
	scanf("%d%d%d", &N, &M, &K);
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			link[i][j] = 0;
		}
	}
	for(i=0; i<M; i++){
		scanf("%d%d", &c1, &c2);
		if(c1 == c2)
			continue;
		c1--; c2--;
		link[c1][c2] = 1;
		link[c2][c1] = 1;
	}
	for(i=0; i<K; i++){
		for(j=0; j<N; j++)
			visited[j] = 0;
		scanf("%d", &lost);
		lost--;
		visited[lost] = 1;
		repair[i] = 0;
		for(j=0; j<N; j++){
			if(visited[j] == 0){
				repair[i]++;
				infect(j);
			}
		}
	} 
	for(i=0; i<K; i++)
		printf("%d\n", repair[i]-1);
	return 0;
} 
