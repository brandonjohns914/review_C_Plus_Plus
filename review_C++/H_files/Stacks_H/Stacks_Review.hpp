//
//  Stacks_Review.hpp
//  review_C++
//
//  Created by Brandon Johns on 2/19/22.
//

#include <stdio.h>


template <class Type>
class stack_ADT{
public:
    virtual void initialize_Stack() = 0;
    virtual bool is_Empty_Stack() const =0;
    virtual bool is_Full_Stack() const =0;
    virtual void push(const Type& newItem) = 0;
    virtual Type top() const = 0;
    virtual void pop() = 0;
};

template <class Type>
class stack_Type: public stack_ADT<Type> {
public:
    const stack_Type<Type> & operator =(const stack_Type<Type>& equal );
    void initialize_Stack();
    bool is_Stack_Empty() const;
    bool is_Stack_Full() const;
    void push(const Type& new_Item);
    Type top() const;
    void pop();
    stack_Type(int stack_Size = 100);
    stack_Type(const stack_Type<Type> & other_Stack);
    ~stack_Type();
private:
    int max_Stack_Size;
    int stack_Top;
    Type *list;
    void copy_Stack(const stack_Type<Type> & other_Stack);
};



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
