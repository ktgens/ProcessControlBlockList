#pragma once
#include "PCB.h"

class ProcessList
{
public:

    bool insert(const PCB& newPCB);

    bool remove(int pid);

    void printList();

    ProcessList();

    ~ProcessList();

private:

    class ListNode
    {
    public:
        PCB data;
        ListNode* next;

        ListNode(const PCB& data, ListNode* next = nullptr);

        ~ListNode();
    };

    ListNode* head;

    size_t size = 0;
};