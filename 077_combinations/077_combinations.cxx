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

    void next(vector<vector<int>>& ans, vector<int>& stack, int N, int k, int n) {
        // No more numbers are required, append the stack to the answer.
        if(k < 1) {
            ans.push_back(stack);
        }
        else {
            // For each number in the range [n,N], push the number onto the stack and recurse.
            //
            // Note the extra condition of (n + k) <= N. The value of k is the amount
            // of numbers we must push onto the stack to get an answer. Since the range
            // [n,N] is sequential, then n + k should not exceed N. This optimization saves
            // many needless recursive function calls to next() that would always fail on the
            // n <= N condition.
            for(--k; n <= N && n + k <= N; ++n) {
                stack.push_back(n);
                next(ans, stack, N, k, n + 1);
                stack.pop_back();
            }
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> stack;
        next(ans, stack, n, k, 1);
        return ans;
    }
};
