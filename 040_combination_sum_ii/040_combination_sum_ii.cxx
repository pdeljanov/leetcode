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
        if(target == 0) {
            combinations.push_back(current);
        }
        else {
            // Never include the same candidate twice.
            for(vector<int>::size_type j = ++i; j < candidates.size(); ++j) {
                // Don't allow duplicate candidates at the same level of recursion, therefore
                // disallowing combinations where a candidate appears in the same index twice.
                if(j > i && candidates[j] == candidates[j-1]) continue;

                int diff = target - candidates[j];

                if(diff >= 0) {
                    current.push_back(candidates[j]);
                    find_sum(combinations, candidates, current, diff, j);
                    current.pop_back();
                }
                else {
                    break;
                }
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // See 039_combination_sum.cxx for an explanation of the main algorithm.

        sort(candidates.begin(), candidates.end(), less<int>());

        vector<vector<int>> combinations;
        vector<int> current;

        // To compensate for the implicit increment in find_sum, start at -1. Cast -1 to the appropriate
        // unsigned size_type to get proper wrapping behaviour.
        find_sum(combinations, candidates, current, target, static_cast<vector<int>::size_type>(-1));

        return combinations;
    }
};
