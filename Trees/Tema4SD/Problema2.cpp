#include <iostream>
#include <stack>
#include <vector>
#include <queue>
using namespace std;
#define COUNT 10

struct TreeNode
{   int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parinte;

    TreeNode(int data)
    {
        val = data;
        left = nullptr;
        right = nullptr;
    }
};
class BinaryTree {
public:
    TreeNode* root;

    void construct_tree(std::vector<int>valori, std::vector<int>nr)
    {
        int ultim_copil = nr[0];
        std::queue<TreeNode*>parinti;
        std::queue<TreeNode*>copii;
        root = new TreeNode(valori[0]);
       // parinti.push(root);
        if (nr[0] == 2)
        {
            TreeNode* elem = new TreeNode(valori[1]);
            TreeNode* elem1 = new TreeNode(valori[2]);
            root->left = elem;
            root->right = elem1;
            elem->parinte = root;
            elem1->parinte = root;
            parinti.push(elem);
            parinti.push(elem1);
            ultim_copil = 3;
        }
        if (nr[0] == 1)
        {
            TreeNode* elem = new TreeNode(valori[1]);
            root->left = elem;
            elem->parinte = root;
            parinti.push(elem);
            ultim_copil = 2;
        }
        if (nr[0] == -1)
        {
            TreeNode* elem = new TreeNode(valori[1]);
            root->right = elem;
            elem->parinte = root;
            parinti.push(elem);
            ultim_copil = 2;

        }
        for (int i = 1; i < nr.size()-1; i++)
        {
            /*if (i == 0) {
                root = new TreeNode(valori[i]);
                parinti.push(root);
            }*/
            if (parinti.empty())
            {
                while (!copii.empty())
                {
                    parinti.push(copii.front());
                    copii.pop();
                }
            }
            if (!parinti.empty()|| i==0)
            {
                
                if (nr[i] == 2) {
                    TreeNode* elem = new TreeNode(valori[ultim_copil]);
                    TreeNode* elem1 = new TreeNode(valori[ultim_copil + 1]);
                    TreeNode* parinte = parinti.front();
                    parinte->left = elem;
                    parinte->right = elem1;
                    elem->parinte = parinte;
                    elem1->parinte = parinte;
                    ultim_copil = ultim_copil + 2;
                    copii.push(elem);
                    copii.push(elem1);
                    parinti.pop();
                 
                  
                }
                if (nr[i] == 1)
                {
                    TreeNode* elem = new TreeNode(valori[ultim_copil]);
                    TreeNode* parinte = parinti.front();
                    parinte->left = elem;
                    elem->parinte = parinte;
                    ultim_copil++;
                    copii.push(elem);
                    parinti.pop();
                }
                if (nr[i] == -1)
                {
                    TreeNode* elem = new TreeNode(valori[ultim_copil]);
                    TreeNode* parinte = parinti.front();
                    parinte->right = elem;
                    elem->parinte = parinte;
                    ultim_copil++;
                    copii.push(elem);
                    parinti.pop();
                }
                if (nr[i] == 0)
                {
                    parinti.pop();
                }
            }
        }
    }
    void parcurgere_niveluri()
    {
        std::queue<TreeNode*>c;
        c.push(root);
        while (!c.empty())
        {
            TreeNode* elem = c.front();
            c.pop();
            cout << elem->val << "\n";
            if (elem->left != nullptr)
                c.push(elem->left);
            if (elem->right != nullptr)
                c.push(elem->right);
        }
    }
    int inaltime(int valoare)
    {
        int ok = 0;
        int height = -1;
        if (root == nullptr)
        {
            return -1;
        }
        std::queue<TreeNode*>q;
        if (root->val == valoare) ok = 1;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
               if(ok==1)
            {
                height++;
            }
            while (size > 0)
            { 
                size--;
                TreeNode* curr = q.front();
                if (curr->val == valoare)  ok = 1;
                q.pop();
                if (curr->left != nullptr)
                {
                    if (curr->left->val == valoare) ok = 1;
                    q.push(curr->left);
                }
                if (curr->right != nullptr)
                {
                    if (curr->right->val == valoare) ok = 1;
                    q.push(curr->right);
                }
            }
        }
        return height;
    }
    int adancime(int valoare)
    {
        int adancime = 0;
        if (root == nullptr)
        {
            return -1;
        }
        if (root->val== valoare) return adancime;
        std::queue<TreeNode*>q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            adancime++;
            while (size > 0)
            {
                size--;
                TreeNode* curr = q.front();
                if (curr->val == valoare) return adancime;
                q.pop();
                if (curr->left != nullptr)
                {
                    if (curr->left->val == valoare) return adancime;
                    q.push(curr->left);
                }
                if (curr->right != nullptr)
                {
                    if (curr->right->val == valoare) return adancime;
                    q.push(curr->right);
                }
            }
        }
        return adancime;

    }
    void frunze(TreeNode* root)
    {
        std::stack<TreeNode*>noduri;
        std::stack<TreeNode*>frunze;
        if (root == nullptr)
        {
            exit(1);
        }
        noduri.push(root);
        while (!noduri.empty())
        {
            TreeNode* elem = noduri.top();
            noduri.pop();
            if (elem->left != nullptr)
            {
                noduri.push(elem->left);
            }
            if (elem->right != nullptr)
            {
                noduri.push(elem->right);
            }
            if (elem->left == nullptr && elem->right == nullptr)
            {
                frunze.push(elem);
            }
        }
        while (!frunze.empty())
        {
            std::cout << frunze.top()->val << " ";
            frunze.pop();
        }



    }
    void print_tree(TreeNode* root, int space = 0, int height = 10)
    {
        if (root == nullptr)
        {
            return;
        }
        space += height;
        print_tree(root->right, space);
        std::cout << std::endl;
        for (int i = height; i < space; i++)
        {
            std::cout << " ";
        }
        std::cout << root->val << std::endl;
        print_tree(root->left, space);
    }
};
int main()
{
    vector<int> inorder = { 21,9,7,3,1,4,6,11,15};
    vector<int> preorder = {2,2,1,0,1,2,0,0,0};
    BinaryTree A;
    A.construct_tree(inorder, preorder);
    A.print_tree(A.root,0,10);
    //A.parcurgere_niveluri();
    std::cout << A.inaltime(4) << "\n";
    std::cout << A.adancime(4);
    cout << endl;
    A.frunze(A.root);
    return 0;
}
