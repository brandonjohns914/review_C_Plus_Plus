//
//  Stack_Linked.cpp
//  review_C++
//
//  Created by Brandon Johns on 2/19/22.
//

#include "Stack_Linked.hpp"
#include "Stacks_Review.hpp"
using namespace std;
#include <iostream>

template <class Type>
const linked_Stack_Type<Type> & linked_Stack_Type<Type>:: operator = (const linked_Stack_Type<Type> & equal)
{
    if(this!= &equal)
        copy_Stack(equal);
    return *this; 
}

template <class Type>
bool linked_Stack_Type<Type>:: is_Empty_Stack() const
{
    return (stack_Top == NULL);
}

template <class Type>
bool linked_Stack_Type<Type>:: is_Full_Stack() const
{
    return false;
}

template <class Type>
void linked_Stack_Type<Type>:: initialize_Stack()
{
    node_Type<Type> *temp;
    while(stack_Top !=NULL)
    {
        temp = stack_Top;
        stack_Top = stack_Top->link;
        delete temp;
    }
}

template <class Type>
void linked_Stack_Type<Type>:: push(const Type& new_Item)
{
    node_Type<Type> *new_Node;
    new_Node = new node_Type<Type>;
    new_Node->infomation= new_Item;
    new_Node->link = stack_Top;
    stack_Top = new_Node;
}

template <class Type>
Type linked_Stack_Type<Type>:: top() const
{
    assert(stack_Top!=NULL);
    return  stack_Top->infomation;
}

template <class Type>
void linked_Stack_Type<Type>:: pop()
{
    node_Type<Type> *temp;
    if(stack_Top != NULL)
    {
        temp = stack_Top;
        stack_Top = stack_Top->link;
        delete temp;
    }
    else
        cout<<"cannot remove from empty stack"<<endl;
}

template <class Type>
linked_Stack_Type<Type>:: linked_Stack_Type()
{
    stack_Top = NULL;
}

template <class Type>
linked_Stack_Type<Type>:: linked_Stack_Type(const linked_Stack_Type<Type>& other_Stack)
{
    stack_Top =NULL;
    copy_Stack(other_Stack);
    
}

template <class Type>
linked_Stack_Type<Type>:: ~linked_Stack_Type()
{
    initialize_Stack();
}

template <class Type>
void linked_Stack_Type<Type>:: copy_Stack(const linked_Stack_Type<Type>& other_Stack)
{
    node_Type<Type> *new_Node;
    node_Type<Type> *current;
    node_Type<Type> *last;
    
    if(stack_Top !=NULL)
        initialize_Stack();
    if(other_Stack.stack_Top==NULL)
    {
        stack_Top = NULL;
    }
    else
    {
        current = other_Stack.stack_Top;
        stack_Top= new node_Type<Type>;
        
        stack_Top->infomation = current->infomation;
        stack_Top->link = NULL;
        current = current->link;
        while(current!=NULL)
        {
            new_Node = new node_Type<Type>;
            new_Node->info = current->infomation;
            new_Node->link =NULL;
            last->link = new_Node;
            current= current->link;
        }
        
    }
}
