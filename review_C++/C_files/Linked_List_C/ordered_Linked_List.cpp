//
//  ordered_Linked_List.cpp
//  review_C++
//
//  Created by Brandon Johns on 2/18/22.
//


#include "Linked_List_Review.hpp"
#include <stdio.h>
#include <iostream>
#include <string>
#include <array>
using namespace std;

template<class Type>
bool ordered_Linked_List<Type>:: search(const Type& search_Item)
{
    bool found = false;
    node_Type<Type> *current;
    
    current = first;
    
    while(current!=NULL && !found)
    {
        if(current->infomation >= search_Item)
        {
            found = true;
        }
        else
        {
            current= current->link;
        }
    }
    if (found)
    {
        found = (current->infomation == search_Item);
        
    }
    return found; 
}
template<class Type>
void ordered_Linked_List<Type>:: insert(const Type& new_Item)
{
    node_Type<Type> *current;
    node_Type<Type> *trail_Currrent;
    node_Type<Type> *new_Node;
    bool found;
    
    new_Node= new node_Type<Type>;
    new_Node->infomation = new_Item;
    new_Node->link = NULL;
    
    if(first==NULL)
    {
        first= new_Node;
        last = new_Node;
        count++;
    }
    else
    {
        current = first;
        found = last;
        while(current!= NULL && !found)
        {
            if(current->infomation >= new_Item)
                found = true;
            else{
                trail_Currrent = current;
                current = current->link;
            }
        }
        if(current == first)
        {
            new_Node->link = first;
            first = new_Node;
            count++;
        }
        else
        {
            trail_Currrent->link = new_Node;
            new_Node->link = current;
            if(current==NULL)
                last = new_Node;
            count++;
        }
    }
}
template<class Type>
void ordered_Linked_List<Type>:: insert_First(const Type& new_Item)
{
    insert(new_Item);
}
template<class Type>
void ordered_Linked_List<Type>:: insert_Last(const Type& new_Item)
{
    insert(new_Item);
}
template<class Type>
void ordered_Linked_List<Type>:: delete_Node(const Type& delete_Item)
{
    node_Type<Type> *current;
    node_Type<Type> *trail_Current;
    bool found;
    
    if(first==NULL)
        cout<<"list is empty cannot delete an item from an empty list"<<endl;
    else
    {
        current= first;
        found = false;
        
        while(current!= NULL && !found)
        {
            if (current->infomation>= delete_Item)
                found=true;
            else
            {
                trail_Current= current;
                current= current->link;
            }
        }
        if(current == NULL)
            cout<<"the item is not in the list"<<endl;
        else
        {
            if(current->infomation == delete_Item)
            {
                if(first==current)
                {
                    first = first->link;
                    if(first==NULL)
                        last = NULL;
                    delete current;
                }
                else
                {
                    trail_Current->link = current->link;
                    if(current==last)
                        last = trail_Current;
                    delete current;
                }
                count--;
            }
            else
            {
                cout<<"item is not in the list "<<endl; 
            }
        }
    }
}
