//
// Created by skysepehr on 7/28/2020.
//

#ifndef TA_19_DOUBLEMAJORSTUDENT_H
#define TA_19_DOUBLEMAJORSTUDENT_H
#include "Student.h"

class DoubleMajorStudent : public Student
{
private:
    std::string major2;
public:
    double calculateSalary() const override;
    DoubleMajorStudent() : Student() {}
    DoubleMajorStudent(const std::string& studentId, std::string first, std::string last , double workHours,
            std::vector<std::string> passedCourses, std::map<std::string, double> currentSemesterCourses , std::string secondMajor);
};


#endif //TA_19_DOUBLEMAJORSTUDENT_H
