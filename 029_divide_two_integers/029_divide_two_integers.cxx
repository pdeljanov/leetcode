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

#include <iostream>
#include <limits>

using namespace std;

class Solution {
public:

    int divide(int dividend, int divisor) {
        // Convert positive divisor to negative to obtain the largest int range (0 to -2^31).
        int mdivisor = divisor > 0 ? -divisor : divisor;

        // Convert positive dividend to negative to obtain the largest int range (0 to -2^31).
        int remainder = dividend > 0 ? -dividend : dividend;

        int quotient = 0;
        int multiple = -1;

        // Find the largest power of two multiple of the divisor that can be subtracted from the remainder.
        while(remainder < mdivisor) {
            multiple += multiple;
            mdivisor += mdivisor;
        }

        // Subtract multiples of the divisor until the multiple settles to -1.
        while(true) {
            if(remainder <= mdivisor) {
                remainder -= mdivisor;
                quotient += multiple;
            }

            // Exit when multiple no longer changes from -1. That is, perform one iteration when multiple is -1,
            // then exit.
            if(multiple == -1) break;

            multiple >>= 1;
            mdivisor >>= 1;
        }

        // Quotient is always counted in the negative direction to maximize the use of the int range. If the result
        // should be negative, simply return quotient.
        if((dividend < 0) ^ (divisor < 0)) {
            return quotient;
        }
        // Otherwise negate quotient, but take care to clamp it to the maximum int value as the absolute value of the
        // minimum int value is greater than the maximum int value.
        else {
            if(quotient == numeric_limits<int>::min()) {
                return numeric_limits<int>::max();
            }
            return -quotient;
        }
    }
};

int main() {
    Solution soln;
    cout << soln.divide(0, 1) << endl;
    cout << soln.divide(1, 1) << endl;
    cout << soln.divide(10, 3) << endl;
    cout << soln.divide(10, 11) << endl;
    cout << soln.divide(-1234,123) << endl;
    cout << soln.divide(2147483647, 1) << endl;
    cout << soln.divide(2147483647, -1) << endl;
    cout << soln.divide(2147483647, 2147483647) << endl;
    cout << soln.divide(-2147483648, 1) << endl;
    cout << soln.divide(-2147483648, -1) << endl;
    cout << soln.divide(-2147483648, -2147483648) << endl;
    return 0;
}
