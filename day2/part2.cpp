// 3 Feb, 2024

#include <bits/stdc++.h>
using namespace std;

#define print(iteration, variable) cout << #iteration << ": " << iteration << "\t|\t" << #variable << ": " << variable << endl
#define printf(variable) cout << #variable << ": " << variable << endl
// #define FileInput 

struct Round
{
    int red{}, blue{}, green{};
};

vector<string> split(string game)
{
    vector<string> rounds{};
    int j = 0;
    for (int i = 0; i < game.size(); i++)
    {
        if (game[i] == ';')
        {
            rounds.push_back(game.substr(j, i - j));
            j = i + 2;
        }
    }
    return rounds;
}

int main()
{
    string game = "Game 2: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red";
    int gameNumber = 1;
    vector<long long int> power{};
#ifdef FileInput
    ifstream file("input_day2.txt");
    for (; getline(file, game); gameNumber++)
    {
#endif
        printf(gameNumber);
        // remove "Game x: "
        for (int i = 0; i < game.size(); i++)
        {
            if (game[i] == ':')
            {
                game.erase(game.begin(), game.begin() + i + 2);
                break;
            }
        }

        // insert ; at the end to finish round
        game.insert(game.end(), ';');

        // parse rounds
        vector<string> Rounds;
        Rounds = split(game);

        for (int i = 0; i < Rounds.size(); i++)
            print(i, Rounds[i]);

        vector<pair<int, Round>> rounds;
        int maxRed=0, maxBlue=0, maxGreen=0;
        for (int i = 0; i < Rounds.size(); i++)
        {
            Round r;

            // for creating round
            for (int indexRoundStr = 0; indexRoundStr < Rounds[i].size(); indexRoundStr++)
            {
            // _sleep(1.25);

                if (Rounds[i].substr(indexRoundStr, 3) == "red")
                {
                    char firstDigit = Rounds[i][indexRoundStr - 3];
                    char lastDigit = Rounds[i][indexRoundStr - 2];
                    if (isdigit(lastDigit))
                    {
                        if (isdigit(firstDigit))
                        {
                            r.red = 10 * (firstDigit - '0') + lastDigit - '0';
                        }
                        else
                            r.red = lastDigit - '0';
                    }
                }
                if (Rounds[i].substr(indexRoundStr, 4) == "blue")
                {
                    char firstDigit = Rounds[i][indexRoundStr - 3];
                    char lastDigit = Rounds[i][indexRoundStr - 2];
                    if (isdigit(lastDigit))
                    {
                        if (isdigit(firstDigit))
                        {
                            r.blue = 10 * (firstDigit - '0') + lastDigit - '0';
                        }
                        else
                            r.blue = lastDigit - '0';
                    }
                }
                if (Rounds[i].substr(indexRoundStr, 5) == "green")
                {
                    char firstDigit = Rounds[i][indexRoundStr - 3];
                    char lastDigit = Rounds[i][indexRoundStr - 2];
                    if (isdigit(lastDigit))
                    {
                        if (isdigit(firstDigit))
                        {
                            r.green = 10 * (firstDigit - '0') + lastDigit - '0';
                        }
                        else
                            r.green = lastDigit - '0';
                    }
                }
            }

            printf(r.red), printf(r.blue), printf(r.green);
            
            maxRed = max(maxRed,r.red), maxBlue = max(maxBlue,r.blue), maxGreen = max(maxGreen,r.green);

            printf(maxRed), printf(maxBlue), printf(maxGreen);
            cout << "-------------------------\n";
        }

        power.push_back(maxRed*maxBlue*maxGreen);

#ifdef FileInput
    }
#endif

    long long sum = 0;
    for (int i = 0; i < power.size(); i++)
    {
        _sleep(400);
        print(power[i], sum);
        sum += power[i];
    }
 
    cout << "\n\n-------------------------\n\n";
    printf(sum);
    cout << "\n\n-------------------------\n\n";
    
    return 0;
}