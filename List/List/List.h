#ifndef _LIST_H_
#define _LIST_H_

class Node;
class Iterator;

class DLList
{
public:
    DLList();
    ~DLList();
    
    bool push_back( const int d );
    bool push_front( const int d );
    
    bool insert( Iterator& it, const int d );
    void erase( Iterator& it );
   
    bool empty() const;
    int size() const;
    
    Iterator find( const Iterator& b, const Iterator& e, const int d );
    Iterator begin() const;
    Iterator end() const;
    
private:
    bool init();
    bool destroy();
    
    Node* head;
    Node* tail;
    int sz;
};

#endif