/*
准备：
1. struct Man *M //所有的客户（含：到达时间arrival, 开始办理时间begin, 处理时间proc）
2. priority_queue *W //所有的窗口(优先队列，代表每个窗口接受下一个时间点)
3. 所有时间都以秒为单位
算法：
1. 提前剔除晚于17:00客户
1. 先将M数组排序，用sort内置函数。把客户按照到达时间arrival排序（使用cmp比较函数）
    默认窗口已从小到大排好
2. time作为时间点，每次选择（窗口空闲最早时间）和（下一个客户）的较大值，不停迭代
3，依次统计符合条件的客户的等待时间（begin-arrival），求出平均等待时间
*/
#include <iostream>
#include <cstdio>
#include <iomanip>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct man{
	int arrival, begin, proc;
}Man;

int N, K;
const int head = 8 * 60 * 60;
const int tail = 17 * 60 * 60;
priority_queue<int, vector<int>, greater<int> > W;
Man *M;

bool cmp(Man a, Man b){
	return a.arrival < b.arrival;
}

void filter(Man* m){
	int i;
	for (i = 0; i < N && m[i].arrival <= tail; i++);
	N = i;
}

int main(){
	cin >> N >> K;
	// init
	for (int i = 0; i < K; i++)
		W.push(head);
	M = new Man[N]();
	char ctemp;
	for (int i = 0, hh, mm, ss; i < N; i++){
		cin >> hh >> ctemp >> mm >> ctemp >> ss;
		M[i].arrival = (hh * 60 + mm) * 60 + ss;
		cin >> M[i].proc;
		M[i].proc = min(M[i].proc, 60) * 60;
	}
	sort(M, M + N, cmp);
	filter(M); // 剔除晚于17点的客户

	double sum = 0;
	for (int i = 0, time; i < N; i++){
		time = W.top(); W.pop();
		time = max(time, M[i].arrival); // time代表所有窗口中最早开始接受下一个的时间
		M[i].begin = time;
		W.push(time + M[i].proc);
		sum += M[i].begin - M[i].arrival;
	}
	if (N == 0)
		cout << 0.0 << endl;
	else
		printf("%.1lf\n", sum / N / 60);
	return 0;
}
