// 3 Feb, 2024

#include <bits/stdc++.h>
using namespace std;

#define print(iteration, variable) cout << #iteration << ": " << iteration << "\t|\t" << #variable << ": " << variable << endl
#define printf(variable) cout << #variable << ": " << variable << endl
#define MAX_red 12
#define MAX_green 13
#define MAX_blue 14

#define FileInput 1

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
        if(game[i]==';')
        {
            rounds.push_back(game.substr(j,i-j));
            j=i+2;
        }
    }
    return rounds;
}

int main()
{
    string game = "Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green";
    vector<int> possibleGames{};
    int gameNumber = 1;

#if FileInput
    ifstream file("input_day2.txt");
    for (; getline(file, game); gameNumber++)
    {
#endif
        // remove "Game x: "
        for (int i = 0; i < game.size(); i++)
        {
            if (game[i]==':')
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
            print(i,Rounds[i]);
        
        vector<pair<int,Round>> rounds;
        
        for (int i = 0; i < Rounds.size(); i++)
        {
            Round r;

            // for creating round
            for (int indexRoundStr = 0; indexRoundStr < Rounds[i].size(); indexRoundStr++)
            {
                if(Rounds[i].substr(indexRoundStr,3)=="red")
                {
                    char firstDigit = Rounds[i][indexRoundStr-3];
                    char lastDigit = Rounds[i][indexRoundStr-2];
                    if (isdigit(lastDigit))
                    {
                        if(isdigit(firstDigit))
                        {
                            r.red = 10 * (firstDigit-'0')+lastDigit-'0';
                        }
                        else r.red = lastDigit-'0';
                    }
                }
                if(Rounds[i].substr(indexRoundStr,4)=="blue")
                {
                    char firstDigit = Rounds[i][indexRoundStr-3];
                    char lastDigit = Rounds[i][indexRoundStr-2];
                    if (isdigit(lastDigit))
                    {
                        if(isdigit(firstDigit))
                        {
                            r.blue = 10 * (firstDigit-'0')+lastDigit-'0';
                        }
                        else r.blue = lastDigit-'0';
                    }
                }
                if(Rounds[i].substr(indexRoundStr,5)=="green")
                {
                    char firstDigit = Rounds[i][indexRoundStr-3];
                    char lastDigit = Rounds[i][indexRoundStr-2];
                    if (isdigit(lastDigit))
                    {
                        if(isdigit(firstDigit))
                        {
                            r.green = 10 * (firstDigit-'0')+lastDigit-'0';
                        }
                        else r.green = lastDigit-'0';
                    }
                }
            }
            
            printf(r.red);
            printf(r.blue);
            printf(r.green);
            
            cout << "1-------------------------\n";

            if (r.red <= MAX_red && r.blue <= MAX_blue && r.green <= MAX_green)
            {
                    cout << "pushed in vector<int, Round>:\n\n2-----------------------------------------\n";
                    rounds.push_back({gameNumber,r});
            }
        }
        if(Rounds.size() == rounds.size())
        {
            possibleGames.push_back(gameNumber);
        }

#if FileInput
    }
#endif

    long long sum = 0;
    for (int i = 0; i < possibleGames.size(); i++)
    {
        print(possibleGames[i], sum);
        sum+=possibleGames[i];
    }
    
    cout << "\n\n-------------------------\n\n";
    printf(sum);
    cout << "\n\n-------------------------\n\n";
    return 0;
}