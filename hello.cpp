#include <iostream>
using namespace std;

struct Process {
    int id, burstTime, arrivalTime, waitingTime, turnaroundTime;
};

void findWaitingTime(Process proc[], int n) {
    proc[0].waitingTime = 0; // First process has no waiting time

    for (int i = 1; i < n; i++) {
        proc[i].waitingTime = proc[i - 1].waitingTime + proc[i - 1].burstTime;
    }
}

void findTurnaroundTime(Process proc[], int n) {
    for (int i = 0; i < n; i++) {
        proc[i].turnaroundTime = proc[i].waitingTime + proc[i].burstTime;
    }
}

void FCFS(Process proc[], int n) {
    findWaitingTime(proc, n);
    findTurnaroundTime(proc, n);

    cout << "Process\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++) {
        cout << proc[i].id << "\t" << proc[i].burstTime << "\t\t" << proc[i].arrivalTime << "\t\t"
             << proc[i].waitingTime << "\t\t" << proc[i].turnaroundTime << endl;
    }
}
int main() {
    Process proc[] = {{1, 6, 0}, {2, 8, 1}, {3, 7, 2}, {4, 3, 3}};
    int n = sizeof(proc) / sizeof(proc[0]);
    FCFS(proc, n);
    return 0;
}
