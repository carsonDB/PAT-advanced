/*
求最短路径的常规题。
与之前的类似题目比较，也许你会发现这次的代码风格改善很多:)
notes：
今天总结一下对int，bool等数组和STL中的vector等初始化的方式及如何方便初始化。
1. 首先是C风格的int等数组的声明不会初始化，所以数组中都是随机数！！！
2. c++风格的int等数组的声明也不会初始化！！！但是可以同时初始化：
  int* int_ls = new int[N]();
3. vector等STL声明时已经初始化。
4. 自己的结构体bool会被初始化，int可能不会。
！！！注意：即使你自己写测试检验上述问题，尽量都要手动初始化。
因为代码交上去后，可能会因为编译器版本不一等原因错误。
*/
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

const int INF = 1e8;
typedef struct Way Way;
typedef struct City City;
struct Way {
  int id, dist, cost;
  Way(int c, int dist, int cost) :id(c), dist(dist), cost(cost) {};
};
struct City {
  int dist, cost, prev;
  vector<Way> ls;
  City() :dist(INF), cost(INF) {};
};

int N, M, S, D;
bool* visited;
vector<City> city;

void affect(int id)
{
  vector<Way>& wLs = city[id].ls;
  for (int i = 0, idt; i < wLs.size(); i++)
  {
    idt = wLs[i].id;
    if (visited[idt]) continue;
    if (city[id].dist + wLs[i].dist < city[idt].dist
        || (city[id].dist + wLs[i].dist == city[idt].dist
            && city[id].cost + wLs[i].cost < city[idt].cost))
    {
      city[idt].prev = id;
      city[idt].dist = city[id].dist + wLs[i].dist;
      city[idt].cost = city[id].cost + wLs[i].cost;
    }
  }
}

int nextCity()
{
  int id = 0, dist = INF, cost = INF;
  for (int i = 0; i < N; i++)
  {
    if (visited[i]) continue;
    if (city[i].dist < dist || (city[i].dist == dist && city[i].cost < cost))
      id = i, dist = city[i].dist, cost = city[i].cost;
  }
  return id;
}

int main()
{
  // input
  cin >> N >> M >> S >> D;
  city.resize(N);
  for (int i = 0, c1, c2, dist, cost; i < M; i++)
  {
    cin >> c1 >> c2 >> dist >> cost;
    city[c1].ls.push_back(Way(c2, dist, cost));
    city[c2].ls.push_back(Way(c1, dist, cost));
  }
  // Dijkstra
  visited = new bool[N](); // auto set to 0
  city[S].dist = city[S].cost = 0;
  for (int i = 0, t; i < N; i++)
  {
    t = nextCity();
    visited[t] = true;
    affect(t);
  }
  // get the path
  vector<int> path;
  for (int id = D; id != S; id = city[id].prev)
    path.push_back(id);
  // output path
  printf("%d", S);
  for (int i = path.size()-1; i >= 0; i--)
    printf(" %d", path[i]);
  // output dist and cost
  printf(" %d %d\n", city[D].dist, city[D].cost);
  return 0;
}
