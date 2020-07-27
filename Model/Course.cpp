#include "Course.h"
#include <iostream>

using namespace std;

Course::Course(std::string courseName, std::string profLastName, std::string semester
       , std::vector<std::string> preCourses)
       : courseName{move(courseName)}, profLastName{move(profLastName)}
         , semester{move(semester)}, preCourses{move(preCourses)}  {}


std::ostream& operator<<(std::ostream & output, const Course& course){
    output << course.courseName << '\t' << course.profLastName << '\t'
           << course.semester << '\t' << course.preCourses.size() << '\t';

    for(size_t i{0}; i < course.preCourses.size(); ++i){
        output << course.preCourses[i] << '\t';
    }

    return output;
}

std::istream& operator>>(std::istream & input, Course& course){
    string courseName;
    string profLastName;
    string semester;
    int preCoursesSize;
    vector<string> preCourses;
    string crs;
    input >> courseName >> profLastName >> semester >> preCoursesSize;

    for( size_t i{0}; i < preCoursesSize; ++i){
        input >> crs;
        preCourses.push_back(crs);
    }

    Course myCourse{courseName, profLastName, semester, preCourses};
    course = myCourse;

    return input;
}

const string &Course::getCourseName() const {
    return courseName;
}
