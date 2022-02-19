//
//  main.cpp
//  review_C++
//
//  Created by Brandon Johns on 2/3/22.
//

#include <iostream>
#include "Array_Review.h"
#include "ordered_Linked_List.hpp"
#include "unordered_Linked_List.hpp"
#include "Linked_List_Review.hpp"
using namespace std;
#include <string>
#include <vector>



int main() {
   
}
/*
void vector()
{
   vector<int> int_List;
    
    int_List.push_back(10);
    int_List.push_back(11);
    int_List.push_back(12);
    int_List.push_back(13);
    int_List.push_back(14);
    int_List.push_back(15);
    int_List.push_back(16);
    int_List.push_back(17);
    int_List.push_back(18);
    int_List.push_back(19);
    
    cout<<"elements: "<<endl;
    for(int i=0; i < 11; i++)
    {
        cout<<int_List[i]<<" "<<endl;
    }
    
    cout<<endl;
    
    for(int i =0; i<11; i++)
    {
        int_List[i] *=2;
        cout<<int_List[i] << "" <<endl;
    }
    
    vector<int>::iterator list_IT;
    cout<<"list elements: "<<endl;
    
    for(list_IT = int_List.begin(); list_IT != int_List.end(); ++list_IT)
    {
        cout<< *list_IT<< ""<<endl;
        
    }
    list_IT= int_List.begin();
    ++list_IT;
    ++list_IT;
    
    int_List.insert(list_IT,20);
    
    cout<<"list: "<<endl;
    
    for (list_IT = int_List.begin();list_IT != int_List.end(); ++list_IT)
    {
        cout<< *list_IT<< " " <<endl;
    }
    
    
}
void array()
{
    
    array_List_Type <int> int_List;
    array_List_Type <string> string_List;
    
    int number;
    string str;
    
    cout << "enter 5 numbers: "<<endl;
    for (int counter =0; counter<5; counter++)
    {
        cin>> number;
        int_List.insert_Item_At(counter, number);
    }
    cout<<endl;
    
    cout<<"list entered is: ";
    int_List.print();
    cout<<endl;
    
    cout<<"enter a number to be deleted: "<<endl;
    cin>> number;
    int_List.remove_Item(number);
    
    int_List.print();
    cout<<endl;
    
    
    cout << "enter 5 names: "<<endl;
    for (int counter =0; counter<5; counter++)
    {
        cin>> str;
        string_List.insert_Item_At(counter, str);
    }
    cout<<endl;
    
    cout<<"list entered is: ";
    string_List.print();
    cout<<endl;
    
    cout<<"enter a name to be deleted: "<<endl;
    cin>> str;
    string_List.remove_Item(str);
    
    string_List.print();
    cout<<endl;
    
}
 */
