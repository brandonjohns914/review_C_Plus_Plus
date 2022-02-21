//
//  unordered_Linked_List.cpp
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

template <class Type>
void unordered_Linked_List<Type>:: linked_Insertion_Sort()
{
    node_Type<Type> *last_In_Order;
    node_Type<Type> *first_Out_Of_Order;
    node_Type<Type> *current;
    node_Type<Type> *trail_Current;
    
    last_In_Order= first;
    
    if(first == NULL)
        cerr<< "cannot sort an empty list"<<endl;
    else if(first->link == NULL)
        cout<<"list only has 1 item"<<endl;
    else
    {
        while(last_In_Order->link != NULL)
        {
            first_Out_Of_Order = last_In_Order->link;
            if(first_Out_Of_Order->infomation < first->infomation)
            {
                last_In_Order->link = first_Out_Of_Order->link;
                first_Out_Of_Order->link = first;
                first=first_Out_Of_Order;
            }
            else
            {
                trail_Current=first;
                current=first->link;
                while(current->infomation<first_Out_Of_Order->infomation)
                {
                    trail_Current=current;
                    current=current->link;
                }
                if(current!= first_Out_Of_Order)
                {
                    last_In_Order->link = first_Out_Of_Order->link;
                    first_Out_Of_Order->link = current;
                    trail_Current->link=first_Out_Of_Order;
                }
                else
                    last_In_Order= last_In_Order->link; 
            }
        }
    }
}

template <class Type>
void unordered_Linked_List<Type>:: divide_List(node_Type<Type> *first1, node_Type<Type>* &first2)
{
    node_Type<Type> * middle;
    node_Type<Type> *current;
    
    if(first1 == NULL)
        first2 = NULL;
    else if(first1->link == NULL)
        first2=NULL;
    else
    {
        middle = first1;
        current = first1->link;
        
        if(current!=NULL)
            current = current->link;
        while(current!= NULL)
        {
            middle= middle->link;
            current = current->link;
            if(current!=NULL)
                current=current->link;
        }
        
        first2= middle->link;
        middle->link = NULL;
    }
}

template <class Type>
node_Type<Type>* unordered_Linked_List<Type>:: merge_List(node_Type<Type> *first1 , node_Type<Type>* &first2)
{
    node_Type<Type> *last_Small;
    node_Type<Type> *new_Head;
    
    if(first1 == NULL)
        return first2;
    else if(first2==NULL)
        return first1;
    else
    {
        if(first1->infomation< first2->infomation)
        {
            new_Head= first1;
            first1=first1->link;
            last_Small=new_Head;
        
        }
        else
        {
            new_Head = first2;
            first2=first2->link;
            last_Small= new_Head;
        }
        while(first1!=NULL && first2!=NULL)
        {
            if(first1->infomation < first2->infomation)
            {
                new_Head = first1;
                first1= first1->link;
                last_Small= new_Head;
            }
            else
            {
                new_Head = first2;
                first2= first2->link;
                last_Small= new_Head;
            }
        }
            if(first1 == NULL)
                last_Small->link = first2;
            else
                last_Small->link=first1;
            
        return new_Head;
    }
}

template <class Type>
void unordered_Linked_List<Type>:: recursive_Merge_Sort(node_Type<Type> * &head)
{
    node_Type<Type> *other_Head;
    if(head!= NULL)
    {
        if(head->link != NULL)
        {
            divide_List(head, other_Head);
            recursive_Merge_Sort(head);
            recursive_Merge_Sort(other_Head);
            head=merge_List(head, other_Head);
        }
    }
}

template <class Type>
void unordered_Linked_List<Type>::  merge_Sort()
{
    recursive_Merge_Sort(first);
    if(first==NULL)
        last=NULL;
    else{
        last = first;
        while(last->link !=NULL)
            last=last->link;
    }
}
