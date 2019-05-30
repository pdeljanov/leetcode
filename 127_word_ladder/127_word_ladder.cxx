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

#include <unordered_set>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> words(wordList.cbegin(), wordList.cend());

        vector<string> next_list { beginWord };
        vector<string> cur_list;

        int step = 1;
        size_t L = endWord.size();

        while(!next_list.empty()) {
            // Swap the "next" to-check list with the "current" to-check list (no copying), and clear the
            // "next" to-check list.
            cur_list.swap(next_list);
            next_list.clear();

            for(auto& word: cur_list) {
                // Modify each character, one by one, in the current word.
                for(size_t i = 0; i < L; ++i) {
                    char oc = word[i];

                    // Check if substituting the character at index i with letters 'a' thru 'z'
                    // produces a new word that is contained in the word set. If it exists in the
                    // word set, enqueue it onto the next check list and remove it from the word
                    // set to prevent cycles.
                    for(char c = 'a'; c <= 'z'; ++c) {
                        word[i] = c;

                        if(oc == c || words.count(word) == 0) continue;

                        if(word == endWord) {
                            return step + 1;
                        }

                        words.erase(word);
                        next_list.emplace_back(word);
                    }

                    word[i] = oc;
                }
            }

            step++;
        }

        return 0;
    }
};
