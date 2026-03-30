#include <iostream>
#define rep(i, n) for (int i = 1; i <= n; i++)
using namespace std;

// 配列は少し多めにとる
int N, Q;
int A[100009], L[100009], R[100009], win[100009], lose[100009];

int main(void)
{
    cin >> N;
    rep(i, N) cin >> A[i];
    cin >> Q;
    rep(j, Q) cin >> L[j] >> R[j];

    win[0] = 0;
    lose[0] = 0;
    rep(i, N)
    {
        win[i] = win[i - 1];
        lose[i] = lose[i - 1];
        if (A[i] == 1)
        {
            win[i] = win[i - 1] + 1;
        }
        else if (A[i] == 0)
        {
            lose[i] = lose[i - 1] + 1;
        }
    }

    rep(j, Q)
    {
        int win_c = win[R[j]] - win[L[j] - 1];
        int lose_c = lose[R[j]] - lose[L[j] - 1];
        if (win_c > lose_c)
        {
            cout << "win" << endl;
        }
        else if (win_c == lose_c)
        {
            cout << "draw" << endl;
        }
        else
        {
            cout << "lose" << endl;
        }
    }

    return 0;
}
