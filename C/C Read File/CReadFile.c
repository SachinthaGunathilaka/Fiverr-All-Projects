#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Customer {
    char name[20];
    char surname[20];
    char bookingID[20];
    char holidayCode[20];
    int cost;
    int paid;
    float discount;

};


struct Holiday {
    char code[20];
    char destination[20];
    char country[20];
    char hotel[20];
    int startDate;
    int startMonth;
    int duration;
    int price;

};


void printCustomer(struct Customer cus) {
    printf("%s %s %s %s %i %i %.2f\n", cus.name, cus.surname, cus.bookingID, cus.holidayCode, cus.cost, cus.paid,
           cus.discount);
}

void printHoliday(struct Holiday hol) {
    printf("%s %s %s %s %i %i %i %i\n", hol.code, hol.destination, hol.country, hol.hotel, hol.startDate,
           hol.startMonth, hol.duration, hol.price);
}

float getDiscounts(int paid, int cost, char *country) {
    float discount = 0;
    if (cost / 2.0 <= paid) {
        discount += (float) cost * 0.1;
    }

    if (strcasecmp(country, "Croatia") == 0) {
        discount += (float) cost * 0.1;
    }

    return discount;
}

struct Holiday getHoliday(struct Holiday holidays[], int size, char *code) {
    struct Holiday holiday;
    for (int i = 0; i < size; ++i) {
        if (strcmp(holidays[i].code, code) == 0) {
            holiday = holidays[i];
            break;
        }

    }
    return holiday;
}

int main() {
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    char *temp_data1[7];

    struct Customer customers[1000];
    int num_of_customers = 0;

    fp = fopen("customers.txt", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    while ((getline(&line, &len, fp)) != -1) {
//        line[strlen(line) - 1] = '\0';
        int i = 0;
        char *p = strtok(line, " ");
        while (p != NULL) {
            temp_data1[i++] = p;
            p = strtok(NULL, " ");
        }


        struct Customer customer;
        strcpy(customer.name, temp_data1[0]);
        strcpy(customer.surname, temp_data1[1]);
        strcpy(customer.bookingID, temp_data1[2]);
        strcpy(customer.holidayCode, temp_data1[3]);
        customer.cost = atoi(temp_data1[4]);
        customer.paid = atoi(temp_data1[5]);
        customer.discount = atof(temp_data1[6]);


        customers[num_of_customers] = customer;
        num_of_customers++;

    }

    fclose(fp);


    len = 0;
    char *temp_data2[8];

    struct Holiday holidays[1000];
    int num_of_holidays = 0;

    fp = fopen("holidays.txt", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    while ((getline(&line, &len, fp)) != -1) {

        int i = 0;
        char *p = strtok(line, " ");
        while (p != NULL) {
            temp_data2[i++] = p;
            p = strtok(NULL, " ");
        }


        struct Holiday holiday;
        strcpy(holiday.code, temp_data2[0]);
        strcpy(holiday.destination, temp_data2[1]);
        strcpy(holiday.country, temp_data2[2]);
        strcpy(holiday.hotel, temp_data2[3]);
        holiday.startDate = atoi(temp_data2[4]);
        holiday.startMonth = atoi(temp_data2[5]);
        holiday.duration = atoi(temp_data2[6]);
        holiday.price = atoi(temp_data2[7]);


        holidays[num_of_holidays] = holiday;
        num_of_holidays++;

    }


    fclose(fp);

    for (int i = 0; i < num_of_customers; ++i) {
        struct Holiday holiday = getHoliday(holidays, num_of_holidays, customers[i].holidayCode);

        float discount = getDiscounts(customers[i].paid, customers[i].cost, holiday.country);
        customers[i].cost -= discount;
        customers[i].discount = discount;
    }

    char name[20], sir_name[20];
    printf("Enter Customer Full Name : ");
    scanf(" %s %s", name, sir_name);
    int is_found = 0;

    for (int i = 0; i < num_of_customers; ++i) {
        if (strcasecmp(name, customers[i].name) == 0 && strcasecmp(sir_name, customers[i].surname) == 0) {
            is_found = 1;
            if (customers[i].paid >= customers[i].cost) {
                printf("You have paid full amount. You have change of %i euro\n",
                       customers[i].paid - customers[i].cost);
            } else {
                printf("You have to pay %i euro\n", customers[i].cost - customers[i].paid);

            }
        }
    }

    if (is_found == 0) {
        printf("Customer does not found");
    }


    char letter;
    printf("\nEnter letter : ");
    scanf(" %c", &letter);

    printf("|Name |         Surname|      HolidayCode|     Destination|           Hotel|            Cost|            Paid|\n");
    for (int i = 0; i < num_of_customers; ++i) {
        struct Holiday holiday = getHoliday(holidays, num_of_holidays, customers[i].holidayCode);
        if (customers[i].name[0] == toupper(letter) || customers[i].name[0] == tolower(letter)) {
            printf("|%s| %15s|  %15s| %15s| %15s| %15i| %15i|\n", customers[i].name, customers[i].surname,
                   customers[i].holidayCode, holiday.destination, holiday.hotel, customers[i].cost, customers[i].paid);

        }

    }

    return 0;
}
