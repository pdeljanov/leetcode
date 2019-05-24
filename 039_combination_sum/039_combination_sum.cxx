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
#include <functional>
#include <vector>

using namespace std;

class Solution {
public:

    void find_sum(
        vector<vector<int>>& combinations,
        vector<int>& candidates,
        vector<int>& current,
        int target,
        vector<int>::size_type i)
    {
        // If target is 0, we've reached a combination, push it onto the combinations list.
        if(target == 0) {
            combinations.push_back(current);
        }
        else {
            // Recurse from the current candidate to the last candidate and test all reasonable
            // combinations.
            for(vector<int>::size_type j = i; j < candidates.size(); ++j) {
                int diff = target - candidates[j];

                // If the difference between the target and the next candidate is less than 0,
                // then that candidate and all candidates after it are too large. Terminate
                // the loop and recursion at that point.
                if(diff >= 0) {
                    // Push the next candidate onto the current combination and recurse.
                    current.push_back(candidates[j]);

                    // Recurse!
                    find_sum(combinations, candidates, current, diff, j);

                    // Pop off the candidate from the current combination.
                    current.pop_back();
                }
                else {
                    break;
                }
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // Sort in ascending order to allow us to skip candidates in the DFS.
        sort(candidates.begin(), candidates.end(), less<int>());

        vector<vector<int>> combinations;
        vector<int> current;

        find_sum(combinations, candidates, current, target, 0);

        return combinations;
    }
};
