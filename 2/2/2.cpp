#include <iostream>
#include <fstream>
#include <set>
#include <vector>

using namespace std;


double f(double x1, double y1, double x2, double y2) 
{
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

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
    input >> n;
    vector<int>arr(n*2);
    set<double>res;
    for (int i = 0; i < n * 2; i++)
        input >> arr[i];
 
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++)
        {
            int x1 = arr[i];
            int y1 = arr[i+1];
            int x2 = arr[j+1];
            int y2 = arr[j+2];

            res.insert(f(x1, y1, x2, y2));
        }
    }
    
    output << res.size() << endl;
    output.precision(20);
    for (auto i : res)
        output << fixed << i << endl;

    input.close();
    output.close();
}

