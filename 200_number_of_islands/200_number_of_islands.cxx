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

#include <stack>
#include <tuple>
#include <vector>

using namespace std;

class Solution {
public:

    using Grid = vector<vector<char>>;
    using Coord = tuple<int, int>;
    using CheckList = stack<Coord, vector<Coord>>;

    void traverseIslandBFS(Grid& grid, Coord initial) {
        // CheckList will never grow beyond the total number of grid elements, so to prevent
        // incremental allocations and slow-downs, one could preallocate a vector in the parent
        // function and pass a reference to this function. Then using emplace_back pop_back, use
        // it as a stack and avoid allocations. Would waste memory though.
        CheckList to_check;

        to_check.push(initial);

        while(!to_check.empty()) {
            auto coord = to_check.top();
            to_check.pop();

            int x = get<0>(coord);
            int y = get<1>(coord);

            if(grid[y][x] == '1') {
                grid[y][x] = '0';

                if(x > 0) {
                    to_check.emplace(x-1, y);
                }
                if(x < grid[y].size()-1) {
                    to_check.emplace(x+1, y);
                }
                if(y > 0) {
                    to_check.emplace(x, y-1);
                }
                if(y < grid.size()-1) {
                    to_check.emplace(x, y+1);
                }
            }

        }
    }

    void traverseIslandDFS(Grid& grid, int x, int y) {
        if(grid[y][x] == '1') {
            grid[y][x] = '0';
            if(x > 0) {
                traverseIslandDFS(grid, x-1, y);
            }
            if(x < grid[y].size()-1) {
                traverseIslandDFS(grid, x+1, y);
            }
            if(y > 0) {
                traverseIslandDFS(grid, x, y-1);
            }
            if(y < grid.size()-1) {
                traverseIslandDFS(grid, x, y+1);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;

        for(int y = 0; y < grid.size(); ++y) {
            for(int x = 0; x < grid[y].size(); ++x) {
                if(grid[y][x] == '1') {
                    // BFS uses more memory and is marginally slower, but a DFS is likely to
                    // overflow the stack with bigger grids. Since LeetCode uses a small test
                    // case, use a DFS.
                    //
                    // traverseIslandBFS(grid, make_tuple(x, y));
                    traverseIslandDFS(grid, x, y);
                    ++islands;
                }
            }
        }

        return islands;
    }

};
