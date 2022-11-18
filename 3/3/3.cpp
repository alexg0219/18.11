#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    ifstream input("input.txt");
    ofstream output("output.txt");

    if (!input)
    {
        cout << "error";
        return 0;
    }

    int n;
    string s;
    input >> n;

    for (int i = 0; i < n; i++)
    {
        input >> s;
        if (count(s.begin(), s.end(), '0') == count(s.begin(), s.end(), '1') && count(s.begin(), s.end(), '0') == count(s.begin(), s.end(), '2'))
        {
            int f = 0;
            int c = count(s.begin(), s.end(), '0');
            for (int i = 1; i < c + 1; i++)
            {
                if (s[c - i] == '0' && s[c - 1 + i] == '1' && s[2 * c - 1 + i] == '2')
                    f++;
                else
                    break;
            }
            if (f == c)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        else
            cout << "NO" << endl;
    }

    input.close();
    output.close();
}


