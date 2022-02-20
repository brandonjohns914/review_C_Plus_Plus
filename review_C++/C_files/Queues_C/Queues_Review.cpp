//
//  Queues_Review.cpp
//  review_C++
//
//  Created by Brandon Johns on 2/19/22.
//

#include "Queues_Review.hpp"
#include <iostream>
using namespace std;

template<class Type>
const queue_Type<Type> & queue_Type<Type>:: operator=(const queue_Type<Type>& equal )
{
    if(this!= &equal)
        copy_Queue(equal);
    return *this;

}
template<class Type>
bool queue_Type<Type>:: is_Empty_Queue() const
{
    return(count ==0);
}
template<class Type>
bool queue_Type<Type>:: is_Full_Queue() const
{
    return(count == max_Queue_Size);
}
template<class Type>
void queue_Type<Type>:: initialize_Queue()
{
    queue_Front=0;
    queue_Rear= max_Queue_Size-1;
    count =0;
}
template<class Type>
void queue_Type<Type>:: add_Queue(const Type& newItem)
{
    if(!is_Full_Queue())
    {
        queue_Rear = (queue_Rear +1)% max_Queue_Size;
        count++;
        list[queue_Rear] = newItem;
    }
    else
        cout<<"cannot add queue is full"<<endl;
}
template<class Type>
void queue_Type<Type>:: delete_Queue()
{
    if(!is_Full_Queue())
    {
        queue_Front = (queue_Front +1)% max_Queue_Size;
        count--;
      
    }
    else
        cout<<"cannot delete queue is empty "<<endl;
}
template<class Type>
Type queue_Type<Type>:: front() const
{
    assert(!is_Empty_Queue());
    return list[queue_Front];
}
template<class Type>
Type queue_Type<Type>:: back() const
{
    assert(!is_Empty_Queue());
    return list[queue_Rear];
}
template<class Type>
queue_Type<Type>:: queue_Type(int queue_Size)
{
    if(queue_Size<=0)
    {
        cout<<"queue must be positive. making default size of 100"<<endl;
        max_Queue_Size=100;
    }
    else
        max_Queue_Size=queue_Size;
    
    queue_Front=0;
    queue_Rear=max_Queue_Size-1;
    count=0;
    list= new Type[max_Queue_Size];
}
template<class Type>
queue_Type<Type>:: queue_Type(const queue_Type<Type> & other_Queue)
{
    list = NULL;
    copy_Queue(other_Queue);
}
template<class Type>
queue_Type<Type>:: ~queue_Type()
{
    delete [] list;
}
template<class Type>
void queue_Type<Type>:: copy_Queue(const queue_Type<Type> & other_Queue)
{
    delete [] list;
    max_Queue_Size= other_Queue.max_Queue_Size;
    queue_Front= other_Queue.queue_Front;
    
    list = new Type[max_Queue_Size];
    for (int i =0; i < max_Queue_Size; i++)
    {
        list[i]= other_Queue.list[i];
    }
}
