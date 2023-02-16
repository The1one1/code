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

    int dfs(TreeNode* root, vector<tuple<int, int, int, TreeNode*>> &v) {
        if(root == nullptr) return 0;
        int l = dfs(root -> left, v);
        int r = dfs(root -> right, v);
        v.push_back({l , r, root -> val, root});
        return l + r + root -> val;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<tuple<int, int, int, TreeNode*>> v;
        dfs(root, v);
        map<tuple<int, int, int>, pair<int, TreeNode*>> m;
        
        for(auto kl: v) {
            int x, y, z, w;
            tie(x, y, z, w) = kl;
            m[{x, y, z}] = {m[{x, y, z}].first + 1, w};
        }
        vector<TreeNode*> ans;

        for(auto x: m) {
            if(x.second.first > 1) ans.push_back(x.second.second);
            // if(x.second > 1) {
            //     // ans.push_back(new TreeNode(get<2>(x.first)));
            //     // ans.push_back(new TreeNode(get<2>(x.first), new TreeNode(get<0>(x.first)), new TreeNode(get<1>(x.first))));
            //     int x, y, z;
            //     tie(x, y, z) = x.first;
            //     ans.push_back()
            // }
        }
        return ans;
    }
};