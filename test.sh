#!/bin/bash
g++ main.cpp -o main
#./main

echo "3" "APPOINT 1 12:30 30 2 andrey alex" "APPOINT 1 12:00 30 2 alex sergey" "APPOINT 1 12:59 60 2 alex andrey" | ./main