// Copyright (c) 2018-2019 Philip Deljanov
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    // For any given number at a position in a permutation, when the lesser order number(s) following it
    // are sorted in descending order, then the number should be swapped with nums[nums.size() - j - 1],
    // and the lesser order number(s) reversed. Order is maintained during the swap and therefore when
    // the lesser order numbers(s) are reversed, they will be in ascending order.
    //
    // It's easiest to see the pattern with a simple example of [1,2,3].
    //
    //  [1 ,2*|3*] : initial sorted vector, pos=2
    //  [1*|3 ,2*] : swap 2<->3 => [1,2,3], reverse [2]   => [1,3,2], pos=1
    //  [2 ,1*|3*] : swap 1<->2 => [2,3,1], reverse [3,1] => [2,1,3], pos=0
    //  [2*|3*,1 ] : swap 1<->3 => [2,3,1], reverse [1]   => [2,3,1], pos=1
    //  [3 ,1*|2*] : swap 2<->3 => [3,2,1], reverse [2,1] => [3,1,2], pos=0
    //  [3 ,2 ,1 ] : swap 1<->2 => [3,2,1], reverse [1]   => [3,2,1], pos=1
    //
    //      * indicates numbers to be swapped.
    //      | indicates split between the currently considered number position (recursion level),
    //        and lower-order number(s).
    //
    // Basically, this algorithm paritions the numbers vector into three parts. A fixed partition above the
    // current position (P), the current position, and the positions below the current position. Initially,
    // since the vector is sorted in ascending order, then all three paritions are in ascending order.
    //
    // For a given P, the algorithm is recursively called until P=N-1 and all numbers in positions > P are sorted
    // in descending order. In the simplest case, this takes two numbers in ascending order and swaps them to
    // put them in descending order. In the case of two numbers, this is all that can be done and we don't recurse
    // any farther.
    //
    // However, in cases of N > 2, say N=3, once we put the last two numbers in descending order, we return to P=0.
    // With partition > P in descending order, the next permutation would require P to change. The number at P is
    // the smallest number for positions >= P. Therefore, swap the number at P with the next largest number from
    // positions > P. If P hasn't been changed since the start, then this is the last number, P=N-1, since numbers
    // at positions > P are sorted in descending order after recursion. More generally however, if P has been increased
    // M times, then we choose the M-th last number from partition > P. This maintains the ordering of partition > P.
    //
    // Lastly, the numbers at positions > P are reversed so that they are in ascending order, and recursion begins
    // again. For any given P, there will be N-P recursions, swaps, and reversal operations since at position P there
    // are N-P numbers left, and therefore the number at P can have any of those potential values.
    void permutate(vector<vector<int>>& ans, vector<int>& nums, size_t i) {

        // The number of numbers in a permutation result.
        size_t n = nums.size();

        // No more numbers left, append the current state of the numbers vector to the answer.
        if(i >= n) {
            ans.push_back(nums);
            return;
        }

        // The variable i indicates the current number position (level of recursion). The variable j is used to count
        // from i up-to the N as there are N-i-1 possible values for the current position. The variable k counts
        // backwards from N-1 and is the index of M-th largest number as per the explanation above.
        for(auto j = i, k = n - 1; j < n; ++j, --k) {
            // Permutate the next digit.
            permutate(ans, nums, i + 1);

            // Do not swap and reverse a digit with itself. While the swap is safe, the reverse operation is
            // detrimental because for any given number, the lesser order numbers should only be reversed when
            // the number itself actually changes.
            if(i < k) {
                swap(nums[i], nums[k]);
                reverse(nums.begin() + i + 1, nums.end());
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        permutate(ans, nums, 0);
        return ans;
    }
};
