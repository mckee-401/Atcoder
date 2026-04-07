#include <iostream>
#define rep1(i, n) for (int i = 1; i <= n; i++)
#define rep0(i, n) for (int i = 0; i < n; i++)

using namespace std;

// 配列は少し多めにとる
int H, W, N;
int math[1509][1509], Z[1509][1509];
int A[100009], B[100009], C[100009], D[100009];

int main(void)
{
    /*
    一次元の累積和(いもす法)を2次元に拡張する
    一次元は、ある区間に対して、区間の開始位置に+1、終了位置の次に-1を加えることで、最終的に累積和を取ると各位置の値が求まるという方法
    二次元は横方向と縦方向の累積和を取る
    縦に累積和(コピー)すると最後の行まで同じ値が入るため、最後の行+1行目に-1を入れることで、最後の行は0になる
    */

    cin >> H >> W >> N;
    rep1(i, N) cin >> A[i] >> B[i] >> C[i] >> D[i];
    rep1(i, N)
    {
        math[A[i]][B[i]] += 1;
        math[A[i]][D[i] + 1] -= 1;
        math[C[i] + 1][D[i] + 1] += 1;
        math[C[i] + 1][B[i]] -= 1;
    }

    // 下準備は必須
    // 一つ前の要素を参照するため0~指定の幅まで用意する
    for (int i = 0; i <= H; i++)
        for (int j = 0; j <= W; j++)
            Z[i][j] = 0;

    // 累積和は指定の左隣の値+そのマスの値
    rep1(i, H) rep1(j, W) Z[i][j] = Z[i][j - 1] + math[i][j];

    // 縦も同義
    rep1(i, H) rep1(j, W) Z[i][j] = Z[i - 1][j] + Z[i][j];

    rep1(i, H)
    {
        rep1(j, W)
        {
            if (j >= 2)
                cout << " ";
            cout << Z[i][j];
        }
        cout << endl;
    }
}