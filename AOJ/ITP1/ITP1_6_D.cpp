#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

int main(void)
{
    int n, m;
    cin >> n >> m;

    // n*m
    vector<vector<int>> A(n, vector<int>(m));
    vector<int> b(m);
    rep(i, n)
    {
        rep(j, m)
        {
            int v;
            cin >> v;
            A.at(i).at(j) = v;
        }
    }

    // 1*m
    rep(k, m)
    {
        int v;
        cin >> v;
        b.at(k) = v;
    }

    rep(i, n)
    {
        int out = 0;
        rep(j, m)
        {
            out += A.at(i).at(j) * b.at(j);
        }
        cout << out << endl;
    }
}

// そのまま解くだけ
// ベクトルの積が ai1b1+ai2b2+...+aimbm(111 122...)と掛けることだけ注意