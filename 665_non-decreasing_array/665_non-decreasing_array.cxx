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

using namespace std;

class Solution {
public:

    // Cases:
    //
    // [3,1,2]
    // [1,3,2]
    // [1,3,2,3,4]
    // [1,4,2,3]
    // [1,2,3,4,2,4,4]
    // [1,2,3,2]
    // [1,2,1,2,3]

    bool checkPossibility(vector<int>& nums) {

        int p[3] = {
            numeric_limits<int>::min(),
            numeric_limits<int>::min(),
            nums[0]
        };

        int hits = 0;

        for(int i = 1; i < nums.size(); ++i) {
            p[0] = p[1];
            p[1] = p[2];
            p[2] = nums[i];

            // Non-monotonic sequence detected:  p[0] < p[1] > p[2]
            if(p[2] < p[1]) {
                ++hits;

                // We know p[0] < p[1], and p[1] > p[2]. If p[2] >= p[0], make p[1] = p[2],
                // therefore: p[0] < p[1] = p[2]
                if(p[2] >= p[0]) {
                    p[1] = p[2];
                }
                // We know p[0] < p[1], and p[1] > p[2]. If p[2] < p[0] make p[2] = p[1],
                // therefore: p[0] < p[1] = p[2].
                else {
                    p[2] = p[1];
                }
            }
        }

        return hits <= 1;
    }

};
