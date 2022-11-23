#include<iostream>
using namespace std;
#define max 30

int main()
{
    int n,i,j,t,k=1,b=0,min,temp[max],bt[max],wt[max],at[max],pr[max],tat[max];
    float awt = 0, atat = 0;
    cout << "Enter the number of processes: ";
    cin >> n;

    cout << "Enter the burst time, arrival time and priority of processes: ";
    for(i = 0; i < n; i++)
        cin >> bt[i] >> at[i] >> pr[i];

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(at[i] < at[j])
            {
                t = at[j];
                at[j] = at[i];
                at[i] = t;

                t = bt[j];
                bt[j] = bt[i];
                bt[i] = t;
            }
        }
    }
    for(j = 0; j < n; j++)
    {
        b += bt[j];
        min = bt[k];
        for(i = k; i < n; i++)
        {
            min = pr[k];
            if(b >= at[i])
            {
                t = at[k];
                at[k] = at[i];
                at[i] = t;

                t = bt[k];
                bt[k] = bt[i];
                bt[i] = t;

                t = pr[k];
                pr[k] = pr[i];
                pr[i] = t;
            }
        }
        k++;
    }
    temp[0] = 0;
    cout << "Process\t   Burst Time\t Arrival Time\t   Priority\t  Waiting Time\t Turn Around Time" << endl;
    for(i = 0; i < n; i++)
    {
        wt[i] = 0;
        tat[i] = 0;
        temp[i+1] = temp[i] + bt[i];
        wt[i] = temp[i] - at[i];
        tat[i] = wt[i] + bt[i];
        awt += wt[i];
        atat += tat[i];
        cout << i+1 << "\t\t" << bt[i] <<"\t\t" << at[i] << "\t\t" << pr[i] << "\t\t" << wt[i] <<"\t\t" << tat[i] << endl;
    }
    awt = awt/n;
    atat = atat/n;
    cout << "Average Wait time: " << awt << endl << "Average Turn Around Time: " << atat;
    return 0;
}