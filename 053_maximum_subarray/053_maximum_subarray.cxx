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
#include <limits>
#include <vector>

using namespace std;

class Solution {
public:
    // Dynamic Programming Solution (Kadane's Algorithm)
    int maxSubArrayDP(vector<int>& nums) {
        int sum = 0;
        int max_sum = nums[0];

        for(size_t i = 0; i < nums.size(); ++i) {
            // If the sum becomes less than 0, reset the sum. In other words, when a 0 is reached,
            // it no longer makes sense to hold onto the previous sum. This is obvious in the case
            // where you add a bunch of positive numbers, then a bunch of negative numbers. If the
            // magnitude of the sum of the negative numbers equals that of the positive numbers
            // then start a new contiguous array. If all the numbers are negative, than the maximum
            // sum is simply the least large negative number.
            sum += nums[i];
            max_sum = max(max_sum, sum);
            sum = max(sum, 0);
        }

        return max_sum;
    }

    // Divide and Conquer Solution.
    int maxSubArrayDC(vector<int>& nums, size_t l, size_t r) {
        if(l == r){
            return nums[l];
        }
        else {
            // Calculate the mid-point.
            size_t m = (l + r)/2;

            // Find the maximum sum in the left and right sub-arrays respectively. Divide and conquer.
            int l_max = maxSubArrayDC(nums, l, m);
            int r_max = maxSubArrayDC(nums, m + 1, r);

            // Find the maximum sum across the two sub-arrays. That is to say, a contiguous sum that
            // starts somewhere in the left sub-array and ends in the right sub-array. Since that sum
            // does not necessarily begin at l, we must work backwards from m to l, and likewise from
            // m to r.
            int cl_max = numeric_limits<int>::min();
            int cr_max = numeric_limits<int>::min();

            int sum = 0;

            for(size_t i = m + 1; i-- > l;) {
                sum += nums[i];
                cl_max = max(cl_max, sum);
            }

            sum = 0;

            for(size_t i = m + 1; i <= r; ++i) {
                sum += nums[i];
                cr_max = max(cr_max, sum);
            }

            // Return the maximum sum either from the left, right, or across the sub-arrays.
            return max(max(l_max, r_max), cl_max + cr_max);
        }
    }

    int maxSubArray(vector<int>& nums) {
        if(nums.size() < 1) {
            return 0;
        }

        return maxSubArrayDC(nums, 0, nums.size() - 1);
    }

};
