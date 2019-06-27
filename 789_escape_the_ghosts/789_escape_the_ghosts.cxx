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

#include <cmath>
#include <vector>

using namespace std;

class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        // The manhatten distance from (0,0) target (Tx, Ty) is the absolute shortest distance
        // you must travel to get to the target.
        int target_dist = abs(target[0]) + abs(target[1]);

        // If any ghost has a shorter distance to travel than you, they can just linger on the target,
        // and therefore you will always lose. Conversely, if any ghost has a longer distance to travel,
        // they will never be able to catch up to you since you both can only move one distance unit at
        // a time. Therefore, if no ghost has a shorter distance to travel than you, you will always win.
        for(const auto& ghost : ghosts) {
            // Manhatten distance from (Gx, Gy) to (Tx, Ty).
            int distance = abs(target[0] - ghost[0]) + abs(target[1] - ghost[1]);

            if(distance <= target_dist) {
                return false;
            }
        }

        return true;
    }
};
