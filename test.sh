#!/bin/bash
# no input c++ file
if [[ $# = 0 ]]; then
  echo "no input cpp (your cpp [correct cpp])"
  exit 0
fi

# init (by default)
out_file="./a.out"
in_txt="./input.txt"
out_txt="./out.txt"
help_msg="help with options"

# one argument
if [[ $# = 1 ]]; then
  if [[ $1 = "-h" ]]; then
    echo $help_msg
    exit 0
  else
    in_cpp=$1
  fi
fi

# two argument
if [ $# = 2 ]; then
  in_cpp=$1
  g++ -g $2 > a.out
  ./a.out < input.txt > ans.txt
fi

# compile
g++ -g $in_cpp > $out_file
./$out_file < input.txt > out.txt
diff out.txt ans.txt
