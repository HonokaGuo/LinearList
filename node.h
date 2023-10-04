#pragma once
template <typename T>
class node {
	
	//template <typename> friend class simple_link_list;
public:

	T data;
	node<T>* next;

	node();
	node(const T& e, node<T>* next = nullptr);
};

template<typename T> 
node<T>::node() {
	next = nullptr;
}

template<typename T>
node<T>::node(const T& e, node<T>* next) {
	data = e;
	this->next = next;
}