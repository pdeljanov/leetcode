# Notes on Algorithms and Data Structures

## Data Structures

### Array

* Can be used as a HashMap if the key values are constrained and small.
	- For example, counting the occurrences of printable ASCII characters in a string. 
	  
	  There are only 95 printable ASCII characters. For a printable ASCII character `c`, a key `k = c - 32` can be used to map a printable ASCII character to an array index. 
	  
	  Using an array `int hist[95]`, loop through the string character by character. For each character, `c`, increment the value by 1 at index `c - 32` in `hist`.

### HashMap

* Useful for general-purpose memoization (storing intermediate computations for re-use later).

* Can be used to build a histogram (counting the number of occurrences values appear in a set of data).
	- For example, given a list of integers, `L`, find the number of unique pairs of integers where `abs(i - j) = k`.
	
	  Build a histogram of all integers. The histogram will contain a bucket for each unique integer.
	  	- If `k == 0`, then only the integers that have a count of 2 or more can satisfy the constraint. So the result is the total number of buckets with a count of 2 or more.
	  	- If `k > 0`, then loop through each bucket. The key of each bucket is the integer `j`. Therefore, if the bucket for `j + k` has a count of atleast 1, then increment a counter since a pair has been found.

* Can be used to find pairs of values that satisfy some constraint by mapping a complementary value to an index.
  - For example, given a list of integers, `L`, find indicies `i` and `j`, such that `L[i] + L[j] == T`. 
	
	Loop through each integer in `L`, and on each iteration, use the current index `i`, to lookup a key `L[i]` in the HashMap. 

    - If the key does not exist, insert a key `T - L[i]` with value `i` into the HashMap.

	- If the key exists, the integer `T - L[i]` can be found at index `j` which has been stored in the value of the key-value pair.


## Algorithms

### Dynamic Programming (DP)

* Dynamic programming is when you use an initial previously calculated set of values to calculate a new set of values, overwriting the previous set with the new set.
	- Dynamic programming should not be confused with memoization. In memoization you generally do not delete past computations.

* Applicable when you do not need values beyond the previous set of values.
	* For example, counting unique paths where you can only advance forward in each dimension.
		* Number of ways to climb up a ladder where you can skip a number of rungs each step.
		* Number of ways to traverse a grid from the top-left to bottom-right where you can only ever move down or right each step.

### Graphs

* Useful for path-finding (DFS or Dijkstra) where movement is unconstrained (can move any direction).

