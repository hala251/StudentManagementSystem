
#include <fstream>
#include <iostream>
#include <istream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <conio.h>

#define CLEAR system("cls")
#define PAUSE system("pause")
using namespace std;

void create_default_credentials();
bool login();
void main_menu();
void gpa(float *, char *, float, float, float, float, float);
void create_record();
void display_record();
void display_specific();
void modify_record();
void change_pass();
void delete_record();

// Maximum number of students
const int MAX_STUDENTS = 100;
const int MAX_PASSWORD_LENGTH = 20;

// Structure to hold student records
struct Student {
    int id;
    char name[50];
    float marks[5];
    char grade;
    float gpa;
};

// Array to store students
Student students[MAX_STUDENTS] = {

};
int student_count = 0;
// Default credentials
char username[] = "admin";
char password[MAX_PASSWORD_LENGTH] = "admin123";

int main() {
    CLEAR;
    create_default_credentials();
    if (login()) {
        main_menu();
    }
    return 0;
}

// Function to create default credentials
void create_default_credentials() {
    ifstream user_name_file_check("user_name.txt");
    ifstream pass_file_check("pass.txt");

    if (!user_name_file_check.is_open() || !pass_file_check.is_open()) {
        ofstream user_name_file("user_name.txt");
        user_name_file << username;
        user_name_file.close();

        ofstream pass_file("pass.txt");
        pass_file << password;
        pass_file.close();

        cout << "Default credentials created.\n";
    }
    user_name_file_check.close();
    pass_file_check.close();
}

// Function to login
bool login() {
    char input_username[50];
    char input_password[MAX_PASSWORD_LENGTH];

    cout << "Enter username: ";
    cin >> input_username;
    cout << "Enter password: ";
    cin >> input_password;

    ifstream file("user_name.txt");
    file >> username;
    file.close();

    file.open("pass.txt");
    file >> password;
    file.close();

    if (strcmp(input_username, username) == 0 && strcmp(input_password, password) == 0) {
        cout << "\nLogin successful.\n";
        return true;
    }

    cout << "\nInvalid login credentials.\n";
    return false;
}
void main_menu() {
    int choice;
    do {
        CLEAR;
        cout << "\n----- Main Menu -----\n";
        cout << "1. Create Record\n";
        cout << "2. Display All Records\n";
        cout << "3. Display Specific Record\n";
        cout << "4. Modify Record\n";
        cout << "5. Delete Record\n";
        cout << "6. Change Password\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                create_record();
                break;
            case 2:
                display_record();
                break;
            case 3:
                display_specific();
                break;
            case 4:
                modify_record();
                break;
            case 5:
                delete_record();
                break;
            case 6:
                change_pass();
                break;
            case 7:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 7);
}

// Function to calculate GPA
void gpa(float *gpa, char *grade, float a, float b, float c, float d, float e) { 
 
    float total_marks = a + b + c + d + e;

 
    float percentage = total_marks / 500.0;


    *gpa = percentage * 5;

    
    if (*gpa >= 4.5) {
        *grade = 'A';
    } else if (*gpa >= 3.5) {
        *grade = 'B';
    } else if (*gpa >= 2.5) {
        *grade = 'C';
    } else if (*gpa >= 1.5) {
        *grade = 'D';
    } else {
        *grade = 'F';
    }
}

// Function to create student record 
void create_record() 
{ 
CLEAR; 
if (student_count < MAX_STUDENTS) 
{ 
Student new_student; 
cout << "Enter Student ID: ";
cin >> new_student.id;
cout << "Enter Student name: ";
cin.ignore();
cin.getline(new_student.name, 50);
for(int i = 0; i < 5; i++){
    cout << "Enter the marks of the subject: ";
    cin >> new_student.marks[i];
}
        gpa(&new_student.gpa, &new_student.grade, new_student.marks[0],
new_student.marks[1], new_student.marks[2], new_student.marks[3],
new_student.marks[4]);
        students[student_count++] = new_student;
        cout << "Record created successfully!" << endl;
    }
else
    {
        cout << "Student limit reached!" << endl;
}
    cin.get();
}

// Function to display all records 
void display_record() 
{ 
CLEAR; 
cout << "\n----- All Student Records -----\n"; 
for(int i = 0; i <= student_count-1; i++){
    
    cout << "ID: " << students[i].id << endl;
    cout << "Name: " << students[i].name << endl;
    cout << "GPA: " << students[i].gpa << endl;
    cout << "Grade: " << students[i].grade << endl;
}

cout << "-----------------------------\n"; 
 
cout << endl; 
PAUSE; 
}
// Function to display a specific record
void display_specific() {
    CLEAR;
    int id;
    cout << "Enter Student ID: ";
    cin >> id;
    cin.ignore();  // ? input buffer

    for (int i = 0; i < student_count; ++i) {
        if (students[i].id == id) {
            cout << "ID: " << students[i].id << endl;
            cout << "Name: " << students[i].name << endl;
            cout << "GPA: " << students[i].gpa << endl;
            cout << "Grade: " << students[i].grade << endl;

            
            return;
        }
    }

    cout << "Record not found!" << endl;
}

// Function to modify a record
void modify_record() {
    CLEAR;
    int id;
    cout << "Enter your specific ID: "; // ????? ?????? ?????? ??????
    cin >> id;

    for (int i = 0; i < student_count; i++) { // ????? ?? ??????
        if (id == students[i].id) { // ??? ?? ?????? ??? ??????
            for (int j = 0; j < 5; j++) { // ?????? ??? ???????? ??? ????
                do {
                    cout << "Enter the marks of subject " << j + 1 << " (0-100): ";
                    cin >> students[i].marks[j];

                    if (students[i].marks[j] < 0 || students[i].marks[j] > 100) {
                        cout << "Invalid marks! Please enter a value between 0 and 100.\n";
                    }
                } while (students[i].marks[j] < 0 || students[i].marks[j] > 100);
            }

            // ??? ????? ???? ?????? ???????? ???????
            gpa(&students[i].gpa, &students[i].grade, 
                students[i].marks[0],
                students[i].marks[1],
                students[i].marks[2],
                students[i].marks[3],
                students[i].marks[4]);

            cout << "Record updated successfully!" << endl;
            cin.get();
            return;
        }
    }

    cout << "Record not found!" << endl; // ??? ?? ??? ?????? ??? ??????
    cin.get();
}

// Function to delete a record
void delete_record()
{
    CLEAR;
    int id;
    cout << "Enter your specific ID: ";
    cin >> id;
    for (int i = 0; i <= student_count - 1; i++) {
        if (id == students[i].id) {
            for (int j = i; j < student_count - 1; j++) {
                students[j] = students[j + 1];
            }
            student_count--;
            cout << "Record deleted perfectly\n";
            //sleep(10);
            return;
        }
    }
    cout << "Record not found!\n";
    cin.get();
}

// Function to change the password
void change_pass() {
    CLEAR;
char old_password[MAX_PASSWORD_LENGTH]; char new_password[MAX_PASSWORD_LENGTH];
cout << "Enter old password: "; cin >> old_password;
if (strcmp(old_password, password) == 0)
    {
        cout << "Enter new password: ";
        cin >> new_password;
        strcpy(password, new_password);
        ofstream file("pass.txt");
        file << password;
        file.close();
cout << "Password changed successfully!" << endl; }
else
    {
        cout << "Old password is incorrect!" << endl;
}
    cin.get();
}
