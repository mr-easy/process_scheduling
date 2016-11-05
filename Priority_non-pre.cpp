#include "Priority_non-pre.h"
#include <queue>
struct compareByPriority
{
    bool operator()(const Process& a, const Process& b) const
    {
        if(a.priority == b.priority)
            return a.arrivalTime > b.arrivalTime;
        return a.priority > b.priority;
    }
};
Result Priority_non_pre::calculate(std::vector<Process> processes)
{
    float atat = 0, awt = 0;
    //The vector of processes is already sorted in increasing order of their arrival time
    int n = processes.size();
    int processesLeft = n;
    int time = 0;

    std::priority_queue<Process, std::vector<Process>, compareByPriority> readyQueue;

    while(processesLeft > 0)
    {
        std::vector<Process>::iterator it = processes.begin();
        while(it != processes.end())
        {
            if((*it).arrivalTime <= time)
            {
                readyQueue.push(*it);
                it = processes.erase(it);
            }
            else
            {
                break;
            }
        }
        if(readyQueue.empty())
        {
            time++;
            continue;
        }
        Process current = readyQueue.top();
        readyQueue.pop();
        awt += time - current.arrivalTime;
        do{
            time++;
        }while(!current.executeOneUnit());
        atat += time - current.arrivalTime;
        processesLeft--;
    }

    Result result;
    result.avgTurnAroundTime = atat/n;
    result.avgWaitingTime = awt/n;
    result.avgResponseTime = result.avgWaitingTime;

    return result;
}
