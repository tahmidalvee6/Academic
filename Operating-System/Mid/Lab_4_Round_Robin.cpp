#include <iostream>
using namespace std;

int main() {
    int n, tq;
    cout<<"Enter number of processes: ";
    cin>>n;

    int at[20], bt[20];
    for(int i = 0; i < n; i++) {
        cout<<"Enter Arrival Time and Burst Time for P"<<i + 1<<": ";
        cin>>at[i]>>bt[i];
    }
    cout<<"Enter Time Quantum: ";
    cin>>tq;

    int rt[20], ct[20], tat[20], wt[20];
    int order[1000], cnt = 0;
    int q[1000], front = 0, rear = 0;
    bool inQ[20] = {false};
    for (int i = 0; i < n; i++) {
        rt[i] = bt[i];
    }

    int time = 0, finished = 0;
    while (finished < n) {
        for (int i = 0; i < n; i++) {
            if (at[i] <= time && inQ[i] == false && rt[i] > 0) {
                q[rear] = i;
                rear++;
                inQ[i] = true;
            }
        }

        if (front == rear) {
            if (cnt == 0 || order[cnt - 1] != 0) {
                order[cnt] = 0;
                cnt++;
            }
            time++;
        }
        else {
            int idx = q[front];
            front++;

            if (cnt == 0) {
                order[cnt] = idx + 1;
                cnt++;
            }
            else if (order[cnt - 1] != idx + 1) {
                order[cnt] = idx + 1;
                cnt++;
            }

            int run;
            if (rt[idx] < tq) {
                run = rt[idx];
            } else {
                run = tq;
            }

            time = time + run;
            rt[idx] = rt[idx] - run;

            for (int i = 0; i < n; i++) {
                if (at[i] <= time && inQ[i] == false && rt[i] > 0) {
                    q[rear] = i;
                    rear++;
                    inQ[i] = true;
                }
            }

            if (rt[idx] > 0) {
                q[rear] = idx;
                rear++;
            }
            else {
                ct[idx] = time;
                tat[idx] = ct[idx] - at[idx];
                wt[idx] = tat[idx] - bt[idx];
                finished++;
            }
        }
    }

    cout<<endl<<"Round Robin"<<endl;
    cout<<"Execution Order: ";
    for (int i = 0; i < cnt; i++) {
        if (order[i] == 0) {
            cout<<"Idle";
        } else {
            cout<<"P"<<order[i];
        }
        if (i != cnt - 1) {
            cout<<" -> ";
        }
    }
    cout<<endl<<endl;

    int sumWT = 0, sumTAT = 0;
    for (int i = 0; i < n; i++) {
        cout<<"P"<< i + 1<< ": "<<endl;
        cout<<"CT="<< ct[i]<<endl;
        cout<<"TAT="<< tat[i]<<endl;
        cout<<"WT="<< wt[i]<<endl;
        cout<<endl;
        sumWT = sumWT + wt[i];
        sumTAT = sumTAT + tat[i];
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
Enter Time Quantum: 2

Round Robin
Execution Order: P1 -> P2 -> P1 -> P3 -> P2 -> P4 -> P1 -> P4 -> P1

P1: 
CT=16
TAT=16
WT=9

P2: 
CT=9
TAT=7
WT=3

P3: 
CT=7
TAT=3
WT=2

P4: 
CT=15
TAT=10
WT=6

Avg WT = 5
Avg TAT = 9

*/
