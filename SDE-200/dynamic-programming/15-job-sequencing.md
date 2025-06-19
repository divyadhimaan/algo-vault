# Job Sequencing

Practice [Link](https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1)


You are given three arrays: id, deadline, and profit, where each job is associated with an ID, a deadline, and a profit. Each job takes 1 unit of time to complete, and only one job can be scheduled at a time. You will earn the profit associated with a job only if it is completed by its deadline.

Your task is to find:

The maximum number of jobs that can be completed within their deadlines.
The total maximum profit earned by completing those jobs.




## Greedy Approach

We need to maximize the profit -> pick jobs with higer profits -> Sort based on profits
- create an array slots, size = maxDeadline given.
- start picking jobs with maxProfit and filling slots.
- Now if for a job with deadline x, slot is already filled -> check for all slots 0 -> x-1

```cpp
class Job {
    public:
    int id;
    int deadline;
    int profit;
};

class Solution {
  public:
    static bool cmp(Job a, Job b)
    {
        return a.profit > b.profit;
    }
  
    vector<int> JobSequencing(vector<int> &id, vector<int> &deadline,
                              vector<int> &profit) {
        int n = id.size();
        vector<Job> jobs;
        for(int i=0;i<n;i++)
        {
            Job j;
            j.id = id[i];
            j.deadline = deadline[i];
            j.profit = profit[i];
            jobs.push_back(j);
        }
        
        sort(jobs.begin(), jobs.end(), cmp);
        
        
        int maxDeadline = *max_element(deadline.begin(), deadline.end());
        vector<int> slots(maxDeadline+1,-1);
        
        int jobsCompleted=0, profitEarned=0;
        for(int i=0;i<n;i++)
        {
            for(int j=jobs[i].deadline;j>0;j--)
            {
                if(slots[j] == -1)
                {
                    slots[j] = j;
                    jobsCompleted++;
                    profitEarned += jobs[i].profit;
                    break;
                }
            }
            
        }
        return {jobsCompleted,profitEarned};
    }
};
```

> Time Complexity: O(nlogn) + O(mn), where m->maxDeadline
>
> Space Complexity: O(m)

## optimized Greedy with DSU

```cpp
class Job {
    public:
    int id;
    int deadline;
    int profit;
};

class Solution {
  public:
    static bool cmp(Job a, Job b)
    {
        return a.profit > b.profit;
    }
    
    int findAvailableSlot(vector<int> &parent, int slot) {
        if (parent[slot] == slot) return slot;
        return parent[slot] = findAvailableSlot(parent, parent[slot]);
    }
  
    vector<int> JobSequencing(vector<int> &id, vector<int> &deadline,
                              vector<int> &profit) {
        int n = id.size();
        vector<Job> jobs(n);
        for(int i=0;i<n;i++)
        {
            jobs[i] = {id[i], deadline[i], profit[i]};
        }
        
        sort(jobs.begin(), jobs.end(), cmp);
        
        
        int maxDeadline = *max_element(deadline.begin(), deadline.end());
        vector<int> slots(maxDeadline+1);
        for (int i = 0; i <= maxDeadline; i++) slots[i] = i;
        
        int jobsCompleted=0, profitEarned=0;
        for(int i=0;i<n;i++)
        {
            int availableSlot = findAvailableSlot(slots, min(maxDeadline, jobs[i].deadline));
            if (availableSlot > 0) {
                slots[availableSlot] = findAvailableSlot(slots, availableSlot - 1); 
                jobsCompleted++;
                profitEarned += jobs[i].profit;
            }
            
        }
        return {jobsCompleted,profitEarned};
    }
};
```

> Time Complexity: `O(nlogn)`, better performing for large `n`
>
> Space Complexity: `O(m)`

## Dp Approach

- Recursive DP with Memoization avoids redundant computations.
- Efficient for small N, but greedy methods are preferred for larger cases.
- Since constraints are large, we will avoid using this approach