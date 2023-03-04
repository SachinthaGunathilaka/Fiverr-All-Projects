import os
import docx
import re
from bs4 import BeautifulSoup
import shutil
import zipfile
from tkinter import filedialog, Tk
from tkinter.filedialog import asksaveasfile
from docxtpl import DocxTemplate, Listing, RichText
from docx import Document
from docxcompose.composer import Composer

if __name__ == '__main__':
    root = Tk()
    root.title('Mémoire technique')
    width = root.winfo_screenwidth()
    height = root.winfo_screenheight()
    print(width, height)
