#include "Priority_pre.h"
#include <queue>
#include <iostream>
using namespace std;
struct compareByPriority
{
    bool operator()(const Process& a, const Process& b) const
    {
        if(a.priority == b.priority)
            return a.arrivalTime > b.arrivalTime;
        return a.priority > b.priority;
    }
};

Result Priority_pre::calculate(std::vector<Process> processes)
{
    float atat = 0, awt = 0, art = 0;
    //The vector of processes is already sorted in increasing order of their arrival time
    int n = processes.size();
    int processesLeft = n;
    int time = 0;

    std::priority_queue<Process, std::vector<Process>, compareByPriority> readyQueue;
    int pt = 0;
    Process current = NULL;
    cout<<"Gantt chart : ";
    while(processesLeft > 0)
    {
        //inserting all the processes into the ready queue which arrived at time t
        while(pt < n && processes[pt].arrivalTime == time)
        {
            readyQueue.push(processes[pt]);
            pt++;
        }
        if(readyQueue.empty())
        {
            time++;
            continue;
        }
        //Take the top element
        //that is the process with shortest burst time left
        current = readyQueue.top();
        readyQueue.pop();
        cout<<current.pid<<" ";
        //allotted for first time?
        if(current.burstTime == current.executionTimeLeft)
        {
            art += time - current.arrivalTime;
        }
        time++;
        //Execute one unit of it
        //And if it's still not complete then push it back
        if(!current.executeOneUnit())
        {
            readyQueue.push(current);
        }
        else
        {
            //If the current process has completed it's execution
            processesLeft--;
            atat += time - current.arrivalTime;
            awt += time - current.arrivalTime - current.burstTime;
        }
    }
    cout<<"\n";
    Result result;
    result.avgTurnAroundTime = atat/n;
    result.avgWaitingTime = awt/n;
    result.avgResponseTime = art/n;

    return result;
}
