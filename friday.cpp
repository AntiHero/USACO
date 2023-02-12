/*
ID: cl34nc0d3r
LANG: C++
TASK: friday
*/
#include <fstream>

using namespace std;

int main()
{
  ifstream fin("friday.in");
  ofstream fout("friday.out");

  int week[7] = {0};
  /* Sat is new Mon
   *  [Mon, Tue, Wen, Th, Fr, Sat, Sun] >> 2
   *  [Sat, Sun, Mon, Tue, Wen, Th, Fr]
   */
  int day = 2;
  int n;

  fin >> n;

  for (int y = 1900; y < 1900 + n; y++)
  {
    for (int m = 0; m < 12; m++)
    {
      week[(day + 12) % 7]++;

      switch (m)
      {
      case 3:
      case 5:
      case 8:
      case 10:
        day += 30;
        break;
      case 1:
        day += 28 + (y % 4 == 0 && y % 100 || y % 400 == 0);
        break;
      default:
        day += 31;
        break;
      }
    }
  }

  int week_len = sizeof(week) / sizeof(week[0]);

  for (int i = 0; i < week_len; i++)
  {
    fout << week[i];

    if (i < week_len - 1)
      fout << ' ';
    else
      fout << endl;
  }
}