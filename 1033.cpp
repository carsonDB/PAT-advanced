/*
思路参考：http://www.sigmainfy.com/blog/pat-1033-to-fill-or-not-to-fill.html
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct Node Node;
struct Node {
  double p;
  int dist;
};

int Cmax, D, Davg, N;
vector<Node> ls;

bool cmp1(Node a, Node b)
{
  return a.dist < b.dist;
}
bool cmp2(Node a, Node b)
{
  return a.p < b.p;
}

int farthest(int id, int rest)
{
  int idt = id;
  while (idt < N && rest >= ls[idt].dist - ls[id].dist)
    idt++;
  return idt-1;
}

int main()
{
  // input
  cin >> Cmax >> D >> Davg >> N;
  int Max = Cmax * Davg;
  N++; // add destination to list
  ls.resize(N);
  for (int i = 0; i < N-1; i++)
    cin >> ls[i].p >> ls[i].dist;
  ls.back().p = 0, ls.back().dist = D;
  // process
  sort(ls.begin(), ls.end(), cmp1);
  // if first dist ！= 0, then max = 0;
  if (ls[0].dist != 0)
  {
    printf("The maximum travel distance = 0.00\n");
    return 0;
  }
  // id -> car at that station(haven't add any gas), rest -> largest distance can reach with remained oil
  // id1 -> farthest station can reach with remained oil, id2 -> farthest station can reach with full oil
  // sumC -> accumulative cost
  int id = 0, rest = 0, id1, id2, idt;
  double sumC = 0;
  while (ls[id].dist + rest < D)
  {
    // // debug
    // printf("%d\t\t%d\t\t%lf\t", id, rest, sumC);
    // get farthest station
    id1 = farthest(id, rest);
    id2 = farthest(id, Cmax * Davg);
    // find cheapest station (include current station) with remained oil
    idt = min_element(ls.begin()+id, ls.begin()+id1+1, cmp2) - ls.begin();
    if (idt != id) // find one (not current one)
    {
      rest -= ls[idt].dist - ls[id].dist;
      id = idt;
      continue;
    }
    // //debug
    // printf("%d %d %d\n", idt, id1, id2);
    // if add some oil at current station, can the car reach the first one that is cheaper than the current one
    for (idt = id+1; idt <= id2 && ls[idt].p >= ls[id].p; idt++);
    if (idt <= id2)
    {
      sumC += (ls[idt].dist - ls[id].dist - rest) * 1.0 / Davg * ls[id].p;
      id = idt, rest = 0;
      continue;
    }
    // just fill the tank up
    if (id == id2) // can't reach destination
    {
      rest = Cmax * Davg * 1.0;
      break;
    }
    idt = min_element(ls.begin()+id+1, ls.begin()+id2+1, cmp2) - ls.begin();
    sumC += (Cmax - rest * 1.0 / Davg) * ls[id].p;
    rest = Cmax * Davg - (ls[idt].dist - ls[id].dist);
    id = idt;
  }
  // // debug
  // printf("%d\t\t%d\t\t%lf\n", id, rest, sumC);
  // output
  if (ls[id].dist + rest < D)
    printf("The maximum travel distance = %.2lf\n", (double)ls[id].dist+rest);
  else
    printf("%.2lf\n", sumC);
  return 0;
}
