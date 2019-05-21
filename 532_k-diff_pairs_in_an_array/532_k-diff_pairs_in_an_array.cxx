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
#include <unordered_map>
#include <vector>

class Solution {
public:

    // O(N log N + N) solution
    //
    // Faster for "small" datasets, and uses not additional memory. For larger datasets, this solution
    // will become slower due to the sort operation. However, since no dynamic memory allocations are
    // made in this solution it will be faster even when compared to solutions with a lower algorithmic
    // complexity that uses dynamic memory.
    int findPairs(vector<int>& nums, int k) {
        // The difference is always positive.
        if(k < 0) {
            return 0;
        }

        // Sort the numbers vector from largest to smallest.
        sort(nums.begin(), nums.end(), std::greater<int>());

        int count = 0;

        // Loop through each number in the sorted number array.
        for(int i = 0; i < nums.size(); ++i) {

            // Starting at the the number one past index i, check if the difference
            // is equal to k. If it is, a diff-pair was found. If it is greater than
            // k, terminate the loop, there is no diff pair. The loop continues to
            // run so long as the difference is less than k.
            for(int j = i + 1; j < nums.size(); ++j) {
                if(nums[i] - nums[j] == k){
                    ++count;
                    break;
                }
                else if(nums[i] - nums[j] > k) {
                    break;
                }
            }

            // The value at index i may been repeated several times, skip the duplicate(s)
            // to avoid non-unique pairs.
            for(int dup = nums[i]; i < nums.size() && nums[i] == dup; ++i);
            --i;
        }

        return count;
    }

    // O(2N) solution.
    //
    // Slower for "small" datasets, and consumes more memory. In practice, the memory allocations in
    // unordered_map makes this solution slower for smaller datasets where there is not a lot of
    // repeated numbers.
    int findPairsHistogram(vector<int>& nums, int k) {
        // The difference is always positive.
        if(k < 0) {
            return 0;
        }

        unordered_map<int, int> histogram;

        // Build a histogram of the number of times a value shows up in the numbers vector.
        // The bucket size is equal to 1, so each unique integer has it's own bucket.
        for(int i = 0; i < nums.size(); ++i) {
            histogram[nums[i]]++;
        }

        int count = 0;

        // If k = 0, then for a diff pair (i, j), |i-j| = 0 when i = j. Therefore, if a
        // histogram bucket has a count of 2 or more, increment the diff pair count by one
        // since duplicate pairs do not count.
        if(k == 0) {
            for(auto iter = histogram.cbegin(); iter != histogram.cend(); ++iter) {
                if(iter->second >= 2) {
                    ++count;
                }
            }
        }
        // If k = 0, then for a diff pair (i, j), |i-j| = k. There is no ordering in the map itself,
        // so define the the key (iter->first) as j. Then for the difference to be equal to k, i = j + k.
        // If the bucket for i has a count > 0, then a pair can be made. Test each bucket in the map to
        // find all unique pairs.
        else {
            for(auto iter = histogram.cbegin(); iter != histogram.cend(); ++iter) {
                if(histogram.count(iter->first + k) > 0) {
                    ++count;
                }
            }
        }

        return count;
    }

};
