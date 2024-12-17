/*
https://adventofcode.com/2023/day/2

HARDER THAN I THOUGHT!
WILL DO SOME TIME LATER!
*/

#include <bits/stdc++.h>
using namespace std;
#define print(iteration, variable) cout << #iteration << ": " << iteration << "\t|\t" << #variable << ": " << variable << endl
#define printf(variable) cout << #variable << ": " << variable << endl
#define MAX_red 12
#define MAX_green 13
#define MAX_blue 14

// vector<string> split(string game)
// {
//     vector<string> rounds = {};
//     for (int indexOfGameStr = 0; indexOfGameStr < game.size(); indexOfGameStr++)
//     {
//         if (game[indexOfGameStr]==';')
//         {
//             rounds.push_back(game.substr(indexOfGameStr));
//         }
//     }
// }

typedef struct Round
{
    int red{}, blue{}, green{};
} Round;

int main()
{
    string game = "Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green";
    ifstream file("input_day2.txt");
    // long long int sum = 0; //, c = 0;
    vector<int> possibleGames{};
    for (int gameNumber = 1; /* getline(file, game) && */ gameNumber <= 1; gameNumber++)
    {
        // to finish last round
        game.insert(game.end(), ';');

        int n = game.size();
        // remove "Game x:"
        for (int i = 0; i < n; i++)
        {
            if (game[i] == ':')
            {
                game.erase(game.begin(), game.begin() + i + 2);
                break;
            }
        }

        vector<pair<Round, int>> rounds;

        // print
        print(gameNumber, game);

        int numRounds = 0;
        n = game.size();
        for (int indexOfGameStr = 0; indexOfGameStr < game.size(); indexOfGameStr++)
        {
            if (game[indexOfGameStr] == ';')
            {
                Round r;
                r.red = 0;
                r.blue = 0;
                r.green = 0;

                string round = game.substr(0, indexOfGameStr);
                numRounds++;

                print(indexOfGameStr, game);  // print
                print(indexOfGameStr, round); // print

                // round individual in a game
                for (int z = 0; z < round.size(); z++)
                {
                    // c++;
                    // cout << "count:" << c << endl;
                    if (round.substr(z, 3) == "red")
                    {
                        int firstDigit = round[z - 3];
                        int lastDigit = round[z - 2];
                        if (isalnum(firstDigit) && isalnum(lastDigit))
                        {
                            r.red = 10 * (firstDigit - '0') + lastDigit - '0';
                        }
                        else if (isalnum(lastDigit))
                        {
                            r.red = lastDigit - '0';
                        }
                    }

                    if (round.substr(z, 4) == "blue")
                    {
                        int firstDigit = round[z - 3];
                        int lastDigit = round[z - 2];
                        if (isalnum(firstDigit) && isalnum(lastDigit))
                        {
                            int numberofBalls = 10 * (firstDigit - '0') + lastDigit - '0';
                            r.blue = numberofBalls;
                        }
                        else if (isalnum(lastDigit))
                        {
                            int numberofBalls = lastDigit - '0';
                            r.blue = numberofBalls;
                        }
                    }

                    if (round.substr(z, 5) == "green")
                    {
                        int firstDigit = round[z - 3];
                        int lastDigit = round[z - 2];
                        if (isalnum(firstDigit) && isalnum(lastDigit))
                        {
                            int numberofBalls = 10 * (firstDigit - '0') + lastDigit - '0';
                            r.green = numberofBalls;
                        }
                        else if (isalnum(lastDigit))
                        {
                            int numberofBalls = lastDigit - '0';
                            r.green = numberofBalls;
                        }
                    }
                }
                print(indexOfGameStr, r.red);
                print(indexOfGameStr, r.blue);
                print(indexOfGameStr, r.green);
                cout << "-------------------------\n";
                game.erase(game.begin(), game.begin() + indexOfGameStr + 1);

                print(indexOfGameStr, round);
                print(indexOfGameStr, game);
                cout << "\n+++++++++++++++++++++++++++++++++++++++\n\n";

                if (r.red <= MAX_red && r.blue <= MAX_blue && r.green <= MAX_green)
                {
                    cout << "pushed in vector<Round,int>:\n\n-----------------------------------------\n";
                    rounds.push_back({r, gameNumber});
                    // sum += gameNumber;
                    // print(gameNumber, sum);
                }
                indexOfGameStr = 0;
            }
            if (rounds.size() == numRounds && rounds.size() != 0)
            {

                cout << "pushed in possibleGames:\n\n-----------------------------------------\n";
                possibleGames.push_back(gameNumber);
                // print(indexOfGameStr, possibleGames.size());
                // sum += gameNumber;
            }
        }

        // for (int al = 0; al < rounds.size(); al++)
        // {
        //     sum += rounds[al].second;
        // }
        // print(gameNumber, sum);
    }
    long long int sum = 0;
    for (int indexOfGameStr = 0; indexOfGameStr < possibleGames.size(); indexOfGameStr++)
    {
        // print(indexOfGameStr, possibleGames[indexOfGameStr]);
        sum += possibleGames[indexOfGameStr];
    }
    cout << sum << endl;
    file.close();
    return 0;
}