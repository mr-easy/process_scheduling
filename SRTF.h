#ifndef SRTF_H_INCLUDED
#define SRTF_H_INCLUDED

#include<vector>
#include"Process.h"
#include"Result.h"
class SRTF
{
    public:
    static Result calculate(std::vector<Process> processes);
};

#endif // SRTF_H_INCLUDED
