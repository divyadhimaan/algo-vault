# Course Schedule - I

There are a total of ```numCourses``` courses you have to take, labeled from ```0``` to ```numCourses - 1```. You are given an array ```prerequisites``` where prerequisites[i] = [ai, bi] indicates that you must take course ```bi``` first if you want to take course ```ai```.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return ```true``` if you can finish all courses. Otherwise, return ```false```.

Practice [Link](https://leetcode.com/problems/course-schedule/description/)

## DFS APPROACH

Time Complexity - ```O(N+E)```, where V is the total number of courses, E is the edges (dependencies)

Space Complexity - ```O(N) + O(N)```

```cpp
class Solution {
public:
    bool checkDFS(vector<vector<int>> &adj, vector<int> &coursesDone, vector<int> &coursesToDo,int currCourse)
    {
        coursesDone[currCourse]=true;
        coursesToDo[currCourse]=true;
        for(auto nextCourse: adj[currCourse])
        {
            if(coursesToDo[nextCourse])
                return true;
            else if(!coursesDone[nextCourse])
                if(checkDFS(adj, coursesDone, coursesToDo, nextCourse))
                    return true;

        }

        coursesToDo[currCourse]=false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<prerequisites.size();i++)
        {
            int ai = prerequisites[i][0];
            int bi = prerequisites[i][1];
            // bi -> ai
            adj[bi].push_back(ai);
        }

        vector<int> coursesDone(numCourses, false);
        vector<int> coursesToDo(numCourses, false);
        for(int i=0;i<numCourses;i++)
        {
            if(!coursesDone[i] && checkDFS(adj, coursesDone, coursesToDo,i))
                return false;
        }
        return true;

    }
};
```
## BFS - TOPOLOGICAL APPROACH

Time Complexity - ```O(N+E)```, where V is the total number of courses, E is the edges (dependencies)

Space Complexity - ```O(N) + O(N)```

```cpp
class Solution {
public:

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adjList(numCourses);
        for(int i=0;i<prerequisites.size();i++)
        {
            int ai = prerequisites[i][0];
            int bi = prerequisites[i][1];
            // bi -> ai
            adjList[bi].push_back(ai);
        }

        vector<int> inDegree(numCourses);
        for(int i=0;i<adjList.size();i++)
        {
            for(int j=0;j<adjList[i].size();j++)
            {
                inDegree[adjList[i][j]]++;
            }
        }


        queue<int> q;
        for(int i=0;i<inDegree.size();i++)
        {
            if(inDegree[i]==0)
                q.push(i);
        }

        int coursesDone = 0;
        while(!q.empty())
        {
            int currNode = q.front();
            q.pop();
            coursesDone++;

            for(auto nextNode: adjList[currNode])
            {
                inDegree[nextNode]--;
                if(inDegree[nextNode]==0)
                    q.push(nextNode);
            }
        }
        return coursesDone == numCourses;
    }
};
```

# Summary

| Approach                 | Strategy       | Time   | Space  | Handles Cycles? | Suitable for                        |
| ------------------------ | -------------- | ------ | ------ | --------------- | ----------------------------------- |
| BFS Topo Sort (Kahn’s)   | Indegree-based | O(V+E) | O(V+E) | ✅ Yes           | Course ordering, No cycle detection |
| DFS with Recursion Stack | DFS            | O(V+E) | O(V)   | ✅ Yes           | Cycle detection                     |
