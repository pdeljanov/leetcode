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

    double partition(vector<int>& A, size_t i, int k) {
        if(dp[i][k] > 0.0) {
            return dp[i][k];
        }

        int count = 0;
        double sum = 0;

        // More than one partition left, the current partition may be any length from 1 to
        // N-i-1. Select a partition length that will yield the largest score by recursing
        // at each possible partition length and picking the maximum.
        if(k > 1) {

            for(auto j = i; j < A.size() - 1; ++j) {
                sum += A[j];
                double part_score = sum / ++count;
                dp[i][k] = max(dp[i][k], part_score + partition(A, j + 1, k - 1));
            }

            // Handle the full length partition case seperately so we can skip the check of
            // i >= A.size() that partition(A, j+1, k-1) would fail when j is at the end of
            // A. Note however that this assumes A.size() > 0.
            sum += A.back();
            dp[i][k] = max(dp[i][k], sum / ++count);
        }
        // One partition left, it MUST contain all remaining elements.
        else {

            for(auto j = i; j < A.size(); ++j, ++count) {
                sum += A[j];
            }

            dp[i][k] = sum / count;
        }

        return dp[i][k];
    }

    double largestSumOfAverages(vector<int>& A, int K) {
        // Initialize the memo.
        for(size_t i = 0; i < A.size(); ++i) {
            for(size_t j = 0; j <= static_cast<size_t>(K); ++j) {
                dp[i][j] = 0.0;
            }
        }

        return partition(A, 0, K);
    }

private:
    double dp[100][101];
};
