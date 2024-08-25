// Time: O(V+E)
// Space: O(V+E)

// Notes:
// 1. Identify that this is a dependency graph
// 2. in order to figure out how many dependencies each course has, maintain a data structre in this case array
// 3. then simply do level order traversal on each course that becomes independent. 
// 4. If there is any dependency present, our queue will become empty but dependency structure 
// will still have dependecies in it

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        if(numCourses < 2 || prerequisites.empty() == true)
        {
            return true;
        }

        // build graph and dependency array
        unordered_map<int, vector<int>> graph;
        vector<int> dependency(numCourses,0);
        int count = 0;
        for(int i = 0; i < prerequisites.size(); i++)
        {
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            dependency[prerequisites[i][0]]++;
        }

        queue<int> q;
        for(int i = 0; i < dependency.size(); i++)
        {
            if(dependency[i] == 0)
            {
                q.push(i);
                count++;
            }
        }

        while(q.empty() == false)
        {
            int currCourse = q.front();
            q.pop();

            if(graph.contains(currCourse) == true)
            {
                for(int i = 0 ; i < graph[currCourse].size(); i++)
                {
                    dependency[graph[currCourse][i]]--;
                    if(dependency[graph[currCourse][i]] == 0)
                    {
                        q.push(graph[currCourse][i]);
                        count++;
                    }
                }
            }

        }

        if(count == numCourses)
        {
            return true;
        }

        return false;
        
    }
};