#pragma once
#include <iostream>

using namespace std;

template<class T> 

class LinkedList
{
public:
	LinkedList() {
		count = 0;
	}

	struct linked_list
	{
		int count;
		node*head;
	};

	linked_list* create_linked_list()
	{
		linked_list* list = new linked_list;
		list->head = nullptr;
		list->count = 0;
		return list;
	}

	void add_first(linked_list*list, string type, string face, int data)
	{
		node* n = new node;
		n->type = type;
		n->face = face;
		n->data = data;
		n->next = list->head;
		list->head = n;
		list->count++;
	}

	void add_last(linked_list*list, string type, string face, int data)
	{
		if (list->head == nullptr)
		{
			add_first(list, type, face, data);
			return;
		}

		node*tail = list->head;
		while (tail->next != nullptr)
			tail = tail->next;

		node*n = new node;
		n->type = type;
		n->face = face;
		n->data = data;
		n->next = nullptr;
		tail->next = n;
		list->count++;
	}

	void remove_first(linked_list* list)
	{
		if (list->head == nullptr)
		{
			cout << "error!" << endl;
			return;
		}

		node*n = list->head;
		list->head = n->next;
		delete n;
		list->count--;
	}

	void remove_item(linked_list*list, int index) {
		if (index == 0)
		{
			remove_first(list);
			return;
		}

		node*prev = list->head;
		while (index - 1 > 0)
		{
			prev = prev->next;
			--index;
		}

		node*n = prev->next;
		prev->next = n->next;
		delete n;
	}

	void print_items(linked_list* list)
	{
		node*n = list->head;
		while (n != nullptr)
		{
			cout << n->face << " of " << n->type << endl;
			n = n->next;
		}
	}

	void clear(linked_list*list)
	{
		node*n = list->head;
		while (n != nullptr)
		{
			node* temp = n;
			n = n->next;
			delete temp;
		}
		delete list;
		list->count = 0;
	}

	~LinkedList() {
	clear()};

private:
	struct node
	{
		string type;
		string face;
		int data;
		node* next;
	};

};




