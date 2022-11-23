#include<iostream>
using namespace std;
#define max 30

int main()
{
    int i,n,j,bt[max],wt[max],pr[max],tat[max],pos;
    float awt = 0, atat = 0;

    cout << "Enter the number of processes: ";
    cin >> n;

    cout << "Enter the burst time of processes: ";
    for(i = 0; i < n; i++)
        cin >> bt[i];

    cout << "Enter the priority time of processes: ";
    for(i = 0; i < n; i++)
        cin >> pr[i];

    for(i = 0; i < n; i++)
    {
        pos = i;
        for(j = i+1; j < n; j++)
        {
            if(pr[j] < pr[pos])
                pos = j;
        }
        int temp = pr[i];
        pr[i] = pr[pos];
        pr[pos] = temp;

        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;
    }
    wt[0] = 0;
    cout << "Process\t   Burst Time\t   Priority\t  Waiting Time\t Turn Around Time" << endl;
    for(i = 0; i < n; i++)
    {
        wt[i] = 0;
        tat[i] = 0;
        for(j = 0; j < i; j++)
        {
            wt[i] += bt[j];
        }
        tat[i] = wt[i] + bt[i];
        awt += wt[i];
        atat += tat[i];
        cout << i+1 << "\t\t" << bt[i] <<"\t\t" << pr[i] << "\t\t" << wt[i] <<"\t\t" << tat[i] << endl;
    }
    awt = awt/n;
    atat = atat/n;
    cout << "Average Wait time: " << awt << endl << "Average Turn Around Time: " << atat;
    return 0;
}