#include <iostream>
#include <vector>
using namespace std;

int N, b;

bool isPal(vector<int>& ls)
{
  int n = ls.size();
  for (int i = 0; i < n/2; i++)
  {
    if (ls[i] != ls[n-i-1])
      return false;
  }
  return true;
}

int main()
{
  cin >> N >> b;
  vector<int> ls;
  if (N == 0)
  {
    cout << "Yes" << endl << 0;
    return 0;
  }
  while (N > 0)
  {
    ls.push_back(N % b);
    N /= b;
  }
  if (isPal(ls))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  cout << ls.back();
  for (int i = ls.size()-2; i >= 0; i--)
    cout << " " << ls[i];

  return 0;
}
