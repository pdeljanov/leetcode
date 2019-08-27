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
    int largestSumAfterKNegations(vector<int>& A, int K) {
        // Sort numbers in ascending order.
        sort(A.begin(), A.end());

        // i is the current index into A
        size_t i = 0;
        // j is the index of the last flipped negative number in A
        size_t j = 0;

        // While there are moves remaining, and i has not exceeded the length of A...
        while(K > 0 && i < A.size()) {
            // If A[i] is negative, then it always makes sense to flip it positive and
            // consume a move.
            if(A[i] < 0) {
                A[i] = -A[i];
                j = i;
                --K;
            }
            // If A[i] is 0, then all previous numbers were negative and have been flipped. Since
            // all future numbers will be positive, it only makes sense to flip the sign on 0 for
            // the remaining number of moves.
            else if(A[i] == 0) {
                K = 0;
            }
            // If A[i] is positive, then all previous negative numbers were flipped positive.
            // We don't want to make any of them negative, nor do we want to make A[i] negative.
            // So first it makes sense to consume as many moves as possible flipping some number(s)
            // positive->negative->positive. Basically, if K is odd, we are forced to flip a positive
            // number negative.
            else if(K & 1) {
                // Choose the smallest positive number seen thus far (either A[i], or the last and smallest
                // negative-turned-positive number, A[j]) and flip it to negative.
                if(A[i] > A[j]) {
                    A[j] = -A[j];
                }
                else {
                    A[i] = -A[i];
                }

                K = 0;
            }

            ++i;
        }

        // If we ended up here, that means there is no positive number of 0 in the list, and we have moves
        // remaining. It also means that every negative number has been flipped positive. So flip the smallest
        // number back to negative. If K is even then we can just flip some number(s) between
        // positive->negative->positive.
        if(K & 1 && j < A.size()) {
            A[j] = -A[j];
        }

        // Return the sum of A now.
        return accumulate(A.cbegin(), A.cend(), 0);
    }
};
