#include <iostream>
#include <vector>

using namespace std;

void solve(int numRows, vector<vector<int>> &res)
{
    vector<int> row{1};
    res.push_back(row);
    if (numRows == 1)
    {
        return;
    }

    for (int i = 1; i < numRows; i++)
    {
        vector<int> newRow{1};
        for (int j = 1; j < res.back().size(); j++)
        {
            newRow.push_back(res.back()[j - 1] + res.back()[j]);
        }
        newRow.push_back(1);
        res.push_back(newRow);
    }
}

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> res;
    solve(numRows, res);
    return res;
}

void print(const vector<vector<int>> &res)
{
    for (auto row : res)
    {
        for (auto col : row)
        {
            cout << col << '\t';
        }
        cout << '\n';
    }
}

int main()
{
    freopen("output.txt", "w", stdout);
    print(generate(5));
    return 0;
}
