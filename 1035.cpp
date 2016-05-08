/*
简单题：可以使用c中的两个array，或者使用这里的map来modify，更优雅一些。
*/
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
using namespace std;

typedef struct Node Node;
struct Node {
  string name, psw;
  Node(string s1, string s2) :name(s1), psw(s2) {};
};

int N;
vector<Node> ls;
map<char, char> dict;

bool checkPsw(string& s)
{
  bool modified = false;
  for (int i = 0; i < s.length(); i++)
    if (dict.count(s[i]) > 0)
    {
      s[i] = dict[s[i]];
      modified = true;
    }
  return modified;
}

int main()
{
  // init map
  dict['1'] = '@';
  dict['0'] = '%';
  dict['l'] = 'L';
  dict['O'] = 'o';
  // input
  cin >> N; getchar(); // eat '\n'
  string s1, s2;
  // input N lines and check every line
  for (int i = 0; i < N; i++)
  {
    cin >> s1 >> s2; getchar();
    if (checkPsw(s2))
      ls.push_back(Node(s1, s2));
  }
  // output
  if (ls.size() == 0)
  {
    if (N == 1)
      cout << "There is 1 account and no account is modified" << endl;
    else
      printf("There are %d accounts and no account is modified\n", N);
    return 0;
  }
    // ls.size() > 0
  cout << ls.size() << endl;
  for (int i = 0; i < ls.size(); i++)
    printf("%s %s\n", ls[i].name.c_str(), ls[i].psw.c_str());
  return 0;
}
