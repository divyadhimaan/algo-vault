# Course Schedule - IV

There are a total of ```numCourses``` courses you have to take, labeled from ```0``` to ```numCourses - 1```. You are given an array prerequisites where ```prerequisites[i] = [ai, bi] ```indicates that you must take course ```ai``` first if you want to take course ```bi```.

For example, the pair [0, 1] indicates that you have to take course 0 before you can take course 1.

Prerequisites can also be **indirect**. If course a is a prerequisite of course b, and course b is a prerequisite of course c, then course a is a prerequisite of course c.

You are also given an array ```queries``` where ```queries[j] = [uj, vj]```. For the jth query, you should answer whether course uj is a prerequisite of course vj or not.

Return a boolean array ```answer```, where answer[j] is the answer to the jth query.



Practice [Link](https://leetcode.com/problems/course-schedule-iv/description/)

## Using DFS

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

Time Complexity: ```O(Q *(N+P))```, where Q-> number of queries, N -> number of courses, P-> prerequisites

Space Complexity: ```O(N+P)```, for graph and queue

```cpp
class Solution {
public:

    bool findDest(vector<vector<int>> &adjList, vector<bool> &vis, int source, int dest)
    {
        if(source == dest)
            return true;

        if(vis[source])
            return false;

        vis[source] = true;

        for(auto next: adjList[source])
        {
            if(findDest(adjList, vis, next, dest))
                return true;
        }
        return false;
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<bool> result(queries.size(), false);
        if(prerequisites.size()==0){
            return result;
        }

        vector<vector<int>> adjList(numCourses);
        for(int i=0;i<prerequisites.size();i++)
        {
            int ai = prerequisites[i][0];
            int bi = prerequisites[i][1];

            adjList[ai].push_back(bi);
        }

        for(int i=0;i<queries.size();i++)
        {
            vector<bool> vis(numCourses);
            int source = queries[i][0];
            int dest = queries[i][1];

            if(findDest(adjList, vis, source, dest))
                result[i]= true;
        }

        return result;         
    }
};
```