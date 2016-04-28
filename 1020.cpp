// 最后一个点没过
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int>::iterator Itr;
typedef struct Node Node;
struct Node
{
  int data, level;
  Node(int a, int b): data(a), level(b) {};
};

int N;
vector<Node> ls;
vector<int> postLs, inLs;

void make(Itr p1, Itr p2, Itr i1, Itr i2, int level)
{
  if (p1 == p2)
    return;
  int root = *(p2-1);
  ls.push_back(*new Node(root, level));
  Itr p = find(i1, i2, root);
  int pos = p - i1;
  level++;
  make(p1, p1+pos, i1, i1+pos, level);
  make(p1+pos, p2-1, i1+1+pos, i2, level);
}

bool cmp(Node& a, Node& b)
{
  return a.level < b.level;
}

int main()
{
  cin >> N;
  postLs.resize(N), inLs.resize(N);
  for (int i = 0; i < N; i++)
    cin >> postLs[i];
  for (int i = 0; i < N; i++)
    cin >> inLs[i];
  make(postLs.begin(), postLs.end(), inLs.begin(), inLs.end(), 1);
  sort(ls.begin(), ls.end(), cmp);
  cout << ls[0].data;
  for (int i = 1; i < ls.size(); i++)
    printf(" %d", ls[i].data);
  printf("\n");
  return 0;
}
