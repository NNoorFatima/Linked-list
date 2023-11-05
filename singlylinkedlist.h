#pragma once
#include "gtest/gtest.h"
#include <iostream>
using namespace std;
template <typename T>
//lab_06
//q1
class Node
{
public:
	T data;
	Node* next;
	Node(T x) : data(x), next(nullptr) {}
	void setData(T x)
	{
		data = x;
	}
	T getData()
	{
		return data;
	}
	void setNext(Node<T>* n)
	{
		next = n;
	}
	Node<T>* getNext()
	{
		return next;
	}
};


template <class T>
class SLinkedList
{
public:
	Node<T>* head;

	SLinkedList()
	{
		head = NULL;
	}
	SLinkedList(T x)
	{
		Node<T>* n_node = new Node<T>(x);
		head = n_node;
	}
	////T getData()
	//{
	//	return head->data;
	//}
	////void setData(T x)
	//{
	//	head->data = x;
	//	head->next = NULL;
	//}
	////Node<T>* getNext()
	//{
	//	return next;
	//}
	////void setNext(Node<T>* x)
	//{
	//	next = x;

	//}
	void insert(T x)
	{
		Node<T>* current = head;
		Node<T>* n_node = new Node<T>(x);
		if (current == NULL)	//inserting at head
		{
			head = n_node;
		}
		else
		{
			while (current->next != NULL)
			{
				current = current->next;
			}
			current->next = n_node;

		}
	}
	void insertAtHead(T x)
	{
		Node<T>* n_node = new Node<T>(x);
		if (head == NULL)
		{
			head = n_node;
		}
		else
		{
			n_node->next = head;

		}
		head = n_node;

	}
	bool isEmpty()
	{
		if (head == nullptr)
			return true;
		return false;
	}
	//its a linked list the size is unlimited 
	//we are using pointer based implementation therefore size can be changed
	//linked list can never be full
	T search(T x)
	{
		Node<T>* current = head;
		if (head->next != NULL)
		{
			while (current != NULL)
			{
				if (current->data == x)
				{
					return current->data;
				}
				current = current->next;
				//cout << current->data << " ";
			}
		}
		else if (head != NULL)
		{
			//cout << current->data << " ";
			if (head->data == x)
				return x;
		}

	}
	void update(int index, T value)
	{
		//Node<T>* n_node = new Node<T>(value);
		Node<T>* current = head;
		int count = 0;
		if (head->next == nullptr)
		{
			if (index == 0)
			{
				head->data = value;
			}
		}
		else
		{
			while (current->next != nullptr)
			{
				if (current->data == index)
					break;
				current = current->next;
				count++;
			}
			current->data = value;
		}

	}
	void InsertAtIndex(T value, int index)
	{
		int count = 0;
		Node<T>* current = head;
		Node<T>* prev = nullptr;
		Node<T>* n_node = new Node<T>(value);
		if (index == 0)
		{
			n_node->next = head;
			head = n_node;
		}
		else
		{
			while (current->next != nullptr)
			{
				//count++;
				if (count == index)
					break;
				prev = current;
				current = current->next;
				count++;

			}
			if (index == count)	//this inserts in the middle of the linked list 
			{
				prev = n_node;
				prev->next = current;
			}
			if (index > count)	//works when indx is greater than number of elements 
			{	//inserts at last node 
				current->next= n_node;
			}
			//print();
		}

	}
	void remove(T value)
	{
		Node<T>* current = head;
		Node<T>* prev = head;
		while (current->next != nullptr)
		{
			if (current->data == value)
				break;
			prev = current;
			current = current->next;
		}
		prev->next = current->next;
		//print();
	}
	void print()
	{
		Node<T>* current = head;
		while (current != nullptr)
		{
			cout << current->data << " ";
			current = current->next;
		}
		cout << endl;
	}


	

};

//q2
template <class T>
Node<T>* swapAdjacentNodes(Node<T>* head_)
{
	if (head_==nullptr || head_->next == nullptr)	//nothing there to swap values
		return head_;

	Node<T>* current = head_;
	Node<T>* next_ = head_->next;
	Node<T>* prev = nullptr;
	while (current != NULL && current->next)		//swapping only happens for data
	{
		Node<T>* n_n = current->next;
		Node<T>* n_n_2 = n_n->next;
		n_n->next = current;
		current->next = n_n_2;
		
		if (prev != nullptr)
			prev->next = n_n;
		prev = current;
		current = n_n_2;

	
	}
	//current = head_;
	//printing to chck 
	/*while(current != nullptr)
	{
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl << endl;*/
	return next_;

}
lab_6.h
Displaying lab_6.h.
