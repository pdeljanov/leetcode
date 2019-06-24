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

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> total(days.size() + 1, 0);

        // For each day, calculate the minimum total cost up to the end of the day by calculating the cost
        // if we had bought a pass today, 7 days ago, or 30 days ago, then choosing the minimum of those
        // options.
        for(size_t i = 1; i < total.size(); ++i) {
            size_t c7i = i, c30i = i;

            // Find the index of the total cost at 7 and 30 days ago respectively.
            while(c7i  > 0 && days[i-1] - days[c7i -1] <  7) --c7i;
            while(c30i > 0 && days[i-1] - days[c30i-1] < 30) --c30i;

            // Calculate the total cost for today if we bought a 1-day pass today, or if we had
            // bought a 7-day pass 7 days ago, or a 30-day pass 30 days ago.
            int c1d  = total[i-1]  + costs[0];
            int c7d  = total[c7i]  + costs[1];
            int c30d = total[c30i] + costs[2];

            total[i] = min(min(c1d, c7d), c30d);
        }

        return total.back();
    }

};
