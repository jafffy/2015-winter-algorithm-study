#include "List.h"
#include "Node.h"

DLList::DLList()
: sz(0)
{
    init();
}

DLList::~DLList()
{
    destroy();
}

bool DLList::init()
{
    head = new Node(0);
    tail = new Node(1);
    
    if( head == nullptr ) return false;
    if( tail == nullptr ) return false;
    
    head->setPrev(tail);
    head->setNext(tail);
    
    tail->setPrev(head);
    tail->setNext(head);
    
    return true;
}

bool DLList::destroy()
{
    clear();
    delete head;
    delete tail;
    
    return true;
}

bool DLList::push_back( const int d )
{
    Node* node = new Node(d);
    
    if( node == nullptr ) return false;
    
    node->setPrev(tail->getPrev());
    node->setNext(tail);
    
    tail->getPrev()->setNext(node);
    tail->setPrev(node);
    
    sz++;
    return true;
}

bool DLList::push_front( const int d )
{
    Node* node = new Node(d);
    
    if( node == nullptr ) return false;
    
    node->setPrev(head);
    node->setNext(head->getNext());
    
    head->getNext()->setPrev(node);
    head->setNext(node);
    
    sz++;
    return true;
}

bool DLList::insert( Iterator& it, const int d )
{
    Node* node = new Node(d);
    
    if( node == nullptr ) return false;
    
    node->setPrev(it.getNode());
    node->setNext(it.getNode()->getNext());
    
    it.getNode()->getNext()->setPrev(node);
    it.getNode()->setNext(node);
    
    sz++;
    return true;
}

void DLList::erase( Iterator& it )
{
    it.getNode()->getPrev()->setNext(it.getNode()->getNext());
    it.getNode()->getNext()->setPrev(it.getNode()->getPrev());
    
    sz--;
    delete it.getNode();
}

void DLList::clear()
{
    for( Iterator it = head->getNext(); it != tail; it++ )
    {
        erase(it);
    }
    
    head->setPrev(tail);
    head->setNext(tail);
    
    tail->setPrev(head);
    tail->setNext(head);
    
    sz = 0;
}

bool DLList::empty() const
{
    if( !sz ) return true;

    return false;
}

int DLList::size() const
{
    return sz;
}

Iterator DLList::find( const Iterator& b, const Iterator& e, const int d )
{
    Iterator it;
    
    for( it = b; it != e; it++ )
    {
        if( (*it) == d )
        {
            return it;
        }
    }
    
    return it;
}

Iterator DLList::begin() const
{
    if( head == tail ) return Iterator(head);
    
    return Iterator(head->getNext());
}

Iterator DLList::end() const
{
    return Iterator(tail);
}