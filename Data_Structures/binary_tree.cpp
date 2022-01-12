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

int n;

void insertBT(int arr[], struct node** root, int i)
{
    if (i < n)
    {
        struct node *temp = create_node(arr[i]);
        *root = temp;
        insertBT(arr, (&(*root)->left), 2 * i + 1);
        insertBT(arr, (&(*root)->right), 2 * i + 2);
    }
}

int height(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (height(root->left) < height(root->right))
    {
        return height(root->right) + 1;
    }
    return height(root->left) + 1;
}


int main(){

    //here goes your code

    return 0;
}