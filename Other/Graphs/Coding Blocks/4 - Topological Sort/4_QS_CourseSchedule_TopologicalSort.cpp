// 4_QS_CourseSchedule_TopologicalSort.cpp

#include <bits/stdc++.h>
using namespace std;

class Solution {
	map<int,list<int>> adjList;
public:
    bool canFinish(int numCourses, vector<vector<int>> prerequisites) {
        // here numCourses -> Vertices
        // prerequisites -> Directed EdgeList
        // for(auto el : )
    }
};

int main() {
	Solution S;
	cout<<S.canFinish(2,{{1,0}});

	return 0;
}