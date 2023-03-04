def getStudentID():
    while True:
        student_id = input()

        is_valid = True
        if len(student_id.strip()) == 0:
            continue
        for char in student_id:
            if not char.isalnum():
                is_valid = False
                break

        if is_valid:
            return student_id


student_id = getStudentID()
print(student_id)
