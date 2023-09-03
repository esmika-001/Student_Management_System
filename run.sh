#!/bin/bash

echo "program is running"

gcc waiting.c -o prog1
gcc server.c -o prog2
./prog1 & ./prog2 &
wait
rm prog1 prog2

cat waiting_queue.txt
cat disk.txt

echo "End"


