#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;                           // array size;

    int arr[n];
    for(int i=0; i<n; i++)
        arr[i] = rand()%100;            // mod with 100 for taking 2 digit value by random;

    cout << "Before Sorting: ";
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";          // output before sorting;

    // Selection Sort Start

    int pos, cur, temp;                 // pos = position, cur = current;

    for(pos=0; pos<n; pos++){
        temp = n-1;

        for(cur=n-2; cur>=pos; cur--){
            if(arr[temp] > arr[cur])
                temp = cur;
        }
        swap(arr[temp], arr[pos]);      //swapping min value to the left most;
    }

    // End of Sorting

    cout << endl << "After Sorting: ";
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";          // output after sorting;

    cout << endl;

    return 0;
}
