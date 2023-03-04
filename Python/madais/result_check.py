"""
=== CMP4266 Computer Progrming ===

Created on Mon Nov 22 09:57:02 2021

Put this file in the same folder of the tasks

@author: Dr Q Sun
"""

import task1 as t1
import task2 as t2
import task3 as t3

if __name__ == '__main__':
    # Task 1
    # You get 1 mark for each of the 6 operation.
    t1.calculate(2, 3, "+")
    t1.calculate(2, 3, "-")
    t1.calculate(2, 3, "*")
    t1.calculate(2, 0, "/")
    t1.calculate(2, 3, "mod")
    t1.calculate(2, 3, "power")

    # You get 1 mark for handling "divided by 0"
    t1.calculate(3, 0, "/")

    # You get 3 marks for main().
    t1.main()

    # Task 3
    # You get 1 mark for is_leap().
    print(t2.is_leap(2000))
    print(t2.is_leap(2021))
    print(t2.is_leap(1900))
    print(t2.is_leap(5))

    # You get 5 marks for days_in_month().
    print(type(t2.days_in_month("January", 200)))
    print(t2.days_in_month("February", 2000))
    print(t2.number_of_day(2, 22, True))

    # Task 3
    # You get 1 mark for cal_distance().
    print(t3.cal_distance((0, 0), (3, 4)))

    # You get 3 marks for distance travelled at each step.
    t3.main()

    # You get 1 mark for total distance travelled.

    # You get 5 marks for the direction travelled at each step.
