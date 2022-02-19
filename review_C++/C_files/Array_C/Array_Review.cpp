//
//  Array_Review.cpp
//  review_C++
//
//  Created by Brandon Johns on 2/3/22.
//

#include "Array_Review.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <array>
using namespace std;

template <class Type>
const array_List_Type<Type> & array_List_Type<Type>:: operator = (const array_List_Type<Type> & otherList)
{
    if(this!= &otherList)
    {
        delete [] list;
        max_Size = otherList.max_Size;
        length= otherList.length;
        
        list = new Type[max_Size];
        assert(list != NULL);
        for(int i=0; i<length; i++)
        {
            list[i] = otherList.list[i];
        }
    }
    return *this;
}

template <class Type>
bool array_List_Type<Type>:: is_Empty() const
{
    return length==0;
}

template <class Type>
bool array_List_Type<Type>:: is_Full() const
{
    return length==max_Size;
}

template <class Type>
int array_List_Type<Type>::list_Size() const
{
    return length;
}

template <class Type>
int array_List_Type<Type>::max_List_Size() const
{
    return max_Size;
}

template <class Type>
void array_List_Type<Type>:: print() const
{
    for (int i=0; i<length; i++)
    {
        cout<< list[i]<< " " <<endl;
    }
    cout<<endl;
}

template <class Type>
bool array_List_Type<Type>::is_Item_Equal_To(int location, const Type& item) const
{
    return list[location]==item;
}

template <class Type>
void array_List_Type<Type>:: insert_item_At(int location, const Type& inserted_Item)
{
    if(location< 0 || location >=max_Size){
        cerr << "the location that this item is to be inserted is out of range"<<endl;
    }
    else
    {
        if(length >= max_Size)
        {
            cerr<<"item cannot be inserted the list is full"<<endl;
        }
        else
        {
            for(int i = length; i > location; i--){
                list[i] = list[i-1]; // moves items down to make room in the list
                
                list[location] = inserted_Item;
                length++;
            }
        }
    }
}

template <class Type>
void array_List_Type<Type>::insert_At_End(const Type& inserted_End_Item)
{
    if(length>= max_Size)
    {
        cerr<<"list is full cannot add this item to the end"<<endl;
    }
    else
    {
        list[length]=inserted_End_Item;
        length++;
    }
}

template <class Type>
void array_List_Type<Type>::remove_Item_At(int location)
{
    if(location<0 || location>= length)
    {
        cerr<<"the item is not at this location so it cannot be removed"<<endl;
    }
    else{
        for (int i = location; i< length-1; i++)
        {
            list[i] = list[i+1];
            length--;
        }
    }
}
template <class Type>
void array_List_Type<Type>::retrieve_Item_At(int location, Type& retrieved_Item)
{
    if(location <0 || location >= length)
    {
        cerr<<"the item is not in this location so it cannot be retrieved"<<endl;
        
    }
    else
    {
        return retrieved_Item;
    }
}

template <class Type>
void array_List_Type<Type>::replace_Item_At(int location, Type& replaced_Item)
{
    if(location <0 || location >= length)
    {
        cerr<<"the item to replace is not here so it cannot be replaced"<<endl;
   }
    else
    {
        list[location]= replaced_Item;
    }
}

template <class Type>
void array_List_Type<Type>::clear_List()
{
    length =0;
}

template <class Type>
int array_List_Type<Type>::sequential_Search(const Type& item) const
{
    int location;
    bool found = false;
    for (location =0; location<length; location++)
    {
        if(list[location]==item)
        {
            found = true;
            break;
        }
        if (found)
        {
            return location;
        }
        else
        {
            return -1;
            
        }
    }
}

template <class Type>
void array_List_Type<Type>::insert_Item(const Type& inserted_Item)
{
    int location;
    if(location ==0 )
    {
        list[length++] = inserted_Item;
    }
    else if(length == max_Size)
    {
        cerr<< "cannot insert in a full list "<<endl;
    }
    else
    {
        location = sequential_Search(inserted_Item);
        if (location == -1)
        {
            list[length++];
        }
        else
        {
            cerr<<"item is already in the list no duplicate items allowed"<<endl;
        }
    }
    
}

template <class Type>
void array_List_Type<Type>::remove_Item(const Type& removed_Item)
{
    int location;
    if(length==0)
    {
        cerr<<"cannot delete from an empty list"<<endl;
    }
    else
    {
        location = sequential_Search(removed_Item);
        if(location!=-1)
        {
            remove_Item_At(location);
        }
        else{
            cout<<"item is not in the list "<<endl;
        }
    }
}

template <class Type>
array_List_Type<Type>:: array_List_Type(int size )
{
    if(size <0)
    {
        cerr<<"the size must be a positive number automatically creating an array of an 100"<<endl;
        max_Size= 100;
    }
    else
    {
        max_Size=size;
        
    }
    length =0;
    list = new Type[max_Size];
    assert(list!=NULL);
}

template <class Type>
// copy constructor
array_List_Type<Type>:: array_List_Type(const array_List_Type<Type>& otherList)
{
    max_Size = otherList.max_Size;
    length = otherList.length;
    list = new Type[max_Size];
    assert(list!= NULL);
    
    for(int j =0; j< length; j++)
    {
        list[j]=otherList.list[j];
    }
}

template <class Type>
//destructor
array_List_Type<Type>:: ~array_List_Type()
{
    delete [] list;
}
