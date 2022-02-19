//
//  Double_Linked_List.cpp
//  review_C++
//
//  Created by Brandon Johns on 2/18/22.
//

#include "Double_Linked_List.hpp"
#include <stdio.h>
#include <iostream>
#include <string>
#include <array>
using namespace std;

template<class Type>
const double_Linked_List<Type>  & double_Linked_List<Type>:: operator =(const double_Linked_List<Type> & equal)
{
    
}

template<class Type>
void double_Linked_List<Type>:: initialized_List()
{
    destory();
}

template<class Type>
bool double_Linked_List<Type>:: is_Empty_List()
{
    return (first==NULL);
}

template<class Type>
void double_Linked_List<Type>:: destory()
{
    node_Type<Type> *temp;
    
    while(first!=NULL)
    {
        temp = first;
        first = first->next;
        delete temp;
    }
    last = NULL;
    count =0;
}

template<class Type>
void double_Linked_List<Type>:: print() const
{
    node_Type<Type> *current;
    current = first;
    while(current != NULL)
    {
        cout<< current->infomation<<" "<<endl;
        current = current->next;
    }
}
template<class Type>
void double_Linked_List<Type>::  reverse_Print() const
{
    node_Type<Type> *current;
    current = last;
    while(current !=NULL)
    {
        cout<< current->infomation << " "<<endl;
        current = current->back;
    }
}

template<class Type>
int double_Linked_List<Type>::  length() const
{
    return count;
}

template<class Type>
Type double_Linked_List<Type>:: front() const
{
    assert(first != NULL);
    return first->infomation;
}

template<class Type>
Type double_Linked_List<Type>:: back() const
{
    assert(last != NULL);
    return last->infomation;
}

template<class Type>
bool double_Linked_List<Type>:: search(const Type& search_Item) const
{
    bool found = false;
    node_Type<Type> *current;
    current = first;
    while(current != NULL && !found)
    {
        if(current->infomation >= search_Item)
            found = true;
        else
            current = current->next;
        
    }
    if(found)
    {
        found = (current -> infomation == search_Item);
    }
    return found;
}

template<class Type>
void double_Linked_List<Type>:: insert(const Type& insert_Item)
{
    bool found;
    node_Type<Type> *current;
    node_Type<Type> *trail_current;
    node_Type<Type> *new_Node;
    new_Node= new node_Type<Type>;
    new_Node->infomation = insert_Item;
    new_Node->next = NULL;
    new_Node->back = NULL;
    
    if(first==NULL)
    {
        first = new_Node;
        last = new_Node;
        count++;
    }
    else
    {
        found = false;
        current = first;
        while(current!=NULL && !found)
        {
            if(current->infomation>= insert_Item)
                found= true;
            else
            {
                trail_current = current;
                current= current->next;
            }
        }
        if(current == first)
        {
            first->back = new_Node;
            new_Node->next = first;
            first = new_Node;
            count++;
        }
        else
        {
            if(current !=NULL)
            {
                trail_current -> next = new_Node;
                new_Node->back = trail_current;
                new_Node->next = current;
                current->back = new_Node;
            }
            else
            {
                trail_current->next = new_Node;
                new_Node->back = trail_current;
                last = new_Node;
            }
            count++;
        }
    }
}

template<class Type>
void double_Linked_List<Type>::  delete_Node(const Type& delete_Item)
{
    node_Type<Type> *current;
    node_Type<Type> *trail_Current;
    bool found;
    
    if(first == NULL)
        cout<<"cannot delete from an empty list" <<endl;
    else if(first ->infomation == delete_Item)
    {
        current = first;
        first = first->next;
        if(first != NULL)
        {
            first ->back = NULL;
        }
        else
            last = NULL;
        count--;
        delete current;
    }
    else
    {
        found = false;
        current = first;
        while(current!= NULL &&!found)
        {
            if(current->infomation >= delete_Item)
                found = true;
            else
                current=current->next;
        }
        if(current==NULL)
        {
            cout<<"item is not in the list "<<endl;
        }
        else if(current->infomation == delete_Item)
        {
            trail_Current = current->back;
            trail_Current -> next = current->next;
            if(current->next !=NULL)
                current->next->back=trail_Current;
            if(current==last)
                last=trail_Current;
            
            count--;
            delete current;
        }
        else{
            cout<<"the item to be dledted is not in the list "<<endl;
        }
    }
}

template<class Type>
double_Linked_List<Type>:: double_Linked_List()
{
    first=NULL;
    last = NULL;
    count =0;
}

template<class Type>
double_Linked_List<Type>:: double_Linked_List(const double_Linked_List<Type> & other_List)
{
    first= NULL;
    copyList(other_List);
}

template<class Type>
void double_Linked_List<Type>::  copy_List(const double_Linked_List<Type> & other_List)
{
    node_Type<Type> *new_Node;
    node_Type<Type> *current;
    
    if (first!= NULL)
        destory();
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
