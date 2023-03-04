def solution(N):
    number = 1
    while True:
        sum_value = 0
        temp_number = number
        while temp_number != 0:
            sum_value += temp_number % 10
            temp_number = temp_number // 10

        if sum_value == N:
            return number

        number += 1

print(solution(19))