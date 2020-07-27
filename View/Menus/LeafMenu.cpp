#include "LeafMenu.h"

using namespace std;

LeafMenu::LeafMenu(std::string name, Menu* parent)
    : Menu{move(name), parent} {}

void LeafMenu:: showSubMenus() const {}

void LeafMenu::run() {
    setCurrentMenu(parent);

    if(name == "Show This Semester Courses"){
        if(controller.currentSemesterCourses.empty())
        {
            cout<<"There Are no Courses for This Semester."<<endl;
            return;
        }
        cout<<"Current Semester Courses Are:"<<endl;
        for(const auto& x : controller.currentSemesterCourses)
        {
            cout<<x.getCourseName()<<endl;
        }
    }

    else if(name == "Take Course"){
        string id,course;
        cout<<"Enter Student ID:"<<endl;
        cin>>id;
        cout<<"Enter Course:"<<endl;
        cin>>course;
        try {
            controller.takeCourse(id,course);
            cout<<"Course has been added."<<endl;
        }
        catch (const invalid_argument& e ){
            cout << e.what() << endl;
        }
    }

    else if(name == "Drop Course"){
        string id,course;
        cout<<"Enter Student ID:"<<endl;
        cin>>id;
        cout<<"Enter Course:"<<endl;
        cin>>course;
        try {
            controller.dropCourse(id,course);
            cout<<"Course had been removed."<<endl;
        }
        catch (const invalid_argument& e ){
            cout << e.what() << endl;
        }
    }

    else if(name == "Show Student Courses In Current Semester"){
        string id;
        cout<<"Enter Student ID:"<<endl;
        cin>>id;
        try {
            map<string, double> m = controller.findStudent(id).getCurrentSemesterCourses();
            vector<string> v;
            for (map<string, double>::iterator it = m.begin(); it != m.end(); ++it) {
                v.push_back(it->first);
                cout << it->first << "\n";
            }
        }
        catch (const invalid_argument& e ) {
            cout << e.what() << endl;
        }
    }

    else if(name == "Calculate Student Salary"){
        string id;
        cout<<"Enter Student ID:"<<endl;
        cin>>id;
        try {
            Student student = controller.findStudent(id);
            cout<<"Student Salary Is:"<<endl<<student.calculateSalary()<<endl;
        }
        catch (const invalid_argument& e ){
            cout << e.what() << endl;
        }
    }

    else if(name == "Show Professor Courses In Current Semester"){

    }

    else if(name == "Submit Grade"){

    }

    else if(name == "Calculate Professor Salary"){

    }

    else if(name == "Add Professor"){

    }

    else if(name == "Show Professors"){

    }

    else if(name == "Add Student"){
        string ID;
        cout << "Enter student number: ";
        cin >> ID;
        string first;
        cout << "Enter First Name: ";
        cin >> first;
        string last;
        cout << "Enter Last Name: ";
        cin >> last;
        controller.addStudent(ID, first, last);
    }

    else if(name == "Show Students"){

    }

    else if(name == "Add Course"){

    }

    else if(name == "Show All Courses"){

    }

    else{
        throw invalid_argument("This Menu hase not been defined!!");
    }
}
