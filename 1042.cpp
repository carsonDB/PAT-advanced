#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const char dict[] = {'S', 'H', 'C', 'D', 'J'};
int N;
vector<int> rls(54, 0);

void shuffle(vector<int>& ls1, vector<int>& ls2)
{
  for (int i = 0; i < 54; i++)
    ls2[rls[i]] = ls1[i];
}

void outPoker(int n)
{
  printf("%c%d", dict[n/13], n % 13 + 1);
}

int main()
{
  // input
  cin >> N;
  vector<int> ls(54, 0), tls(54, 0);
  for (int i = 0, t; i < 54; i++)
  {
    cin >> t;
    rls[i] = --t;
    ls[i] = i;
  }
  // repeat
  for (int i = 0; i < N; i++)
  {
    shuffle(ls, tls);
    ls = tls;
  }
  // output
  outPoker(ls[0]);
  for (int i = 1; i < 54; i++)
  {
    cout << " ";
    outPoker(ls[i]);
  }
  cout << endl;
  return 0;
}
