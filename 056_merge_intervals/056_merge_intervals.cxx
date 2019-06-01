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
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        vector<vector<int>> ans;

        // Trivial case.
        if(intervals.size() < 1) {
            return ans;
        }

        // Sort the intervals in ascending order with priority given to the start time. This means that
        // [0,0] appears before [1,2], but [0,2] appears before [1,2] and after [0,0].
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) -> bool {
            return (a[0] < b[0]) || (a[0] == b[0] && a[1] < b[1]);
        });

        // Place the first interval on the answer vector as the first merged interval.
        ans.emplace_back(intervals[0]);

        // Iterate over the intervals.
        //
        // If the start-time of the current interval is greater than the end-time of the last
        // merged interval, there is no further overlap. Start a new merged interval using
        // the current interval.
        //
        // Otherwise, if the start-time of the current interval is less than or equal to the
        // end-time of the last merged interval, the intervals overlap. If the current interval's
        // end-time exceeds the last merged interval's end-time, update the end time of the last
        // merged interval.
        for(size_t i = 1, a = 0; i < intervals.size(); ++i) {
            if(intervals[i][0] > ans[a][1]) {
                ans.emplace_back(intervals[i]);
                ++a;
            }
            else {
                ans[a][1] = max(ans[a][1], intervals[i][1]);
            }
        }

        return ans;
    }
};
