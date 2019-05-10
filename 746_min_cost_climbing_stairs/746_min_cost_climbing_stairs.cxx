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

    int descend(vector<int>& cost, vector<int>& totals, int i) {
        // End reached.
        if(i >= cost.size()) {
            return 0;
        }

        // This sub-tree has not been explored before yet.
        if(totals[i] < 0) {
            int left = descend(cost, totals, i + 1);
            int right = descend(cost, totals, i + 2);
            totals[i] = cost[i] + min(left, right);
        }

        return totals[i];
    }

    // Approach #1 (DFS with memoization)
    int minCostClimbingStairs3(vector<int>& cost) {
        vector<int> totals(cost.size(), -1);
        return min(descend(cost, totals, 0), descend(cost, totals, 1));
    }

    // Approach #2 ("Dynamic Programming")
    int minCostClimbingStairs2(vector<int>& cost) {
        vector<int> totals(cost.size() + 1, 0);

        if(cost.size() < 2) {
            return 0;
        }

        for(int i = 2; i <= cost.size(); ++i) {
            totals[i] = min(totals[i-2] + cost[i-2], totals[i-1] + cost[i-1]);
        }

        return totals.back();
    }

    // Approach #3 (Optimized "Dynamic Programming")
    int minCostClimbingStairs(vector<int>& cost) {
        int i = 2;
        for(; i < cost.size(); ++i) {
            cost[i] += min(cost[i-2], cost[i-1]);
        }
        return min(cost[i-2], cost[i-1]);
    }

};
