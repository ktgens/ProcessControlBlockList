#include <iostream>
#include "PCB.h"
#include "ProcessList.h"

#ifdef _WIN32
	#include "Windows.h"
#endif


int main()
{

#ifdef _WIN32
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
#endif


	PCB p1 = { 101, "System", ProcessStatus::Running, 0, { 10, 20, 30, 40,10, 20, 30, 40 } };
	PCB p2 = { 102, "Calculator", ProcessStatus::Waiting, 15, { 10, 20, 30, 40,10, 20, 30, 40 } };
	PCB p3 = { 103, "Yandex",     ProcessStatus::Stopped, 404, { 10, 20, 30, 40,10, 20, 30, 40 } };
	PCB p4 = { 104, "Firefox",     ProcessStatus::Stopped, 404, { 10, 20, 30, 40,10, 20, 30, 40 } };

	//создание списка процессов
	ProcessList list;
	//добавление элементов
	list.insert(p2);
	list.insert(p3);
	list.insert(p1);
	//вывод списка
	list.printList();
	//удаление элементов
	list.remove(p2.processID);
	//вывод списка
	std::cout << "До" << std::endl;
	list.printList();
	//---неудачные операции
	list.insert(p1); //попытка добавить дубликат
	list.remove(p2.processID);//попытка удалить несуществующий элемент
	//финальный вывод списка
	std::cout << "После" << std::endl;
	list.printList();
}

