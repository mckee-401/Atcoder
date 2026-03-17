#!/bin/bash

cd ~/competitive/
if [ $# -eq 0 ]; then
    ./a.out < in.txt > out.txt
elif [ "$1" == "term" ]; then
    ./a.out < in.txt
else
    ./a.out < in.txt > "$1.txt"
fi

#io.shは、in.txtの内容を標準入力として受け取ってa.outを実行し、標準出力をout.txtに書き込みます(ファイル入出力)。
#また、引数としてファイル名を渡せば標準出力を[ファイル名].txtに書き込みます。
#termを引数にすると標準出力をターミナルに書き込みます(標準出力)。