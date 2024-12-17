#include <bits/stdc++.h>
using namespace std;
#define print(variable) cout << "\t|\t" << #variable << ": " << variable << endl
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
        cout << i++ << "\t|\t" << line << endl;
        int n = line.size();
        int firstDigit = 0, lastDigit = 0;
        for (int j = 0; j < n; j++)
        {
            if (isnum(line[j]))
            {
                firstDigit = line[j] - '0';
                break;
            }   
        }
        print(firstDigit);
        for (int j = 0; j < n; j++)
        {
            if (isnum(line[n-1-j]))
            {
                lastDigit = line[n-1-j] - '0';
                break;
            }
        }
        print(lastDigit);
        int number = 10 * firstDigit + lastDigit;
        print(number);
        sum += number;
        print(sum)<<endl;
    }
    cout << "---------------------------------------------\n" << endl << sum << endl;
    (file).close();
    return 0;
}