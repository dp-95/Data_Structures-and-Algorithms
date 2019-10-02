# @Author: _dp95
# @Date:   2019-10-02 01:15:03
# @Author: _dp95
# @Date:   2019-10-02 00:57:06
#!/bin/bash

mx=100

i=1

g++ -std=c++11 -O2 GEN.cpp -o gen
g++ -std=c++11 -O2 SOL.cpp -o sol
g++ -std=c++11 -O2 BRT.cpp -o brt

while [ $i -le $mx ]
do
  echo "#$i"
  ./gen > in
  ./sol < in > out1 
  ./brt < in > out2
  diff -w out1 out2 > temp || break
  i=$((i+1))
done

if [ $i != 1001 ]
then
  clear
  cat in
  echo -n "Origi = "
  cat out1
  echo ""
  echo -n "brute = "  
  cat out2
  echo ""
fi

rm gen
rm sol
rm brt
rm in
rm out2
rm out1
rm temp

if [ $i == 1001 ]
then
  clear
  echo "OK :)"
fi
