#include <bits/stdc++.h>
using namespace std;

struct node{
  int val;
  struct node* left;
  struct node* right;
};

struct node* create_node(int i){
  struct node* n = new node();
  n->val = i;
  n->left = NULL;
  n->right= NULL;
  return n;
}

void insert(struct node **tree, int x)
{
    struct node* root = *tree;
    if (root == NULL)
    {
        root = create_node(x);
        *tree = root;
        return;
    }
    if (x > (root->val))
    {
        insert(&(root->right), x);
    }
    else if (x < (root->val))
    {
        insert(&(root->left), x);
    }
}

void Preorder(struct node* node)
{
    if (node == NULL)
        return;
    cout<< node->val<<" ";
    Preorder(node->left);
    Preorder(node->right);
}

bool isleaf(struct node *root){
    if (root->left==NULL && root->right==NULL){
        return true;
    }
    return false;
}

int main(){

    //here goes your code

    return 0;
}