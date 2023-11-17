#include<iostream>
#include<algorithm>

using namespace std;

struct Process {
    int id;
    int at;
    int bt;
    int wt;
    int tat;
};

// Comparison function for sorting based on burst time
bool compare(Process a, Process b) {
    return a.bt < b.bt;
}

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    Process p[n];

    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        cout << "Enter arrival time for process " << i + 1 << ": ";
        cin >> p[i].at;
        cout << "Enter burst time for process " << i + 1 << ": ";
        cin >> p[i].bt;
    }

    sort(p, p + n, compare);

    int wt = 0, tat = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            p[i].wt = 0;
        } else {
            p[i].wt = p[i - 1].wt + p[i - 1].bt;
        }
        p[i].tat = p[i].wt + p[i].bt;

        wt += p[i].wt;
        tat += p[i].tat;
    }

    float avgWt = (float)wt / n;
    float avgTat = (float)tat / n;

    cout << "Process\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++) {
        cout << p[i].id << "\t\t" << p[i].at << "\t\t" << p[i].bt << "\t\t" << p[i].wt << "\t\t" << p[i].tat << "\n";
    }

    cout << "\nAverage Waiting Time: " << avgWt << endl;
    cout << "Average Turnaround Time: " << avgTat << endl;

    return 0;
}

/*
Enter the number of processes: 5
Enter arrival time for process 1: 0
Enter burst time for process 1: 8
Enter arrival time for process 2: 3
Enter burst time for process 2: 4
Enter arrival time for process 3: 7
Enter burst time for process 3: 5
Enter arrival time for process 4: 10
Enter burst time for process 4: 3
Enter arrival time for process 5: 12
Enter burst time for process 5: 6
Process	Arrival Time	Burst Time	Waiting Time	Turnaround Time
4		10		3		0		3
2		3		4		3		7
3		7		5		7		12
5		12		6		12		18
1		0		8		18		26

Average Waiting Time: 8
Average Turnaround Time: 13.2
/*
