#include <bits/stdc++.h>
using namespace std;

struct Queue
{
    int first = -1;
    int last = -1;
    int len = 5;
    int *arr;
};

struct Queue *
createQ()
{
    struct Queue *q = new Queue;
    q->first = q->last = -1;
    q->len = 5;
    q->arr = new int;
    return q;
}

void IB(struct Queue **Q, int x)
{
    struct Queue* q = *Q;
    if (q->last==0){
        cout<<"Dequeue Full"<<endl;
        return;
    }
    q->last = q->last + 1;
    for (int i=q->last;i>0;i--){
        q->arr[i]=q->arr[i-1];
    }
    q->arr[0]=x;
}

void IE(struct Queue **Q, int x)
{
    struct Queue* q = *Q;
    if (q->last==5){
        cout<<"Dequeue Full"<<endl;
        return;
    }
    q->last = q->last + 1;
    q->arr[q->last] = x;
}

void DB(struct Queue **Q)
{
    struct Queue* q = *Q;
    if (q->last==-1){
        cout<<"Dequeue Empty"<<endl;
        return;
    }
    cout<<q->arr[0]<<endl;
    for (int i=0;i<q->last;i++){
        q->arr[i]=q->arr[i+1];
    }
    q->last = q->last - 1;
}

void DE(struct Queue **Q)
{
    struct Queue* q = *Q;
    if (q->last==-1){
        cout<<"Dequeue Empty"<<endl;
        return;
    }
    cout<<(q->arr)[q->last]<<endl;
    q->last = q->last - 1;
}

void P(struct Queue *q)
{
    for(int i=0;i<q->last+1;i++){
        cout<<(q->arr)[i]<<" ";
    }
    cout<<endl;
}

int main(){

    //here goes your code
    
    return 0;
}