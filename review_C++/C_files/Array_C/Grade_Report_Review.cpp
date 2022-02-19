//
//  Grade_Report_Review.cpp
//  review_C++
//
//  Created by Brandon Johns on 2/7/22.
//

#include "Grade_Report_Review.hpp"

#include <stdio.h>
#include <iostream>
#include <string>
#include <array>
#include <ostream>
#include <iomanip>
using namespace std;


void courseType:: set_Course_Infomation(string course_Name_F, string course_Number_F, char grade_F, int number_Credits_F)
{
    course_Name = course_Name_F;
    course_Number = course_Number_F;
    course_Grade = grade_F;
    course_Credits = number_Credits_F;
}
void courseType::  print(ostream& output, bool is_grade)
{
    output<<left;
    output<< setw(8) << course_Name << "   "<<endl;
    output<< setw(15) << course_Name << endl;
    output.unsetf(ios::left);
    output<<setw(3)<< course_Credits << "   "<<endl;
    if(is_grade)
        output<<setw(4)<< course_Grade<<endl;
    else
        output<<setw(4)<< "***" <<endl;
    
    
}

int courseType::  get_Credits()
{
    return course_Credits;
}

void courseType::  get_Course_Number(string& course_Number)
{
    course_Number = course_Number;
}

char courseType:: get_Grade()
{
    return course_Grade;
}

bool courseType:: operator==(const courseType& equal_equal) const
{
    return (course_Number == equal_equal.course_Number);
}
bool courseType::  operator !=(const courseType& not_Equal) const
{
    return (course_Number != not_Equal.course_Number);
}
bool courseType:: operator <=(const courseType& lessThan_Equal) const
{
    return (course_Number <= lessThan_Equal.course_Number);
}
bool courseType:: operator < (const courseType& less_Than) const
{
    return(course_Number < less_Than.course_Number);
}
bool courseType:: operator >= (const courseType& greaterThan_Equal) const
{
    return (course_Number >= greaterThan_Equal.course_Number);
}
bool courseType:: operator >(const courseType& greater_Than) const
{
    return (course_Number > greater_Than.course_Number);
}

courseType::courseType(string course_Name, string course_Number, char Grade, int credits)
{
    set_Course_Infomation(course_Name,course_Number, Grade, credits );
}
