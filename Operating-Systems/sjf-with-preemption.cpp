// SRTF / SJF with preemption
#include <iostream>
#include <climits>
using namespace std;
class process
{
public:
    int at, bt, tat, wt, completion;
};
int main()
{
    int n;
    cout << "enter the number of processes: ";
    cin >> n;
    process *p = new process[n];
    cout << "enter the arrival time of the processes: ";
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].at;
    }
    cout << "enter the burst time of the processes: ";
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].bt;
    }
    int burst[n];
    for (int i = 0; i < n; i++)
    {
        burst[i] = p[i].bt;
    }
    int i = 0, shortest = 0, minimum = INT_MAX;
    bool found = false;
    int time = 0;
    while (i != n)
    {
        for (int j = 0; j < n; j++)
        {
            if (p[j].at <= time && burst[j] < minimum && burst[j] > 0)
            {
                shortest = j;
                minimum = burst[j];
                found = true;
            }
        }
        if (found ==false)
        {
            time++;
            continue;
        }
        burst[shortest]--;
        minimum = burst[shortest];
        if (minimum == 0)
        {
            p[shortest].completion=time+1;
            p[shortest].tat=p[shortest].completion-p[shortest].at;
            p[shortest].wt=p[shortest].tat-p[shortest].bt;
            found=false;
            minimum=INT_MAX;
            i++;
            if(p[shortest].wt < 0)
            {
                p[shortest].wt=0;
            }
        }
        time++;
    }
    double tat_total=0,wat_total=0,tat_avg,wat_avg;
    for (int j = 0; j < n; j++)
    {
        tat_total+=p[j].tat;
        wat_total+=p[j].wt;
    }
    tat_avg=tat_total/n;
    wat_avg=wat_total/n;
    cout << "Average Wait time: " << wat_avg << endl << "Average Turn Around Time: "<<tat_avg<< endl ;
    return 0;
}
