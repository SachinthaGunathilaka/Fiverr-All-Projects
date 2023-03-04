# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(A):
    count = 0
    for i in range(len(A)):
        is_shine = True
        prev = 1
        for j in range(0, i+1):
            if prev not in A[0:i+1]:
                is_shine = False
            prev += 1

        if is_shine:
            count += 1

    return count



print(solution([2, 1, 3, 5, 4]))