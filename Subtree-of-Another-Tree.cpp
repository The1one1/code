class Solution {
public:
    bool fun(TreeNode *root, TreeNode *subRoot) {
        if (root == nullptr and subRoot == nullptr)  return true;
        else if (root == nullptr or subRoot == nullptr) return false;
        
        if (root->val == subRoot->val) {
            return (fun(root->left, subRoot->left) and fun(root->right, subRoot->right));
        }
        else return false;
    }

    bool isSubtree(TreeNode *root, TreeNode *subRoot) {
        if (root == nullptr or subRoot == nullptr) return false;

        bool flag = false;
        if (root->val == subRoot->val) {
            flag or_eq fun(root, subRoot);
        }

        if(flag != true) {
            return (isSubtree(root->left, subRoot) or isSubtree(root->right, subRoot));
        }
        return flag;
    }
};