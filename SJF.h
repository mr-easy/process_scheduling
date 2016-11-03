#ifndef SJF_H_INCLUDED
#define SJF_H_INCLUDED

#include<vector>
#include"Process.h"
#include"Result.h"
class SJF
{
    public:
    static Result calculate(std::vector<Process> processes);
};

#endif // SJF_H_INCLUDED
