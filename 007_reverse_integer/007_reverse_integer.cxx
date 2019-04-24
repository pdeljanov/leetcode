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

#include <limits>

using namespace std;

class Solution {
public:

    template<typename T>
    bool overflows_upper(int num, int digit) {
        return (num > numeric_limits<T>::max() / 10) ||
            ((num == numeric_limits<T>::max() / 10) && (digit > numeric_limits<T>::max() % 10));
    }

    template<typename T>
    bool overflows_lower(int num, int digit) {
        return (num < numeric_limits<T>::min() / 10) ||
            ((num == numeric_limits<T>::min() / 10) && (digit < numeric_limits<T>::min() % 10));
    }

    int reverse(int x) {
        int reversed = 0;

        while(x != 0) {
            int lsd = x % 10;

            if(overflows_upper<int>(reversed, lsd) || overflows_lower<int>(reversed, lsd))
            {
                return 0;
            }

            reversed *= 10;
            reversed += lsd;
            x /= 10;
        }

        return reversed;
    }
};
