#ifndef PRIORITY_PRE_H_INCLUDED
#define PRIORITY_PRE_H_INCLUDED

#include<vector>
#include"Process.h"
#include"Result.h"
class Priority_pre
{
    public:
    static Result calculate(std::vector<Process> processes);
};

#endif // PRIORITY_PRE_H_INCLUDED
