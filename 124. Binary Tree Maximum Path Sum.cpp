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
    int helper(TreeNode* root, int& maxSum) {
        if(root==NULL)
            return 0;
        int leftSum=helper(root->left, maxSum);
        int rightSum=helper(root->right, maxSum);
        
        // never consider negetive path
        if(leftSum<0)
            leftSum=0;
        if(rightSum<0)
            rightSum=0;
        
        int sum= root->val + leftSum + rightSum;
        if(sum>maxSum)
            maxSum=sum;
        
        return root->val+max(leftSum, rightSum);
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxSum=INT_MIN;
        helper(root, maxSum);
        return maxSum;
    }
};