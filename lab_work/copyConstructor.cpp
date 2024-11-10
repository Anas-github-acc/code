#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

// You have a class Employee that contains an immutable String for the employee's name
// and a mutable ArrayList<Project> representing their assigned projects. Implement a copy
// constructor that ensures the name remains shared (since it's immutable), but creates deep
// copies of each project in the ArrayList. How would you handle this efficiently without breaking
// encapsulation or creating memory leaks?

class Project {
private: 
    string projectName;

public:
    Project(const string& name) : projectName(name) {}
    // Project(const Project& other) : projectName(other.projectName) {}
    
    string getName() const {
        return projectName;
    }
};

class Employee {
private:
    const string name;
    vector<std::unique_ptr<Project>> projects;

public:
    Employee(const string& name, const vector<Project>& projectsList) 
        : name(name) {
        for (const auto& project : projectsList) {
            projects.push_back(make_unique<Project>(project));
        }
    } 

    Employee(const Employee& other) 
        : name(other.name) {
        for (const auto& project : other.projects) {
            projects.push_back(make_unique<Project>(*project));
        }
    }

    string getName() const {
        return name;
    }

    vector<Project> getProjects() const {
        vector<Project> copiedProjects;
        for (const auto& project : projects) {
            copiedProjects.push_back(*project);
        }
        return copiedProjects;
    }
};

int main() {
    vector<Project> projects = { Project("Project A"), Project("Project B") };
    Employee emp1("Anas", projects);

    Employee emp2 = emp1; // shallow copy
    Employee emp3 = Employee(emp1); // deep copy

    cout << "Employee 1: " << emp1.getName() << endl;
    for (const auto& project : emp1.getProjects()) {
        cout << "  " << project.getName() << endl;
    }

    cout << "Employee 2: " << emp2.getName() << endl;
    for (const auto& project : emp2.getProjects()) {
        cout << "  " << project.getName() << endl;
    }

    cout << "Employee 3: " << emp3.getName() << endl;
    for (const auto& project : emp3.getProjects()) {
        cout << "  " << project.getName() << endl;
    }

    return 0;
}
