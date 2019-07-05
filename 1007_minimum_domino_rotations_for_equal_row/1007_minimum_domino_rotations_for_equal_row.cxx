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
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        // Count of each number appearing uniquely in the top OR bottom position, respectively, for all dominos.
        int hist_a[]   = {0, 0, 0, 0, 0, 0, 0};
        int hist_b[]   = {0, 0, 0, 0, 0, 0, 0};

        // Count of each number appearing in both the top AND bottom position for all dominos.
        int hist_dbl[] = {0, 0, 0, 0, 0, 0, 0};

        for(size_t i = 0; i < A.size(); ++i) {
            if(A[i] == B[i]) {
                ++hist_dbl[A[i]];
            }
            else {
                ++hist_a[A[i]];
                ++hist_b[B[i]];
            }
        }

        // For each possible number, 1 thru 6, sum the occurences of that number appearing only on the top or
        // bottom of the dominos, with the number of dominos with that number on both sides. If the sum is equal
        // to the total number of dominos, then we can flip either the dominos with the number on the top, or the
        // dominos with the number on the bottom to yield a row of identical numbers. Since we want the least
        // number of moves, we choose the side with the least occurences of the number, and flip the dominos
        // where the number appears on that side.
        //
        // Note that there can only be one answer because unless all the dominos have the same numbers on each
        // side, the occurences of the other numbers will always be lower. In the case of identical dominos,
        // the number of flips regardless of the number you pick will be the same.
        for(size_t i = 1; i <= 6; ++i) {
            if(hist_a[i] + hist_b[i] + hist_dbl[i] == A.size()) {
                return min(hist_a[i], hist_b[i]);
            }
        }

        return -1;
    }
};
