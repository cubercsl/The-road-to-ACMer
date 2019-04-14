#! /bin/bash
g++ C.cpp -o C
g++ D_gen.cpp -o D
./D >1.in
./C <1.in >1.out
python3 D_test.py <1.out