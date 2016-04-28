/*
思路：
1. 每次以一个节点为根BFS算出深度。然后，在bfs的同时，visited是记录本次搜寻过的点，而
G[i].visited则是全局记录扫描过得点。因此，可以算出有几个孤立的部分。
2. 若partNum多于1， 则说明不是连通图，报错。否则，找出深度最大的几个点。
记录本次的
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct Node Node;
struct Node {
  vector<int> ls;
  bool visited;
};
int N;
Node* G;
int calDep(int id, bool* visited)
{
  int tId, depth = 0, len;
  queue<int> ls;
  ls.push(id);
  while (ls.size() > 0)
  {
    depth++;
    len = ls.size();
    for (int i = 0; i < len; i++)
    {
      tId = ls.front(); ls.pop();
      if (visited[tId]) continue;
      visited[tId] = G[tId].visited = true;
      for (int j = 0, ttId; j < G[tId].ls.size(); j++)
      {
        ttId = G[tId].ls[j];
        if (visited[ttId]) continue;
        ls.push(ttId);
      }
    }
  }
  return depth;
}

int main()
{
  cin >> N;
  G = new Node[N];
  // input edges
  for (int i = 0, t1, t2; i < N-1; i++)
  {
    cin >> t1 >> t2;
    G[t1-1].ls.push_back(t2-1);
    G[t2-1].ls.push_back(t1-1);
  }
  // calculate depths and components
  int partNum = 0, deepMax = 0;
  vector<int> rLs;
  bool* visited = new bool[N];
  for (int i = 0, t; i < N; i++)
  {
    if (G[i].visited == false)
      partNum++;
    memset(visited, 0, sizeof(*visited)*N);
    t = calDep(i, visited);
    if (t > deepMax)
    {
      rLs.resize(1);
      rLs[0] = i; deepMax = t;
    }
    else if (t == deepMax)
      rLs.push_back(i);
  }
  // more than one components
  if (partNum > 1)
  {
    printf("Error: %d components\n", partNum);
    return 0;
  }
  // output deepest roots
  for (int i = 0; i < rLs.size(); i++)
    cout << rLs[i]+1 << endl;
  return 0;
}
