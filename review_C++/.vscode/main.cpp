//
//  main.cpp
//  review_C++
//
//  Created by Brandon Johns on 2/3/22.
//

#include <iostream>
#include "Array_Review.hpp"
using namespace std;
#include <string>

int main() {
    array_List_Type<int> int_List;
    array_List_Type<string> string_List;
    
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
