#ifndef PROCESS_H_INCLUDED
#define PROCESS_H_INCLUDED

class Process
{
public:
    int burstTime;
    int arrivalTime;
    int executionTimeLeft;
    int priority;
    int pid;

    Process(int id, int burstTime = 0, int arrivalTime = 0, int priority = 0);
    bool executeOneUnit();
    static bool byArrivalTime(const Process &a, const Process &b);
    bool operator<(const Process& a) const;
};


#endif // PROCESS_H_INCLUDED
