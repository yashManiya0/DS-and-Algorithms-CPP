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

void insertion_sort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i;
        while (j > 0)
        {
            if (arr[j - 1] > arr[j])
            {
                int x = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = x;
            }
            j--;
        }
    }
}

int main(){

    // here goes your code

    return 0;
}