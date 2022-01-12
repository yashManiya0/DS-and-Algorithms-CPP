#include <bits/stdc++.h>
using namespace std;

struct node
{
    int val;
    struct node *next = NULL;
};

struct node* create_node(int a){
    struct node* n = new node;
    n->val = a;
    n->next = NULL;
    return n;
}

void push(struct node **head, int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    struct node *last = *head;
    new_node->val = data;
    new_node->next = NULL;

    if (*head == NULL)
    {
        *head = new_node;
        return;
    }

    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = new_node;
}

void print_ll(struct node* head){
    struct node* temp = head;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){

    //here goes your code

    return 0;
}