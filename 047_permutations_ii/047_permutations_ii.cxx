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

    // See #46 for a complete description of this algorithm.
    void permutate(vector<vector<int>>& ans, vector<int>& nums, size_t i) {

        size_t n = nums.size();

        if(i >= n) {
            ans.push_back(nums);
            return;
        }

        for(auto j = i, k = n; j < n; ++j) {
            permutate(ans, nums, i + 1);

            // Unlike #46, where integers were distinct we may have duplicates. The invariant that must be maintained
            // is that the number being swapped must be larger than nums[i]. Therefore, if nums[k] is <= nums[i], move
            // on to the next possible number. Take care to not underflow k as it is an unsigned size type.
            // Additionally, since the loop just breaks if i >= k, stop at i.
            while(k > i && nums[--k] <= nums[i]);

            // Still need to check if nums[k] is larger than nums[i] because k just may be at the end of the list.
            if(i < k && nums[i] < nums[k]) {
                swap(nums[i], nums[k]);
                reverse(nums.begin() + i + 1, nums.end());
            }
            else {
                break;
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        permutate(ans, nums, 0);
        return ans;
    }
};
