//
//  Queue_Link.cpp
//  review_C++
//
//  Created by Brandon Johns on 2/19/22.
//

#include <stdio.h>
#include "Queues_Review.hpp"
#include <iostream>
using namespace std;


template<class Type>
const linked_Queue_Type<Type> & linked_Queue_Type<Type>:: operator=(const linked_Queue_Type<Type>& equal )
{
    if(this!= &equal)
        copy_Queue(equal);
    return *this;

}
template<class Type>
bool linked_Queue_Type<Type>:: is_Empty_Queue() const
{
    return(front_Queue==NULL);
}
template<class Type>
bool linked_Queue_Type<Type>:: is_Full_Queue() const
{
    return false;
}
template<class Type>
void linked_Queue_Type<Type>:: initialize_Queue()
{
    node_Type<Type> *temp;
    while(front_Queue !=NULL)
    {
        temp = front_Queue;
        front_Queue= front_Queue->link;
        delete temp;
    }
    rear_Queue = NULL;
}
template<class Type>
void linked_Queue_Type<Type>:: add_Queue(const Type& newItem)
{
    node_Type<Type> * new_Node;
    new_Node = new node_Type<Type>;
    new_Node->infomation = newItem;
    new_Node->link=NULL;
    if(front_Queue==NULL)
    {
        front_Queue= new_Node;
        rear_Queue = new_Node;
    }
    else
    {
        rear_Queue->link = new_Node;
        rear_Queue = rear_Queue->link;
    }
}

template<class Type>
void linked_Queue_Type<Type>:: delete_Queue()
{
    node_Type<Type> *temp;
    if(!is_Empty_Queue())
    {
        temp = front_Queue;
        front_Queue=front_Queue->link;
        delete temp;
        if(front_Queue==NULL)
            rear_Queue= NULL;
      
    }
    else
        cout<<"cannot delete queue is empty "<<endl;
}
template<class Type>
Type linked_Queue_Type<Type>:: front() const
{
    assert(front_Queue != NULL);
    return front_Queue->infomation;
}
template<class Type>
Type linked_Queue_Type<Type>:: back() const
{
    assert(rear_Queue != NULL);
    return rear_Queue->infomation;
}
template<class Type>
linked_Queue_Type<Type>:: linked_Queue_Type()
{
    front_Queue=NULL;
    rear_Queue=NULL;
}
template<class Type>
linked_Queue_Type<Type>:: linked_Queue_Type(const linked_Queue_Type<Type> & other_Queue)
{
    front_Queue = NULL;
    copy_Queue(other_Queue);
}
template<class Type>
linked_Queue_Type<Type>:: ~linked_Queue_Type()
{
    initialize_Queue();
}

template<class Type>
void linked_Queue_Type<Type>:: copy_Queue(const linked_Queue_Type<Type> & other_Queue)
{
    node_Type<Type> *new_Node;
    node_Type<Type> *current;
    node_Type<Type> *last;
    
    if(front_Queue !=NULL)
        initialize_Queue();
    if(other_Queue.queue_Front==NULL)
    {
        front_Queue = NULL;
    }
    else
    {
        current = other_Queue.front_Queue;
        front_Queue= new node_Type<Type>;
        
        front_Queue->infomation = current->infomation;
        front_Queue->link = NULL;
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
