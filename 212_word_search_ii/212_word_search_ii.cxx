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

#include <array>
#include <memory>
#include <vector>
#include <string>

class Solution {
public:

    struct Trie {
        string word;
        std::array<unique_ptr<Trie>, 26> chars;

        Trie() {}
    };

    void descend(
        vector<string>& ans,
        vector<vector<char>>& board,
        int x,
        int y,
        Trie* parent)
    {
        char c = board[y][x];

        // Check the current letter is in the Trie.
        auto node = parent->chars[c - 'a'].get();

        // Mark the current cell as visited.
        board[y][x] = '\0';

        // If the trie node has a word, add it to the answer and clear the word to prevent duplicate
        // answers.
        if(node->word.size()) {
            ans.push_back(node->word);
            node->word.clear();
        }

        // Can we go up?
        if(y > 0 &&
           board[y-1][x] &&
           node->chars[board[y-1][x] - 'a'])
        {
            descend(ans, board, x, y - 1, node);
        }

        // Can we go down?
        if(y + 1 < board.size() &&
           board[y+1][x] &&
           node->chars[board[y+1][x] - 'a'])
        {
            descend(ans, board, x, y + 1, node);
        }

        // Can we go left?
        if(x > 0 &&
           board[y][x-1] &&
           node->chars[board[y][x-1] - 'a'])
        {
            descend(ans, board, x - 1, y, node);
        }

        // Can we go right?
        if(x + 1 < board[0].size() &&
           board[y][x+1] &&
           node->chars[board[y][x+1] - 'a'])
        {
            descend(ans, board, x + 1, y, node);
        }

        // Restore the cell to its original character as we are no longer visiting it.
        board[y][x] = c;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;

        // Do preliminary checks: board needs atleast one cell.
        size_t n = board.size();

        if(n < 1) {
            return ans;
        }

        size_t m = board[0].size();

        if(m < 1) {
            return ans;
        }

        // Build a simple trie.
        unique_ptr<Trie> root = make_unique<Trie>();

        for(const string& word : words) {
            Trie* node = root.get();

            for(auto c : word) {
                auto& val = node->chars[c - 'a'];
                if(!val) {
                    val.reset(new Trie());
                }
                node = val.get();
            }

            node->word = word;
        }

        for(size_t y = 0; y < n; ++y) {
            for(size_t x = 0; x < m; ++x) {
                auto next = root->chars[board[y][x] - 'a'].get();
                if(next) {
                    descend(ans, board, x, y, root.get());
                }
            }
        }

        return ans;
    }
};
