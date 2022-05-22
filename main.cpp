#include <vector>
#include <iostream>
#include <algorithm>
#include <list>


using namespace std;

int Solution(const int& N, const vector<int>& weights, const int& W, const vector<int>& values)
{
    int i, j;
    vector< vector <int> > list(N+1, vector<int>(W + 1));
    for (i = 0; i <= W; i++) 
    {
        list[0][i] = 0;
    }
    for (i = 1; i <= N; i++)
    {
        for (j = 0; j <= W; j++)
        {
            list[i][j] = list[i-1][j];
            if (j >= weights[i - 1])
            {
                list[i][j] = max(list[i][j], list[i-1][j - weights[i-1]]);
            }
        }
    }
    return list[N][W];
}

int main()
{
    int N, W;
    cin >> N >> W;
    vector<int> Values;
    vector<int> Weights;

    return 0;
}
