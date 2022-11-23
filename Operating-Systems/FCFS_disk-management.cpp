#include <bits/stdc++.h>
using namespace std;

int fcfs (int *a, int n)
{
  int sum = 0;
  for (int i = 1; i < n; i++)
    {
      sum += abs (a[i] - a[i - 1]);
    }
  return sum;
}


int main()
{
    int n;
  cin >> n;

  int *a = new int[n];
  for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
  cout << fcfs(a,n);
    return 0;
}