/*
简单题：联系map和vector。
因为结果输出第一个unique数，所以要用vector保存顺序。而map则是从数字到该数字出现的映射
*/
#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
using namespace std;

int N;
vector<int> ls;
map<int, int> dict;

int main()
{
  // input
  cin >> N;
  ls.resize(N);
  for (int i = 0; i < N; i++)
  {
    cin >> ls[i];
    dict[ls[i]]++;
  }
  // output
  for (int i = 0; i < N; i++)
  {
    if (dict[ls[i]] == 1)
    {
      cout << ls[i] << endl;
      return 0;
    }
  }
  cout << "None" << endl;
  return 0;
}
