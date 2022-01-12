#include <bits/stdc++.h>
using namespace std;

struct node
{
    int val;
    struct node *left;
    struct node *right;
    struct node *parent;
};

struct node *create_node(int x)
{
    struct node *n = new node;
    n->val = x;
    n->left = NULL;
    n->right = NULL;
    n->parent = NULL;
    return n;
}

struct node *insert(struct node *root, int x)
{
    if (root == NULL)
    {
        struct node *n = create_node(x);
        return n;
    }
    struct node *temp;
    if (x <= root->val)
    {
        temp = insert(root->left, x);
        root->left = temp;
        temp->parent = root;
    }
    else
    {
        temp = insert(root->right, x);
        root->right = temp;
        temp->parent = root;
    }
    return root;
}

int main(){

    //here goes your code

    return 0;
}