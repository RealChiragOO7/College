#include<iostream>
using namespace std;
#define max 30

int main()
{
    int i,j,n,bt[max],at[max],wt[max],tat[max],temp[max];

    float awt = 0, atat = 0;

    // Take input of number of processes from user
    cout << "Enter the number of processes: ";
    cin >> n;

    cout << "Enter the burst time of processes: ";
    for(i = 0; i < n; i++)
        cin >> bt[i];

    cout << "Enter the arrival time of processes: ";
    for(i = 0; i < n; i++)
        cin >> at[i];

    temp[0] = 0;

    cout << "Process\t   Burst Time\t Arrival Time\t Waiting Time\t  Turn Around Time" << endl;
     
    for(i = 0; i < n; i++)
    {
        wt[i] = 0;
        tat[i] = 0;
        temp[i+1] = temp[i] + bt[i];
        wt[i] = temp[i] - at[i];

        if(wt[i]<0) // Initially wait time for process 1 is 0
            wt[i]=0;

        tat[i] = wt[i] + bt[i];
        awt = awt + wt[i];
        atat = atat + tat[i];
        cout << i+1 << "\t\t" << bt[i] << "\t\t" << at[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << endl;
    }
    awt = awt/n;
    atat = atat/n;
    cout << "Average Wait time: " << awt << endl << "Average Turn Around Time: " << atat;
    return 0;
}