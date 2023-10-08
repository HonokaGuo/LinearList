#pragma once
#include "node.h"
#include <memory>
template<typename T>
class simple_link_list
{
protected:
	std::shared_ptr<node<T>> real_head;
	node<T>* head;
	node<T>* get_elem_ptr(int position) const;

public:
	simple_link_list();
	virtual ~simple_link_list();
	bool insert(int position, const T& e);
	int length() const;
	bool get_elem(int position, T& e);
	bool m_delete(int position);
	bool append(const T& e);
	bool is_empty() const;
	void clear();
	bool pop(int position, T& e);
	bool set_elem(int position, const T& e);
	simple_link_list(const simple_link_list <T>& source); //initialize with copied head value
	simple_link_list<T>&operator = (const simple_link_list <T>& source);
	void Traverse(void (*visit) (const T&)) const;   //apply func visit to every element
};


template<typename T> 
simple_link_list<T> ::simple_link_list() {
	//head = new node<T>; 
	real_head = std::make_shared<node <T>>();
	head = real_head.get();
}

template<typename T>
simple_link_list<T> :: ~simple_link_list() {
	clear();
	head = nullptr;
	real_head.reset();
}

template<typename T>
bool simple_link_list<T>::insert(int position, const T& e)   //append=insert(length(), e)
{
	node<T>* tmp_ptrL = get_elem_ptr(position - 1);
	node<T>* tmp_ptr = nullptr;
	if (tmp_ptrL == nullptr) {
		return false;
	}
	else {
		tmp_ptr = tmp_ptrL->next;
	}
	node <T>* p = new node<T>(e, tmp_ptr);
	tmp_ptrL->next = p;
	return true;

}

template<typename T>
int simple_link_list<T>::length() const
{
	int length = 0;
	node<T>* iter = head->next;
	while (iter != nullptr) {
		++length;
		iter = iter->next;
	}

	return length;
}

template<typename T>
bool simple_link_list<T>::get_elem(int position, T& e)
{
	node<T>* tem_ptr = get_elem_ptr(position);
	if (tem_ptr == nullptr) {
		return false;
	} 
	else {
		e = tem_ptr->data;
		return true;
	}
}

template<typename T>
inline bool simple_link_list<T>::m_delete(int position)
{
	node<T>* tmp_ptrL = get_elem_ptr(position-1);
	node<T>* tmp_ptr = nullptr;
	if (tmp_ptrL == nullptr || tmp_ptrL->next == nullptr) {
		return false;
	}
	else {
		tmp_ptr = tmp_ptrL->next;
	}

	tmp_ptrL->next = tmp_ptr->next;
	delete tmp_ptr;
	return true;
}

template<typename T>
inline bool simple_link_list<T>::append(const T& e)
{
	if (insert(length() + 1, e)) {
		return true;
	}
	else {
		return false;
	}
}

template<typename T>
inline bool simple_link_list<T>::is_empty() const
{
	return head->next == nullptr;
}

template<typename T>
inline void simple_link_list<T>::clear()
{
	while (!this->is_empty()) {
		m_delete(1);
	}
}

template<typename T>
inline bool simple_link_list<T>::pop(int position, T& e)
{
	e = get_elem(position);
	m_delete(position);

	//this remain to be fixed 'cause code above request O(2n), but 
	//I also don't want to copy from m_delete because they are just too alike
}

template<typename T>
inline bool simple_link_list<T>::set_elem(int position, const T& e)
{
	if (position < 1 || position > length()) {
		return false;
	}
	get_elem_ptr(position)->data = e;
	return true;
}

template<typename T>
inline simple_link_list<T>::simple_link_list(const simple_link_list<T>& source)
{
	head = source.head();
}

template<typename T>
inline simple_link_list<T>& simple_link_list<T>::operator=(const simple_link_list<T>& source)
{
	// TODO: 在此处插入 return 语句
	if (this != &source) {
		this ->clear();
		real_head.reset();
		real_head = source.real_head;
		head = real_head.get();
	}
	
	return *this; //便于连用赋值运算符
}

template<typename T>
inline void simple_link_list<T>::Traverse(void(*visit)(const T&)) const
{
	node <T>* ptr = head -> next;
	for (; ptr != nullptr; ptr = ptr->next) {
		(*visit)(ptr->data);
	}
}

template<typename T>
node<T>* simple_link_list<T>::get_elem_ptr(int position) const {
	node<T>* ptr = head; 
	int i = 0;//dummy head 0, data 1, 2, 3
	while( i < position && ptr != nullptr) {
		ptr = ptr->next;
		++i;
	}

	if (i != position || ptr == nullptr) {
		return nullptr;
	}
	else {
		return ptr;
	}
	
}

