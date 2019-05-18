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

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        // Shave 300kB off memory usage by using a stack allocated dynamic array instead of
        // a vector. Since m is no more than 100, we can spare 400 bytes of the stack for
        // this optimization.
        int counts[m];

        // Initialize the first row to 1. There is only one unique path to get to each
        // block on the first row.
        fill_n(counts, m , 1);

        // For all inner (x>0 && y>0) squares, the number of unique paths to that square
        // is the number of unique paths to the square above (x), plus the number of unique
        // paths to the square on the left (x-1). Counts contains the uniques path to each
        // square on the PREVIOUS row until overwritten in the loop. Therefore counts[x] is
        // actually the number of unqiue paths for (x, y-1) initially, and counts[x-1] is
        // initially the number of unique paths to (x-1, y-1).
        for(int y = 1; y < n; ++y) {
            for(int x = 1; x < m; ++x) {
                counts[x] += counts[x-1];
            }
        }

        return counts[m-1];
    }
};
