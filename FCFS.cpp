#include "FCFS.h"
Result FCFS::calculate(std::vector<Process> processes)
{
    float atat = 0, awt = 0;
    //The vector of processes is already sorted in increasing order of their arrival time
    int n = processes.size();
    int time = 0;
    for(int i = 0; i < n; i++)
    {
        while(time < processes[i].arrivalTime)
            time++;
        awt += time - processes[i].arrivalTime;
        do{
            time++;
        }while(!processes[i].executeOneUnit());
        atat += time - processes[i].arrivalTime;
    }
    Result result;
    result.avgTurnAroundTime = atat/n;
    result.avgWaitingTime = awt/n;
    result.avgResponseTime = result.avgWaitingTime;

    return result;
}
