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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Need atleast a 1x1 matrix.
        if(matrix.size() < 1 || matrix[0].size() < 1) {
            return false;
        }

        // Binary search for the row that (should) contain target.
        size_t l = 0;
        size_t r = matrix.size() - 1;

        while(l < r) {
            size_t m = (l + r) / 2;

            if(matrix[m].back() < target) {
                l = m + 1;
            }
            else {
                r = m;
            }
        }

        size_t row = r;

        // If the target is not in the row, exit early.
        if(matrix[row][0] > target || matrix[row].back() < target) {
            return false;
        }

        // Binary search for the column that (should) contain target.
        l = 0;
        r = matrix[row].size() - 1;

        while(l < r) {
            size_t m = (l + r) / 2;

            if(matrix[row][m] < target) {
                l = m + 1;
            }
            else {
                r = m;
            }
        }

        return (matrix[row][r] == target);
    }
};
