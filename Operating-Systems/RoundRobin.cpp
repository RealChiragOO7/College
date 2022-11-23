#include<iostream>
using namespace std;
#define max 50
int main()
{
    int n,i,qt,count = 0,temp,sq = 0,bt[max],wt[max],tat[max],rem_bt[max];
    float awt=0,atat=0;

    cout << "Enter the number of processes: ";
    cin >> n;

    cout << "Enter the burst time of processes: ";
    for(i = 0; i < n; i++)
    {
        cin >> bt[i];
        rem_bt[i] = bt[i];
    }
    cout << "Enter quantum time: ";
    cin >> qt;

    while(1)
    {
        for(i = 0,count = 0;i < n; i++)
        {
            temp = qt;
            if(rem_bt[i] == 0)
            {
                count++;
                continue;
            }
            if(rem_bt[i] > qt)
                rem_bt[i] = rem_bt[i] - qt;
            else    
                if(rem_bt[i] >= 0)
                {
                    temp = rem_bt[i];
                    rem_bt[i] = 0;
                }
                sq += temp;
                tat[i] = sq;
        }
        if(n == count)
            break;
    }
    cout << "Process\t   Burst Time\t Waiting Time\t Turn Around Time" << endl;
    for(i = 0; i < n; i++)
    {
        wt[i] = tat[i] - bt[i];
        awt += wt[i];
        atat += tat[i];
        cout << i+1 << "\t\t" << bt[i] <<"\t\t"<< wt[i] <<"\t\t" << tat[i] << endl;
    }
    awt = awt/n;
    atat = atat/n;
    cout << "Average Wait time: " << awt << endl << "Average Turn Around Time: " << atat;
    return 0;
}