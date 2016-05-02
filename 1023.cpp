/*
1. rcd(record)数组储存0~9共10位数字出现的次数。
2. add函数用于实现加法。
3. 注意string，char，int之间的转换。
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int rcd[10];

string add(string& s)
{
  int c = 0, d;
  string s2 = "";
  for (int i = s.length()-1; i >= 0; i--)
  {
    d = (c + 2*(s[i] - '0')) % 10;
    c = (c + 2*(s[i] - '0')) / 10;
    s2.push_back('0'+d);
  }
  if (c != 0)
    s2.push_back('0'+c);
  reverse(s2.begin(), s2.end());
  return s2;
}

int main()
{
  memset(rcd, 0, sizeof(rcd));
  string s;
  cin >> s;
  for (int i = 0; i < s.length(); i++)
  {
    rcd[s[i] - '0']++;
  }
  string s2 = add(s);
  for (int i = 0; i < s2.length(); i++)
  {
    rcd[s2[i] - '0']--;
  }
  int i;
  for (i = 0; i < 10 && rcd[i] == 0; i++)
    ;
  if (i == 10)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  cout << s2 << endl;
  return 0;
}
