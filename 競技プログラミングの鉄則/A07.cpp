#include <iostream>
#define rep(i, n) for (int i = 1; i <= n; i++)
using namespace std;

// 配列は少し多めにとる
int D, N;
int L[100009], R[100009], B[100009], ans[100009];

int main(void)
{
    cin >> D;
    cin >> N;
    rep(i, N) cin >> L[i] >> R[i];

    B[0] = 0;
    rep(i, N)
    {
        B[L[i]] += 1;
        B[R[i] + 1] -= 1;
    }

    ans[0] = 0;
    rep(i, D)
    {
        ans[i] = ans[i - 1] + B[i];
    }

    rep(i, D) cout << ans[i] << endl;
    return 0;
}
