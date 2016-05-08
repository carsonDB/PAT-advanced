/*
思路：将输入的两组数据，各分成正负两组，正正配对，负负配对。
贪心思想：门当户对，大乘大，小乘小。
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a, int b)
{
  if (a > 0) return a > b;
  return a < b;
}

int main()
{
  int NC, NP;
  // cp(coupon positive), cn(coupon negative)
  // pp(product positive), pn(product negative)
  cin >> NC;
  vector<int> cp, cn, pp, pn;
  for (int i = 0, t; i < NC; i++)
  {
    cin >> t;
    if (t > 0)
      cp.push_back(t);
    else if (t < 0)
      cn.push_back(t);
  }
  cin >> NP;
  for (int i = 0, t; i < NP; i++)
  {
    cin >> t;
    if (t > 0)
      pp.push_back(t);
    else if (t < 0)
      pn.push_back(t);
  }
  // sort
  sort(cp.begin(), cp.end(), cmp);
  sort(cn.begin(), cn.end(), cmp);
  sort(pp.begin(), pp.end(), cmp);
  sort(pn.begin(), pn.end(), cmp);
  // match
  int ans = 0;
  for (int i = 0; i < min(cp.size(), pp.size()); i++)
    ans += cp[i] * pp[i];
  for (int i = 0; i < min(cn.size(), pn.size()); i++)
    ans += cn[i] * pn[i];
  // output
  cout << ans << endl;
  return 0;
}
