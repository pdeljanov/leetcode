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

#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        // Empty case.
        if(nums.size() == 0) {
            return -1;
        }

        size_t l = 0;
        size_t r = nums.size() - 1;

        while(l < r) {
            size_t m = (l + r) / 2;

            // If the sub-range [l, m] is in ascending order, and the target value is contained within
            // that sub-range, then perform the next binary search iteration on the range [l, m]. If the
            // target is not contained in the sub-range [l, m], then the target must be in the sub-range
            // [m+1, r].
            //
            // This also covers the case where both the [l, m] and [m+1, r] sub-ranges are in ascending
            // order, but the logic applies in the same way in that case.
            //
            // If the sub-range [l, m] is not in ascending order, then the value might be contained in
            // the sub-range if and only if it is not contained in the [m+1, r] sub-range.
            if(nums[l] < nums[m]) {
                if(nums[l] <= target && target <= nums[m]) {
                    r = m;
                }
                else {
                    l = m + 1;
                }
            }
            // If the sub-range [l, m] was not in ascending order, then the sub-range [m+1, r] must be in
            // ascending order. If the target value is contained within the [m+1, r] sub-range, then perform
            // the next binary search iteration on the range [m+1, r]. If the target value is not within the
            // [m+1, r] sub-range, then it must be within the [l, m] sub-range.
            else {
                if(nums[m+1] <= target && target <= nums[r]) {
                    l = m + 1;
                }
                else {
                    r = m;
                }
            }
        }

        // Check if the value converned upon is the target. If it is correct, then return the index, otherwise
        // return -1.
        return nums[l] == target ? l : -1;
    }
};
