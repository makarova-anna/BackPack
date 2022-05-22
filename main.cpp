#include <vector>
#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

// функция для решения задачи
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
            list[i][j] = list[i - 1][j];
            if (j >= weights[i - 1])
            {
                list[i][j] = max(list[i][j], list[i-1][j - weights[i - 1]] + values[i - 1]);
            }
        }
    }
    return list[N][W];
}

class thing
{
    public:
        int v, w, n;
        thing(int x, int y, int z) : v(x), w(y), n(z) {}
};

int main()
{
    int N, W, i;
    cin >> N >> W;
    
    vector<int> Weights;
    vector<int> Values;
   
    for (i = 0; i < N; i++)
    {
        int value, weight;
        cin >> value >> weight;
        Values.push_back(value);
        Weights.push_back(weight);
    }
    int Maxx = Solution(N, Weights, W, Values);
    cout << Maxx << endl;
    return 0;
}
