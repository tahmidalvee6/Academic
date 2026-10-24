#include <iostream>
using namespace std;

int main() {
    int n, tq;
    cout<<"Enter number of processes: ";
    cin>>n;

    int at[20], bt[20], pr[20];
    for(int i = 0; i < n; i++) {
        cout<<"Enter Arrival Time, Burst Time and Priority for P"<<i + 1<<": ";
        cin>>at[i]>>bt[i]>>pr[i];
    }
    cout<<"Enter Time Quantum: ";
    cin>>tq;

    int rt[20], ct[20], tat[20], wt[20], rdy[20];
    int order[1000], cnt = 0;
    for (int i = 0; i < n; i++) {
        rt[i] = bt[i];
        rdy[i] = at[i] * 2;     // queue position key (arrivals get priority over requeued)
    }

    int time = 0, finished = 0;
    int cur = -1, qc = 0;       // current process and quantum used
    while (finished < n) {
        // quantum expired: put back in queue
        if (cur != -1 && rt[cur] > 0 && qc == tq) {
            rdy[cur] = time * 2 + 1;
            cur = -1;
        }
        // finished
        if (cur != -1 && rt[cur] == 0) {
            cur = -1;
        }
        // preemption by a higher priority process
        if (cur != -1) {
            for (int i = 0; i < n; i++) {
                if (rt[i] > 0 && at[i] <= time && pr[i] < pr[cur]) {
                    rdy[cur] = time * 2 + 1;
                    cur = -1;
                    break;
                }
            }
        }
        // pick next process: lowest priority number, then RR order
        if (cur == -1) {
            int best = -1;
            for (int i = 0; i < n; i++) {
                if (rt[i] > 0 && at[i] <= time) {
                    if (best == -1 || pr[i] < pr[best] || (pr[i] == pr[best] && rdy[i] < rdy[best])) {
                        best = i;
                    }
                }
            }
            if (best == -1) {
                if (cnt == 0 || order[cnt - 1] != 0) order[cnt++] = 0;
                time++;
                continue;
            }
            cur = best;
            qc = 0;
        }

        if (cnt == 0 || order[cnt - 1] != cur + 1) order[cnt++] = cur + 1;
        rt[cur]--;
        time++;
        qc++;
        if (rt[cur] == 0) {
            ct[cur] = time;
            tat[cur] = ct[cur] - at[cur];
            wt[cur] = tat[cur] - bt[cur];
            finished++;
        }
    }

    cout<<endl<<"Priority + Round Robin"<<endl;
    cout<<"Execution Order: ";
    for (int i = 0; i < cnt; i++) {
        if (order[i] == 0) cout<<"Idle";
        else cout<<"P"<<order[i];
        if (i != cnt - 1) cout<<" -> ";
    }
    cout<<endl<<endl;

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
Enter number of processes: 5
Enter Arrival Time, Burst Time and Priority for P1: 0 5 2
Enter Arrival Time, Burst Time and Priority for P2: 1 4 1
Enter Arrival Time, Burst Time and Priority for P3: 2 2 3
Enter Arrival Time, Burst Time and Priority for P4: 3 3 1
Enter Arrival Time, Burst Time and Priority for P5: 4 3 2
Enter Time Quantum: 2

Priority + Round Robin
Execution Order: P1 -> P2 -> P4 -> P2 -> P4 -> P1 -> P5 -> P1 -> P5 -> P3

P1: 
CT=14
TAT=14
WT=9

P2: 
CT=7
TAT=6
WT=2

P3: 
CT=17
TAT=15
WT=13

P4: 
CT=8
TAT=5
WT=2

P5: 
CT=15
TAT=11
WT=8

Avg WT = 6.8
Avg TAT = 10.2

*/
