#!/bin/bash

# ソースファイルの決定
SOURCE_FILE="${1:-main}.cpp"

# ファイルが存在するかチェック（これがないとgrepがエラーを吐きます）
if [ ! -f "$SOURCE_FILE" ]; then
    echo "Error: $SOURCE_FILE not found."
    exit 1
fi

# カウント処理
ATCODER_COUNT=$(grep -o "atcoder" "$SOURCE_FILE" | wc -l)
GMP_COUNT=$(grep -o "gmpxx.h" "$SOURCE_FILE" | wc -l)

# 基本フラグ
CXX_FLAGS="-std=gnu++23 -O2 -Wall -Wextra"
LINK_FLAGS=""

# デバッグモード（アドレスサニタイザ等）
if [ "$2" == "debug" ]; then
    CXX_FLAGS+=" -g -fsanitize=address -fsanitize=undefined"
fi

# ライブラリ判定
if [ "$ATCODER_COUNT" -ge 1 ]; then
    # カレントディレクトリの ac-library を参照
    CXX_FLAGS+=" -I./ac-library"
fi

if [ "$GMP_COUNT" -ge 1 ]; then
    LINK_FLAGS+=" -lgmpxx -lgmp"
fi

# コンパイル実行（-o a.out を追加）
echo "Compiling $SOURCE_FILE with C++23..."
g++ $CXX_FLAGS "$SOURCE_FILE" -o a.out $LINK_FLAGS

# 成功したらメッセージを出す
if [ $? -eq 0 ]; then
    echo "Build Successful: ./a.out"
fi