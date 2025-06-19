# Course Schedule - II

There are a total of ```numCourses``` courses you have to take, labeled from ```0``` to ```numCourses - 1```. You are given an array ```prerequisites``` where ```prerequisites[i] = [ai, bi]``` indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.

Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.



Practice [Link](https://leetcode.com/problems/course-schedule-ii/description/)

## Using BFS - Kahn's Algo

### Approach

1. **Build the Adjacency List:**
			Represent the graph using an adjacency list where adj[bi] contains all courses ai that depend on bi
2.  **Compute In-Degree of Nodes:**
			Use an array inDegree where inDegree[i] represents the number of prerequisites (incoming edges) for course i.
3. **Find Nodes with Zero In-Degree:**
		Push all nodes with inDegree[i] == 0 into a queue. These are courses that can be taken immediately.
4. **Process the Nodes Using a Queue:**
		For each node processed:
				* Add it to the result list (ans).
				* Reduce the in-degree of its neighbors (dependent courses).
				* If any neighbor's in-degree becomes zero, push it into the queue.
5. **Check for Cycles:**
		If the size of the result list (ans) is not equal to numCourses, a cycle exists, and it's not possible to complete all courses.


### Implementation

Time Complexity: ```O(N+P)```, where N-> number of courses, P-> prerequisites

Space Complexity: ```O(N+P)```, for graph and queue

```cpp
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<prerequisites.size();i++)
        {
            int ai = prerequisites[i][0];
            int bi = prerequisites[i][1];

            adj[bi].push_back(ai);
        }

        vector<int> inDegree(numCourses);
        for(int i=0;i<adj.size();i++)
        {
            for(int j=0;j<adj[i].size();j++)
            {
                inDegree[adj[i][j]]++;
            }
        }

        queue<int> q;
        for(int i=0;i<inDegree.size();i++)
        {
            if(inDegree[i]==0)
                q.push(i);
        }

        vector<int> ans;
        while(!q.empty())
        {
            int currNode = q.front();
            q.pop();

            ans.push_back(currNode);

            for(auto nextNode: adj[currNode])
            {
                inDegree[nextNode]--;
                if(inDegree[nextNode]==0)
                    q.push(nextNode);
            }
        }

        if(ans.size()!= numCourses)
            return {};
        return ans;
    }
};
```