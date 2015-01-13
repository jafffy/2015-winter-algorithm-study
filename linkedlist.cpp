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
        prev = head;
    }

    newNode->next = prev->next;
    prev->next = newNode;
}

void List::remove(Node* target)
{
    if (target == nullptr) {
        std::printf("target is nullptr\n");
        return;
    }

    if (target == head) {
        head = head->next;
    }

    for (auto idx = head;
        idx->next != target && idx->next != nullptr;
        idx = idx->next);

    if (idx->next == nullptr) {
        std::printf("we cannot find target\n");

        return;
    } else {
        idx->next = target->next;
    }

    delete target;
}

void List::push_front(int data)
{
    insert(head, data);
}

void List::push_back(int data)
{
    auto idx = head;

    while (idx->next != nullptr)
        idx = idx->next;

    insert(idx, data);
}

void List::pop_front()
{
    remove(head);
}

void List::pop_back()
{
    auto idx = head;

    while (idx->next != nullptr)
        idx = idx->next;

    remove(head);
}

void List::clear()
{
}