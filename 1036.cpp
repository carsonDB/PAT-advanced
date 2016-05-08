#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main()
{
  int N;
  cin >> N;
  // every one
  string name, gender, id;
  int grade;
  // record two
  string sf, sm, idf, idm;
  int gf = -1, gm = 101; // ponder why I prefer these initial numbers
  for (int i = 0; i < N; i++)
  {
    cin >> name >> gender >> id >> grade;
    getchar();
    if (gender == "F" && grade > gf)
      sf = name, idf = id, gf = grade;
    else if (gender == "M" && grade < gm)
      sm = name, idm = id, gm = grade;
  }
  // output
  if (gf >= 0)
    printf("%s %s\n", sf.c_str(), idf.c_str());
  else
    cout << "Absent\n";
  if (gm <= 100)
    printf("%s %s\n", sm.c_str(), idm.c_str());
  else
    cout << "Absent\n";
  if (gf >= 0 && gm <= 100)
    cout << gf - gm << endl;
  else
    cout << "NA" << endl;
  return 0;
}
