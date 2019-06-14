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

#include <map>
#include <vector>

using namespace std;

class Solution {
public:

    bool isNStraightHand(vector<int>& hand, int W) {
        // Create a histogram of all integers.
        map<int, int> hist;

        for(auto iter = hand.cbegin(); iter != hand.cend(); ++iter) {
            hist[*iter]++;
        }

        for(auto card = hist.begin(), end = hist.end(); card != end; ++card) {
            // The current card has N cards. That means there must be atleast N cards each for the next
            // W-1 cards. Essentially, N groups will be formed.
            if(card->second < 1) {
                continue;
            }

            auto iter = card;

            for(int w = 1; w < W; ++w) {
                // Note the value of the previous card.
                int value = iter->first;

                // Advance to the next card. If the end of the histogram is reached, then there are not
                // enough cards left to make a groups of length W. Additionally, check if the next card
                // has a value that's 1 greater than the previous card.
                if(++iter == end || iter->first - value > 1) {
                    return false;
                }

                // Subtract the number of cards required to make N groups using the current card.
                // If there are < 0 cards after subtraction, then there weren't enough cards to
                // make all the groups.
                iter->second -= card->second;

                if(iter->second < 0) {
                    return false;
                }
            }
        }

        return true;
    }
};
