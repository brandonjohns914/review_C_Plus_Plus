//
//  unordered_Linked_List.cpp
//  review_C++
//
//  Created by Brandon Johns on 2/18/22.
//

#include "unordered_Linked_List.hpp"
#include "Linked_List_Review.hpp"
#include <stdio.h>
#include <iostream>
#include <string>
#include <array>
using namespace std; 
template <class Type>
bool unordered_Linked_List<Type>:: search(const Type& search_Item)
{
    node_Type<Type> *current;
    bool found = false;
    current = first;
    while(current!=NULL && !found)
    {
        if(current->info == search_Item)
            found = true;
        else
        {
            current = current->link;
            return found;
        }
    }
}
template <class Type>
void unordered_Linked_List<Type>:: insert_First(const Type& new_Item)
{
    node_Type<Type> *new_Node;
    new_Node = new node_Type<Type>;
    new_Node->infomation = new_Item;
    new_Node->link = first;
    first = new_Node;
    count++;
    if(last==NULL)
    {
        last = new_Node;
    }
}
template <class Type>
void unordered_Linked_List<Type>:: insert_Last(const Type& new_Item)
{
    node_Type<Type> *new_Node;
    new_Node = new node_Type<Type>;
    new_Node->infomation = new_Item;
    new_Node->link;
    
    if (first==NULL)
    {
        first = new_Node;
        last = new_Node;
        count++;
    }
    else
    {
        last -> link = new_Node;
        last = new_Node;
        count++;
    }
}
template <class Type>
void unordered_Linked_List<Type>:: delete_Node(const Type& delete_Item)
{
    node_Type<Type> *current;
    node_Type<Type> *trail_Current;
    bool found;
    
    if(first == NULL)
        cout<<" cannot delete from an empty list"<<endl;
    else
    {
        if(first->infomation == delete_Item)
        {
            current= first;
            first=first->link;
            count--;
            if(first==NULL)
                last=NULL;
            
            delete  current;
        }
        else
        {
            found = false;
            trail_Current = first;
            current = first->link;
            while(current!=NULL && !found)
            {
                if(current->infomation !=delete_Item)
                {
                    trail_Current = current;
                    current= current->link;
                }
                else
                {
                    found = true;
                }
            }
            if(found)
            {
                trail_Current->link = current->link;
                count--;
                if(last==current)
                    last=trail_Current;
            
                delete current;
            }
            else
            {
                cout<<"item is not in the list "<<endl;
            }
        }
    }
}
