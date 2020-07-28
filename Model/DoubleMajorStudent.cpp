//
// Created by skysepehr on 7/28/2020.
//

#include "DoubleMajorStudent.h"

double DoubleMajorStudent::calculateSalary() const {
    return 6500 * getWorkHours();
}

DoubleMajorStudent::DoubleMajorStudent(const std::string &studentId, std::string first, std::string last,
                                       double workHours, std::vector<std::string> passedCourses,
                                       std::map<std::string, double> currentSemesterCourses, std::string secondMajor)
                                       : Student(studentId,first,last,workHours,passedCourses,currentSemesterCourses)
                                       ,major2{std::move(secondMajor)}{}
