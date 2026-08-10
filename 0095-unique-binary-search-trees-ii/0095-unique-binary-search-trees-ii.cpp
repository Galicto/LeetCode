class Solution {
public:
    vector<TreeNode*> generate(int l, int r) {
        if (l > r) return {nullptr};

        vector<TreeNode*> ans;

        for (int root = l; root <= r; root++) {
            vector<TreeNode*> left = generate(l, root - 1);
            vector<TreeNode*> right = generate(root + 1, r);

            for (auto L : left) {
                for (auto R : right) {
                    TreeNode* node = new TreeNode(root);
                    node->left = L;
                    node->right = R;
                    ans.push_back(node);
                }
            }
        }

        return ans;
    }

    vector<TreeNode*> generateTrees(int n) {
        return generate(1, n);
    }
};