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
#include <limits>
#include <vector>

class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {

        // Trivial case.
        if(A.size() < 2) {
            return 0;
        }

        // Find the minimum and maximum values in A.
        int a_min = numeric_limits<int>::max();
        int a_max = numeric_limits<int>::min();

        for(int a : A) {
            a_min = min(a_min, a);
            a_max = max(a_max, a);
        }

        // If the difference between the minimum and maximum numbers are less than 2*K, then
        // it is possible to add a positive value to the minimum, and a negative value to the
        // maximum to yield a difference of 0. If the difference is larger than 2*K, then
        // even if we add the K to the minimum, and the -K to the maximum, a difference will be
        // yielded.
        //
        // Since we can add -K <= x <= K to each number in A, then every number between the
        // minimum and maximum can be modified to continue staying between the minimum and
        // maximum.
        //
        // All this can be yielded from a taking the maximum of 0, and the difference minus 2*K.
        // Since only differences that are less than 2*K, and therefore nullable, produce a
        // negative value, max() will return 0. In all other cases where the difference exceeds
        // 2*K, the difference minus 2*K is returned.
        return max(0, a_max - a_min - 2*K);
    }
};
