#include <iostream>
#include <algorithm>
using namespace std;

struct Job {
    char id;
    int deadline;
    int profit;
};

bool compare(Job j1, Job j2) {
    return j1.profit > j2.profit;
}

void scheduleJobs(Job jobs[], int n) {
    sort(jobs, jobs + n, compare);

    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        maxDeadline = max(maxDeadline, jobs[i].deadline);
    }

    char result[maxDeadline] = {0};
    int profit = 0;

    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            if (result[j] == 0) {
                result[j] = jobs[i].id;
                profit += jobs[i].profit;
                break;
            }
        }
    }

    cout << "Scheduled Jobs: ";
    for (int i = 0; i < maxDeadline; i++) {
        if (result[i] != 0) {
            cout << result[i] << " ";
        }
    }

    cout << "\nTotal Profit: " << profit << endl;
}

int main() {
    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;

    Job jobs[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter job " << i + 1 << " details (id, deadline, profit): ";
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
    }

    scheduleJobs(jobs, n);

    return 0;
}
