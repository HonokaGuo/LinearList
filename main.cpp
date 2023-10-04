#include "node.h"
#include "simple_link_list.h"
#include <iostream> 
int main() {
	simple_link_list<int> myList;
	int a;
	myList.insert(1, 2);
	myList.append(2);
	myList.append(6);
	std::cout << myList.length() << std::endl;
	myList.m_delete(2);
	std::cout << myList.length() << std::endl;
	myList.set_elem(1, 9);
	myList.get_elem(1, a);
	std::cout << a  << std::endl;
	std::cout << myList.is_empty() << std::endl;
	myList.clear();
	std::cout << myList.is_empty() << std::endl;
	std::cout << myList.length() << std::endl;
	return 0;
}