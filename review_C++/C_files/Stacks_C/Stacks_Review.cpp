//
//  Stacks_Review.cpp
//  review_C++
//
//  Created by Brandon Johns on 2/19/22.
//

#include "Stacks_Review.hpp"
using namespace std;
#include <iostream>


template <class Type>
const stack_Type<Type> & stack_Type<Type>:: operator =(const stack_Type<Type>& equal )
{
    if(this!= &equal)
        copy_Stack(equal);
    return *this; 
}
template <class Type>
void stack_Type<Type>:: initialize_Stack()
{
    stack_Top=0;
}
template <class Type>
bool stack_Type<Type>:: is_Stack_Empty() const
{
    return (stack_Top ==0);
}
template <class Type>
bool stack_Type<Type>:: is_Stack_Full() const
{
    return (stack_Top==max_Stack_Size);
}
template <class Type>
void stack_Type<Type>:: push(const Type& new_Item)
{
    if(!is_Stack_Full())
    {
        list[stack_Top] = new_Item;
    stack_Top++;
    }
    else
    {
        cout<<"cannot add to a full stack "<<endl;
    }
}
template <class Type>
Type stack_Type<Type>:: top() const
{
    assert(stack_Top !=0);
    return list[stack_Top-1];
}
template <class Type>
void stack_Type<Type>:: pop()
{
    if(!is_Stack_Empty())
        stack_Top--;
    else
        cout<<"cannot remove from an empty stack"<<endl;
}
template <class Type>
stack_Type<Type>:: stack_Type(int stack_Size )
{
    if(stack_Size <= 0)
    {
        cout<<"must be a positive number"<<endl;
        cout<<"creating default size of 100"<<endl;
        max_Stack_Size=100;
    }
    else
    {
        max_Stack_Size= stack_Size;
    }
    stack_Top =0;
    list = new Type[max_Stack_Size];
}
template <class Type>
stack_Type<Type>:: stack_Type(const stack_Type<Type> & other_Stack)
{
    list = NULL;
    copy_Stack(other_Stack);
}
template <class Type>
stack_Type<Type>:: ~stack_Type()
{
    delete [] list;
}
template <class Type>
void stack_Type<Type>:: copy_Stack(const stack_Type<Type> & other_Stack)
{
    delete [] list;
    max_Stack_Size= other_Stack.max_Stack_Size;
    stack_Top= other_Stack.stack_Top;
    
    list = new Type[max_Stack_Size];
    for (int i =0; i < stack_Top; i++)
    {
        list[i]= other_Stack.list[i];
    }
}
