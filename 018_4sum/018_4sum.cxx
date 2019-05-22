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
#include <functional>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        vector<vector<int>> result;

        auto n = nums.size();

        // Trivial case, we need atleast 4 values.
        if(n < 4) {
            return result;
        }

        // Sort numbers in ascending order.
        sort(nums.begin(), nums.end(), less<int>());

        // Using four loops, find all possible unique quadruplets of values. Since the array is sorted in ascending
        // order, duplicate values are adjacent to each other. For each loop iteration of A, and B, skip duplicate
        // values. The technique for finding C and D is the same as in 3sum. Use the pointers to C and D to converge
        // on the target value. If C and D are not adjacent, advance c until c >= d while skipping duplicate values
        // of C.
        for(int a = 0; a < n - 3; ++a) {

            // Skip duplicate values of A.
            if(a > 0 && nums[a] == nums[a-1]) continue;

            // If the smallest possible sum given the current value of A is greater than the target,
            // give up.
            if(nums[a] + nums[a+1] + nums[a+2] + nums[a+3] > target) break;

            // If the largest possible sum given the current value of A is less than the target,
            // skip to the next value of A.
            if(nums[a] + nums[n-1] + nums[n-2] + nums[n-3] < target) continue;

            for(int b = a + 1; b < n - 2; ++b) {

                // Skip duplicate values of B.
                if(b > a + 1 && nums[b] == nums[b-1]) continue;

                // If the smallest possible sum given the current value of A and B, is greater than the target,
                // give up.
                if(nums[a] + nums[b] + nums[b+1] + nums[b+2] > target) break;

                // If the largest possible sum given the current value of A and B is less than the target,
                // skip to the next value of A.
                if(nums[a] + nums[b] + nums[n-1] + nums[n-2] < target) continue;

                // Cache the sum of A and B since it will be used a lot in the inner loops.
                int partial_sum = nums[a] + nums[b];

                int d = n - 1;

                // For each value of C, converge on the target value.
                for(int c = b + 1; c < d; ++c) {

                    // Skip duplicate values of C.
                    if(c > b + 1 && nums[c] == nums[c-1]) continue;

                    while(d > c) {
                        int sum = partial_sum + nums[c] + nums[d];

                        if(sum == target) {
                            result.push_back({ nums[a], nums[b], nums[c], nums[d] });
                            break;
                        }
                        else if(sum < target) {
                            ++c;
                        }
                        else if(sum > target) {
                            --d;
                        }
                    }
                }
            }
        }

        return result;
    }
};

