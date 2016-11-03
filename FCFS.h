#ifndef FCFS_H_INCLUDED
#define FCFS_H_INCLUDED

#include<vector>
#include"Process.h"
#include"Result.h"
class FCFS
{
    public:
    static Result calculate(std::vector<Process> processes);
};
#endif // FCFS_H_INCLUDED
