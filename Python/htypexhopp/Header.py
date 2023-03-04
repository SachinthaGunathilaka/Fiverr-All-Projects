import os
import shutil
import zipfile
import re
from docx import Document

from bs4 import BeautifulSoup

doc_file_path = "Wod doc.docx"
xml_file_path = "Word Document/word/document.xml"
zip_file_path = "input_zip.zip"
output_zip_path = "output.zip"
output_doc_path = "output.docx"


class Headers:
    def __init__(self):
        self.headers = []

    def addHeader(self, number, text):
        self.headers.append([number, text])

    def getLevels(self, header_num):
        return len(header_num.split(".")) - 2

    def display(self):
        for [header_num, text] in self.headers:
            print("\t" * self.getLevels(header_num) + header_num, text)

    def getChapters(self):
        chapters = []
        for i in range(len(self.headers)):
            if self.getLevels(self.headers[i][0]) == 0:
                chapters.append(self.headers[i])
        return chapters

    def getHeaderTextUI(self, header):
        return "\t" * self.getLevels(header[0]) + header[0] + header[1]

    def getHeaderPath(self, index):
        path = []

        header_nums = self.headers[index][0].split(".")

        for i in range(len(header_nums) - 1):
            if i == 0:
                path.append(ord(header_nums[i]) - 64)
            elif i == 1:
                path.append(int(header_nums[i]))
            else:
                path.append(int(header_nums[i]) - 1)

        return path


headers = Headers()


def iter_heading(paragraphs):
    for paragraph in paragraphs:
        isItHeading = re.match('Heading ([1-9])', paragraph.style.name)
        if isItHeading:
            yield int(isItHeading.groups()[0]), paragraph


def addHeaderNumbering(document):
    hNums = [-1, -1, -1, -1, -1, -1, -1, -1, -1]
    for index, hx in iter_heading(document.paragraphs):

        for i in range(index + 1, 9):
            if i > 2:
                hNums[i] = 0
            else:
                hNums[i] = -1

        hNums[index] += 1

        header_num = ""

        if index < 4:
            for i in range(1, index + 1):
                if i == 1:
                    header_num += chr(64 + hNums[i]) + "."
                else:
                    header_num += "%d." % hNums[i]

            headers.addHeader(header_num, hx.text.strip())


def initDocFile(filename):
    shutil.copyfile(filename, zip_file_path)

    with zipfile.ZipFile(zip_file_path, 'r') as zip_ref:
        zip_ref.extractall("Word Document")


def clearFiles():
    for file in [zip_file_path, output_zip_path, output_doc_path, doc_file_path, "pre_output.docx", "input", "generated_doc.docx"]:
        if os.path.exists(file):
            os.remove(file)

    try:
        shutil.rmtree("Word Document")

    except:
        pass

def getParaIds():
    xml_file = open(xml_file_path, 'r')
    content = xml_file.read()
    soup = BeautifulSoup(content, 'xml')
    xml_file.close()

    header_para_ids = []
    p_s = soup.findAll("w:p")
    index = 0

    for p in p_s:
        ppr_s = p.findAll("w:pPr")
        if len(ppr_s) == 0:
            continue

        for ppr in ppr_s:
            p_style = ppr.findAll("w:pStyle",
                                  {"w:val": re.compile("Heading1|Titre1|Heading2|Titre2|Heading3|Titre3")})
            if len(p_style) == 0:
                continue

            index += 1

            header_content = str(p_style[0].parent.parent)
            # print("header", header_content)
            pos = header_content.find("paraId")

            end_pos = pos + 8
            while True:
                if header_content[end_pos] == '\"':
                    break

                end_pos += 1

            header_para_ids.append(header_content[pos + 8: end_pos])
            # print(header_content[pos + 8:end_pos])

    return header_para_ids







