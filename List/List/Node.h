#ifndef _NODE_H_
#define _NODE_H_

class Node
{
public:
    Node( int d ) : data(d) {}
    
    ~Node() {}
    
    void  setPrev( Node* n ) { prev = n; }
    Node* getPrev() { return prev; } // why can't return Node* ?
    
    void  setNext( Node* n ) { next = n; }
    Node* getNext() { return next; }
    
    void setData( const int& d ) { data = d; }
    int& getData() { return data; }
    
private:
    Node* prev;
    Node* next;
    
    int data;
};

class Iterator
{
public:
    Iterator() {}
    Iterator( Node* n ) : node(n) {}
    
    ~Iterator() {}
    
    int& operator*()
    {
        return node->getData();
    }
    
    Iterator& operator=( const Iterator& it )
    {
        node = it.node;
        return *this;
    }
    
    Iterator operator+( const int& v )
    {
        for( int i = 0; i < v; i++ )
        {
            node = node->getNext();
        }
    
        return *this;
    }
    
    Iterator operator-( const int& v )
    {
        for( int i = 0; i < v; i++ )
        {
            node = node->getPrev();
        }
        
        return *this;
    }
    
    Iterator& operator+=( const int& v )
    {
        for( int i = 0; i < v; i++ )
        {
            node = node->getNext();
        }
        
        return *this;
    }
    
    Iterator& operator-=( const int& v )
    {
        for( int i = 0; i < v; i++ )
        {
            node = node->getPrev();
        }
        
        return *this;
    }
    
    Iterator& operator++()
    {
        node = node->getNext();
        return *this;
    }
    
    const Iterator operator++( int )
    {
        Iterator temp = *this;
        node = node->getNext();
        return temp;
    }
    
    Iterator& operator--()
    {
        node = node->getPrev();
        return *this;
    }
    
    const Iterator operator--( int )
    {
        Iterator temp = *this;
        node = node->getPrev();
        return temp;
    }
    
    bool operator==( const Iterator& it )
    {
        if( node == it.node ) return true;
        return false;
    }
    
    bool operator!=( const Iterator& it )
    {
        if( node != it.node ) return true;
        return false;
    }
    
    void  setNode( Node* n ) { node = n; }
    Node* getNode() { return node; }
    
private:
    Node* node;
};

#endif