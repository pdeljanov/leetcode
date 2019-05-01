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

#include <vector>

using namespace std;

class Solution {
public:

    enum class State {
        Unvisited = 0,
        Visited,
        Recursing,
    };

    bool checkCycle(vector<vector<int>>& prereqs, vector<State>& states, int i) {
        // If the course is currently part of the recursion tree and is being checked again,
        // then a cycle is present.
        if(states[i] == State::Recursing) {
            return true;
        }
        // If the course is unvisited, the course pre-requisite(s) must be traversed to
        // detect cycles.
        else if(states[i] == State::Unvisited) {

            // Mark the course as part of the recursion tree.
            states[i] = State::Recursing;

            for(int prereq : prereqs[i]) {
                if(checkCycle(prereqs, states, prereq)) {
                    return true;
                }
            }

            // Course is no longer being recursed, but it is has been visited.
            states[i] = State::Visited;
        }

        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> prereqs(numCourses);
        vector<State> states(numCourses, State::Unvisited);

        // Convert edge-list to a sparse adjacency matrix.
        for(auto& pair : prerequisites) {
            int course = pair[0];
            int prereq = pair[1];
            prereqs[course].push_back(prereq);
        }

        // Check for cycles starting at the first course. If other courses are incidently visited
        // while checking a course, then those courses have been implicitly checked for cycles and
        // can be safely skipped.
        for(int i = 0; i < prereqs.size(); ++i) {
            if(states[i] == State::Visited) {
                continue;
            }

            if(checkCycle(prereqs, states, i)) {
                return false;
            }
        }

        return true;
    }
};
