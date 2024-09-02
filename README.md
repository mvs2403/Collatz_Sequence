# Collatz Sequence
## Problem description
Write two programs that find the starting number below a given limit that has the longest Collatz sequence. The program should be called with a single number as the command line parameter. This number is the upper limit below which the longest chain should be found. Note that intermediate steps may go above this upper limit. Program one will optimise for code simplicity and low memory usage. Program two sacrifices some simplicity and memory for a significant reduction in CPU time required.

## Collatz sequence definition
The following iterative sequence is defined for the set of positive integers: 
```
n → n/2 (n is even)
n → 3n + 1 (n is odd)
```
Using the rule above and starting with 13, we generate the following sequence:
```
13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
```
It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1

---

Here are examples of the commands I used to compile and run the program 

Compile:
```
g++ -std=c++14 -o collatz_caching Collatz_Caching.cpp
```

Run: (Upper limit = 101010)
```
/usr/bin/time -al ./collatz_caching 101010
```

OR
```
/usr/bin/time -al ./collatz_caching
```

This one will ask you then to enter the value and then use that value

