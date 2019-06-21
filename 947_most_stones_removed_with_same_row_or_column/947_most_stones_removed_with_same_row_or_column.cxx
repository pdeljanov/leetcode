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

using <bitset>
using <stack>
using <vector>

using namespace std;

// A Disjoint-Set Union (DSU) data structure using path compression and union-by-size heuristic.
class dsu {
private:
    vector<int16_t> parent;

public:
    dsu(size_t n) : parent(n, -1) {}

    int16_t find(int16_t x) {
        // If the parent value is negative, then x is the root of the set, and the magnitude
        // of the value indicates the number of elements in the set.
        if(parent[x] < 0) {
            return x;
        }

        // Update the parent value of x on look-up for path compression.
        parent[x] = find(parent[x]);
        return parent[x];
    }

    void join(int16_t x, int16_t y) {
        // Get the root index for the sets that contain x and y.
        auto xi = find(x);
        auto yi = find(y);

        // If the roots of x and y are the same, then x and y are already part of the same set.
        if(xi == yi) {
            return;
        }

        // Merge the smallest set with the largest set. The roots of the sets that contain x and
        // y store the size of the set as a negative number in parent. Therefore the set root with
        // the most negative parent value is the largest set. Merge the smaller set into the larger
        // set.
        if(parent[yi] < parent[xi]) {
            parent[yi] += parent[xi];
            parent[xi] = yi;
        }
        else {
            parent[xi] += parent[yi];
            parent[yi] = xi;
        }
    }
};

class Solution {
public:

    // Method 1: Using a disjoint set union data structure to find the number of completely unrelated stone
    // islands. Completely unrelated islands are a group of stones in which no stone shares the same row or
    // column with any other island. If any stone shares the same row or column as a stone in another island,
    // those two islands are considered related and part of the same set.
    int removeStones(vector<vector<int>>& stones) {

        dsu unions(20000);

        for(const auto& stone : stones) {
            unions.join(stone[0], 10000 + stone[1]);
        }

        // Count the number of completely unrelated islands (disjoint sets).
        bitset<20000> unique;

        for(const auto& stone : stones) {
            unique.set(unions.find(stone[0]));
        }

        // Each completely unrelated island must have one stone remaining after all moves. Therefore, the maximum
        // number of moves is the number of stones minus the number of unrelated islands.
        return stones.size() - unique.count();
    }

    // Method 2: Same as Method 1, except using a graph traversal to count the number of stones in related islands
    // and then subtracting one after each traversal is complete.
    int removeStonesDFS(vector<vector<int>>& stones) {

        size_t N = stones.size();

        // Build an adjaceny list for all stones. Stones are considered adjacent to each other if they share the
        // same row or column.
        vector<vector<int>> graph(N);

        for(size_t i = 0; i < N; ++i) {
            for(size_t j = i + 1; j < N; ++j) {
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        int ans = 0;

        vector<bool> seen(N, false);

        // Traverse every disjoint graph of stones in the adjaceny list.
        for(size_t i = 0; i < N; ++i) {
            if(seen[i]) continue;

            seen[i] = true;

            stack<int> next;
            next.push(i);

            // Traverse every stone in the disjoint graph. Count the number of stones traversed.
            while(!next.empty()) {
                int stone = next.top();
                next.pop();

                for(int adjacent : graph[stone]) {
                    if(!seen[adjacent]) {
                        seen[adjacent] = true;
                        next.push(adjacent);
                    }
                }

                ++ans;
            }

            // There must be one stone left unremoved in each disjoint graph, so subtract one from the move count.
            --ans;
        }

        return ans;
    }

};
