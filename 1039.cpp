/*
本题很简单，但是很卡时间。不用c++的string，只能用hash。
思路：http://zacharyjia.me/2016/02/23/PAT-1039/
*/
#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

// Col(collection)
typedef set<int> Col;

int N, K;
const int MAX = 26 * 26 * 26 * 10 + 1;
Col ls[MAX];

int s2i(char* s)
{
  int sum = s[3] - '0', fc = 10;
  for (int i = 2; i >= 0; i--, fc *= 26)
    sum += (s[i] - 'A') * fc;
  return sum;
}

int main()
{
  // input
  cin >> N >> K;
  char s[5];
  for (int i = 0, id, n; i < K; i++)
  {
    scanf("%d %d\n", &id, &n);
    for (int j = 0; j < n; j++)
    {
      scanf("%s", s);
      ls[s2i(s)].insert(id);
    }
    scanf("\n");
  }
  // input last line (query)
  for (int i = 0; i < N; i++)
  {
    scanf("%s", s);
    Col& col = ls[s2i(s)];
    printf("%s %d", s, (int)col.size());
    for (Col::iterator itr = col.begin(); itr != col.end(); itr++)
      printf(" %d", *itr);
    cout << endl;
  }
  return 0;
}
