# quicksort
A project for a Data Structures and Algorithms class in which I implemented
quicksort. The program uses Lomuto style partitioning by default but I also 
implemented Hoare partitioning for extra credit, which can be used by running
with "-h".

Sorts integers of up to nine digits long. Prints output with leading zeros.

test.txt contains 1000 randomly generated strings containing integers,
and can be used as a test input.

hoare.txt and writeup.txt summarize my testing process and reasons for certain
choices I made within my implementation, including my chosen constant for calling
median of three (to mitigate worst-case ordering of data) before performing the sort.

For this assignment I recieved full credit and 20% extra credit for implementing Hoare
partitioning and completing the additional writeup (hoare.txt).
