#include<iostream>
using namespace std;
#define max 30

int main()
{
    int i,j,n,p[max],bt[max],wt[max],tat[max];
    float awt = 0, atat = 0;

    cout << "Enter the number of processes: ";
    cin >> n;

    cout << "Enter the process number: ";
    for(i = 0; i < n; i++)
        cin >> p[i];

    cout << "Enter the burst time of processes: ";
    for(i = 0; i < n; i++)
        cin >> bt[i];

    // applying bubble sort technique to sort according to their burst time
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(bt[j] > bt[j + 1])
            {
                int temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
    cout << "Process\t   Burst Time\t Waiting Time\t Turn Around Time" << endl;

    for(i = 0; i < n; i++)
    {
        wt[i] = 0;
        tat[i] = 0;
        for(j = 0; j < i; j++)
            wt[i] = wt[i] + bt[j];
        tat[i] = wt[i] + bt[i];
        awt = awt + wt[i];
        atat = atat + tat[i];
        cout << p[i] << "\t\t" << bt[i] <<"\t\t"<< wt[i] <<"\t\t" << tat[i] << endl;
    }
    awt = awt/n;
    atat = atat/n;
    cout << "Average Wait time: " << awt << endl << "Average Turn Around Time: " << atat;
    return 0;
}