if __name__ == '__main__':
    while True:
        try:
            attributes = ["name=\"", "n=\""]
            attributes_li = []
            for attribute in attributes:
                attributes_li.append(list(attribute))
            input_file_name = input("\nEnter filename : ")
            # input_file_name = "XML_SourceSan.xml"
            output_file_name = "output_" + input_file_name

            f = open(input_file_name, encoding="utf8")
            data = list(f.read())

            tag_flag = False

            i = 0
            while i < len(data):

                if data[i] == "<":
                    tag_flag = True

                elif data[i] == ">":
                    tag_flag = False

                if tag_flag:
                    if data[i:i + 6] == attributes_li[0]:
                        i = i + 6
                        if data[i:i + 2] == ['_', '_']:
                            i = i + 2
                            continue

                        while data[i] != "\"":
                            if data[i] == " ":
                                data[i] = "_"
                            i += 1

                    elif data[i:i + 3] == attributes_li[1]:
                        i = i + 3
                        if data[i:i + 2] == ['_', '_']:
                            i = i + 2
                            continue

                        while data[i] != "\"":
                            if data[i] == " ":
                                data[i] = "_"
                            i += 1

                i += 1

            new_data = ''.join(data)

            with open(output_file_name, "w", encoding="utf8") as file:
                file.write(str(new_data))

            break

        except:
            print("File not found!")
            continue
