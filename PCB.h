#pragma once
#include <string>

enum class ProcessStatus
{
    Running, Waiting, Stopped
};

struct PCB
{
    int processID;
    std::string processName;
    ProcessStatus processStatus;
    int commandCounter;
    int cpuRegisters[8];
};