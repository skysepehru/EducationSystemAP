#ifndef TA_19_CONTROLLER_H
#define TA_19_CONTROLLER_H

#include <string>
#include <vector>
#include "../Model/Student.h"
#include "../Model/Professor.h"
#include "../Model/Course.h"
#include "../Model/DoubleMajorStudent.h"

class Controller {
    friend class Menu;
    friend class LeafMenu;
    friend class CommandsFromFileMenu;
private:
    std::string currentSemester;
    std::vector<Student> students;
    std::vector<Professor> professors;
    std::vector<Course> courses;
    std::vector<Course> currentSemesterCourses;
    std::vector<Person*> mathClass;
    Controller() = default;

public:
    explicit Controller(std::string currentSemester);
    void load();
    void save() const;

    void addStudent(std::string ID, std::string first, std::string last);
    void addProfessor(std::string ID, std::string first, std::string last, std::string title);
    void addCourse(std::string courseName, std::string profLast, std::string semester,
            std::vector<std::string> pre);
    void addMathClassStudent(std::string studentName , std::string lastName , std::string studentID , double workHours , bool isDoubleMajor);
    void addMathClassProfessor(std::string name , std::string lastName , std::string ID , double workHours , std::string title);
    double calculateMathClassTotalSalary();
    void takeCourse(const std::string& studentID, const std::string& courseName);
    void dropCourse(const std::string& studentID, const std::string& courseName);
    Student& findStudent(std::string ID);


    bool inStudents(const std::string& ID) const;
    bool inProfessors(const std::string& ID) const;
    bool inProfessorsByLastName(const std::string& last) const;
    bool inCourses(const std::string& courseName) const;
};


#endif //TA_19_CONTROLLER_H
