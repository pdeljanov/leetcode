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

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int, int> hist;

        int ans = 0;
        int sum = 0;

        // If a number = k, it by itself is a contiguous array. Therefore, increment the answer
        // by 1.
        hist[0] = 1;

        for(size_t i = 0; i < nums.size(); ++i) {
            // Calculate the sum up to this point.
            sum += nums[i];
            // The histogram counts the number of times a sum appears up-to i-1. Given the current
            // sum up-to i, calculate a delta, such that if it were subtracted from the current
            // sum the result would be k. The number of times this delta has appeared thus far
            // indicates the number of "starting" points, and thus contiguous arrays, that terminate
            // at i and have sums of k. Therefore, increment the answer by the number of times that
            // delta has appeared.
            ans += hist[sum - k];
            // Increment the number of times sum has appeared.
            hist[sum]++;
        }

        return ans;
    }
};
