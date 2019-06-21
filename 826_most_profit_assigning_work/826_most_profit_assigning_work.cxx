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

// Comparator for use on a vector of indicies. When two indicies are compared, the values for the
// left and right indicies are found in the given values vector, and then the comparison is performed
// using the left and right values.
template<class T, class C>
class alt_order {
private:
    const vector<T>& values_;
    C cmp_;

public:
    alt_order(const vector<T>& values) : values_(values), cmp_() {}

    bool operator()(size_t i, size_t j) const {
        return cmp_(values_[i], values_[j]);
    }
};

class Solution {
public:

    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        // Generate a vector of indicies with a range of [0, profit.size() - 1]. Each index in the
        // vector is a pointer to a profit and difficulty pair, aka, a job.
        vector<size_t> job(profit.size());
        iota(job.begin(), job.end(), 0);

        // Sort the vector of indicies using profit as the value. After this operation, the indicies
        // will be sorted in such a way that profit[job[i]] and difficulty[job[i]] will be the i-th
        // most profitable job.
        sort(job.begin(), job.end(), alt_order<int, std::greater<int>>(profit));

        // Sort the workers in decreasing order of ability.
        sort(worker.begin(), worker.end(), greater<int>());

        // The maximum profit can now be calculated by matching workers to the most profitable job
        // they are capable of handling. Since the jobs are sorted in decreasing order of profitability,
        // and workers are sorted in decreasing order of ability, we can use two pointers starting from 0
        // to match workers to jobs. If a worker is capable of doing the next job, add up the profit and
        // move on to the next worker. If a worker is not capable of doing the next job, then the workers
        // after him can't as well. Therefore, move on to the next job, and repeat.
        int ans = 0;

        for(size_t i = 0, j = 0; i < worker.size() && j < job.size();) {
            if(worker[i] >= difficulty[job[j]]) {
                ans += profit[job[j]];
                i++;
            }
            else {
                j++;
            }
        }

        return ans;
    }
};
