/*
将十进制转换成二进制
注意char和ascii编号的格式问题
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
      cout << (char)('A' - 10 + ans[i]); // 注意若不加char转换，会输出ascii编号
      // printf("%c", 'A' + ans[i] - 10); 这样也可以
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
