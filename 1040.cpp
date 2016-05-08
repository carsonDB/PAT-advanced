/*
思路：以字符串中每一个点为中心，向两侧延展。
注意：不仅每个字符可以是中心，而且字符间也可以是中心
*/
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

string s;

int palLen(int c)
{
  // center is between c-1, c
  int cnt1 = 0;
  for (int i = 1; c-i >= 0 && c+i-1 < s.length() && s[c-i] == s[c+i-1]; i++, cnt1 += 2);
  // center is c
  int cnt2 = 1;
  for (int i = 1; c-i >= 0 && c+i < s.length() && s[c-i] == s[c+i]; i++, cnt2 += 2);
  return max(cnt1, cnt2);
}

int main()
{
  // input
  getline(cin, s);
  // process
  int ans = 1;
  for (int i = 1; i < s.length(); i++)
  {
    ans = max(ans, palLen(i));
  }
  // output
  cout << ans << endl;
  return 0;
}
