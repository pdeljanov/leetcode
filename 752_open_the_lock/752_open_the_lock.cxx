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
#include <vector>

using namespace std;

class Solution {
public:

    int openLock(vector<string>& deadends, string target) {
        array<uint8_t, 10000> blocked = { 0 };

        // Mark the initial code "0000" as blocked.
        blocked[0] = -1;

        // Mark all deadend codes as blocked
        for(auto& deadend : deadends) {
            uint16_t value = static_cast<uint16_t>(stoi(deadend));

            // If the initial code is a deadend, return immediately.
            if(value == 0) {
                return -1;
            }
            else if(value >= 0 && value < 10000) {
                blocked[value] = -1;
            }
        }

        // Parse the target as an integer.
        uint16_t t = static_cast<uint16_t>(stoi(target));

        queue<uint16_t> q;
        q.push(0);

        int moves = 0;

        // Find a path from the initial code to the target code using a breadth-first search.
        while(q.size()) {
            size_t n = q.size();

            while(n-- > 0) {
                // Pop off the next code.
                auto state = q.front();
                q.pop();

                // If the popped off code is equal to the target, return the number of moves it took to get
                // here.
                if(state == t) {
                    return moves;
                }

                // Mutate the current code in all possible combinations (increase and decrease each wheel).
                for(size_t i = 1000; i > 0; i /= 10) {
                    // The value of the digit to change.
                    uint16_t digit = (state % (10 * i)) / i;

                    // Calculate the new code when the digit is increased or decreased by 1. Do this by taking
                    // the current code and subtracting out the value of the digit, taking into account it's
                    // place in the code. Then, increment or decrement the digit whilst wrapping it around.
                    // Last, add the modified digit back to the code, once again taking into account it's place.
                    uint16_t incremented = state - (digit * i) + (((digit == 9 ? 0 : digit + 1) % 10) * i);
                    uint16_t decremented = state - (digit * i) + (((digit == 0 ? 9 : digit - 1) % 10) * i);

                    // If the incremented code is not blocked, mark it as blocked to prevent cycles, then push
                    // it onto the queue.
                    if(blocked[incremented] == 0) {
                        blocked[incremented] = -1;
                        q.push(incremented);
                    }

                    // Likewise, do the same for the decremented digit.
                    if(blocked[decremented] == 0) {
                        blocked[decremented] = -1;
                        q.push(decremented);
                    }
                }
            }

            ++moves;
        }

        return -1;
    }

};
