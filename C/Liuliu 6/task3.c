#include <stdio.h>
#include <string.h>

struct Car {
    int id;
    float miles;
};

void addCar(struct Car *cars, int id, int *count) {

    int i;
    for (i = 0; i < *count; ++i) {
        if (cars[i].id == id) {
            printf("Error! Car with ID %d already exists in the database.\n", id);
            return;
        }
    }
    struct Car car;
    car.id = id;
    car.miles = 0;

    cars[*count] = car;
    *count += 1;
}

void display(struct Car *cars, int count) {
    int i;
    for (i = 0; i < count; ++i) {
        printf("%-7d %.1f\n", cars[i].id, cars[i].miles);
    }
}

void reset(struct Car *cars, int count, int id) {
    int isExits = 0;

    int i;
    for (i = 0; i < count; ++i) {
        if (cars[i].id == id) {
            isExits = 1;

            cars[i].miles = 0;
            break;
        }
    }

    if (!isExits) {
        printf("Error! Car with ID %d doesn't exist in the database.\n", id);
        return;
    }
}

void addTrip(struct Car *cars, int count, int id, float miles) {
    int isExits = 0;
    int i;
    for (i = 0; i < count; ++i) {
        if (cars[i].id == id) {
            isExits = 1;
            cars[i].miles += miles;
            break;
        }
    }

    if (!isExits) {
        printf("Error! Car with ID %d doesn't exist in the database.\n", id);
        return;
    }
}

int main() {
    int num_of_cars = 0;
    struct Car cars[10];

    char command[20];

    while (1) {
        printf("> ");
        scanf(" %s", command);
        if (strcasecmp(command, "AddCar") == 0) {
            int id;
            scanf(" %d", &id);

            addCar(cars, id, &num_of_cars);
        } else if (strcasecmp(command, "AddTrip") == 0) {
            int id;
            scanf(" %d", &id);

            float milage;
            scanf(" %f", &milage);

            addTrip(cars, num_of_cars, id, milage);
        } else if (strcasecmp(command, "Display") == 0) {
            display(cars, num_of_cars);
        } else if (strcasecmp(command, "Reset") == 0) {
            int id;
            scanf(" %d", &id);
            reset(cars, num_of_cars, id);
        } else if (strcasecmp(command, "quit") == 0) {
            return 0;
        } else {
            printf("Invalid Command!\n");
        }
    }
}