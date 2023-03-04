def printf(text_model, text_array):
    # Initialize num_of_symbols to 0 and result to empty string
    num_of_symbols = 0
    result = ""

    i = 0
    # Iterate through each char in the text_model
    while i != len(text_model):
        # If the current character is '%'
        if text_model[i] == '%':
            # If '%' is the last character of the word or
            # If next character is not '%' or 's'
            if i == (len(text_model) - 1) or text_model[i + 1] not in ['%', 's']:
                # Return an error
                raise RuntimeError("invalid format")

            # If next character is 's'
            if text_model[i + 1] == 's':
                # If the num of symbols are greater than the length of the text_array
                if num_of_symbols > len(text_array):
                    # Return an error
                    raise RuntimeError("invalid format")

                # Append the symbol in the corresponding position to the result
                result += text_array[num_of_symbols]
                # Increment the number of symbols by 1
                num_of_symbols += 1
                # Increment the i by 1 (To skip next char)
                i += 1

            # If the next character is '%'
            else:
                # Append '%' symbol to the result
                result += "%"
                # Increment i by 1 (To skit the next char)
                i += 1

        # If the current character is not '%'
        else:
            # Append the current character to the result
            result += text_model[i]

        # Increment i by 1
        i += 1

    # If the number of symbols are not equal to the text_array length
    if num_of_symbols != len(text_array):
        # Return an error
        raise RuntimeError("invalid format")

    # Return result string
    print(result)



# Testing functions
printf("Hello %%s", [])
printf("%s is a %s%s%%", ["The tomato", "fruit", "hello"])
printf("This homework is worth %s%%", ["2.5"])
