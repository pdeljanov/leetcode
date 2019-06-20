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
#include <vector>

using namespace std;

class Solution {
public:

    // Method 1 - Computations: O(N*M), Memory: O(M)
    int maximalSquare(vector<vector<char>>& matrix) {

        size_t n = matrix.size();
        if(n < 1) return 0;

        size_t m = matrix[0].size();
        if(m < 1) return 0;

        int mx = 0;

        vector<int> dp(m, 0);

        // Fill DP vector with the first row of the matrix.
        for(size_t j = 0; j < m; ++j) {
            dp[j] = matrix[0][j] == '1' ? 1 : 0;
            mx = max(mx, dp[j]);
        }

        // For each row and column, {i, j}, calculate the maximal length of a square intersecting {i,j}.
        // Check the side-length for cells {i-1, j-1}, {i-1, j}, {i-1, j-1}, the minimal side-length + 1
        // is the side-length for the current cell.
        //
        // Since the value of previous cells are required, the first row and column are filled in from the
        // matrix directly so only cells with i > 0 && j > 0 are iterated over. For these edges, the side-length
        // would always only either be 0 or 1.
        //
        // Example:
        //
        //      matrix = [ 1 1 ]    dp = [ 1 1 ]    min(min(dp[0][0], dp[1][0]), dp[0][1]) + 1 = 1 + 1 = 2
        //               [ 1 1 ]         [ 1 ? ]
        //
        // therefore,
        //
        //      dp = [ 1 1 ]    the answer is therefore 2*2 as it's the longest side-length.
        //           [ 1 2 ]
        //
        // Since the only history needed is the previous row, then only a single row vector is required. The
        // only caveat is that we need {i-1, j-1} which would be overwritten before it can be used. Use a
        // temporary variable, dp_i1_j1, to store this value for the next iteration.
        for(size_t i = 1; i < n; ++i) {

            // Use dp_i1_j1 to store what would be dp[i-1][j-1] for iteration j.
            int dp_i1_j1 = dp[0], tmp = 0;

            // Update first column manually. The value is always equal to 1 if matrix == '1', otherwise 0.
            dp[0] = matrix[i][0] == '1' ? 1 : 0;
            mx = max(mx, dp[0]);

            // Iterate over all other columns.
            for(size_t j = 1; j < m; ++j) {
                tmp = dp[j];

                // If the cell in the matrix == '1', calculate how far the square's boundary can be pushed forward.
                // This is dependant on the side-lengths of the adjacent and diagonal cells.
                if(matrix[i][j] == '1') {
                    dp[j] = min(min(dp_i1_j1, dp[j-1]), dp[j]) + 1;
                    mx = max(mx, dp[j]);
                }
                // If the cell in the matrix == '0', then the side-length is 0.
                else {
                    dp[j] = 0;
                }

                dp_i1_j1 = tmp;
            }
        }

        // Return the area.
        return mx * mx;
    }

    // Method 2 (original version of method 1) - Computations: O(N*M), Memory: O(N*M)
    int maximalSquare2(vector<vector<char>>& matrix) {
        size_t n = matrix.size();
        if(n < 1) return 0;

        size_t m = matrix[0].size();
        if(m < 1) return 0;

        int mx = 0;

        vector<vector<int>> dp(n, vector<int>(m, 0));

        for(size_t i = 0; i < n; ++i) {
            dp[i][0] = matrix[i][0] == '1' ? 1 : 0;
            mx = max(mx, dp[i][0]);
        }

        for(size_t j = 0; j < m; ++j) {
            dp[0][j] = matrix[0][j] == '1' ? 1 : 0;
            mx = max(mx, dp[0][j]);
        }

        for(size_t i = 1; i < n; ++i) {
            for(size_t j = 1; j < m; ++j) {
                if(matrix[i][j] == '1') {
                    dp[i][j] = min(min(dp[i-1][j-1], dp[i][j-1]), dp[i-1][j]) + 1;
                    mx = max(mx, dp[i][j]);
                }
            }
        }

        return mx * mx;
    }

};
