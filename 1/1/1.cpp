#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string revers(string line)
{
    if (line.empty())
    {
        cout << "error";
        return 0;
    }
    else
    {
        string nline;
        for (int i = 1; i < line.length()+1; i++)
            nline = nline + line[line.length() - i];
        return nline;
    }
}

int main()
{
    ifstream input("input.txt");
    ofstream output("output.txt");

    if (!input)
    {
        cout << "error" << endl;
        return 0;
    }
    
    int d, m, y;
    string nd,nm,ny;
    char trash;

    input >> d;
    input >> trash;
    input >> m;
    input >> trash;
    input >> y;

    if (d == 9)
        output << d << "/" << m << "/" << y;

    if (d < 9)
    {
        int c = d + 1;
        while (d > 0)
        {
            string s1 = to_string(d % c);
            nd = nd + s1;
            d = d / c;
        }
        while (m > 0)
        {
            string s2 = to_string(m % c);
            nm = nm + s2;
            m = m / c;
        }
        while (y > 0)
        {
            string s3 = to_string(y % c);
            ny = ny + s3;
            y = y / c;
        }
        output << revers(nd) << "/" << revers(nm) << "/" << revers(ny) << endl;
    }
    
    if (d > 9)
    {
        int c = d + 1;
        while (d > 0)
        {
            nd = nd + char(d % c + 55);
            d = d / c;
        }

        while (m > 0)
        {
            if ((m % c) < 11)
            {
                string s2 = to_string(m % c);
                nm = nm + s2;
                d = m / c;
            }
            else
            {
                nm = nm + char(m % c + 55);
                m = m / c;
            }
        }
        while (y > 0)
        {
            if ((y % c) < 11)
            {
                string s3 = to_string(y % c);
                ny = ny + s3;
                y = y / c;
            }
            else
            {
                ny = ny + char(y % c + 55);
                y = y / c;
            }
        }
        output << revers(nd) << "/" << revers(nm) << "/" << revers(ny) << endl;
    }
    
    input.close();
    output.close();
}