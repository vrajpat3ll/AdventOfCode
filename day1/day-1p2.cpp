#include <bits/stdc++.h>
using namespace std;
#define print(variable) cout << "\t|\t" << #variable << ": " << variable << endl

string words[] = {"zero", "one",
                  "two", "three",
                  "four", "five",
                  "six", "seven",
                  "eight", "nine"};
int convert(string s)
{
    if(s == "zero") return 0;
    if(s == "one") return 1;
    if(s == "two") return 2;
    if(s == "three") return 3;
    if(s == "four") return 4;
    if(s == "five") return 5;
    if(s == "six") return 6;
    if(s == "seven") return 7;
    if(s == "eight") return 8;
    if(s == "nine") return 9;
    return 0;
}
pair<bool,int> isnum(string s)
{
    for (int i = 0; i < 10; i++)
        if (s == words[i])
            return {true,i};
    return {false,-1};
}
bool isnum(char c) { return c >= '0' && c <= '9'; }

int main()
{
    ifstream file;
    file.open("input_day1.txt");
    string line;

    int i = 1;
    long long int sum = 0;
    while (getline(file, line))
    {
        cout << i << "\t|\t" << line << endl;
        int n = line.size();
        i++;

        int firstDigit = 0, lastDigit = 0;

        for (int j = 0; j < n; j++)
        {

            if (isnum(line[j]))
            {
                firstDigit = line[j] - '0';
                break;
            }else
            {
                bool flag=0;
                for (int k = 0; k < n; k++)
                {
                    auto pi=isnum(line.substr(j, k));
                    if (pi.first)
                    {
                        firstDigit = convert(words[pi.second]);
                        flag = 1;
                        break;
                    }
                }
                if(flag==1)break;
            }
            
        }
        print(firstDigit);
        for (int j = 0; j < n; j++)
        {
            if (isnum(line[n-1-j]))
            {
                lastDigit = line[n-1-j] - '0';
                break;
            }else
            {
                bool flag=0;
                for (int k = 0; k < n; k++)
                {
                    auto pi=isnum(line.substr(n-1-j, k));
                    if (pi.first)
                    {
                        lastDigit = convert(words[pi.second]);
                        flag = 1;
                        break;
                    }
                }
                if(flag==1)break;
            }
        }
        print(lastDigit);
        int number = 10 * firstDigit + lastDigit;
        print(number);
        sum += number;
        print(sum)<<endl;
    }
    cout << "---------------------------------------------\n"
         << endl;
    cout << sum << endl;
    (file).close();
    return 0;
}
