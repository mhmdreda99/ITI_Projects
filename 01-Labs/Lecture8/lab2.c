/**
 * @file lab2.c
 * @author mhmdreda99 (Moreda491999@gmail.com)
 * @brief Write a C code to manage a class of 10
        students. Each student studies 4 subjects
        Math, Language, Physics and Chemistry.
        First define an array of 10 elements and assign
        random grades for students. The system will
        ask the user to enter the student ID then the
        system will show its grades. The software shall
        manage wrong IDs
 * @version 0.1
 * @date 2023-07-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "StdTypes.h"

// Define the struct for the student
typedef struct {
    u8 id;
    u16 math, lang, phy, chem;
} Student;

// Function to generate random grades for each student
void generateGrades(Student *students, u8 size) {
    for (u8 i = 0; i < size; i++) {
        students[i].math =  rand()% 100 ;
        students[i].lang =  rand()% 100 ;
        students[i].phy =  rand()% 100 ;
        students[i].chem =  rand()% 100 ;
    }
}

// Function to display the grades of a student
void displayGrades(Student student) {
    printf("ID: %d\n", student.id);
    printf("Math: %d\n", student.math);
    printf("Language: %d\n", student.lang);
    printf("Physics: %d\n", student.phy);
    printf("Chemistry: %d\n", student.chem);
}

// Function to manage the class of students
void manageStudents(Student *students, u8 size) {
    u8 id;
    printf("Enter student ID: ");
    scanf("%d", &id);

    for (u8 i = 0; i < size; i++) {
        if (students[i].id == id) {
            displayGrades(students[i]);
            return;
        }
    }

    printf("Invalid ID\n");
}

int main() {
    //the random numbers that are generated will be different each time the program is run. 
    srand(time(NULL)); // Seed the random number generator 

    // Define an array of 10 students
    Student students[10];
    for (u8 i = 0; i < 10; i++) {
        students[i].id = i + 1; // Assign IDs to each student
    }

    // Generate random grades for each student
    generateGrades(students, 10);
    //manage wrong IDs
    manageStudents(students,10);

}