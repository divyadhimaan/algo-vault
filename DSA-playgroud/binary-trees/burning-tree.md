# Burning Tree

Practice [Link](https://www.geeksforgeeks.org/problems/burning-tree/1)

Given a binary tree and a node data called target. Find the minimum time required to burn the complete binary tree if the target is set on fire. It is known that in 1 second all nodes connected to a given node get burned. That is its left child, right child, and parent.
Note: The tree contains unique values.
```cpp
class Solution {
  public:
  
    void generateGraph(unordered_map<int,vector<int>> &graph, Node* root)
    {
        if(!root)
            return;
            
        if(root->left){
            graph[root->data].push_back(root->left->data);
            graph[root->left->data].push_back(root->data);
            generateGraph(graph, root->left);
        }
        if(root->right){
            graph[root->data].push_back(root->right->data);
            graph[root->right->data].push_back(root->data);
            generateGraph(graph, root->right);
        }
        
        if(graph.find(root->data) == graph.end())
            graph[root->data] = {};
    }
  
    int minTime(Node* root, int target) {
        unordered_map<int,vector<int>> graph;
        generateGraph(graph, root);
        
        int time = -1;
        queue<int> q;
        unordered_set<int> visited;
        
        q.push(target);
        visited.insert(target);
        
        while(!q.empty())
        {
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                int curr = q.front();
                q.pop();
                
                for(int next: graph[curr])
                    if(visited.find(next)==visited.end()){
                        q.push(next);
                        visited.insert(next);
                    }
            }
            time++;
        }
        return time;
        
    }
};
```