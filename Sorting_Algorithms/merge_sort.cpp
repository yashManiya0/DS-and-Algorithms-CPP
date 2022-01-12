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

void merge_sort(int arr[], int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int mid = (start + end) / 2;
    merge_sort(arr, start, mid);
    merge_sort(arr, mid + 1, end);

    int left[mid + 1 - start];
    int right[end - mid];
    for (int i = start; i < mid + 1; i++)
    {
        left[i - start] = arr[i];
    }
    for (int i = mid + 1; i < end + 1; i++)
    {
        right[i - mid - 1] = arr[i];
    }
    
    int l = 0;
    int r = 0;
    int i = start;
    while (l < mid + 1 - start && r < end - mid)
    {
        if (left[l] > right[r])
        {
            arr[i] = right[r];
            i++;
            r++;
            if (r == end - mid && l < mid + 1 - start)
            {
                while (l < mid + 1 - start)
                {
                    arr[i] = left[l];
                    i++;
                    l++;
                }
                break;
            }
        }
        else
        {
            arr[i] = left[l];
            i++;
            l++;
            if (r < end - mid && l == mid + 1 - start)
            {
                while (r < end - mid)
                {
                    arr[i] = right[r];
                    i++;
                    r++;
                }
                break;
            }
        }
    }
}

int main(){

    // here goes your code

    return 0;
}