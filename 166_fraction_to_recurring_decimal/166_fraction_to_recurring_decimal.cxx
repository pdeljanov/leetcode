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
#include <sstream>
#include <map>
#include <deque>
#include <tuple>
#include <cmath>

using namespace std;

class Solution {
public:


    class Number {
    public:
        Number(long number) : sign_(number < 0 ? -1 : 1) {
            number = sign_ * number;
            while(number > 0) {
                digits_.push_front(number % 10);
                number /= 10;
            }
        };

        bool is_empty() {
            return digits_.empty();
        }

        int pop_left() {
            int digit = digits_.front();
            digits_.pop_front();
            return digit;
        }

        int pop_right() {
            int digit = digits_.back();
            digits_.pop_back();
            return digit;
        }

        void push_left(int digit) {
            digits_.push_front(digit);
        }

        void push_right(int digit) {
            digits_.push_back(digit);
        }

    private:
        deque<int> digits_;
        int sign_;
    };



    string fractionToDecimal(int numerator, int denominator) {
        bool negative = (denominator < 0) ^ (numerator < 0);

        Number dividend(numerator);

        long divisor = abs(static_cast<long>(denominator));

        //cout << "Solution for num=" << numerator << ", denom=" << denominator << endl;

        string result;

        long carry{0};

        // Long division for the integer parts of the result.
        while(!dividend.is_empty()) {
            carry = (10 * carry) + dividend.pop_left();

            long a = carry / divisor;
            carry = carry - (a * divisor);

            if(a != 0 || (a == 0 && !result.empty())){
                result += to_string(a);
            }
        }

        // Add leading 0 if required.
        if(result.empty()) {
            result += "0";
        }

        // Add decimal point if required.
        if(carry != 0) {
            result += ".";
        }

        map<tuple<long, int>, int> retable;

        // Long division for the decimal parts of the result.
        while(carry != 0) {
            carry = 10 * carry;

            long a = carry / divisor;
            carry = carry - (a * divisor);

            // If carry returns to a previous value, there is a repeating decimal..
            auto repeat = retable.find(make_tuple(carry, a));
            if(repeat != retable.cend()) {
                // Insert brackets where repetition begins and ends.
                result.insert(result.end() - (retable.size() - repeat->second), '(');
                result += ')';
                break;
            }

            // Insert carry value to repeat hashmap.
            retable.insert(make_pair(make_tuple(carry, a), retable.size()));
            result += to_string(a);
        }

        // Add sign if required.
        if(result != "0" && negative){
            result = "-" + result;
        }

        return result;
    }
};

int main() {
    Solution soln;
    cout << soln.fractionToDecimal(0,2) << endl;
    cout << soln.fractionToDecimal(1,2) << endl;
    cout << soln.fractionToDecimal(12,2) << endl;
    cout << soln.fractionToDecimal(50,2) << endl;
    cout << soln.fractionToDecimal(13,2) << endl;
    cout << soln.fractionToDecimal(1343,5) << endl;
    cout << soln.fractionToDecimal(2,3) << endl;
    cout << soln.fractionToDecimal(4,333) << endl;
    cout << soln.fractionToDecimal(1,6) << endl;
    cout << soln.fractionToDecimal(-50,8) << endl;
    cout << soln.fractionToDecimal(-20,-8) << endl;
    cout << soln.fractionToDecimal(-1,-2147483648) << endl;
    cout << soln.fractionToDecimal(-2147483648,2) << endl;

    return 0;
}
