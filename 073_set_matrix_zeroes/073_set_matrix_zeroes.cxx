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
    void setZeroes(vector<vector<int>>& matrix) {

        bool zero_row_prev = false;

        for(size_t row = 0; row < matrix.size(); ++row) {
            bool zero_row = false;

            for(size_t col = 0; col < matrix[row].size(); ++col) {

                // If the current column in the current row is 0, propagate the 0 upwards and
                // flag the row for zeroing.
                if(matrix[row][col] == 0) {

                    // Propagate the 0 up the column.
                    for(size_t prev_row = 0; prev_row < row; ++prev_row) {
                        matrix[prev_row][col] = 0;
                    }

                    // Flag row to be zeroed.
                    zero_row = true;
                }
                // If the current column in the current row is not zero, but the previous row's cell
                // is 0, propagate the 0 into the current row.
                else if(row > 0 && matrix[row-1][col] == 0) {
                    matrix[row][col] = 0;
                }
            }

            // Zero the previous row if flagged to do so.
            if(zero_row_prev) {
                for(size_t col = 0; col < matrix[row-1].size(); ++col) {
                    matrix[row-1][col] = 0;
                }
            }

            zero_row_prev = zero_row;
        }

        // Zero the last row.
        if(zero_row_prev){
            for(size_t col = 0; col < matrix.back().size(); ++col) {
                matrix.back()[col] = 0;
            }
        }
    }
};
