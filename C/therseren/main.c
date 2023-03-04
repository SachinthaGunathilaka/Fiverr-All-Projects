
#include <stdio.h>
#include <string.h>

// employees structure
struct employees {
    int employeeNO;
    char firstName[20];
    char lastName[20];
    int departmentNO;
    float hourlySalary;
};

// create list of employees
struct employees emps[100];
int num_of_employees; // to hold the number of employees

// courses structure
struct courses {
    char course[20];
    int employees[50];
    int num_of_employees;

};
// create list of courses
struct courses crs[20];

int num_of_courses; // to hold the number of courses

// Scan function
void Scan(char *filename) {
    // open file for read
    FILE *ptr = fopen(filename, "r");
    num_of_employees = 0;

    // If file not exist
    if (ptr == NULL) {
        printf("File not found\n");
        return;
    }

    // read line by line and add details to emps (list of employees)
    while (!feof(ptr)) {
        fscanf(ptr, "%d%s%s%d%f", &emps[num_of_employees].employeeNO, emps[num_of_employees].firstName,
               emps[num_of_employees].lastName, &emps[num_of_employees].departmentNO,
               &emps[num_of_employees].hourlySalary);

        num_of_employees++;
    }

    fclose(ptr);

}

// Print function
void Print(FILE * fp, char *data, int taskNo) {
    fprintf(fp, "\nTask %d\n------------\n",taskNo);

    // write employees details to a file
    if (strlen(data) == 0) {
        for (int i = 0; i < num_of_employees; ++i) {
            fprintf(fp, "%d %s %s %d %.2f\n", emps[i].employeeNO, emps[i].firstName, emps[i].lastName,
                    emps[i].departmentNO, emps[i].hourlySalary);
        }
    }
        // write custom data to a file
    else {
        fprintf(fp, "%s\n", data);
    }
}

// average function
double average() {

    // calculate sum of the salaries of employees
    double sum = 0;
    for (int i = 0; i < num_of_employees; ++i) {
        sum += emps[i].hourlySalary;
    }

    // return average salary
    return sum / num_of_employees;

}


// newsalary function
void newSalary(int departmentNo, double percentage) {

    // increase salary of selected department by given percentage
    for (int i = 0; i < num_of_employees; ++i) {
        if (emps[i].departmentNO == departmentNo) {
            emps[i].hourlySalary = emps[i].hourlySalary * (1 + percentage / 100.0);
        }
    }
}

// add function
void add(int employeeNO, char *firstName, char *lastName, int departmentNO, double hourlySalary) {

    // create employee object using given data
    struct employees emp;
    emp.employeeNO = employeeNO;
    strcpy(emp.firstName, firstName);
    strcpy(emp.lastName, lastName);
    emp.departmentNO = departmentNO;
    emp.hourlySalary = hourlySalary;

    // add employee to employees list
    emps[num_of_employees] = emp;
    num_of_employees++; // increment number of employees

}


// delete function
void delete(int employeeNO) {
    int index;
    // get the index of the employee that want to delete
    for (index = 0; index < num_of_employees; ++index) {
        if (emps[index].employeeNO == employeeNO) {
            break;
        }
    }

    // If employee does not exist
    if (index == num_of_employees) {
        printf("Employee not found\n");
        return;
    }

    // remove employee
    for (int i = index; i < num_of_employees - 1; ++i) {
        emps[i] = emps[i + 1];
    }
    num_of_employees--; // decrement number of employees by 1
}


// scan_courses function
void scanCourses(char *filename) {

    // open file to read
    num_of_courses = 0;
    FILE *ptr = fopen(filename, "r");

    // if file not found
    if (ptr == NULL) {
        printf("File not found\n");
        return;
    }

    int employeeID;
    char course[30];

    // read file line by line
    while (!feof(ptr)) {
        fscanf(ptr, "%d%s", &employeeID, course);
        int index;

        // add data to courses list
        for (index = 0; index < num_of_courses; ++index) {
            // If the course already exists
            if (strcasecmp(crs[index].course, course) == 0) {
                crs[index].employees[crs[index].num_of_employees++] = employeeID;
                break;
            }
        }

        // If the course does not exists
        if (index == num_of_courses) {
            strcpy(crs[num_of_courses].course, course);
            crs[num_of_courses].employees[0] = employeeID;
            crs[num_of_courses].num_of_employees = 1;
            num_of_courses++;
        }

    }

    fclose(ptr);
}


// printAll function
void printAll(FILE * fp) {
    fprintf(fp, "\nTask 6 And 7\n------------\n");


    // Iterate through each employee
    for (int index = 0; index < num_of_employees; ++index) {
        // write employee details to file
        fprintf(fp, "%d %s %s %d %.2f ", emps[index].employeeNO, emps[index].firstName, emps[index].lastName,
                emps[index].departmentNO, emps[index].hourlySalary);

        // Iterate through each courses
        for (int i = 0; i < num_of_courses; ++i) {
            // find selected course for the employee
            for (int j = 0; j < crs[i].num_of_employees; ++j) {
                if (crs[i].employees[j] == emps[index].employeeNO) {
                    // write selected course to the file
                    fprintf(fp, "%s ", crs[i].course);
                    break;
                }
            }
        }
        fprintf(fp, "\n");
    }
}


// course with function
void coursesWith(FILE * fp, char *course) {
    fprintf(fp, "\nTask %d\n------------\n",8);

    // iterate through each courses
    for (int i = 0; i < num_of_courses; ++i) {

        // If the course matches
        if (strcasecmp(crs[i].course, course) == 0) {

            // Iterate through each employee
            for (int j = 0; j < crs[i].num_of_employees; ++j) {
                // Iterate through each course for selected employee
                for (int k = 0; k < num_of_employees; ++k) {
                    if (emps[k].employeeNO == crs[i].employees[j]) {
                        fprintf(fp, "%d %s %s %d %.2f\n", emps[k].employeeNO, emps[k].firstName, emps[k].lastName,
                                emps[k].departmentNO, emps[k].hourlySalary);
                    }

                }
            }
        }
        break;
    }
}


int main() {

    FILE *fp;
    fp = fopen("output.txt", "w");

    // Test Scan function
    Scan("tekstfil.txt");
    Print(fp, "", 1);


    // Test average function
    double average_salary = average();
    char str[30];
    sprintf(str, "Average salary : %.2f", average_salary);
    Print(fp, str, 2);

    // Test newsalary function
    newSalary(3, 5);
    Print(fp, "", 3);

    // Test add function
    add(12, "Erik", "Eriksen", 3, 260.75);
    Print(fp, "", 4);


    // Test delete function
    delete(4);
    Print(fp, "", 5);

    // Test scan courses function
    scanCourses("kurser.txt");
    printAll(fp);


    // Test course with function
    coursesWith(fp, "Word");

    fclose(fp);

    return 0;
}


