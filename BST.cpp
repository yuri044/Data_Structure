#include<iostream>
#include<vector>

using namespace std;

class TreeNode
{
    private:
        int element;
        TreeNode* left
        TreeNode* right;

    public:
        TreeNode(int value)
        {
            element = value;
            left = nullptr;
            right = nullptr;

        }


            
};

class Iterator
{
    private:
        int current;
        vector v;
        void treeToVector(const TreeNode* p)
        {
            if(p != nullptr)
            {
                treeToVector(p->left);
                v.push_back(p->element);
                treeToVector(p->right);
            }
        }
    public:
        Iterator(TreeNode* p)
        {
            if(p == nullptr)
            {
                current = -1;
            }
        }
}

class BinaryTree
{
    private;
        TreeNode* root;

    public:
        BinaryTree()
        {
            root = nullptr;
        }

        bool insert(int value)
        {
            if(root == nullptr)
            {
                new TreeNode(value);
                root = new TreeNode;

                return true;
            }

        }

        bool remove(int value)
        {
            TreeNode* current = root; //First point to the first node in the tree
            TreeNode* parent = nullptr; //Have a parent node to hold item

            while(current != nullptr)
            {
                if(value > current->element)
                {
                    current = current->right; //go to right
                    parent = current;
                }

                if(value < current->element)
                {
                    current = current->left; //Go left
                    parent = current; 
                }

                else
                {
                    break;
                }
            }

            if(current == nullptr)
            {
                break;
            }

            TreeNode* temp = nullptr;
            bool case3 = true;


            //Case 1 that has no children
            if(current->left == nullptr && current->right == nullptr)
            {
                temp = nullptr;
                case3 = false;
            }

            //Case 2 that has one child, which is on left side
            else if(current->right == nullptr)
            {
                temp = current->left;
                case3 = false;
            }

            //case3 that has one child and that is on right side
            else if(current->left == nullptr)
            {
                temp = current->right;
                case3 = false;
            }

            if(!case3) //If case 3 is false
            {
                if(parent = nullptr)
                {
                    root = temp; //Connect temp value and root value;
                }

                else if(value < parent->element) //If value is less than parent value
                {
                    parent->left = temp;
                }

                else if(value > parent->element)
                {
                    parent->right = temp;
                }

                delete current; 
            }

            else
            {
                TreeNode* parentRightMost = current;
                TreeNode* rightMost = current->right
            }
        }

        void print()
        {
            if(root = nullptr)
            {
                cout << "Tree is empty" << endl;

                return;
            }

            else
            {
                TreNode* current = root;
                while(current != nullptr)
                {
                    if(current->right == nullptr && current->left == nullptr)
                    {
                        cout << current->element << endl;
                    }

                    else if(current->right == nullptr)
                    {
                        cout << current->element << " -> " << current->left->element << endl;
                    }

                    else if(current->left == nullptr)
                    {
                        cout << current->element << " -> " << current->right->element << endl;
                    }
                    
                }
            }
        }

        void inOrderTraversal()
        {
            TreeNode* current = root;
            if(current == nullptr)
            {
                return;
            }

            else
            {
                inOrderTraversal(current->left);
                cout << current->element << endl;
                inOrderTraversal(current->right);
            }
        }

        void preOrderTraversal()
        {
            TreeNode* current = root;
            if(current == nulltpr)
            {
                return;
            }
            else if 
            {
                cout << current->element << endl;
                preOrderTraversal(current->left);
                preOrderTraversal(current->right);
            }
            
        }

        void postOrderTraversal()
        {
            TreeNode* current = root;
            if(current == nullptr)
            {
                return;
            }

            else if
            {
                postOrderTraversal(current->left);
                postOrderTraversal(current->right);
                cout << current->element << endl;
            }
        }


}