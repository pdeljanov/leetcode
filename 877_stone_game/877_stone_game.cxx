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

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        vector<int> score(piles.size() + 2, 0);

        size_t i = 2;
        size_t l = 0;
        size_t r = piles.size() - 1;

        while(l < r) {
            // There are N piles, and therefore N turns.
            //
            // For each turn, i, the player (Alex if i % 2 == 0, or Lee if i % 2 != 0 ), chooses
            // to pick either the left-most or right-most pile. We represent the current player's
            // options as a pair of piles (l, r).
            //
            // If we remove the left-most pile, the player next turn will choose which pile to remove
            // from the (l+1, r) pair. Likewise if we remove the right-most pile, the player next turn
            // will choose which pile to remove from the (l, r-1) pair.
            //
            // Therefore, to play optiminally, the player should pick the pile that minimizes the
            // maximum of the pair for the next player's turn. In other words, choose and remove the
            // pile that minimizes the maximum increase in the next turn player's score.
            if(max(piles[r], piles[l+1]) <= max(piles[l], piles[r-1])) {
                score[i] = score[i-2] + piles[l++];
            }
            else {
                score[i] = score[i-2] + piles[r--];
            }
            ++i;
        }

        // Player 1 (Alex) is always the second last score, and player 2 (Lee) is always the last score.
        // Check if Alex has a larger score than Lee.
        return score[score.size() - 1] < score[score.size() - 2];
    }
};
