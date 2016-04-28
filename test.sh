#!/bin/bash
# $1 is cpp file being test
if [ -z "$1" ]
then
  echo "no input cpp"
  exit 0
fi
g++ -g $1 > a.out
./a.out < input.txt > out1.txt
g++ -g sample.cpp > a.out
./a.out < input.txt > out2.txt
diff out1.txt out2.txt
