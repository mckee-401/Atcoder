#include <iostream>
#define rep1(i, n) for (int i = 1; i <= n; i++)
#define rep0(i, n) for (int i = 0; i < n; i++)

using namespace std;

// 配列は少し多めにとる
int N, Q;
int X[100009], Y[100009];
int S[1509][1509], T[1509][1509];
int A[100009], B[100009], C[100009], D[100009];

int main(void)
{
    cin >> N;
    rep1(i, N) cin >> X[i] >> Y[i];

    cin >> Q;
    rep1(i, Q) cin >> A[i] >> B[i] >> C[i] >> D[i];

    // 座標に点がいくつ入っているかを示す二次元配列を作成
    rep1(i, N) S[X[i]][Y[i]] += 1;

    // 入る点の数に限らず1500*1500が必要なので1500*1500回す

    // 累積和用の配列準備
    rep0(i, 1505) rep0(j, 1505) T[i][j] = 0;

    // 横方向の累積和を取る
    rep1(i, 1505) rep1(j, 1505) T[i][j] = T[i][j - 1] + S[i][j];

    // 縦方向の累積和を取る
    rep1(i, 1505) rep1(j, 1505) T[i][j] = T[i - 1][j] + T[i][j];

    // 累積和から回答を求める
    rep1(i, Q) cout << (T[C[i]][D[i]] + T[A[i] - 1][B[i] - 1]) - (T[A[i] - 1][D[i]] + T[C[i]][B[i] - 1]) << endl;

    return 0;
}