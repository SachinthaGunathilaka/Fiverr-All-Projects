# import re
#
# from bs4 import BeautifulSoup
#
# attributes = ["name"]
# while True:
#     # try:
#     # input_file_name = input("\nEnter filename : ")
#     input_file_name = "output_XML_SourceSan.xml"
#
#     # f = open(input_file_name).read()
#     # print(f)
#     infile = open(input_file_name, "r", encoding="utf8")
#     output_file_name = "output_" + input_file_name
#     contents = infile.read()
#     soup = BeautifulSoup(contents, 'xml')
#     print(soup)
#
#     # for attribute in attributes:
#
#         # number_of_els = len(soup.findAll(re.compile("[\s\S]"), {attribute: re.compile("[\s\S]")}))
#         # for i in range(number_of_els):
#         #     # print("hi")
#         #
#         #     value = soup.findAll(re.compile("[\s\S]"), {attribute: re.compile("[\s\S]")})[i][attribute]
#         #     value = value.replace(" ", "_")
#         #     soup.findAll(re.compile("[\s\S]"), {attribute: re.compile("[\s\S]")})[i][attribute] = value
#
#     # with open(output_file_name, "w") as file:
#     #     file.write(str(soup))
#     #
#     # print("New file saved as " + output_file_name)
#     # break
#
# # except:
# #     print("File not found!")
# #     continue

s = "name=\""

print(list(s))