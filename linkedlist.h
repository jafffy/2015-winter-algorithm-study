#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

class List 
{
public:
    class Node // XXX : push to not public boundary
    {
    public:
        Node(const int& data = 0, const Node* next = nullptr)
        : data(data), next(next)
        {

        }

        ~Node()
        {

        }

        int data;
        Node* next;
    };

    Node *head;

    List();
    ~List();

    void insert(Node* prev, int data);
    void remove(Node* target);

    void push_front(int data);
    void push_back(int data);

    void pop_front();
    void pop_back();
};

#endif // LINKEDLIST_H_