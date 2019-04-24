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

#include <bitset>
#include <iomanip>
#include <sstream>
#include <stdint>
#include <vector>

using namespace std;

class Solution {
public:

    const uint32_t kMaxTime = 0x3ff;
    const uint32_t kMinuteMask = 0x3f;
    const uint32_t kHourMask = 0x3c0;

    bool validHour(uint32_t h) {
        return h < 12;
    }

    bool validMinute(uint32_t m) {
        return m < 60;
    }

    int countBits(uint32_t num) {
        return bitset<10>(num).count();
    }

    vector<string> readBinaryWatch(int num) {
        vector<string> res;

        for(uint32_t time = 0; time <= kMaxTime; ++time) {

            if(num == countBits(time)) {

                uint32_t h = (time & kHourMask) >> 6;
                uint32_t m = (time & kMinuteMask);

                if(validHour(h) && validMinute(m)) {
                    stringstream ss;
                    ss << h << ":" << setw(2) << setfill('0') << m;
                    res.push_back(ss.str());
                }
            }
        }

        return res;
    }

};
