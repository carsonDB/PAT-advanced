/*
  还有两个测试点没过！sigh！！！
*/
#include <iostream>
#include <vector>
#include <cstdlib>
#define Infinite 100000000
using namespace std;

int perfectNum;

class Road
{
public:
	int index, weight;
	Road(int i, int w)
	{
		weight = w;
		index = i;
	}
};

class Station
{
public:
	int index, num, prev, dist, adjust;
	bool visited;
	vector<Road> way;
	Station()
	{
		index = num = prev = dist = adjust = visited = 0;
	}
	Station(int i, int n)
	{
		index = i;
		num = n;
		dist = Infinite;
		adjust = Infinite;
		visited = false;
	}
	void affect(vector<Station*> list);
	void confirm();
};
void Station::affect(vector<Station*> list)
{
	Station* end;
	for (int i = 0; i < way.size(); i++){
		end = list[way[i].index];
		if (end->visited)
			continue;
		if (end->dist > dist + way[i].weight){
			end->dist = dist + way[i].weight;
			end->prev = index;
			end->adjust = adjust + end->num - perfectNum;
		}
		else if (end->dist == dist + way[i].weight && abs(end->adjust) > abs(adjust + end->num - perfectNum)){
			end->prev = index;
			end->adjust = adjust + end->num - perfectNum;
		}
	}
}

int chooseOne(vector<Station*> list)
{
	int dist = Infinite;
	int node = 0;
	for (int i = 1; i < list.size(); i++){
		if (list[i]->dist < dist && list[i]->visited == false){
			node = i;
			dist = list[node]->dist;
		}
	}
	return node;
}

int main()
{
	int Cmax; // 每站容量
	int N; // 站数
	int Sp; // 问题站号
	int M; // 马路数量
	// first line
	cin >> Cmax >> N >> Sp >> M;
	perfectNum = Cmax / 2;
	vector<Station*> list(N + 1);
	list[0] = new Station();
	// second line
	for (int i = 1, temp; i <= N; i++){
		cin >> temp;
		list[i] = new Station(i, temp);
	}
	// rest several lines
	for (int i = 0, v1, v2, weight; i < M; i++){
		cin >> v1 >> v2 >> weight;
		list[v1]->way.push_back(* new Road(v2, weight));
		list[v2]->way.push_back(* new Road(v1, weight));
	}
	int node = 0;
	while (1)
	{
		list[node]->visited = true;
		list[node]->affect(list);
		node = chooseOne(list);
		if (node == 0)
			break;
	}
	vector<int> output;
	node = Sp;
	while (node){
		output.push_back(node);
		node = list[node]->prev;
	}
	// send to
	if (list[Sp]->adjust < 0)
		cout << -list[Sp]->adjust << " ";
	else
		cout << 0 << " ";
	cout << 0;
	for (int i = output.size() - 1; i >= 0; i--){
		cout << "->" << output[i];
	}
	// take back
	if (list[Sp]->adjust >= 0)
		cout << " " << list[Sp]->adjust;
	else
		cout << " " << 0;
	return 0;
}
