#pragma once
#include<fstream>
#include<iostream>
template<typename T>
class double_linked_list
{
private:
	struct cell
	{
		T key;
		cell *next;
		cell *prev;
	};
	cell *begin;
	cell *end;
public:
	double_linked_list();
	void init(T value);
	void push_back(T value);
	void delete_by_index(int index);
	void print_list(std::ostream &out);
	void print_list_from_back(std::ostream &out);
	void delete_by_value(T value);
	int size();
	

	~double_linked_list();
	

};
template<typename T>
double_linked_list<T>::double_linked_list()
{
	begin = NULL;
}
template<typename T>
void double_linked_list<T>::init(T value)
{
	if (begin != NULL)
	{
		std::cout << "There is first ellement!";
	}
	else
	{
		begin = new cell;
		begin->key = value;
		begin->next = NULL;
		begin->prev = NULL;
		end = begin;
	}
}
template<typename T>
int double_linked_list<T>::size()
{
	int counter_size = 0;
	cell*intermediate_pointer = begin;
	while (intermediate_pointer)
	{
		counter_size++;
		intermediate_pointer = intermediate_pointer->next;
	}
	return counter_size;
}
template<typename T>
void double_linked_list<T>::push_back(T value)
{
	if (begin == NULL) {
		this->init(value);
	}
	else
	{
		cell*temp = end;
		end->next = new cell;
		end = end->next;
		end->key = value;
		end->prev = temp;
		end->next = NULL;
	}
}
template<typename T>
void double_linked_list<T>::delete_by_index(int index)
{
	int i = 0;
	cell *intermediate_pointer = begin;
	cell*deleted, *temp;
	while (i != index)
	{
		i++;
		intermediate_pointer = intermediate_pointer->next;
	}
	temp = intermediate_pointer->prev;
	deleted = intermediate_pointer;
	intermediate_pointer = intermediate_pointer->next;
	delete deleted;
	temp->next = intermediate_pointer;
	intermediate_pointer->prev = temp;
}
template<typename T>
void double_linked_list<T>::delete_by_value(T value)
{
	cell *intermediate_pointer = begin;
	cell*deleted, *temp;
	while (intermediate_pointer)
	{
		if (intermediate_pointer->key == value)
		{
			temp = intermediate_pointer->prev;
			deleted = intermediate_pointer;
			intermediate_pointer = intermediate_pointer->next;
			delete deleted;
			temp->next = intermediate_pointer;
			intermediate_pointer->prev = temp;
			intermediate_pointer = intermediate_pointer->next;
		}
		else
		{
			intermediate_pointer = intermediate_pointer->next;
		}
	}
	
}
template<typename T>
void double_linked_list<T>::print_list(std::ostream &out)
{
	cell *print_pointer=begin;
	while (print_pointer)
	{
		out << print_pointer->key << ' ';
		print_pointer = print_pointer->next;
	}
}
template<typename T>
void double_linked_list<T>::print_list_from_back(std::ostream &out)
{
	cell *print_pointer =end;
	while (print_pointer)
	{
		out << print_pointer->key << ' ';
		print_pointer = print_pointer->prev;
	}
}
template<typename T>
double_linked_list<T>::~double_linked_list()
{
	if (begin == end)
		delete begin;
	else
	{
		delete begin;
		delete end;
	}
}
