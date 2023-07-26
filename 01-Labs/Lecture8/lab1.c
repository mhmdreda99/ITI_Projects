/**
 * @file lab1.c
 * @author mhmdreda99 (Moreda491999@gmail.com)
 * @brief Write a c code that defines a structure for
    employees that contains his salary, bonus and
    deductions. The program shall ask the user to
    enter these information for three employees (
    Ahmed, Waleed and Amr). Then the program
    will print the total value shall be supplied by
    finance team.
 * @version 0.1
 * @date 2023-07-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>
#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>

struct employee {
    char name[20];
    float salary;
    float bonus;
    float deductions;
};

int main() {
    struct employee emp[3];
    float total_salary = 0;

    // Get the employee information from the user
    for (int i = 0; i < 3; i++) {
        printf("Enter the name of employee %d: ", i + 1);
        scanf("%s", emp[i].name);
        printf("Enter the salary of employee %d: ", i + 1);
        scanf("%f", &emp[i].salary);
        printf("Enter the bonus of employee %d: ", i + 1);
        scanf("%f", &emp[i].bonus);
        printf("Enter the deductions of employee %d: ", i + 1);
        scanf("%f", &emp[i].deductions);
    }

    // Calculate the total salary
    for (int i = 0; i < 3; i++) {
        total_salary += emp[i].salary + emp[i].bonus - emp[i].deductions;
    }

    // Print the total salary
    printf("The total Value needed is: %.2f\n", total_salary);

    return 0;
}