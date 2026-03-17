#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

// S:0 H:1 C:2 D:3
int main(void)
{
    int n;
    cin >> n;

    vector<vector<int>> data(4, vector<int>(13, 0));

    // input cards
    rep(i, n)
    {
        string egara;
        int num;
        cin >> egara >> num;
        if (egara == "S")
        {
            data.at(0).at(num - 1) = num;
        }
        else if (egara == "H")
        {
            data.at(1).at(num - 1) = num;
        }
        else if (egara == "C")
        {
            data.at(2).at(num - 1) = num;
        }
        else if (egara == "D")
        {
            data.at(3).at(num - 1) = num;
        }
    }

    // out
    // S{1,2,3...} H{1,2,3...} C{1,2,3...} D{1,2,3...}
    // search dropped cards
    rep(i, 4)
        rep(j, 13)
    {
        if (data.at(i).at(j) == 0)
        {
            if (i == 0)
            {
                cout << "S" << " " << j + 1 << endl;
            }

            if (i == 1)
            {
                cout << "H" << " " << j + 1 << endl;
            }

            if (i == 2)
            {
                cout << "C" << " " << j + 1 << endl;
            }

            if (i == 3)
            {
                cout << "D" << " " << j + 1 << endl;
            }
        }
    }
}

// バケット法（バケツ管理 / 出現頻度カウント）というらしい
// →バケツに印を入れるから

//   型定義は 型 変数名[i][j]

// 13*4の存在チェック表を作る
// vector<vector<bool>> has_card(4, vector<bool>(13, false))

// marks = "SHCD"
// cin >> s >> num;

// findで文字列から特定の文字を探す
// int mark_idx = marks.finds(s);

// has_card[mark_idx][num - 1] = true

// falseなら呼び出す

// mapで map<string, int> とするのも良さげ