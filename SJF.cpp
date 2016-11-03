#include "SJF.h"
#include <queue>
Result SJF::calculate(std::vector<Process> processes)
{
    float atat = 0, awt = 0;
    //The vector of processes is already sorted in increasing order of their arrival time
    int n = processes.size();
    int processesLeft = n;
    int time = 0;

    std::priority_queue<Process> readyQueue;
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
    }
    Result result;
    result.avgTurnAroundTime = atat/n;
    result.avgWaitingTime = awt/n;
    result.avgResponseTime = result.avgWaitingTime;

    return result;
}
