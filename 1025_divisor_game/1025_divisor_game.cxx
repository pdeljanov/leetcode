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

class Solution {
public:
    bool divisorGame(int N) {
        // Whoever gets an even number first, wins. The recipient of the first even
        // number is determined by the initial value of N.
        //
        // This is becuase if N is even, the optimal move is to always pick x=1 such
        // that the opponent always has an odd number and will never have the final
        // move.
        //
        // If N is odd, then it may only be divided evenly by another odd number.
        // Two odd numbers subtracted from each other produces an even number. Therefore,
        // if N is even, pick x=1 to make N-1, an odd number. Your opponent will always
        // have to pick an odd x, and therfore you'll always have an even N for your turn.
        //
        // An even N will always have a value of x that can evenly divide it and therefore
        // you cannot lose if you have an even N as you can ALWAYS pick x=1.
        //
        // For example, in the pathological case where the players both choose x=1 every
        // move, the final move occurs when N=2, the player chooses x=1 leaving N=1.
        // The next move, there is no integer value between 0 < x < 1 for the player to pick.
        // Therefore they lose.
        //
        // Therefore, in general,
        //
        // If N is even, Alice wins.
        // If N is odd, Bob wins.
        return !(N & 1);
    }
};
