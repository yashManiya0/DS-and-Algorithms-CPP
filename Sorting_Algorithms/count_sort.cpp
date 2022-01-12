#include <bits/stdc++.h>
using namespace std;

void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void count_sort(int arr[],int n, int k){
    int count[k+1]={0};
    for (int i=0;i<n;i++){
        count[arr[i]]++;
    }
    for (int i=1;i<k+1;i++){
        count[i]+=count[i-1];
    }
    int ans[n];
    for (int i=n-1;i>-1;i--){
        ans[count[arr[i]]-1]=arr[i];
        count[arr[i]]--;
    }
    for (int i=0;i<n;i++){
        arr[i]=ans[i];
    }
}

int main(){

    // here goes your code

    return 0;
}