#include <iostream>
using namespace std;
int main() {
    int n;
    cout<<"Enter number of processes: ";
    cin>>n;
    int at[20], bt[20], ct[20], tat[20], wt[20];
    for(int i = 0; i < n; i++) {
        cout<<"Enter Arrival Time and Burst Time for P"<<i + 1<<": ";
        cin>>at[i]>>bt[i];
    }

    int time = 0;

    cout<<endl<<"Execution Order: ";
    for (int i = 0; i < n; i++) {
        cout<<"P"<<i+1;
        if (i != n-1) cout<<" -> ";
    }
    cout<<endl;

    for (int i = 0; i < n; i++) {
        if (time < at[i]) {
            time = at[i];
        }
        time += bt[i];
        ct[i] = time;
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    cout<<endl<<"FCFS Scheduling"<<endl;
    int sumWT = 0, sumTAT = 0;
    for (int i = 0; i < n; i++) {
        cout<<"P"<< i + 1<< ": "<<endl;
        cout<<"CT="<< ct[i]<<endl;
        cout<<"TAT="<< tat[i]<<endl;
        cout<<"WT="<< wt[i]<<endl;
        cout<<endl;
        sumWT += wt[i];
        sumTAT += tat[i];
    }
    cout<<"Avg WT = "<<(float)sumWT / n<<endl;
    cout<<"Avg TAT = "<<(float)sumTAT / n<<endl;

    return 0;
}





/*
Enter number of processes: 4
Enter Arrival Time and Burst Time for P1: 0 7
Enter Arrival Time and Burst Time for P2: 2 4
Enter Arrival Time and Burst Time for P3: 4 1
Enter Arrival Time and Burst Time for P4: 5 4

FCFS Scheduling
Execution Order: P1 -> P2 -> P3 -> P4

P1:
CT=7
TAT=7
WT=0

P2:
CT=11
TAT=9
WT=5

P3:
CT=12
TAT=8
WT=7

P4:
CT=16
TAT=11
WT=7

Avg WT = 4.75
Avg TAT = 8.75

*/
