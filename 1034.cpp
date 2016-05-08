/*
常规题：思路见
http://www.sigmainfy.com/blog/pat-1034-head-of-a-gang.html
*/
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

typedef struct Node Node;
typedef struct Gang Gang;
struct Node {
  string name;
  map<int, int> rDict;
  bool visited;
  int sum;
  Node(string& s) :name(s), sum(0), visited(0) {};
};
struct Gang {
  int head, cnt;
  Gang(int head, int cnt) :head(head), cnt(cnt) {};
};

int N, K;
map<string, int> dict;
vector<Node> ls;

int s2id(string& s)
{
  if (dict.count(s))
    return dict[s];
  dict[s] = ls.size();
  ls.push_back(Node(s));
  return ls.size()-1;
}

bool isGang(int id, int& head, int& cnt)
{
  head = id, cnt = 0;
  int headW = ls[id].sum, allSum = 0;
  ls[id].visited = true;
  vector<int> stack;
  map<int, int>::iterator itr;
  stack.push_back(id);
  while (stack.size() > 0)
  {
    id = stack.back(); stack.pop_back();
    // visit one node
    cnt++; allSum += ls[id].sum;
    if (ls[id].sum > headW) // original one is not head
      head = id, headW = ls[id].sum;
    // add its edges into stack
    map<int, int>& tdict = ls[id].rDict;
    for (itr = tdict.begin(); itr != tdict.end(); itr++)
      if (ls[itr->first].visited == false)
      {
        ls[itr->first].visited = true;
        stack.push_back(itr->first);
      }
  }
  // attention: allSum = 2 * all_sum_weight_of_gang
  if (allSum > 2*K)
    return true;
  return false;
}

bool cmp(Gang a, Gang b)
{
  return ls[a.head].name < ls[b.head].name;
}

int main()
{
  // input
  cin >> N >> K;
  string s1, s2;
  for (int i = 0, w, i1, i2; i < N; i++)
  {
    cin >> s1 >> s2 >> w;
    getchar(); // eat '\n'
    i1 = s2id(s1); i2 = s2id(s2);
    if (ls[i1].rDict.count(i2))
      ls[i1].rDict[i2] += w;
    else
      ls[i1].rDict[i2] = w;
    if (ls[i2].rDict.count(i1))
      ls[i2].rDict[i1] += w;
    else
      ls[i2].rDict[i1] = w;
    ls[i1].sum += w;
    ls[i2].sum += w;
  }
  // process
  vector<Gang> ans;
  for (int i = 0, head, cnt; i < ls.size(); i++)
  {
    if (ls[i].visited) continue;
    if (isGang(i, head, cnt) && cnt > 2)
      ans.push_back(Gang(head, cnt));
  }
  // sort and output
  sort(ans.begin(), ans.end(), cmp);
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++)
    cout << ls[ans[i].head].name << " " << ans[i].cnt << endl;
  return 0;
}
