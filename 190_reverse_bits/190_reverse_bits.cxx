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

class Solution {
public:

    const uint32_t REV[16] = {
        0x0, // 0b0000  -> 0b0000
        0x8, // 0b0001  -> 0b1000
        0x4, // 0b0010  -> 0b0100
        0xc, // 0b0011  -> 0b1100
        0x2, // 0b0100  -> 0b0010
        0xa, // 0b0101  -> 0b1010
        0x6, // 0b0110  -> 0b0110
        0xe, // 0b0111  -> 0b1110
        0x1, // 0b1000  -> 0b0001
        0x9, // 0b1001  -> 0b1001
        0x5, // 0b1010  -> 0b0101
        0xd, // 0b1011  -> 0b1101
        0x3, // 0b1100  -> 0b0011
        0xb, // 0b1101  -> 0b1011
        0x7, // 0b1110  -> 0b0111
        0xf  // 0b1111  -> 0b1111
    };

    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        ans =              REV[n & 0xf]; n >>= 4;
        ans = (ans << 4) | REV[n & 0xf]; n >>= 4;
        ans = (ans << 4) | REV[n & 0xf]; n >>= 4;
        ans = (ans << 4) | REV[n & 0xf]; n >>= 4;
        ans = (ans << 4) | REV[n & 0xf]; n >>= 4;
        ans = (ans << 4) | REV[n & 0xf]; n >>= 4;
        ans = (ans << 4) | REV[n & 0xf]; n >>= 4;
        ans = (ans << 4) | REV[n & 0xf];
        return ans;
    }
};
