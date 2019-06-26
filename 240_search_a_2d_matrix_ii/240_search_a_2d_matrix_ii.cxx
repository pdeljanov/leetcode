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
        size_t m = matrix.size();

        // Need atleast one row to find the number of columns.
        if(m < 1) {
            return false;
        }

        size_t r = 0;
        size_t c = matrix[0].size();

        // Starting at the end of the first row, for each iteration, check if the value in the current
        // cell {r,c} is equal to target. If it is, return true. Otherwise, if the value is larger than
        // target, then the rest of the cells in the same column will also be larger than target.
        // Therefore, move to the next smaller cell in the same row, {r, c-1}. However, if the value
        // in the current cell has a value less than target, then move to the next larger cell in the
        // same column {r+1, c} since the rest of the cells in the same row will also be smaller than
        // target. Exit if the bounds of the matrix are exceeded before finding the value.
        while(r < m && c > 0) {
            if(matrix[r][c-1] == target) {
                return true;
            }
            else if(matrix[r][c-1] > target) {
                --c;
            }
            else {
                ++r;
            }
        }

        return false;
    }
};
