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
    int cnt[10]={0,};
    int ans=0;
    void dfs(TreeNode* node){
        cnt[node->val]++;
        if(node->left==nullptr && node->right==nullptr){
            int odds=0;
            for(int i=1; i<=9; i++)
                if(cnt[i]%2) odds++;
            if(odds<=1) ans++;
        }
        if(node->left!=nullptr)
            dfs(node->left);
        if(node->right!=nullptr)
            dfs(node->right);
        cnt[node->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        dfs(root);
        return ans;
    }
};