#include <bits/stdc++.h>
using namespace std;

#define print(iteration, variable) cout << #iteration << ": " << iteration << "\t|\t" << #variable << ": " << variable << endl
#define printf(variable) cout << #variable << ": " << variable << endl

// #define FileInput

vector<string> split(string s, char c)
{
    vector<string> rounds{};
    int j = 0, n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == c)
        {
            rounds.push_back(s.substr(j, i - j));
            j = i + 2;
        }
    }
    return rounds;
}

vector<pair<int, int>>
    dirs = {
        make_pair(1, 0),
        make_pair(1, 1),
        make_pair(0, 1),
        make_pair(-1, 1),
        make_pair(-1, 0),
        make_pair(-1, -1),
        make_pair(0, -1),
        make_pair(1, -1)};

int main(int agc, char *argv[])
{
    ifstream file("input.txt");
    string s;

#ifdef FileInput
    ifstream file("input_day2.txt");
    for (int line = 0; getline(file, s); line++)
    {
#endif

#ifdef FileInput
    }
#endif
}