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

void push(struct node** head, int data)
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->val  = data;
    new_node->next = NULL;

    if (*head == NULL)
    {
       *head = new_node;
       return;
    } 
    
    new_node->next=*head;
    *head = new_node;
}

void pop(struct node** head){
    if (*head==NULL){
        return;
    }
    *head = (*head)->next;
}

void printstack(struct node* top){
    struct node* temp = top;
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