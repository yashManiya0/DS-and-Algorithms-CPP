#include <bits/stdc++.h>
using namespace std;

struct Queue{
    struct node* first = NULL;
    struct node* last = NULL;
    int len = 0;
};

struct Queue* createQ(){
    struct Queue* q = new Queue;
    q->first = NULL;
    q->last = NULL;
    q->len = 0;
    return q;
}

void enqueue(struct Queue **Q,int x){
    struct node* new_node = new node;
    new_node->val = x;
    new_node->next = NULL;
    if ((*Q)->last==NULL){
        (*Q)->first = new_node;
        (*Q)->last = new_node;
        return;
    }
    (*Q)->last->next = new_node;
    (*Q)->last = new_node;
}

void dequeue(struct Queue **q)
{
    if ((*q)->first == NULL)
    {
        return;
    }
    (*q)->len -= 1;
    cout << (*q)->first->val << endl;
    (*q)->first = (*q)->first->next;
}

void printQ(struct Queue *Q)
{
    struct node *start = Q->first;
    while (start != NULL)
    {
        int x = start->val;
        cout << x << " ";
        start = start->next;
    }
    cout << endl;
}

int main(){

    //here goes your code

    return 0;
}