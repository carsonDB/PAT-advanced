#include <stdio.h>
#include <string.h>

int M;

int main(){
	int i;
	char id[16], firstID[16], lastID[16];
	int firstTime, lastTime;
	int hh, mm, ss, time;

	firstTime = 24 * 60 * 60;
	lastTime = 0;
	scanf("%d", &M);
	for(i=0; i<M; i++){
		scanf("%s %d:%d:%d", id, &hh, &mm, &ss);
		time = hh*60*60 + mm*60 + ss;
		if(time < firstTime){
			firstTime = time;
			strcpy(firstID, id);
		}
		scanf("%d:%d:%d", &hh, &mm, &ss);
		time = hh*60*60 + mm*60 + ss;
		if(time > lastTime){
			lastTime = time;
			strcpy(lastID, id);
		}
	}
	printf("%s %s", firstID, lastID);
	return 0;
}
