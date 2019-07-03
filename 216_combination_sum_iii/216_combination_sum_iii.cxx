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

    void combo(vector<vector<int>>& ans, vector<int> cur, int i, int k, int n) {
        // If n is 0, and we've used all k numbers, add the current combination to the answer list.
        if(n == 0) {
            if(k == 0) {
                ans.push_back(cur);
            }
            return;
        }

        // If n is unobtainable, don't allow infinite recursion.
        if(k < 1) {
            return;
        }

        for(int j = i; j <= 9; ++j) {
            // The current (and future) number(s) are too large. Exit early.
            if(j > n) {
                return;
            }

            cur.push_back(j);
            combo(ans, cur, j + 1, k - 1, n - j);
            cur.pop_back();
        }

    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> cur;
        combo(ans, cur, 1, k, n);
        return ans;
    }
};
