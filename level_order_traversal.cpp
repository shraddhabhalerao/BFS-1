// BFS
// time O(N)
// space O(N)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == nullptr)
        {
            return result;
        }

        queue<TreeNode*> q;
        q.push(root);

        int level = 0;

        while(q.empty() == false)
        {
            level++;
            int q_size = q.size();
            if(result.size() < level )
            {
                result.push_back({});
            }

            for(int i = 0; i < q_size; i++)
            {
                TreeNode* node = q.front();
                result[level -1].push_back(node->val);
                if(node->left != nullptr)
                {
                    q.push(node->left);
                }
                if(node->right != nullptr)
                {
                    q.push(node->right);
                }
                q.pop();
            }
        }

        return result;
        
    }
};



// DFS 

// time : o(N)
// space : O(N)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> levelOrder(TreeNode* root) {
        dfs(root, 0);
        return result;
    }

    void dfs(TreeNode* node, int level)
    {
        // base
        if(node == nullptr)
        {
            return;
        }

        // logic

        if(result.size() < level + 1)
        {
            result.push_back({});
        }

        dfs(node->left, level+1);
        dfs(node->right, level+1);
        result[level].push_back(node->val);

    }

};