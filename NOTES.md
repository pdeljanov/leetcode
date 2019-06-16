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

Dynamic Programming is a family of techniques whereby the algorithm uses data calculated in previous steps to calculate the current step or solution.

#### Memoization

Memoization is a Dynamic Programming technique where the algorithm, given some state, calculates a result and stores it. If that state is encountered again, the stored result is used instead of calculating it again.

*Note: Memoization IS Dynamic Programming, but Dynamic Programming IS NOT just memoization.*

A common example is a recursive algorithm that calculates a result by traversing elements in depth-first order. Once the result of a sub-tree is calculated, it needn't be calculated it again. By associating the algorithm's state (the parameters of the recursive function) to the calculated result, whenever that state is encountered again, the algorithm can lookup the result in the memo, thus reducing redundant work.

Visualizing recursive functions is difficult so it may not be obvious when sub-trees are visited more than once. Therefore, it is easier just consider the parameters of the recursive function itself. If the underlying data is *immutable*, and the recursive function parameters are the same, then result MUST also be the same. However, if the underlying data is *mutable*, then the memo must also be parameterized by the value of the element as well.

*Note: Any algorithm, iterative or recursive, where the complete state can be parameterized can use memoization. However, it is only useful if the state occurs multiple times.*

The memory complexity of memoization is dependant on the number of unique states. For example, if the recursive function above is parameterized by two values, A and B, then the *worst-case* memory usage is O(A*B).

The computational complexity of memoized problems is dependent on the original algorithm's complexity, and the number of unique states.

#### Forward-Only Problems

Some problems never look beyond one or two previous states to calculate a new state. Using memoization in this case would waste too much memory.

Examples of these problems include:

* Counting unique paths where you can only advance forward in each dimension.
	* Number of ways to climb up a ladder where you can skip a number of rungs each step.
	* Number of ways to traverse a grid from the top-left to bottom-right where you can only ever move down or right each step.

 Generally, for these problems the *worst-case* memory usage will either be O(1) or O(N+1).
 
 The computational complexity of these problems are generally O(N) in the 1D case, O(N\*M) in the 2D case, O(N\*M\*P) in the 3D case, and so on.

### Graphs

* Useful for path-finding (DFS or Dijkstra) where movement is unconstrained (can move any direction).

