//
//  Array_Review.hpp
//  review_C++
//
//  Created by Brandon Johns on 2/3/22.
//


#include <stdio.h>
#include <iostream>
#include <string>
#include <array> 


template <class Type>
class array_List_Type
{
protected:
    Type *list;
    int length;
    int max_Size;

public:
    // assignment operator overload
    array_List_Type();
    const array_List_Type<Type> & operator = (const array_List_Type<Type> & );
    bool is_Empty() const;
    bool is_Full() const;
    int list_Size() const;
    int max_List_Size() const;
    void print() const;
    bool is_Item_Equal_To(int location, const Type& item) const;
    void insert_Item_At(int location, const Type& inserted_Item);
    void insert_At_End(const Type& inserted_End_Item);
    void remove_Item_At(int location);
    void retrieve_Item_At(int location, Type& retrieved_Item);
    void replace_Item_At(int location, Type& replaced_Item);
    void clear_List();
    int sequential_Search(const Type& item) const;
    void insert_Item(const Type& inserted_Item);
    void remove_Item(const Type& removed_Item);
    array_List_Type(int size);
    // copy constructor
    array_List_Type(const array_List_Type<Type>& otherList);
    //destructor
    ~array_List_Type();
    
    
    
};

