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

#include <numeric>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> s;
        int k_val = numeric_limits<int>::min();

        // Iterating the list of numbers backwards...
        for(size_t n = nums.size(); n-- > 0;) {
            // Read the remainder of the comments first before this comment.
            //
            // If the k value has been set, then a j value > k has been found. Thus we simply need an i value that is
            // less than k to complete the pattern. If the value indexed by n is less than k, that value is our i value,
            // and we have found a "132" pattern. If not, then our process repeats.
            if(nums[n] < k_val) {
                return true;
            }

            // The "132" (ijk) pattern implies that from k onwards, the numbers should generally monotonically increase.
            // If we iterate backwards, this looks like a monotonic decrease. If we continue iterating backwards, we may
            // encounter a number indexed by n that is larger than the number n-1, and thus terminating the
            // monotonically decreasing sequence.
            //
            // So, at that moment, the stack is full of /potential/ k values, and the current value indexed by n is the
            // j value.
            //
            // This loop chooses the largest k value for the current j (indexed by n) value. Simply put, the best k
            // value is the one closest to j, but also smaller than j. Any values larger than j would not be appropriate
            // for the "132" pattern as j must > than k. However, they may be useful later for other j values.
            while(!s.empty() && s.top() < nums[n]) {
                k_val = s.top();
                s.pop();
            }

            // Push the current value onto the stack. The stack will either be empty, or contain strictly larger values
            // than that indexed by n (aka j).
            s.push(nums[n]);
        }

        return false;
    }
};
