#!/bin/bash
# $1 is cpp file being test
if [ $# -eq 0 ]
then
  echo "no input cpp (your cpp [correct cpp])"
  exit 0
fi

# generate correct answer
if [ $# -eq 2 ]
then
  g++ -g $2 > a.out
  ./a.out < input.txt > ans.txt
fi

g++ -g $1 > a.out
./a.out < input.txt > out.txt
diff out.txt ans.txt
