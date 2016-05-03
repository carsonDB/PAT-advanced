/*
option：
  输入的C可以投射到enum Way 枚举，使用的时候语义感觉更好。
1. cin与cout同时使用会超时，所以把cout改成printf。
2. 本题使用scanf和printf速度最快，但只能用数组存string，注意使用
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

typedef enum Way { ID = 1, NAME, GRADE, REST } Way;
typedef struct Node Node;
struct Node {
  int id, grade;
  string name;
};

int N, C;
Way way;

bool cmp(Node a, Node b)
{
  if (way == NAME && a.name != b.name)
    return a.name < b.name;
  else if (way == GRADE && a.grade != b.grade)
      return a.grade < b.grade;
  return a.id < b.id;
}

int main()
{
  // input
  cin >> N >> C;
  vector<Node> ls;
  ls.resize(N);
  for (int i = 0; i < N; i++)
    cin >> ls[i].id >> ls[i].name >> ls[i].grade;
  // sort
  way = static_cast<Way>(C);
  sort(ls.begin(), ls.end(), cmp);
  // output
  for (int i = 0; i < N; i++)
    printf("%06d %s %d\n", ls[i].id, ls[i].name.c_str(), ls[i].grade);
  return 0;
}
