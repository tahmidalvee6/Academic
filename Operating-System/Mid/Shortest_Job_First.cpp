#include <iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter number of processes: ";
    cin>>n;

    int at[20], bt[20];
    for(int i = 0; i < n; i++) {
        cout<<"Enter Arrival Time and Burst Time for P"<<i + 1<<": ";
        cin>>at[i]>>bt[i];
    }

    // Non-Preemptive SJF 
    int bt1[20], ct1[20], tat1[20], wt1[20];
    for (int i = 0; i < n; i++) {
        bt1[i] = bt[i];
    }

    int time1 = 0, finished1 = 0;
    while (finished1 < n) {
        int idx = -1, minBT = 9999;
        for (int i = 0; i < n; i++) {
            if (bt1[i] != -1 && at[i] <= time1 && bt1[i] < minBT) {
                minBT = bt1[i];
                idx = i;
            }
        }
        if (idx == -1) {
            time1++;
        } 
        else {
            time1 += bt1[idx];
            ct1[idx] = time1;
            tat1[idx] = ct1[idx] - at[idx];
            wt1[idx] = tat1[idx] - bt[idx];
            bt1[idx] = -1;
            finished1++;
        }
    }

    cout<<endl<<"Non-Preemptive SJF"<<endl;
    int sumWT1 = 0, sumTAT1 = 0;
    for (int i = 0; i < n; i++) {
        cout<<"P"<< i + 1<< ": "<<endl;
        cout<<"CT="<< ct1[i]<<endl;
        cout<<"TAT="<< tat1[i]<<endl;
        cout<<"WT="<< wt1[i]<<endl;
        cout<<endl;
        sumWT1 += wt1[i];
        sumTAT1 += tat1[i];
    }
    cout<<"Avg WT = "<<(float)sumWT1 / n<<endl;
    cout<<"Avg TAT = "<<(float)sumTAT1 / n<<endl;

    // -Preemptive SJF 
    int rt2[20], ct2[20], tat2[20], wt2[20];
    for (int i = 0; i < n; i++) {
        rt2[i] = bt[i];
    }

    int time2 = 0, finished2 = 0;
    while (finished2 < n) {
        int idx = -1, minRT = 9999;
        for (int i = 0; i < n; i++) {
            if (rt2[i] > 0 && at[i] <= time2 && rt2[i] < minRT) {
                minRT = rt2[i];
                idx = i;
            }
        }
        if (idx == -1) {
            time2++;
        } 
        else {
            rt2[idx]--;
            time2++;
            if (rt2[idx] == 0) {
                ct2[idx] = time2;
                tat2[idx] = ct2[idx] - at[idx];
                wt2[idx] = tat2[idx] - bt[idx];
                finished2++;
            }
        }
    }

    cout<<endl<<"Preemptive SJF"<<endl;
    int sumWT2 = 0, sumTAT2 = 0;
    for (int i = 0; i < n; i++) {
        cout<<"P"<< i + 1<< ": "<<endl;
        cout<<"CT="<< ct2[i]<<endl;
        cout<<"TAT="<< tat2[i]<<endl;
        cout<<"WT="<< wt2[i]<<endl;
        cout<<endl;
        sumWT2 += wt2[i];
        sumTAT2 += tat2[i];
    }
    cout<<"Avg WT = "<<(float)sumWT2 / n<<endl;
    cout<<"Avg TAT = "<<(float)sumTAT2 / n<<endl;

    return 0;
}




/*
Enter number of processes: 4
Enter Arrival Time and Burst Time for P1: 0 7
Enter Arrival Time and Burst Time for P2: 2 4
Enter Arrival Time and Burst Time for P3: 4 1
Enter Arrival Time and Burst Time for P4: 5 4

Non-Preemptive SJF
P1: 
CT=7
TAT=7
WT=0

P2: 
CT=12
TAT=10
WT=6

P3: 
CT=8
TAT=4
WT=3

P4: 
CT=16
TAT=11
WT=7

Avg WT = 4
Avg TAT = 8

Preemptive SJF
P1: 
CT=16
TAT=16
WT=9

P2: 
CT=7
TAT=5
WT=1

P3: 
CT=5
TAT=1
WT=0

P4: 
CT=11
TAT=6
WT=2

Avg WT = 3
Avg TAT = 7

*/
