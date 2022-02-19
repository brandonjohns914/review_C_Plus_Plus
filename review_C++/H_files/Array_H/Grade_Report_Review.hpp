//
//  Grade_Report_Review.hpp
//  review_C++
//
//  Created by Brandon Johns on 2/7/22.
//



#include <stdio.h>
#include <iostream>
#include <string>
#include <array>
using namespace std;

class courseType
{
public:
    void set_Course_Infomation(string course_Name_F, string course_Number_F, char grade_F, int number_Credits_F);
    void print(ostream& output, bool is_grade);
    
    int get_Credits();
    
    void get_Course_Number(string& course_Number);
    
    char get_Grade();
    
    bool operator==(const courseType& equal_equal) const;
    bool operator !=(const courseType& not_Equal) const;
    bool operator <=(const courseType& lessThan_Equal) const;
    bool operator < (const courseType& less_Than) const;
    bool operator >= (const courseType& greaterThan_Equal) const;
    bool operator >(const courseType& greater_Than) const;
    
    courseType(string course_Name, string course_Number, char Grade, int credits);
    
private:
    string course_Name;
    string course_Number;
    char course_Grade;
    int course_Credits; 
    
};



