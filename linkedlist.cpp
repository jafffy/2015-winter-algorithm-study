#include "linkedlist.h"

List::List()
: head(nullptr)
{
}

List::~List()
{
}

void List::insert(Node* prev, int data)
{
    auto newNode = new Node(data);

    if (head == nullptr) {
        head = newNode;

        return;
    }

    if (prev == nullptr) {
        newNode->next = head->next;
        head->next = newNode;

        return;
    }

    
}

void List::remove(Node* target)
{

}

void List::push_front(int data)
{

}

void List::push_back(int data)
{

}

void List::pop_front()
{

}

void List::pop_back()
{

}