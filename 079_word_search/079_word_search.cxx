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

#include <string>
#include <vector>

using namespace std;

class Solution {
public:

    bool check(vector<vector<char>>& board, int x, int y, string& word, int c) {
        // We've got all characters in the word. The word has therefore been found.
        if(c == word.size()) {
            return true;
        }

        // Mark the cell as visited by changing the character of the current cell to the null
        // character. This will prevent recursing to an already visited cell by never matching
        // the next character.
        char oc = board[y][x];
        board[y][x] = 0;

        // Should we go up?
        if(y > 0 && board[y-1][x] == word[c]) {
            if(check(board, x, y-1, word, c + 1)) {
                return true;
            }
        }

        // Should we go down?
        if(y+1 < board.size() && board[y+1][x] == word[c]) {
            if(check(board, x, y+1, word, c + 1)) {
                return true;
            }
        }

        // Should we got left?
        if(x > 0 && board[y][x-1] == word[c]) {
            if(check(board, x-1, y, word, c + 1)) {
                return true;
            }
        }

        // Should we go right?
        if(x+1 < board[0].size() && board[y][x+1] == word[c]) {
            if(check(board, x+1, y, word, c + 1)) {
                return true;
            }
        }

        // Change the cell back to the original character.
        board[y][x] = oc;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        // Do preliminary checks: board needs atleast one cell, and the word needs atleast one
        // character.
        size_t n = board.size();

        if(n < 1 || !word.size()) {
            return false;
        }

        size_t m = board[0].size();

        if(m < 1) {
            return false;
        }

        // Check each cell on the board for the first character in word. If a matching cell is found
        // start a recursive check of all possible paths for the word.
        for(size_t y = 0; y < n; ++y) {
            for(size_t x = 0; x < m; ++x) {
                if(board[y][x] == word[0]) {
                    if(check(board, x, y, word, 1)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};
