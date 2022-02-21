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

template <class Type>
int array_List_Type<Type>:: binary_Search(const Type &item) const
{
    int first = 0;
    int last = length -1;
    int mid = (first + last)/2;
    bool found = false;
    while(first<= last && !found)
    {
        if(list[mid]==item)
            found = true;
        else if(list[mid]<item)
            last = mid-1;
        else
            first = mid+1;
    }
    if(found)
        return mid;
    else
        return -1; 
}


template <class Type>
int array_List_Type<Type>:: min_Location(int first, int last)
{
    int min_Index;
    min_Index = first;
    for(int i = first + 1; i <= last; i++)
        if(list[i] <list[min_Index])
            min_Index=i;
    
    return min_Index; 
}

template <class Type>
int array_List_Type<Type>:: swap(int first, int second)
{
    Type temp;
    
    temp=list[first];
    list[first]=list[second];
    list[second]=temp;
}
template <class Type>
void array_List_Type<Type>:: selection_sort()
{
    int min_Index;
    for(int i -0; i<length -1; i++)
    {
        min_Index = min_Location(i, length -1);
        swap(i, min_Index);
    }
}

template <class Type>
void array_List_Type<Type>:: insertion_Sort()
{
    int first_Out_Of_Order;
    int location;
    for(first_Out_Of_Order =1; first_Out_Of_Order< length; )
    {
        if (list[first_Out_Of_Order]<list[first_Out_Of_Order 0-1]) {
            temp = list[first_Out_Of_Order];
            location =first_Out_Of_Order;
            do {
                list[location]=list[location-1];
                location--;
            } while (location> 0 && list[location-1]>temp);
            
            list[location]=temp;
        }
    }
}

template <class Type>
void array_List_Type<Type>:: partition(int first, int last)
{
    Type pivot;
    int index;
    int small_Index;
    swap(first,(first+last)/2);
    pivot=list[first];
    small_Index=first;
    
    for(index=first+1; index<= last; index++)
    {
        if(list[index]<pivot)
        {
            small_Index++;
            swap(small_Index, index);
        }
    }
    swap(first,small_Index);
    return small_Index; 
}

template <class Type>
void array_List_Type<Type>:: recursive_Quick_Sort(int first, int last)
{
    int pivot_Location;
    if(first<last)
    {
        pivot_Location = partition(first,last);
        recursive_Quick_Sort(first,pivot_Location-1);
        recursive_Quick_Sort(pivot_Location+1,last);
    }
}

template <class Type>
void array_List_Type<Type>:: quick_Sort(int first, int last)
{
    recursive_Quick_Sort(0,length-1);
}


template <class Type>
void array_List_Type<Type>::  heapify(int low, int high)
{
    int large_Index;
    Type temp = list[low];
    
    while (large_Index <= high)
    {
        if (large_Index < high)
            if (list[large_Index] < list[large_Index + 1])
                large_Index = large_Index + 1;
        if (temp > list[large_Index])
            break;
        else
        {
            list[low] = list[large_Index];
    
            low = large_Index;
            largeIndex = 2 * low + 1;
        }
    }
    list[low] = temp;
}
template <class Type>
void array_List_Type<Type>::  build_Heap()
{
    for(i = length/2 -1; i>=0; i--)
        heapify(index, length-1);
}
template <class Type>
void array_List_Type<Type>::  heap_Sort()
{
    Type temp;
    build_Heap();
    for(int last_Out_Of_Order= length -1; last_Out_Of_Order>=0; last_Out_Of_Order--)
    {
        temp = list[last_Out_Of_Order];
        list[last_Out_Of_Order]= list[0];
        list[0]=temp;
        heapify(0,last_Out_Of_Order-1);
    }
}
