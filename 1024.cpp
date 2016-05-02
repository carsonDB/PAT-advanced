/*
1. 注意N和K的大小。
注意到N最大可以到10位，unsigned int也许不够用了。long long保证可以。但是看到要做K次加法，
每次可以近似看成×2，所以会出现很大的数字。用vector来存储，名为Num。
2. 剩下的就很简单了，本题主要考察 回文数 和 大整数加法。
*/
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> Num;
int K;
string N;

bool isPal(Num& n)
{
  for (int i = 0; i < n.size()/2; i++)
    if (n[i] != n[n.size()-1-i])
      return false;
  return true;
}

Num add(Num& n1, Num& n2)
{
  int c = 0, len = n1.size();
  Num ans;
  for (int i = 0; i < len; i++)
  {
    ans.push_back((c + n1[i] + n2[i]) % 10);
    c = (c + n1[i] + n2[i]) / 10;
  }
  if (c != 0)
    ans.push_back(c);
  return ans;
}

int main()
{
  // input
  cin >> N >> K;
  Num n1, n2;
  for (int i = N.length()-1; i >= 0; i--)
    n1.push_back(N[i]-'0');
  // process
  int cnt;
  for (cnt = 0; cnt < K; cnt++)
  {
    if (isPal(n1))
      break;
    n2 = n1;
    reverse(n2.begin(), n2.end());
    n1 = add(n1, n2);
  }
  // output
  for (int i = n1.size()-1; i >= 0; i--)
    cout << n1[i];
  cout << endl;
  printf("%d\n", cnt);
  return 0;
}
