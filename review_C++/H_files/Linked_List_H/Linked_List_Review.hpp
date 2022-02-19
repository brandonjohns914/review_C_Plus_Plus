//
//  Linked_List_Review.hpp
//  review_C++
//
//  Created by Brandon Johns on 2/18/22.
//



#include <stdio.h>

template <class Type>
struct node_Type
{
    Type infomation;
    node_Type<Type> *link;
};


// iterator
template <class Type>
class Linked_List_Iterator
{
protected:
    int count;
    node_Type<Type> *first;
    node_Type<Type> *last;
public:
    Linked_List_Iterator();
    Linked_List_Iterator(node_Type<Type> *pointer);
    Type operator*();
    
    Linked_List_Iterator<Type> operator++();
    bool operator == (const Linked_List_Iterator<Type> & right) const;
    
    bool operator!=(const Linked_List_Iterator<Type> & right) const;

private:
    node_Type<Type> *current;
};


//type
template <class Type>
class Linked_List_Type
{
public:
    const Linked_List_Type<Type> & operator = (const Linked_List_Type<Type> & equal);
    void initialize_List();
    
    bool is_Empty_List() const;
    void print() const;
    
    int length() const;
    void destory_List();
    Type front() const;
    Type back() const;
    
    virtual bool search(const Type& search_Item) const = 0;
    virtual void insert_First(const Type& newItem) = 0;
    virtual void insert_Last(const Type& newItem) = 0;
    virtual void delete_Node(const Type& deleteItem) = 0;
    Linked_List_Iterator<Type> begin();
    Linked_List_Iterator<Type> end();
    
    Linked_List_Type();
    Linked_List_Type(const Linked_List_Type<Type> & other_List);
    ~Linked_List_Type();
protected:
    int count;
    node_Type<Type> *first;
    node_Type<Type> *last;
private:
    void copyList(const Linked_List_Type<Type>& other_List);
};


// unordered
template <class Type>
class unordered_Linked_List: public Linked_List_Type<Type>
{
public:
    bool search(const Type& search_Item);
    void insert_First(const Type& new_Item);
    void insert_Last(const Type& new_Item);
    void delete_Node(const Type& delete_Item);
protected:
    int count;
    node_Type<Type> *first;
    node_Type<Type> *last;
};

// ordered 
template<class Type>
class ordered_Linked_List: public Linked_List_Type<Type>
{
public:
    bool search(const Type& search_Item);
    void insert(const Type& new_Item);
    void insert_First(const Type& new_Item);
    void insert_Last(const Type& new_Item);
    void delete_Node(const Type& delete_Item);
protected:
    int count;
    node_Type<Type> *first;
    node_Type<Type> *last;
};
