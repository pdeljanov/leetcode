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

struct PalindromeGenerator {
public:

    PalindromeGenerator(int N) : n_(0), odd_(1), power_(10) {
        // This is an optimization to start the palindrome generator further along based on N.
        if(N >= 10000) {
            n_ = 100;
            power_ = 1000;
        }
        else if(N >= 1000000) {
            n_ = 1000;
            power_ = 10000;
        }
        else if(N >= 100000000) {
            n_ = 10000;
            power_ = 100000;
        }
    }

    int next() {
        int n = n_;
        int p = n_;

        if(odd_) { n /= 10; }

        while(n > 0) {
            p = (p * 10) + (n % 10);
            n /= 10;
        }

        // Increment the palindrome monotonically (i.e., the next palindrome is always smaller
        // than the previous).
        if(++n_ >= power_) {
            if(odd_) {
                n_ -= power_ - 1;
            }
            else {
                power_ *= 10;
            }
            odd_ = ++odd_ & 1;
        }

        return p;
    }

private:
    int n_;
    int odd_;
    int power_;
};

class Solution {
public:

    // This is a simple priminality test. A more complex test would likely yield marginally better performance,
    // but the primes in this problem are small anyways.
    //
    // For more details, see: https://en.wikipedia.org/wiki/Primality_test
    bool is_prime(int n) {
        // Numbers 0, and 1 are not prime, but 2 and 3 are prime.
        if (n <= 3) {
            return (n > 1);
        }

        // Numbers evenly divisible by 2 and 3 are not prime.
        if (n % 2 == 0 || n % 3 == 0) {
            return false;
        }

        int i = 5;

        while (i * i <= n) {
            if (n % i == 0 || n % (i + 2) == 0) {
                return false;
            }
            i += 6;
        }

        return true;
    }

    int primePalindrome(int N) {
        PalindromeGenerator p(N);
        int n;

        while((n = p.next()) < 200000000) {
            if(n >= N && is_prime(n)) {
                return n;
            }
        }

        return -1;
    }
};
