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
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<int> horiz_max(n);
        vector<int> vert_max(n);

        int old_height = 0;

        // Find the maximum heights for each column and each row of the grid. Sum the
        // heights into a total for comparison with with the new skyline height.
        for(int col = 0; col < n; ++col) {
            for(int row = 0; row < n; ++row) {
                horiz_max[col] = max(horiz_max[col], grid[row][col]);
                vert_max[row] = max(vert_max[row], grid[row][col]);
                old_height += grid[row][col];
            }
        }

        int new_height = 0;

        // The new height for grid[y][x] is minimum between the maximum height for column x,
        // and the maximum height for row y. Sum the new height for comparision with the old
        // skyline height.
        for(int x = 0; x < n; ++x) {
            for(int y = 0; y < n; ++y) {
                new_height += min(horiz_max[x], vert_max[y]);
            }
        }

        // Return the difference between the new and old skyline height.
        return new_height - old_height;
    }
};
