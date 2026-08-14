class BSTIterator {
public:
    stack<TreeNode*> st;
    bool isReverse;

    BSTIterator(TreeNode* root, bool reverse) {
        isReverse = reverse;
        PushAll(root);
    }

    int next() {
        TreeNode* node = st.top();
        st.pop();

        if (isReverse) {
            PushAll(node->left);
        }
        else {
            PushAll(node->right);
        }

        return node->val;
    }

    bool hasNext() {
        return !st.empty();
    }

    void PushAll(TreeNode* root) {
        while (root != NULL) {
            st.push(root);

            if (isReverse) {
                root = root->right; 
            }
            else {
                root = root->left;  
            }
        }
    }
};


class Solution {
public:
    bool findTarget(TreeNode* root, int k) {

        BSTIterator left(root, false); 
        BSTIterator right(root, true); 

        int i = left.next();
        int j = right.next();

        while (i < j) {

            if (i + j == k)
                return true;

            else if (i + j < k) {
                if (!left.hasNext())
                    break;

                i = left.next();
            }

            else {
                if (!right.hasNext())
                    break;

                j = right.next();
            }
        }

        return false;
    }
};