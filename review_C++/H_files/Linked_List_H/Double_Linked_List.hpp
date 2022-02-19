//
//  Double_Linked_List.hpp
//  review_C++
//
//  Created by Brandon Johns on 2/18/22.
//


#include <stdio.h>

template <class Type>
struct node_Type {
    Type infomation;
    node_Type<Type> *next;
    node_Type<Type> *back;
};

template<class Type>
class double_Linked_List
{
public:
    const double_Linked_List<Type> & operator =(const double_Linked_List<Type> & equal);
    void initialized_List();
    bool is_Empty_List();
    void destory();
    void print() const;
    void reverse_Print() const;
    int length() const;
    Type front() const;
    Type back() const;
    bool search(const Type& search_Item) const;
    void insert(const Type& insert_Item);
    void delete_Node(const Type& delete_Item);
    double_Linked_List();
    double_Linked_List(const double_Linked_List<Type> & other_List);
    ~double_Linked_List();
protected:
    int count;
    node_Type<Type> *first;
    node_Type<Type> *last;
private:
    void copy_List(const double_Linked_List<Type> & other_List);
};
