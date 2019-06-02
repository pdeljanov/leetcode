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

    int findMin(vector<int>& nums) {
        size_t l = 0;
        size_t r = nums.size() - 1;

        // Perform a binary search over the entire range of nums.
        //
        // For a given range, when split in two at a mid-point, one sub-range will be in ascending order,
        // and the other sub-range will be *appear* to be in descending order. If we follow the sub-range
        // that is sorted in descending order (the range where the minimum element is contained), and
        // continue the binary search, eventually we will converge on a single element (the minimum) or
        // where the binary search range will be in ascending order, in which case, the minimum element
        // is the first element in that range.
        while(l < r) {

            // The binary search range is in ascending order, there is no more searching to do.
            if(nums[l] < nums[r]) {
                break;
            }

            // Find the mid point.
            size_t m = (l + r)/2;

            // If the sub-range [l,m] is not in ascending order, use the sub-range for the next binary
            // search iteration.
            if(nums[m] < nums[l]) {
                r = m;
            }
            // Otherwise, use the sub-range [m+1,r] for the next binary search iteration. This also
            // covers the case where BOTH sub-ranges are sorted in ascending order. However, since the
            // list always has to be rotated to the right, the minimum will always be in the sub-range
            // to the right of the mid-point.
            else {
                l = m + 1;
            }
        }

        // Return the first element from the sub-range that was converged upon.
        return nums[l];
    }

};

