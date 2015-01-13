#include <iostream>
#include "List.h"
#include "Node.h"
using namespace std;

int main()
{
    DLList list;
    Iterator it;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);
    list.push_back(6);
    list.push_back(7);
    list.push_back(8);
    
    it = list.begin()+3;
    list.insert(it, 100000);
    
    it = list.find(list.begin(), list.end(), 7);
    list.erase(it);
    
    for( it = list.begin(); it != list.end(); it++ )
    {
        cout << *it << endl;
    }
    
    return 0;
}