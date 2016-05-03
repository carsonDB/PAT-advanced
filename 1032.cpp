/*
此题是利用map的典型例题。
1. 将地址接受为int，而不是string可以加快速度。
2. 先沿着word1的走一边，将经过的节点的visited设为true
3. 再沿着word2开始走，一遇到有节点visited == true，则为suffix的第一个节点
*/
#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

typedef struct Node Node;
struct Node {
  char data;
  int next;
  bool visited;
};

int d1, d2, N;
map<int, Node> dict;

int main()
{
  // input into a map
  cin >> d1 >> d2 >> N;
  Node tnode;
  for (int i = 0, addr, next; i < N; i++)
  {
    scanf("%d %c %d\n", &addr, &tnode.data, &tnode.next);
    dict[addr] = tnode;
  }
  // process one word
  for (int i = d1; i != -1; i = dict[i].next)
    dict[i].visited = true;
  // process another one and find out the intersection
  int i;
  for (i = d2; i != -1 && !dict[i].visited; i = dict[i].next);
  // output the position of two words intersection
  if (i != -1)
    printf("%05d\n", i);
  else
    printf("-1\n");
  return 0;
}
