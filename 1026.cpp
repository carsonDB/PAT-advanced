/*
还有一个测试点没过！！
process:
1. 从table中扫描一遍，然后取出最小time。
2. 从两队中arrival时间中取最小值
3. 从上述两个时间中取较大值为lim
4. 若lim之前，已有vip到达，先分配vip给vip桌
5. 若上面没有vip桌，则进行平常分配————按照先来先得分配
*/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct Node Node;
typedef struct Table Table;
struct Node {
  // arrive, begin, play tennis times
  int arr, begin, len;
  // 1 for VIP
  bool tag;
};
struct Table {
  int next, cnt;
  bool tag;
};

const int HEAD = 8 * 60 * 60;
const int TAIL = 21 * 60 * 60;
// troop1 -> ordinary players
vector<Node> tr1;
// troop2 -> vip players
vector<Node> tr2;
vector<Table> table;
int N, K, K_vip;

bool cmp1(Node a, Node b)
{
  return a.arr < b.arr;
}
bool cmp2(Node a, Node b)
{
  return (int)a.begin < (int)b.begin;
}

void pTime(int t)
{
  int hh, mm, ss;
  ss = t % 60;
  mm = (t / 60) % 60;
  hh = (t / 60) / 60;
  printf("%02d:%02d:%02d", hh, mm, ss);
}

// return first
int nextTime()
{
  int t = table[0].next;
  for (int i = 1; i < K; i++)
    t = min(t, table[i].next);
  // for (int i = 0; i < table.size(); i++)
  // {
  //   pTime(table[i].next);cout << " ";
  // }
  // cout << endl;
  return t;
}

// scan all table and process if any
void procOrd(int lim, Node& tnode)
{
  int i;
  for (i = 0; i < K && lim < table[i].next; i++);
  tnode.begin = lim;
  table[i].next = lim + tnode.len;
  table[i].cnt++;
}
// scan vip tables only and process if any
bool procVip(int lim, Node& tnode)
{
  int i;
  for (i = 0; i < K && (lim < table[i].next || table[i].tag == 0); i++);
  if (i == K)
    return false;
  tnode.begin = lim;
  table[i].next = lim + tnode.len;
  table[i].cnt++;
  return true;
}

int main()
{
  cin >> N;
  Node tnode;
  // put every pair of players into two troops respectively
  for (int i = 0, hh, mm, ss; i < N; i++)
  {
    scanf("%d:%d:%d ", &hh, &mm, &ss);
    tnode.arr = (hh * 60 + mm) * 60 + ss;
    cin >> tnode.len >> tnode.tag;
    tnode.len = tnode.len > 2*60*60 ? 2*60*60 : tnode.len * 60; // no more than 2 hours
    tnode.begin = TAIL;
    if (tnode.tag == 0)  tr1.push_back(tnode); // push into two troops respectively
    else  tr2.push_back(tnode);
  }
  // sort two troops
  sort(tr1.begin(), tr1.end(), cmp1);
  sort(tr2.begin(), tr2.end(), cmp1);
  // input table
  cin >> K >> K_vip;
  table.resize(K);
  // table init
  for (int i = 0; i < K; i++)
    table[i].next = HEAD;
  // input vip table
  for (int i = 0, t; i < K_vip; i++)
  {
    cin >> t;
    table[t-1].tag = true;
  }
  // process (i1 -> troop1, i2 -> troop2)
  // note: begin < TAIL(21:00:00)
  int i1, i2, lim;
  for (i1 = 0, i2 = 0; i1 < tr1.size() && i2 < tr2.size(); )
  {
    lim = max(nextTime(), min(tr1[i1].arr, tr2[i2].arr));
    if (lim >= TAIL) break;
    // cut in line no matter where is vip
    if (lim >= tr2[i2].arr && procVip(lim, tr2[i2]))
    {
      i2++;
      continue;
    }
    procOrd(lim, (tr1[i1].arr < tr2[i2].arr)? tr1[i1] : tr2[i2]);
    (tr1[i1].arr < tr2[i2].arr)? i1++ : i2++;
  }
  // troop1 remain
  for (int i = i1; i < tr1.size(); i++)
  {
    lim = max(nextTime(), tr1[i].arr);
    if (lim >= TAIL) break;
    procOrd(lim, tr1[i]);
  }
  // troop2 remain
  for (int i = i2; i < tr2.size(); i++)
  {
    lim = max(nextTime(), tr2[i].arr);
    if (lim >= TAIL) break;
    if (procVip(lim, tr2[i])) continue;
    procOrd(lim, tr2[i]);
  }
  // merge two troop
  tr1.insert(tr1.end(), tr2.begin(), tr2.end());
  sort(tr1.begin(), tr1.end(), cmp2);
  // output (filter pairs that are late than 21:00:00)
  for (int i = 0; i < N && tr1[i].begin < TAIL; i++)
  {
    pTime(tr1[i].arr);
    cout << " ";
    pTime(tr1[i].begin);
    cout << " " << round((tr1[i].begin - tr1[i].arr)/60.0) << endl;
  }
  // output count of every table served
  cout << table[0].cnt;
  for (int i = 1; i < K; i++)
    cout << " " << table[i].cnt;
  return 0;
}
