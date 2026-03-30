#include <iostream>
#define rep(i, n) for (int i = 1; i <= n; i++)
using namespace std;

int N, A[100009], S[100009];
int Q, L[100009], R[100009];

int main(void)
{
    cin >> N >> Q;
    rep(i, N) { cin >> A[i]; }
    rep(j, Q) { cin >> L[j] >> R[j]; }

    S[0] = 0;
    rep(i, N) { S[i] = S[i - 1] + A[i]; }
    rep(j, Q) { cout << S[R[j]] - S[L[j] - 1] << endl; }
}
