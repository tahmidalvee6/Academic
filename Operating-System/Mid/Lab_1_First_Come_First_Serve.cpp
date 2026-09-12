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
