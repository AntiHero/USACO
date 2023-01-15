/*
ID: cl34nc0d3r
LANG: C++
TASK: ride
*/
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ofstream fout("ride.out");
    ifstream fin("ride.in");

    const int magic = 47;

    int group_mod, comet_mod;

    string group_name = "";
    string comet_name = "";

    fin >> comet_name >> group_name;

    int group_mul = 1;
    int comet_mul = 1;

    for (auto c : group_name)
    {
        group_mul *= int(c) - int('A') + 1;
    }

    for (auto c : comet_name)
    {
        comet_mul *= int(c) - int('A') + 1;
    }

    group_mul % magic == comet_mul % magic ? fout << "GO" << endl : fout << "STAY" << endl;

    return 0;
}