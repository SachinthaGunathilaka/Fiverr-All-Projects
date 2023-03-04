import re

if __name__ == '__main__':
    from docx.oxml.ns import qn
    from docx.oxml import OxmlElement
    from docx import Document

    document = Document("full.docx")

    for paragraph in document.paragraphs:
        isItHeading = re.match('Heading ([1])', paragraph.style.name)
        if isItHeading:
            print(int(isItHeading.groups()[0]), paragraph.text.strip())
            paragraph.text = "Edited 1"

    document.save("temp.docx")




