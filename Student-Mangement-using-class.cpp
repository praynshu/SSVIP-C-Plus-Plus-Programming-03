//First part
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

// Second part
class Student {
private:
    int id;
    string name;
    double gpa;

public:
    Student(int _id, const string& _name, double _gpa) : id(_id), name(_name), gpa(_gpa) {}

    int getId() const { return id; }
    const string& getName() const { return name; }
    double getGpa() const { return gpa; }

    void display() const {
        cout << "ID: " << id << " | Name: " << name << " | GPA: " << gpa << endl;
    }
};

// Third part
void writeToFile(const vector<Student>& records, const string& filename) {
    ofstream file(filename);
    if (!file) {
        cerr << "Error opening file for writing." << endl;
        return;
    }

    for (const Student& student : records) {
        file << student.getId() << " " << student.getName() << " " << student.getGpa() << endl;
    }

    file.close();
}

void readFromFile(vector<Student>& records, const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file for reading." << endl;
        return;
    }

    records.clear();
    int id;
    string name;
    double gpa;

    while (file >> id >> name >> gpa) {
        records.emplace_back(id, name, gpa);
    }

    file.close();
}

//Fourth part
void addStudent(vector<Student>& records) {
    int id;
    string name;
    double gpa;

    cout << "Enter Student ID: ";
    cin >> id;

    cin.ignore(); // Consume the newline character
    cout << "Enter Student Name: ";
    getline(cin, name);

    cout << "Enter GPA: ";
    cin >> gpa;

    records.emplace_back(id, name, gpa);
    cout << "Student added successfully!" << endl;
}

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

void updateStudent(vector<Student>& records) {
    int searchId;
    cout << "Enter Student ID to update: ";
    cin >> searchId;

    for (Student& student : records) {
        if (student.getId() == searchId) {
            cout << "Enter new GPA: ";
            double newGpa;
            cin >> newGpa;
            student = Student(student.getId(), student.getName(), newGpa);
            cout << "Student record updated!" << endl;
            return;
        }
    }

    cout << "Student with ID " << searchId << " not found." << endl;
}

void deleteStudent(vector<Student>& records) {
    int searchId;
    cout << "Enter Student ID to delete: ";
    cin >> searchId;

    for (auto it = records.begin(); it != records.end(); ++it) {
        if (it->getId() == searchId) {
            records.erase(it);
            cout << "Student record deleted!" << endl;
            return;
        }
    }

    cout << "Student with ID " << searchId << " not found." << endl;
}


//Fifth Part
int main() {
    vector<Student> studentRecords;
    string filename = "student_records.txt";

    // Load data from file
    readFromFile(studentRecords, filename);

    int choice;

    while (true) {
        cout << "\nStudent Record Management System" << endl;
        cout << "1. Add Student Record" << endl;
        cout << "2. View All Student Records" << endl;
        cout << "3. Update Student Record" << endl;
        cout << "4. Delete Student Record" << endl;
        cout << "5. Save and Exit" << endl;
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
                updateStudent(studentRecords);
                break;
            case 4:
                deleteStudent(studentRecords);
                break;
            case 5:
                writeToFile(studentRecords, filename);
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
