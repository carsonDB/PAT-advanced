//还有最后一个测试点，没有通过。。。

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <algorithm>
using namespace std;

typedef struct item{
	int time;
	bool status;
}item;

typedef struct person{
	int n, mon;
	item record[1000];
	char name[21];
}person;

int N;
int toll[24];
person **lst;

bool compare1(item a, item b){
	return a.time < b.time;
}
bool compare2(person *a, person *b){
	return strcmp(a->name, b->name) > 0 ? false : true; 
}

void insrt(char *name, int mon, int time, bool status){
	int i;
	person *p;
	for(i=0; lst[i] != NULL && strcmp(name, lst[i]->name) != 0; i++)
		;
	 if(lst[i] == NULL){
	 	p = (person*)malloc(sizeof(person));
	 	strcpy(p->name, name);
	 	p->n = 0;
	 	lst[i] = p;
	 }
 	p = lst[i];
 	p->mon = mon;
 	p->record[p->n].time = time;
 	p->record[p->n].status = status;
 	p->n++;
}

double settle(int gap){
	int cnt = 0;
	double cost = 0; 
	while(gap >= 60){
		cost += toll[cnt] * 60;
		cnt = (cnt + 1) % 24;
		gap -= 60;
	}
	cost += toll[cnt] * gap;
	return cost/100;
}

void putItem(person *p){
	int i;
	int time0, time1;
	double cost, all = 0;
	bool flag = false;
	item *t = p->record;
	for(i=0; i+1 < p->n; i++){
		if(p->record[i].status == false && p->record[i+1].status == true){
			flag = true;
			break;
		}
	}
	if(flag == false)
		return;
	printf("%s %02d\n", p->name, p->mon);
	for(i=0; i+1 < p->n; i++){
		if(p->record[i].status == false && p->record[i+1].status == true){
			time0 = t[i].time;
			time1 = t[i+1].time;
			cost = settle(time1) - settle(time0);
			all += cost;
			printf("%02d:%02d:%02d %02d:%02d:%02d %02d $%.2lf\n", time0/60/24, time0%(24*60)/60, time0%(24*60)%60, 
															      time1/60/24, time1%(24*60)/60, time1%(24*60)%60, time1-time0, cost);
		}
	}
	printf("Total amount: $%.2lf\n", all);
}

int main(){
	int i, mn, dd, hh, mi, time;
	char name[21], status[9];
	bool flag;
	item *t;
	for(i=0; i<24; i++){
		scanf("%d", toll + i);
	}
	scanf("%d", &N);
	lst = (person**)malloc(sizeof(person*) * N);
	for(i=0; i<N; i++){
		lst[i] = NULL;
	}
	for(i=0; i<N; i++){
		scanf("%s%d:%d:%d:%d%s", name, &mn, &dd, &hh, &mi, status);
		time = (dd * 24 + hh) * 60 + mi;
		if(strcmp(status, "on-line") == 0)
			flag = false;
		else if(strcmp(status, "off-line") == 0)
			flag = true;
		insrt(name, mn, time, flag);
	}
	for(i=0; lst[i] != NULL && i < N; i++){
		sort(lst[i]->record, lst[i]->record + lst[i]->n, compare1);
	}
	sort(lst, lst + i, compare2);
	for(i=0; lst[i] != NULL && i < N; i++){
		putItem(lst[i]);
	}
	return 0;
} 
