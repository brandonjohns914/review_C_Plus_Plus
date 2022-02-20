//
//  Stack_Linked.hpp
//  review_C++
//
//  Created by Brandon Johns on 2/19/22.
//
#include <stdio.h>
#include "Stacks_Review.hpp"

template <class Type>
struct node_Type
{
    Type infomation;
    node_Type<Type> *link;
};

template <class Type>
class linked_Stack_Type: public stack_ADT<Type> 
{
    
public:
    const linked_Stack_Type<Type> & operator = (const linked_Stack_Type<Type> & equal);
    bool is_Empty_Stack() const;
    bool is_Full_Stack() const;
    void initialize_Stack();
    void push(const Type& new_Item);
    Type top() const;
    void pop();
    linked_Stack_Type();
    linked_Stack_Type(const linked_Stack_Type<Type>& other_Stack);
    ~linked_Stack_Type();
private:
    node_Type<Type> *stack_Top;
    void copy_Stack(const linked_Stack_Type<Type>& other_Stack);
    
};

