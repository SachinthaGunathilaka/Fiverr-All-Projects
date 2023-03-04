def is_leap(year):
    if year % 400 == 0:
        return True
    elif (year % 4 == 0) and (year % 100 != 0):
        return True

    return False


def days_in_month(month, year):
    number_of_days = 0
    if month in ['September', 'April', 'June', 'November']:
        number_of_days = 30

    elif month in ['January', 'March', 'May', 'July', 'August', 'October', 'December']:
        number_of_days = 31


    elif month == 'February' and is_leap(year):
        number_of_days = 29

    elif month == 'February' and (not is_leap(year)):
        number_of_days = 28

    return number_of_days


def number_of_day(month, day, leap):
    months = ["January", "February", "March", "April", "May", "June", "July", "August", "September", "October",
              "November",
              "December"]
    count = day
    for i in range(1, month):
        if i == 2:
            if leap:
                count += 29
            else:
                count += 28

        else:
            count += days_in_month(months[i - 1], 2000)

    return count


# if __name__ == '__main__':
    # print(days_in_month("January", 2000))
    # print(days_in_month("February", 2000))
    # print(days_in_month("March", 2000))
    # print(days_in_month("April", 2000))
    # print(days_in_month("December", 2000))
    # print(days_in_month("July", 2000))
    # print(days_in_month("February", 1990))
    # print(days_in_month("Februay", 1990))

    # print(number_of_day(1, 1, False))
    # print(number_of_day(3, 1, True))
    # print(number_of_day(12, 31, False))
    # print(number_of_day(12, 31, True))
