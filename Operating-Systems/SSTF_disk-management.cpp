#include <bits/stdc++.h>
using namespace std;

void bubbleSort_asc(int arr[], int n)
{
  int i, j;
  for(i = 0; i < n - 1; i++)

    // Last i elements are already in place
    for(j = 0; j < n - i - 1; j++)
      if(arr[j] > arr[j + 1])
	      swap (arr[j], arr[j + 1]);
}

int fcfs(int *a, int n)
{
  int sum = 0;
  for (int i = 1; i < n; i++)
    {
      sum += abs(a[i] - a[i - 1]);
    }
  return sum;
}

int shortest_seek(int *a, int n)
{
  bubbleSort_asc(a, n);
  return fcfs(a, n);
}

int shortestseekinitial(int *a,int n,int h){
	bubbleSort_asc(a,n);
	int sum=h-a[0];
	sum+=a[n-1]-a[0];
	return sum;
}

int main ()
{
  int n;
  cin >> n;

  int *a = new int[n];
  for(int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
  int h, total;
  cout << "enter head: ";
  cin >> h;
  cout << shortest_seek(a,n);
  //cout << shortestseekinitial(a,n,h);
  return 0;
}