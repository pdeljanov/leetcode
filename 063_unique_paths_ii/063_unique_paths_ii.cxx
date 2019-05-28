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
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int n = obstacleGrid.size();

        // Atleast one row is required.
        if(n < 1) {
            return 0;
        }

        int m = obstacleGrid[0].size();

        // Use counts to store the number of uniques paths to each column in the previous row.
        // Since m is limited to a maximum of 100, then 800 bytes on the stack is acceptable.
        unsigned long counts[m];

        // Initialize counts to the number of unique paths to each column in the 1st row. This
        // is 1 for every column until an obstacle is hit, at that point, the remaining columns
        // have no paths to them and therefore counts will be 0 for those columns.
        counts[0] = (obstacleGrid[0][0] == 0) ? 1 : 0;

        for(int x = 1; x < m; ++x) {
            counts[x] = (obstacleGrid[0][x] == 0) ? counts[x-1] : 0;
        }

        for(int y = 1; y < n; ++y) {
            // The first column in a row will always have 1 unique path to it (straight down) if
            // no obstacles were encountered.
            counts[0] = (obstacleGrid[y][0] == 0) ? counts[0] : 0;

            // The number of unique paths to each column is equal to the number of unique paths
            // to the cell above it, and to the left of it. Since counts[x] already contains the
            // number of unique paths of the cell above it, simply add the number of unique paths
            // to cell x-1. If an obstacle is encountered, the number of unique paths is 0 since
            // nothing can traverse it.
            for(int x = 1; x < m; ++x) {
                if(obstacleGrid[y][x] == 1) {
                    counts[x] = 0;
                }
                else {
                    counts[x] += counts[x-1];
                }
            }
        }

        return counts[m-1];
    }
};
