def code_char(c, key):
    if ord('a') <= ord(c) <= ord('z'):
        return chr((ord(c) + key - ord('a')) % 26 + ord('a'))

    else:
        return chr((ord(c) + key - ord('A')) % 26 + ord('A'))


def code_block(word, key):
    result = ""
    for i in range(len(word)):
        result += code_char(word[i], int(key[i]))
    return result


def isletter(c):
    if ord('a') <= ord(c) <= ord('z') or ord('A') <= ord(c) <= ord('Z'):
        return True

    return False


def encrypt(message, key):
    result = ""

    key_index = 0
    for i in range(len(message)):
        if key_index == 8:
            key_index = 0

        if isletter(message[i]):
            result += code_char(message[i], int(key[key_index]))
            key_index += 1
        else:
            result += message[i]
    return result


assert (encrypt("This is a secret message!!", "12345678") == "Ujlw ny h afeuiy slatcji!!")
assert (encrypt("Hello, How are you?", "12345678") == "Igopt, Nve bth cta?")

key = input("Enter the encryption key : ")
f = open("message.txt")
text = f.read()
f.close()
secret_text = encrypt(text, key)
f = open("secret.txt", "w")
f.write(secret_text)
f.close()

print("Encrypted text has written to secret.txt file")
