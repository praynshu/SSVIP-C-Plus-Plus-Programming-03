#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Define the Student class
class Student {
private:
    int id;
    string name;
    double gpa;

public:
    // Constructor to initialize a student object
    Student(int id, const string& name, double gpa) : id(id), name(name), gpa(gpa) {}

    // Getter methods
    int getId() const { return id; }
    const string& getName() const { return name; }
    double getGpa() const { return gpa; }

    // Function to display student information
    void display() const {
        cout << "ID: " << id << " | Name: " << name << " | GPA: " << gpa << endl;
    }
};

// Function to add a new student record
void addStudent(vector<Student>& records) {
    int id;
    string name;
    double gpa;

    cout << "Enter Student ID: ";
    cin >> id;
    cout << "Enter Student Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter GPA: ";
    cin >> gpa;

    Student student(id, name, gpa);
    records.push_back(student);
    cout << "Student added successfully!" << endl;
}

// Function to view all student records
void viewStudents(const vector<Student>& records) {
    if (records.empty()) {
        cout << "No student records found." << endl;
        return;
    }

    cout << "Student Records:" << endl;
    for (const Student& student : records) {
        student.display();
    }
}

// Function to search for a student record by ID
void searchStudent(const vector<Student>& records) {
    int searchId;
    cout << "Enter Student ID to search: ";
    cin >> searchId;

    for (const Student& student : records) {
        if (student.getId() == searchId) {
            cout << "Student Found:" << endl;
            student.display();
            return;
        }
    }

    cout << "Student with ID " << searchId << " not found." << endl;
}

int main() {
    vector<Student> studentRecords;
    int choice;

    while (true) {
        cout << "\nStudent Record Management System" << endl;
        cout << "1. Add Student Record" << endl;
        cout << "2. View All Student Records" << endl;
        cout << "3. Search for a Student Record" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(studentRecords);
                break;
            case 2:
                viewStudents(studentRecords);
                break;
            case 3:
                searchStudent(studentRecords);
                break;
            case 4:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
