#include"Result.h"
#include<iostream>
void Result::show()
{
    std::cout<<"ATAT : "<<avgTurnAroundTime<<"\n";
    std::cout<<"AWT  : "<<avgWaitingTime<<"\n";
    std::cout<<"ART  : "<<avgResponseTime<<"\n";
}
