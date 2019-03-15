# 350-assignment-3

This program automatically outputs the amounts of hits and misses for all 5 algorithms.
It does this for cache sizes 5-100, in increments of 5.
Before running the program, the user must decide on the workload they wish to test.
There are three types of workloads: No-Locality (noLocality), 80-20 (eightTwo), and Looping-Sequential (loopSeq).

In the main.cpp file, in the "Testing Section" on line 98, one must choose what workload they will be testing.
To do this:
  - uncomment the block of code marked with your chosen workload
  - comment out the block of code
  - change all occurences of unwanted workloads to the workload you desire to change. There should be comments above these occurences (there should be 14 such occurences)
 
Now all you have to do is type "make" in the terminal, and run "./main" !
