#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef enum Req { L, G }Req;
typedef struct Node Node;
typedef vector<Node> Ls;
struct Node {
  string id;
  int score, all_R, loc_R, loc_N;
};

int N, K;
Ls ls;

// sort locally
bool cmp1(Node a, Node b)
{
  if (a.loc_N < b.loc_N)
    return true;
  else if (a.loc_N > b.loc_N)
    return false;
  else if (a.score == b.score)
    return a.id < b.id;
  else
    return a.score > b.score;
}
// sort globally
bool cmp2(Node a, Node b)
{
  if (a.score == b.score)
    return a.id < b.id;
  else
    return a.score > b.score;
}

void rankLs(Ls& lst, Req req)
{
  int order = 1, cnt = 0, score = -1, loc = lst[0].loc_N;
  for (int i = 0; i < lst.size(); i++, order++)
  {
    // reset order for local-sort
    if (req == L && lst[i].loc_N != loc)
      order = 1, cnt = 0, loc = lst[i].loc_N;
    // same rank with same score
    if (score == lst[i].score)
      order--, cnt++;
    else
      order += cnt, cnt = 0, score = lst[i].score;
    if (req == L) lst[i].loc_R = order;
    else lst[i].all_R = order;
  }
}

int main()
{
  // input
  cin >> N;
  Node t;
  for (int i = 0; i < N; i++)
  {
    cin >> K;
    for (int j = 0; j < K; j++)
    {
      cin >> t.id >> t.score;
      getchar();
      t.loc_N = i+1;
      ls.push_back(t);
    }
  }
  // sort locally
  sort(ls.begin(), ls.end(), cmp1);
  rankLs(ls, L);
  // sort globally
  sort(ls.begin(), ls.end(), cmp2);
  rankLs(ls, G);
  // output
  cout << ls.size() << endl;
  for (int i = 0; i < ls.size(); i++)
    printf("%s %d %d %d\n", ls[i].id.c_str(), ls[i].all_R, ls[i].loc_N, ls[i].loc_R);
  return 0;
}
