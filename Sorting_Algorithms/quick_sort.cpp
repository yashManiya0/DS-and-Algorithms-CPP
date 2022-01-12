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

void quick_sort(int arr[],int start,int end){
    if (start>=end){
        return;
    }
    int i=start-1;
    for (int j=start;j<end;j++){
        if (arr[j]<arr[end]){
            i++;
            int x = arr[i];
            arr[i]=arr[j];
            arr[j]=x;
        }
    }
    int x = arr[i+1];
    arr[i+1]=arr[end];
    arr[end]=x;

    int piv = i+1;
    quick_sort(arr,start,piv-1);
    quick_sort(arr,piv+1,end);
}

int main(){

    // here goes your code

    return 0;
}