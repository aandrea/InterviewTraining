#include <bits/stdc++.h>
using namespace std;

/*
Sample Input

7
5 8 1 3 7 9 2

Sample Output

2 3
1 2 3
7 8 9
1 2 3 5 7 8 9

*/
void quickSort(vector <int> &arr) {
    if(arr.size()<2)
    {
        return;
    }
    
    int pivot = arr[0];
    vector<int> left;
    vector<int> right;
    for(int i =1; i< arr.size(); ++i)
    {
      if(arr[i] <= pivot)
      {
          left.push_back(arr[i]);
      }
      else
      {
          right.push_back(arr[i]);
      }
    }
    quickSort(left);
    quickSort(right);
  
      
    int iArr= 0;
    for (int iL = 0; iL < left.size(); ++iL)
    {
        cout <<left[iL] << " ";
        arr[iArr]= left[iL];
        iArr++;
    }
    
    cout<< pivot;
    arr[iArr]=pivot;
    iArr++;
    
    for (int iR = 0; iR < right.size(); ++iR)
    {
        cout << " "<<right[iR];
        arr[iArr]=right[iR];
        iArr++;
    }
    cout << endl;
}


int main()
{
    int n;
    cin >> n;

    vector <int> arr(n);
    for(int i = 0; i < (int)n; ++i) {
        cin >> arr[i];
    }
    quickSort(arr);

    return 0;
}

