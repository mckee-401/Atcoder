// Official_House

#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
    // Your code here!
    // 1-10
    //*3
    //*4
    int n;
    int b, f, r, v;
    cin >> n;
    vector<vector<vector<int>>> data(4, vector<vector<int>>(3, vector<int>(10)));
    for (int i = 0; i < n; i++)
    {

        cin >> b >> f >> r >> v;
        data[b - 1][f - 1][r - 1] += v;
    }

    // 入居者数の出力
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 10; k++)
            {
                cout << " " << data[i][j][k];
            }
            cout << endl;
        }
        if (i < 3)
        {
            for (int l = 0; l < 20; l++)
            {
                cout << "#";
            }
            cout << endl;
        }
    }
}