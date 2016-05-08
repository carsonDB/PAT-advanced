/*
思路：比较两个字符串大小，当一个字符串a是另一个b的前缀时，需要比较b的后缀与b的前缀，循环一直到找到不同的位
坑：输入可能全是0，所以只输出一个0。
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int N;

bool cmp(string a, string b)
{
  int i;
  for (i = 0; i < min(a.length(), b.length()); i++)
    if (a[i] != b[i])
      return a[i] < b[i];
  // pick the longer one
  string& s = a.length() < b.length() ? b : a;
  for (int j = 0; i < s.length(); i++, j++)
    if (s[i] != s[j])
      if (a == s) return a[i] < a[j];
      else return b[i] > b[j];
  // if a == b
  return true;
}

int main()
{
  // input
  cin >> N;
  vector<string> ls;
  string s;
  for (int i = 0; i < N; i++)
  {
    cin >> s;
    if (atoi(s.c_str()) == 0) continue;
    ls.push_back(s);
  }
  // sort
  sort(ls.begin(), ls.end(), cmp);
  // output
  if (ls.size() > 0)
    cout << atoi(ls[0].c_str()); // first number with no 0 at the front
  else
    cout << 0;
  for (int i = 1; i < ls.size(); i++)
    cout << ls[i];
  cout << endl;
  return 0;
}
