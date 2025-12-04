#include "ProcessList.h"
#include <iostream>

std::string statusToString(ProcessStatus status)
{
	switch (status)
	{
	case ProcessStatus::Running: return "Running";
	case ProcessStatus::Waiting: return "Waiting";
	case ProcessStatus::Stopped: return "Stopped";
	default: return "Unknown";
	}
}


std::ostream& operator<<(std::ostream& os, const PCB& pcb)
{
	os << "Процесс: " << pcb.processID << std::endl;
	os << "Имя: " << pcb.processName << std::endl;
	os << "Статус: " << statusToString(pcb.processStatus) << std::endl;
	os << "Счётчик комманд: " << pcb.commandCounter << std::endl;

	os << "Регистры CPU: [ ";

	for (int i = 0; i < 8; i++)
	{
		os << pcb.cpuRegisters[i];
		if (i < 7) os << ", ";
	}
	os << " ]" << std::endl;
	return os;
}

ProcessList::ProcessList()
{
	head = nullptr;
}

ProcessList::~ProcessList()
{
	ListNode* current = head;
	while (current != nullptr)
	{
		ListNode* next = current->next;
		delete current;
		current = next;
	}
}

bool ProcessList::insert(const PCB& newPCB)
{
	if (head == nullptr)
	{
		head = new ListNode(newPCB,nullptr);
		size++;
		return true;
	}

	if (head->data.processID == newPCB.processID) return false;

	ListNode* current = head;

	if (newPCB.processID < current->data.processID)
	{
		ListNode* temp = head;
		head = new ListNode(newPCB, nullptr);
		head->next = temp;
		size++;
		return true;

	}

	while (current->next != nullptr && current->next->data.processID < newPCB.processID)
	{
		current = current->next;
	}

	if (current->next != nullptr && current->next->data.processID == newPCB.processID) return false;
	
		
	current->next = new ListNode(newPCB, current->next);
	size++;
	return true;

}

bool ProcessList::remove(int pid)
{
	if (head == nullptr) return false;

	if (head->data.processID == pid)
	{
		ListNode* temp = head;
		head = head->next;
		delete temp;
		size--;
		return true;
	}

	ListNode* current = head;
	while ( current->next != nullptr && current->next->data.processID != pid)
	{
		current = current->next;
	}
	if (current->next == nullptr) return false;

	ListNode* temp = current->next;
	current->next = temp -> next;
	delete temp;
	size--;
	return true;
}


void ProcessList::printList()
{
	if (head == nullptr)
	{
		std::cout << "Список пуст" << std::endl;
		return;
	}

	ListNode* current = head;

	std::cout << "---Данные о процессах---" << std::endl;
	for (int i = 0; i < size; i++)
	{
		if (current == nullptr)
		{
			return;
		}

		std::cout << current->data;
		std::cout << "------------------------" << std::endl;

		current = current->next;
	}
	std::cout << std::endl;
}

ProcessList::ListNode::ListNode(const PCB& data, ListNode* next): data(data), next(next)//ща
{
}

ProcessList::ListNode::~ListNode()
{
}


