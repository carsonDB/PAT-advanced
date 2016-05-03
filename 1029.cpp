/*
注意：本题与上一题都尽量不要用cin和cout，会超时
思路：
  1. 先算出两行合并后，中位数的位置 = （N1+N2-1）/2
  2. i1和i2分别指向两行，哪一行的被指向的小，那个i++，然后知道i1+i2 == pos
  3. 此时两个指向的数中的较小者即为中位数。
  注意i1和i2中的某一个可能会越过边界。
*/
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

typedef long int N;
int N1, N2;
vector<N> ls1;
vector<N> ls2;

int main()
{
  // input first line
  cin >> N1;
  ls1.resize(N1);
  for (int i = 0; i < N1; i++)
    scanf("%ld", &ls1[i]);
  // input second line
  cin >> N2;
  ls2.resize(N2);
  for (int i = 0; i < N2; i++)
    scanf("%ld", &ls2[i]);
  // process
  int pos = (N1 + N2 - 1) / 2;
  int i1, i2;
  for (i1 = 0, i2 = 0; i1+i2 < pos && i1 < ls1.size() && i2 <ls2.size(); )
  {
    if (ls1[i1] < ls2[i2])
      i1++;
    else
      i2++;
  }
  for ( ; i1+i2 < pos && i1 < ls1.size(); i1++);
  for ( ; i1+i2 < pos && i2 < ls2.size(); i2++);
  // output
  if (i1 < ls1.size() && i2 <ls2.size())
    printf("%ld\n", min(ls1[i1], ls2[i2]));
  else if (i1 < ls1.size())
    printf("%ld\n", ls1[i1]);
  else
    printf("%ld\n", ls2[i2]);
  return 0;
}
