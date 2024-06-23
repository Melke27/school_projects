/*Developed by: Melkamu Wako*/


#include <iostream>//For cin and cout
#include<fstream>//To use file in the system
#include <string>//For string data Type
#include<cstdlib>
#include <cstring> // For std::strcpy
#include<iomanip>//For setw() and set precision
#include<limits>//for numeric limits
using namespace std;

//Creating a structure called Student
struct Student {
    char name[20];
    string id;
    string section;
    int scores [10];
    double creditHours [10];
    string courses [10];
    double averageGPA;
    string grades[20];
};
//Initializing a function which adds Students to the System
void addStudent(const string& filename);
// Function to calculate and assign grades based on scores
void calculateGrades(Student& student, int x) {
    for (int i = 0; i < x; i++) {
        int y = student.scores[i];
        if (y >= 90 && y <= 100) {
            student.grades[i] = "A+";
        }
        else if (y >= 85 && y < 90) {
            student.grades[i] = "A";
        }
        else if (y >= 80 && y < 85) {
            student.grades[i] = "A-";
        }
        else if (y >= 75 && y < 80) {
            student.grades[i] = "B+";
        }
        else if (y >= 70 && y < 75) {
            student.grades[i] = "B";
        }
        else if (y >= 65 && y < 70) {
            student.grades[i] = "B-";
        }
        else if (y >= 60 && y < 65) {
            student.grades[i] = "C+";
        }
        else if (y >= 50 && y < 60) {
            student.grades[i] = "C";
        }
        else if (y >= 45 && y < 50) {
            student.grades[i] = "C-";
        }
        else if (y >= 40 && y < 45) {
            student.grades[i] = "D";
        }
        else {
            student.grades[i] = "F";
        }
    }
}

//Declaring a function which calculates GPA from the entered Scores
double calculateGPA(const Student& student, int x) {
    double totalGradePoints = 0.0;
    double totalCreditHours = 0.0;

    for (int i = 0; i < x; ++i) {
        double gradePoint = 0.0; // Initialize gradePoint for each iteration

        if (student.scores[i] >= 85 && student.scores[i] <= 100) {
            gradePoint = 4.0;
        } else if (student.scores[i] >= 80 && student.scores[i] < 85) {
            gradePoint = 3.75;
        } else if (student.scores[i] >= 75 && student.scores[i] < 80) {
            gradePoint = 3.5;
        } else if (student.scores[i] >= 70 && student.scores[i] < 75) {
            gradePoint = 3.0;
        } else if (student.scores[i] >= 65 && student.scores[i] < 70) {
            gradePoint = 2.75;
        } else if (student.scores[i] >= 60 && student.scores[i] < 65) {
            gradePoint = 2.5;
        } else if (student.scores[i] >= 55 && student.scores[i] < 60) {
            gradePoint = 2.0;
        } else if (student.scores[i] >= 50 && student.scores[i] < 55) {
            gradePoint = 1.75;
        } else if (student.scores[i] >= 45 && student.scores[i] < 50) {
            gradePoint = 1.0;
        } else if (student.scores[i] >= 40 && student.scores[i] < 45) {
            gradePoint = 0.0;
        }
        totalGradePoints += student.creditHours[i] * gradePoint;
        totalCreditHours += student.creditHours[i];
    }

    if (totalCreditHours > 0) { // Avoid division by zero
        double gpa = totalGradePoints / totalCreditHours;
        return gpa;
    } else {
        return 0.0; // Or handle the case of no credit hours appropriately
    }
}
//Initializing a function of main menu
void mainMenu(const string& filename);

//Function to add a new student to the System
void addStudent(const string& filename) {
    cout<<"----------------------------------------------------\n";
    Student student;
    cin.ignore();
    cout << "Enter student name: ";
    cin.getline(student.name, 20);
     // Consume the newline    character
    cout << "Enter student ID: ";
    cin >> student.id;

    cout << "Enter student section: ";
    cin >> student.section;
    cin.ignore();
    // Ask how many courses the student is taking
    int numCourses;
    cout << "Enter the number of courses: ";
    cin >> numCourses;

    cout << "Enter  a course details for each courses separated by space(course name,credit_hour,score):\nsample input: EnLa1002 3 87\n";
    for (int i = 0; i < numCourses; ++i) {
        cout<<"Enter the coure name, credit_hour and score of the student out of 100 separated by space for course number"<<i+1<<endl;
        cout<<"-------------------------------------------------------------------------------------------------------------\n";
        cin >> student.courses[i] >> student.creditHours[i] >> student.scores[i];
    }
   // Calculate grades based on scores and credit hours
    calculateGrades(student,numCourses);
    student.averageGPA =   calculateGPA(student,numCourses);
    // open the file in append mode
    ofstream file;
    file.open(filename, ios::app);
    if (!file.is_open()) {
        cerr << "Failed to create file." << endl;
        return;
    }

    // Write student details to the file in tabular format that seems like the initialized data
    file << "ID: " << student.id << endl;
    file << "Name: " << student.name << endl;
    file << "Section: " << student.section << endl;
    file << left << setw(15) << "Course" << setw(10)<< "Score" << setw(10) << "Grade" << endl;
    // Write course details
    for (int i = 0; i < numCourses; ++i) {
        file << setw(15) << student.courses[i] << setw(20) << setw(10) << student.scores[i] << setw(10) << student.grades[i] << endl;
    }
    file << "Average GPA: " << fixed << setprecision(2) << student.averageGPA << endl;

    file << endl;
    file.close();
    cout << "The data is successfully added to the system." << endl;

}
// Function for displaying details of all students
void displayStudents(const string& filename) {
    cout<<"----------------------------------------------------\n";
    ifstream file;
    file.open(filename);

    if (!file.is_open()) {
        cerr << "There is no stored data please make sure that you added students to the system." << endl;
        return;
    }
    string line;
    while (getline(file, line)) {
        cout << line << endl;

    }
    file.close();
}
// A function to display details of a specific student
void displaySpecificStudent(const string& filename, const string& studentID) {
    ifstream file;
    file.open(filename);

    if (!file.is_open()) {
        cerr << "Student with the ID:"<<studentID<<" is not added to the System, please make sure that the teacher added your details to the system" << endl;
        return;
    }
    cout<<"----------------------------------------------------\n";
    string line;
    bool found = false;
    while (getline(file, line)) {

        if (line.find("ID: " + studentID) != string::npos) {
            found = true;
            cout << line << endl;
            while (getline(file, line) && line != "") {
                cout << line << endl;
            }
            break;
        }
    }

    file.close();

    if (!found) {
        cout << "Student with ID " << studentID << " not found." << endl;
    }
}
//Declaring  a function which controls features under login as Teacher option
void asTeacher(const string& filename) {
        cout<<"----------------------------------------------------\n";
        cout << "You Loogged in as a Teacher\n\n";
        cout << "1. Display details of all Students\n";
        cout << "2. Add a new student\n";
        cout << "3. Previous menu\n";
        cout << "4. exit\n";
        int choice;
        cout << "Please choose an option: ";
        cin >> choice;

        if (choice == 1) {
            displayStudents(filename);
            int option;
            cout<<"\n 1.back\n 2.exit\n ";
            cout<<"Enter your option: ";
            cin>>option;
        switch(option){

            case 1:{
                asTeacher(filename);
                break;
            }
             case 2:{
                exit(1);
                break;
             }
            default:{
                cout << "Invalid choice";
                break;
            }

      };
}
        else if (choice == 2) {
            addStudent(filename);
            int option;
            cout<<"\n 1.back\n 2.exit\n ";
            cout<<"Enter your option: ";
            cin>>option;
            switch(option){

            case 1:{
                asTeacher(filename);
                break;
            }
             case 2:{
                exit(1);
                break;
             }
            default:{
                cout << "Invalid choice";
                break;
            }
        };
        }
        else if (choice == 3) {
            mainMenu(filename);
        }
        else if(choice==4){
            exit(1);
        }
        else {
            cout << "Invalid choice, please choose again.\n";
        }
    }
//Declaring  a function which controls features under login as Student option
void asStudent(const string& filename) {
        cout<<"----------------------------------------------------\n";
        cout << "You are logged in as Student\n"<<endl;
        cout << "1. Display My Details\n";
        cout << "2. Previous menu\n";
        cout << "3. exit\n";

        int choice;
        cout << "Please choose an option: ";
        cin >> choice;

        switch(choice){
    case 1:
        {
        string studentID;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Enter student ID: ";
        getline(cin, studentID);
        cout << "\nDisplaying details for student with ID " << studentID << ":\n" << endl;
        displaySpecificStudent(filename, studentID);
        int option;
        cout<<"\n 1.back\n 2.exit\n";
        cout<<"Enter your option: ";
        cin>>option;
        switch(option){
            case 1:{
                asStudent(filename);
                break;
            }
            case 2:{
                exit(1);
                break;
            }
            default:{
                cout << "Invalid choice";
                break;
            }
        };
        break;
        }
    case 2:
        {
        mainMenu(filename);
        break;
        }
    case 3:
        {
        exit(1);
        break;
        }
    default:
        {
        cout << "Invalid choice, please choose again.\n";
        asStudent(filename);
        break;
        }
        };
}
// Declaring The main menu page function
void mainMenu(const string& filename) {
        cout<<"----------------------------------------------------\n";
        cout << "Main Menu\n";
        cout << "1. Login as a Teacher\n";
        cout << "2. Login as a Student\n";
        cout << "3. Developer of the program\n";
        cout << "4. Exit\n";

        int choice;
        cout << "Please choose an option: ";
        cin >> choice;

        if (choice == 1) {
            asTeacher(filename);
        } else if (choice == 2) {
            asStudent(filename);
        }else if (choice == 3) {
             cout<<"----------------------------------------------------\n";
             cout << "NAME\n";
             cout<<"----------------------------------------------------\n";
             cout<<"Melkamu Wako\n";
            
             int option;
             cout<<"\n 1.back\n 2.exit\n ";
             cout<<"Enter your option: ";
             cin>>option;
        switch(option){

            case 1:{
               mainMenu(filename);
                break;
            }
             case 2:{
                exit(1);
                break;
             }
            default:{
                cout << "Invalid choice";
                break;
            }

      };

        } else if (choice == 4) {
            cout << "Exiting program.\n";
            exit(1);
        } else {
            cout << "Invalid choice, please choose again.\n";
        }
    }

//Declaring the main function
int main() {
    cout<<"----------------------------------------------------\n";
    std::cout<<"WELCOME TO ASTU GRADE MANAGEMENT SYSTEM"<<std::endl;
    string filename= "students data.dat";//Giving a name for the file in which Students data stored
    mainMenu(filename);
    return 0;
}
