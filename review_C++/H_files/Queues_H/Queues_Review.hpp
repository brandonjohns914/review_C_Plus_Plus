//
//  Queues_Review.hpp
//  review_C++
//
//  Created by Brandon Johns on 2/19/22.
//



#include <stdio.h>

template <class Type>
class queues_ADT{
public:
    virtual void initialize_Queue() = 0;
    virtual bool is_Empty_Queue() const =0;
    virtual bool is_Full_Queue() const =0;
    virtual void add_Queue(const Type& newItem) = 0;
    virtual void delete_Queue() = 0; 
    virtual Type front() const = 0;
    virtual Type back() const = 0;
};

template <class Type>
class queue_Type: public queues_ADT<Type> {
public:
    const queue_Type<Type>& operator=(const queue_Type<Type>& equal );
    bool is_Empty_Queue() const;
    bool is_Full_Queue() const;
    void initialize_Queue();
    void add_Queue(const Type& newItem);
    void delete_Queue();
    Type front() const;
    Type back() const;
    queue_Type(int queue_Size =100);
    queue_Type(const queue_Type<Type> & other_Queue);
    ~queue_Type();

private:
    int max_Queue_Size;
    int count;
    int queue_Front;
    int queue_Rear;
    Type* list;
    void copy_Queue(const queue_Type<Type> & other_Queue);
};

template <class Type>
struct node_Type
{
Type infomation;
node_Type<Type> *link;
    
};

template <class Type>
class linked_Queue_Type: public queues_ADT<Type> {
public:
    const linked_Queue_Type<Type>& operator=(const linked_Queue_Type<Type>& equal );
    bool is_Empty_Queue() const;
    bool is_Full_Queue() const;
    void initialize_Queue();
    void add_Queue(const Type& newItem);
    void delete_Queue();
    Type front() const;
    Type back() const;
    linked_Queue_Type();
    linked_Queue_Type(const linked_Queue_Type<Type> & other_Queue);
    ~linked_Queue_Type();

private:
    node_Type<Type> *front_Queue;
    node_Type<Type> *rear_Queue;
    void copy_Queue(const linked_Queue_Type<Type> & other_Queue);
};

