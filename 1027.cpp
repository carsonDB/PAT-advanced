/*
将十进制转换成二进制
note：
  printf("%c", 'A' + ans[i] - 10);
  cout << 'A' + ans[i] - 10;
  上述两式区别在哪
*/
#include <iostream>
#include <cstdio>
using namespace std;

void output(int n)
{
  int ans[2];
  ans[0] = n/13, ans[1] = n%13;
  for (int i = 0; i < 2; i++)
  {
    if (ans[i] < 10)
      cout << ans[i];
    else
      printf("%c", 'A' + ans[i] - 10);
      // 14行改成右边，就会报错：cout << 'A' + ans[i] - 10;
  }
}

int main()
{
  cout << "#";
  for (int i = 0, t; i < 3; i++)
  {
    cin >> t;
    output(t);
  }
  cout << endl;
  return 0;
}
