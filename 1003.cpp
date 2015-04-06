#include <stdio.h>
#include <stdlib.h>

#define MAX 10000

typedef struct node{
	int city, len;
	struct node *next;
}node;

int city, road;
int *res;
node **ros;
int *dist, *cnt, *coll, *certain;

void addLine(int order, node *end){
	if(ros[order] == NULL){
		ros[order] = end;
		return;
	}
	node *t;
	t = ros[order];
	while(t->next != NULL){
		t = t->next;
	}
	t->next = end;
}

int getNear(){
	int i;
	int tempD = MAX, tempC = -1;
	for(i=0; i<city; i++){
		if(certain[i] == 0 && dist[i] < tempD){
			tempD = dist[i];
			tempC = i;
		}
	}
	return tempC;
}

void affect(int center){
	node *temp = ros[center];
	while(temp != NULL){
		if(certain[temp->city] == 0){
			if(dist[center]+temp->len == dist[temp->city]){
				cnt[temp->city] += cnt[center];
				if(coll[center]+res[temp->city] > coll[temp->city]){
					coll[temp->city] = coll[center]+res[temp->city];
				}
			}
			else if(dist[center]+temp->len < dist[temp->city]){
				dist[temp->city] = dist[center]+temp->len;
				coll[temp->city] = coll[center]+res[temp->city];
				cnt[temp->city] = cnt[center];
			}
		}
		temp = temp->next;
	}
}

int main(){
	int start, end;
	int i, tempS;
	node *t1, *t2;

	scanf("%d%d%d%d", &city, &road, &start, &end);
	res = (int*)malloc(sizeof(int) * city);
	ros = (node**)malloc(sizeof(node*) * city);
	dist = (int*)malloc(sizeof(int) * city);
	cnt = (int*)malloc(sizeof(int) * city);
	coll = (int*)malloc(sizeof(int) * city);
	certain = (int*)malloc(sizeof(int) * city);

	for(i=0; i<city; i++){
		scanf("%d", &res[i]);
		ros[i] = NULL;
		dist[i] = MAX;
		cnt[i] = 1;
		coll[i] = res[i];
		certain[i] = 0;
	}
	for(i=0; i<road; i++){
		t1 = (node*)malloc(sizeof(node));
		t1->next = NULL;
		scanf("%d%d%d", &tempS, &t1->city, &t1->len);
		addLine(tempS, t1);
		t2 = (node*)malloc(sizeof(node));
		t2->next = NULL;
		t2->city = tempS;
		t2->len = t1->len;
		addLine(t1->city, t2);
	}
	certain[start] = 1;
	dist[start] = 0;
	affect(start);
	int now;
	while(1){
		if( (now = getNear()) == -1)
			break;
		certain[now] = 1;
		affect(now);
	}
	printf("%d %d", cnt[end], coll[end]);
	return 0;
}
