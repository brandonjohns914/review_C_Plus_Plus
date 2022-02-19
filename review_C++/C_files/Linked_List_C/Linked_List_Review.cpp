//
//  Linked_List_Review.cpp
//  review_C++
//
//  Created by Brandon Johns on 2/17/22.
//

#include "Linked_List_Review.hpp"
#include <stdio.h>
#include <iostream>
#include <string>
#include <array>
using namespace std;

template <class Type>
Linked_List_Iterator<Type>:: Linked_List_Iterator()
{
    current = NULL;
}
template <class Type>
Linked_List_Iterator<Type>:: Linked_List_Iterator(node_Type<Type> *pointer)
{
    current = pointer;
}
template <class Type>
Type Linked_List_Iterator<Type>:: operator * ()
{
    return current->infomation;
}

template <class Type>
Linked_List_Iterator<Type> Linked_List_Iterator<Type>:: operator++()
{
    current = current->link;
    return *this;
}
template <class Type>
bool Linked_List_Iterator<Type>::  operator == (const Linked_List_Iterator<Type> & right) const
{
    return (current == right.current);
}
template <class Type>
bool Linked_List_Iterator<Type>:: operator!=(const Linked_List_Iterator<Type> & right) const
{
    return (current != right.current); 
}



template <class Type>
const Linked_List_Type<Type> & Linked_List_Type<Type>:: operator = (const Linked_List_Type<Type> & equal)
{
    if( this!= & equal)
    {
        copyList(equal);
    }
    return *this;
}

template <class Type>
void Linked_List_Type<Type>:: initialize_List()
{
    destory_List();
}

template <class Type>
bool Linked_List_Type<Type>:: is_Empty_List() const
{
    if (first==NULL)
        return true;
    else
        return false;
}

template <class Type>
void Linked_List_Type<Type>:: print() const
{
    node_Type<Type> *current;
    current = first;
    while (current!= NULL)
    {
        cout<< current->infomation << " " <<endl;
        current=current->link;
    }
}

template <class Type>
int Linked_List_Type<Type>:: length() const
{
    return count;
}

template <class Type>
void Linked_List_Type<Type>:: destory_List()
{
    node_Type<Type> *temp;
    
    while (first != NULL)
    {
        temp = first;
        first = first->link;
        delete temp;
    }
    last = NULL;
    count =0;
}

template <class Type>
Type Linked_List_Type<Type>:: front() const
{
    assert(first!=NULL);
    return first->infomation;
}
template <class Type>
Type Linked_List_Type<Type>:: back() const
{
    assert(last!=NULL);
    return last->infomation;
}

template <class Type>
Linked_List_Iterator<Type> Linked_List_Type<Type>::  begin()
{
    Linked_List_Iterator<Type> temp(first);
    return temp;
}
template <class Type>
Linked_List_Iterator<Type> Linked_List_Type<Type>:: end()
{
    Linked_List_Iterator<Type> temp(last);
    return temp;
}

template <class Type>
Linked_List_Type<Type>:: Linked_List_Type()
{
    first = NULL;
    last = NULL;
    count = 0;
}
template <class Type>
Linked_List_Type<Type>:: Linked_List_Type(const Linked_List_Type<Type> & other_List)
{
    first= NULL;
    copyList(other_List);
}

template <class Type>
Linked_List_Type<Type>:: ~Linked_List_Type()
{
    destory_List();
}

template <class Type>
void Linked_List_Type<Type>::  copyList(const Linked_List_Type<Type>& other_List)
{
    node_Type<Type> *new_Node;
    node_Type<Type> *current;
    
    if (first!= NULL)
        destory_List();
    if(other_List.first==NULL)
    {
        first= NULL;
        last=NULL;
        count = 0;
    }
    else
    {
        current = other_List.first;
        count = other_List.count;
        
        first = new node_Type<Type>;
        first->infomation = current->infomation;
        first->link = NULL;
        last = first;
        current=current->link;
        
        while(current!=NULL)
        {
            new_Node = new node_Type<Type>;
            new_Node->infomation= current->infomation;
            new_Node->link = NULL;
            
            last->link = new_Node;
            last = new_Node;
            current=current->link;
        }
    }
}


//unordered





