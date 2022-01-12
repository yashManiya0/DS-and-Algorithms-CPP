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

void cycle_sort(int arr[],int n){
    for (int i=0;i<n;i++){
        int curr = arr[i];
        while (1){
            int ix=i;
            for (int ii=i+1;ii<n;ii++){
                if (arr[ii]<curr){
                    ix++;
                }
            }
            swap(arr[ix],curr);
            if (ix==i){
                break;
            }
        }
    }
}

int main(){

    // here goes your code

    return 0;
}