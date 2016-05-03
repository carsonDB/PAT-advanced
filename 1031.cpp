#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main()
{
  string s;
  cin >> s;
  // m = n1 = n3, n = n2
  int m = (s.length() + 2) / 3;
  int n = s.length() + 2 - 2 * m;
  // output
  for (int i = 0; i < m-1; i++)
  {
    cout << s[i];
    for (int j = 0; j < n-2; j++)
      cout << " ";
    cout << s[s.length()-i-1] << endl;
  }
  // output last line
  for (int i = m-1; i < m-1+n; i++)
    cout << s[i];
  cout << endl;
  return 0;
}
