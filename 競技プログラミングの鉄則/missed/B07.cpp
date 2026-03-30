#include <iostream>
#define rep(i, n) for (int i = 1; i <= n; i++)
using namespace std;

// 制限は毎回確認
int T, N;
int L[500009], R[500009], E[500009], ans[500009];

int main(void)
{
    cin >> T >> N;
    rep(i, N) cin >> L[i] >> R[i];

    for (int i = 0; i <= T; i++)
        E[i] = 0;

    rep(i, N)
    {
        E[L[i]] += 1;
        E[R[i]] -= 1;
    }

    ans[0] = E[0];
    for (int i = 1; i <= T; i++)
    {
        ans[i] = ans[i - 1] + E[i];
    }

    for (int i = 0; i < T; i++)
    {
        cout << ans[i] << endl;
    }
}
