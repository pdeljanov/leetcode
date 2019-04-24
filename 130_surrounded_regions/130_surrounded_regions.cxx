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

#include <tuple>
#include <vector>

using namespace std;

class Solution {
public:

    using CheckList = stack<tuple<int,int>, vector<tuple<int,int>>>;
    using Row = vector<char>;
    using Board = vector<Row>;

    // Adds the cells adjacent to x,y to the check list.
    void checkNeighbours(CheckList& list, Board& board, int x, int y) {
        if(x > 0) {
            list.push(make_tuple(x-1, y));
        }
        if(x < board[y].size()-1) {
            list.push(make_tuple(x+1, y));
        }
        if(y > 0) {
            list.push(make_tuple(x, y-1));
        }
        if(y < board.size()-1){
            list.push(make_tuple(x, y+1));
        }
    }

    // Marks a cell at x,y and queues adjacent cells to the check list.
    void mark(CheckList& list, Board& board, int x, int y) {
        board[y][x] = '-';
        checkNeighbours(list, board, x, y);
    }

    // Marks all 'O' cells on the edge of the board.
    void markEdgeCells(CheckList& list, Board& board) {
        for(int x = 0; x < board[0].size(); ++x){
            if(board[0][x] == 'O')
                mark(list, board, x, 0);
        }

        int my = board.size()-1;
        for(int x = 0; x < board[my].size(); ++x){
            if(board[my][x] == 'O')
                mark(list, board, x, my);
        }

        for(int y = 0; y < board.size(); ++y) {
            if(board[y][0] == 'O')
                mark(list, board, 0, y);
        }

        for(int y = 0; y < board.size(); ++y) {
            int mx = board[y].size()-1;
            if(board[y][mx] == 'O')
                mark(list, board, mx, y);
        }
    }

    void solve(vector<vector<char>>& board) {

        if(board.size() == 0) return;

        // List of cells which were touching cells that were marked as touching an edge.
        CheckList list;

        // Mark edge cells that are 'O's and add adjacent cells to the list.
        markEdgeCells(list, board);

        while(!list.empty()) {
            auto item = list.top();
            list.pop();

            int x = get<0>(item);
            int y = get<1>(item);

            // The cell at x,y were touching a cell that touched an edge and is an O, therefore
            // the cell at x,y must also be marked.
            if(board[y][x] == 'O') {
                mark(list, board, x, y);
            }
        }

        for(int y = 0; y < board.size(); ++y) {
            for (int x = 0; x < board[y].size(); ++x) {
                if(board[y][x] == '-') {
                    board[y][x] = 'O';
                }
                else if(board[y][x] == 'O') {
                   board[y][x] = 'X';
                }
            }
        }

    }

};
