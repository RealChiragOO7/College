#include <bits/stdc++.h>
using namespace std;

void bubbleSort_asc(int arr[], int n)
{
  int i, j;
  for(i = 0; i < n - 1; i++)

    // Last i elements are already in place
    for(j = 0; j < n - i - 1; j++)
      if(arr[j] > arr[j + 1])
	    swap(arr[j], arr[j + 1]);
}

void bubbleSort_dec(int arr[], int n)
{
  int i, j;
  for(i = 0; i < n - 1; i++)

    // Last i elements are already in place
    for(j = 0; j < n - i - 1; j++)
      if(arr[j] < arr[j + 1])
	    swap(arr[j], arr[j + 1]);
}


int fcfs(int *a, int n)
{
  int sum = 0;
  for(int i = 1; i < n; i++)
    {
      sum += abs(a[i] - a[i - 1]);
    }
  return sum;
}

int clook(int *a,int n,int head)
{
    int k=0;
    int *later = new int[n];
    int l = 0;
    int *first = new int[n];
    for(int i=0;i<n;i++)
    {
        if(a[i]>=head)
        {
            later[k++] = a[i];
        }
        else
        {
            first[l++] = a[i];
        }
    }
    bubbleSort_asc(later,k);
    bubbleSort_asc(first,l);
    int sum = later[0]-head;
    sum += fcfs(later,k);
    sum += later[k-1]-first[0];
    sum += fcfs(first,l);
    return sum;
}

int main()
{
  int n;
  cout<<"enter n: ";
  cin >> n;

  int *a = new int[n];
  cout<<"enter array elements:";
  for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }

  int h, total;
  cout<<"enter head:";
  cin >> h;
  cout << clook (a, n, h);


  return 0;
}