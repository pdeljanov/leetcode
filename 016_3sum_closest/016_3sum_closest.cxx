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
    int threeSumClosest(vector<int>& nums, int target) {

        // There needs to be atleast 3 numbers to do anything.
        if(nums.size() < 3) {
            return 0;
        }

        // Sort the numbers in ascending order.
        sort(nums.begin(), nums.end(), less<int>());

        // Calculate the initial closets sum, the first three numbers.
        int closest = nums[0] + nums[1] + nums[2];

        int n = nums.size();

        for(int a = 0; a < n-2; ++a) {
            // Skip duplicates of A.
            if(a > 0 && nums[a] == nums[a-1]) continue;

            // Given value A, calculate the smallest and largest possible sums.
            int smallest = nums[a] + nums[a+1] + nums[a+2];
            int largest = nums[a] + nums[n-1] + nums[n-2];

            // If given the value A, and the closest sum is less than the target value, if our largest
            // possible sum is less than the closest sum, there is nothing more to do. Likewise, if the
            // closest sum is greater than the target, if our smallest possible sum is greater than the
            // closest, there is nothing more to do.
            if(closest < target && largest < closest) break;
            if(closest > target && smallest > closest) break;

            // Iterate the remainder of the numbers array from both ends to try and converge on the
            // target, recording the closest sum found so far. If the target is actually found, return
            // immediately since that's the best solution.
            int b = a+1;
            int c = n-1;

            while(b < c) {
                int sum = nums[a] + nums[b] + nums[c];

                if(sum == target) {
                    return sum;
                }
                else if(sum > target) {
                    --c;
                }
                else if(sum < target) {
                    ++b;
                }

                if(abs(target - closest) > abs(target - sum)) {
                    closest = sum;
                }
            }
        }

        return closest;
    }
};
