#include "node.h"
#include "simple_link_list.h"
#include <iostream> 

void print_elem(const int& i) {
	std::cout << i << std::endl;
}

int main() {
	simple_link_list<int> myList;
	myList.append(2);
	myList.append(7);
	myList.append(9);
	myList.insert(2, 114);
	myList.Traverse(&print_elem);
	simple_link_list<int> sec_list;
	sec_list = myList;
	sec_list.Traverse(&print_elem);

	return 0;
}


