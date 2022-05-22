#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
#include <fstream>
#include <filesystem>

using namespace std;


int Solution(int N, vector<int> weights, int W, vector<int> values)
{
    vector<int> first(W+1, 0);
    vector<int> second(W+1, 0);
    int output = 0, i;
    
    for (i = 1; i <= N; i++) 
    {
        vector<int> tempo = first;
        first = second;
        second = tempo;
        for (int j = 0; j <= W; j++)
        {
            second[j] = first[j];
            if (j - weights[i - 1] >= 0) 
            {
                second[j] = max(second[j], first[j - weights[i - 1]] + values[i - 1]);
            }
        }
    }
    for (i = W; i >= 0; i--) 
    {
        if(second[i] != 0)
        {
            output = second[i];
            break;
        }
    }
    return output;
}
namespace fsm = std::filesystem;

int main() 
{
    string path = "/Users/Анна/Desktop/backpack";
    auto iterator = fsm::directory_iterator(path);
    vector<fsm::path> Array;
    copy_if(fsm::begin(iterator), fsm::end(iterator), std::back_inserter(Array), [](const auto& enter)
    {
        return fsm::is_regular_file(enter);
    });
    for (auto& s : Array)
    {
        ifstream fin;
        fin.open(s.string());
        cout << s.string() << endl;
        
        int N, W;
        fin >> N >> W;
        
        vector<int> Weights;
        vector<int> Values;
        
        for (int i = 0; i < N; i++)
        {
            int value, weight;
            fin >> value >> weight;
            Values.push_back(value);
            Weights.push_back(weight);
        }
        
        int Maxx = Solution(N, Weights, W, Values);
        cout << Maxx << endl;
    }
    return 0;
}
