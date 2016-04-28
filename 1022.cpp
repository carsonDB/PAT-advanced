/*
思路：
1. 建立map名为Index， 将内容作为key，id作为内容。
2. Index【0】为title，以此类推。
3. 根据request的序号，选择对应Index，将request的作为key找到包含id的set，输出自然具有顺序 
*/
#include <cstdio>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

typedef set<string> Res;
typedef map<string, Res> Index;

int N, M;
Index bLs[5];

void record(int i, string& s, string& id)
{
  if (bLs[i].count(s) <= 0)
    bLs[i][s] = *new Res;
  bLs[i][s].insert(id);
}

int main()
{
  // input
  stringstream ss;
  scanf("%d\n", &N);
  string id, s, kwd;
  for (int i = 0; i < N; i++)
  {
    getline(cin, id);
    for (int j = 0; j < 5; j++)
    {
      getline(cin, s);
      if (j == 2)
      {
        ss.clear(); ss.str(s);
        while (ss >> kwd)
          record(j, kwd, id);
      }
      else
        record(j, s, id);
    }
  }
  // input request and give response
  string req;
  scanf("%d\n", &M);
  for (int i = 0, t; i < M; i++)
  {
    getline(cin, s);
    cout << s << endl;
    t = s[0] - '1'; req = s.substr(3);
    if (t < 0 || t > 4 || bLs[t].count(req) == 0)
    {
      printf("Not Found\n");
      continue;
    }
    Res& res = bLs[t][req];
    for (Res::iterator itr = res.begin(); itr != res.end(); itr++)
      cout << *itr << endl;
  }
  return 0;
}
