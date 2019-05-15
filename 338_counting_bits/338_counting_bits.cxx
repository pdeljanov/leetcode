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

#include <vector>

using namespace std;
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> bits(num + 1, 0);

        // The current value for which we are calculating the number of 1 bits.
        int i = 1;
        // A counter for itereating the previously calculated values of bits.
        int j = 0;
        // The next nearest power of two.
        int p2 = 0x2;

        // For each iteration, the number of 1 bits in value i is one plus the number of 1 bits in the
        // lower N-1 bits where N is the index of the most significant 1 bit in i.
        //
        // For example, if i = 38 = 0b100110, then N = 5, and bits N-1 and below are 0b00110.
        // We previously calculated the number of 1s in this value previously, and it can be found at index
        // 0b00110 (6) in the bits array.
        //
        // We use a counter j to quickly determine this index and reset it to 0 every time i reaches a power
        // of two (all bits other than bit N are 0).
        while(i <= num) {
            bits[i++] = 1 + bits[j++];

            // If next value for which we will be calculating the number of bits for is greater-than or
            // equal to the next nearest power of two, reset j, and shift the next nearest power of two
            // to the left by one (multiply by 2).
            if(i >= p2) {
                j = 0;
                p2 <<= 1;
            }
        }

        return bits;
    }
};
