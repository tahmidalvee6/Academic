// Non preemptive 

#include <iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter number of processes: ";
    cin>>n;

    int at[20], bt[20], pr[20];
    for(int i = 0; i < n; i++) {
        cout<<"Enter Arrival Time, Burst Time and Priority for P"<<i + 1<<": ";
        cin>>at[i]>>bt[i]>>pr[i];
    }

    // Non-Preemptive Priority
    int bt1[20], ct1[20], tat1[20], wt1[20];
    int order1[20], orderCount1 = 0;
    for (int i = 0; i < n; i++) {
        bt1[i] = bt[i];
    }

    int time1 = 0, finished1 = 0;
    while (finished1 < n) {
        int idx = -1, minPR = 9999;
        for (int i = 0; i < n; i++) {
            if (bt1[i] != -1 && at[i] <= time1) {
                if (pr[i] < minPR || (pr[i] == minPR && at[i] < at[idx])) {
                    minPR = pr[i];
                    idx = i;
                }
            }
        }
        if (idx == -1) {
            time1++;
        } 
        else {
            order1[orderCount1++] = idx;
            time1 += bt1[idx];
            ct1[idx] = time1;
            tat1[idx] = ct1[idx] - at[idx];
            wt1[idx] = tat1[idx] - bt[idx];
            bt1[idx] = -1;
            finished1++;
        }
    }

    cout<<endl<<"Non-Preemptive Priority"<<endl;
    cout<<"Gantt Chart Order: ";
    for (int i = 0; i < orderCount1; i++) {
        cout<<"P"<<order1[i] + 1;
        if (i != orderCount1 - 1) {
            cout<<" -> ";
        }
    }
    cout<<endl<<endl;

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

    return 0;
}




/*
Enter number of processes: 6
Enter Arrival Time, Burst Time and Priority for P1: 3 5 2
Enter Arrival Time, Burst Time and Priority for P2: 2 4 1
Enter Arrival Time, Burst Time and Priority for P3: 5 1 3
Enter Arrival Time, Burst Time and Priority for P4: 4 7 4
Enter Arrival Time, Burst Time and Priority for P5: 1 6 3
Enter Arrival Time, Burst Time and Priority for P6: 0 2 5

Non-Preemptive Priority
Gantt Chart Order: P6 -> P2 -> P1 -> P5 -> P3 -> P4

P1: 
CT=11
TAT=8
WT=3

P2: 
CT=6
TAT=4
WT=0

P3: 
CT=18
TAT=13
WT=12

P4: 
CT=25
TAT=21
WT=14

P5: 
CT=17
TAT=16
WT=10

P6: 
CT=2
TAT=2
WT=0

Avg WT = 6.5
Avg TAT = 10.6667

*/
