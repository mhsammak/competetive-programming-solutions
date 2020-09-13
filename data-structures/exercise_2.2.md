## Exercise 2.2.1

### 1
Sort the array in O(nlogn) time and traverse the array starting from
position 1 to the end. If the element in the position is equal to its
previous position add 1 to result. Overall complexity is O(nlogn).

### 2
Sort the array in O(nlogn) time. Set two pointers, one at the begining,
and other at the end. If the sum of the two pointers are greater than
the target sum, decrease right pointer by 1. If smaller, increase left
pointer by 1. If their sum is equal to the target sum, return them. Also,
you can loop until they both meet at some point to find all the pairs. 
Total running time is O(nlogn).

### 3
If the given array is already sorted, total running time will be O(n) if
we follow the same alogrithm.

### 4
