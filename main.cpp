#include <iostream>
#include <vector>
#include <algorithm>
#include "Process.h"
#include "Result.h"
#include "FCFS.h"
#include "SJF.h"
#include "Priority_non-pre.h"
#include "SRTF.h"
using namespace std;

int main()
{
    int n;
    int t1, t2, t3;
    cout<<"Enter number of processes : ";
    cin>>n;
    vector<Process> processes;
    for(int i = 0; i < n; i++)
    {
        cout<<"Enter burst time, arrival time and priority for Process "<<i+1<<" : ";
        cin>>t1>>t2>>t3;

        processes.push_back(*(new Process(i+1, t1, t2, t3)));
    }
    sort(processes.begin(), processes.end(), Process::byArrivalTime);

    Result fcfs_result = FCFS::calculate(processes);
    cout<<"FCFS:\n"; fcfs_result.show(); cout<<"\n";

    Result sjf_result = SJF::calculate(processes);
    cout<<"SJF:\n"; sjf_result.show(); cout<<"\n";

    Result priority_np_result = Priority_non_pre::calculate(processes);
    cout<<"Priority Non Pre-emptive:\n"; priority_np_result.show(); cout<<"\n";

    cout<<"Shortest Remaining Time First (SRTF):\n";
    Result srtf_result = SRTF::calculate(processes);
    srtf_result.show();

    return 0;
}
