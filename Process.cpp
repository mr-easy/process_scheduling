#include"Process.h"
Process::Process(int id, int burstTime, int arrivalTime, int priority)
{
    this->pid = id;
    this->burstTime = burstTime;
    this->arrivalTime = arrivalTime;
    this->priority = priority;
    this->executionTimeLeft = burstTime;
}
bool Process::executeOneUnit()
{
    //already completed it's execution
    if(executionTimeLeft == 0)
        return true;
    executionTimeLeft--;
    //If execution ended with this time unit
    if(executionTimeLeft == 0)
        return true;
    return false;
}
bool Process::byArrivalTime(const Process &a, const Process &b)
{
    if(a.arrivalTime == b.arrivalTime)
        return a.pid < b.pid;
    return a.arrivalTime < b.arrivalTime;
}
