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

#include <cstdlib>

using namespace std;

class Solution {
public:

    const uint32_t CNT[16] = {
        0, // 0b0000
        1, // 0b0001
        1, // 0b0010
        2, // 0b0011
        1, // 0b0100
        2, // 0b0101
        2, // 0b0110
        3, // 0b0111
        1, // 0b1000
        2, // 0b1001
        2, // 0b1010
        3, // 0b1011
        2, // 0b1100
        3, // 0b1101
        3, // 0b1110
        4  // 0b1111
    };

    int hammingWeight(uint32_t n) {
        int ans = 0;
        ans += CNT[n & 0xf]; n >>= 4;
        ans += CNT[n & 0xf]; n >>= 4;
        ans += CNT[n & 0xf]; n >>= 4;
        ans += CNT[n & 0xf]; n >>= 4;
        ans += CNT[n & 0xf]; n >>= 4;
        ans += CNT[n & 0xf]; n >>= 4;
        ans += CNT[n & 0xf]; n >>= 4;
        ans += CNT[n & 0xf];
        return ans;
    }
};
