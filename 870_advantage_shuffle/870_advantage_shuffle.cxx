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

class Solution {
public:

    // A comparator adapter that uses the values from a secondary vector to determine ordering.
    template<class T, class C>
    class alt_order {
    private:
        const vector<T>& order_;
        C c_;

    public:
        alt_order(const vector<T>& order) : order_(order), c_() {}

        bool operator()(size_t a, size_t b) const {
            return c_(order_[a], order_[b]);
        }
    };

    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        size_t N = A.size();

        // Generate order, a vector of indicies from 0..N-1, and sort it such that when iterated, the values,
        // when used to index B, would iterate B in ascending order.
        vector<size_t> order(N);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), alt_order<int, less<int>>(B));

        // Sort A in ascending order.
        sort(A.begin(), A.end());

        vector<int> ans(N);

        size_t i = 0, j = 0, k = N;

        while(j < N) {
            // If the next value A is > the next value in B (using the order vector to iterate B in ascending order),
            // then the A value should be paired with the B value in the answer vector.
            if(A[j] > B[order[i]]) {
                ans[order[i]] = A[j];
                ++i;
            }
            // Otherwise, the A value will never be greater than any upcoming B value, so pair it with the largest
            // available value in B (iterating the order vector backwards iterates B in descending order).
            else {
                ans[order[--k]] = A[j];
            }
            ++j;
        }

        return ans;
    }

};
