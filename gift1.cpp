/*
ID: cl34nc0d3r
LANG: C++
TASK: gift1
*/
#include <string>
#include <vector>
#include <fstream>
#include <unordered_map>

using namespace std;

int main()
{
    ofstream fout("gift1.out");
    ifstream fin("gift1.in");

    unordered_map<string, int> givers;
    vector<string> giver_names;

    int num_of_givers;

    string recipient_name;
    string giver_name;
    string line;

    fin >> num_of_givers;

    int amount;
    int num_of_recipients;

    for (int i = 0; i < num_of_givers; i++)
    {
        fin >> giver_name;

        giver_names.push_back(giver_name);
        givers[giver_name] = 0;
    }

    while (true)
    {
        if (!(fin >> giver_name))
            break;

        fin >> amount >> num_of_recipients;

        if (amount == 0)
            continue;

        int rem = amount % num_of_recipients;
        int gift = amount / num_of_recipients;

        givers[giver_name] += rem - amount;

        for (int i = 0; i < num_of_recipients; i++)
        {
            fin >> recipient_name;

            givers[recipient_name] += gift;
        }
    }

    for (auto &name : giver_names)
    {
        fout << name << ' ' << givers[name] << endl;
    }

    return 0;
}
