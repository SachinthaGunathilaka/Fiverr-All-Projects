import time
import threading

from selenium import webdriver
from shutil import which
from bs4 import BeautifulSoup
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.chrome.options import Options


# outfile_name = "output.txt"
# infile_name = "input.txt"

def func(license_number):
    website_url = "https://eservices.dubaided.gov.ae/Pages/Anon/GstHme.aspx?dedqs=BvvMKRMxIgc="

    chrome_path = which("chromedriver")
    chrome_options = Options()

    driver = webdriver.Chrome(executable_path=chrome_path, options=chrome_options)
    driver.get(website_url)
    time.sleep(1)

    # print(driver.page_source)
    license_section = driver.find_elements_by_class_name("es-link")[9]
    license_section.click()

    time.sleep(1)

    search_input = driver.find_element_by_id("DEDLCNr")
    search_input.send_keys(license_number)
    search_input.send_keys(Keys.ENTER)

    time.sleep(1)

    row = driver.find_elements_by_tag_name("a")[4]
    row.click()
    time.sleep(1)
    driver.close()


thread_list = []
results = []
for x in range(800000, 800005):
    thread = threading.Thread(target=func, args=[x])
    thread_list.append(thread)
for thread in thread_list:
    thread.start()
for thread in thread_list:
    thread.join()

#
# soup = BeautifulSoup(driver.page_source, "lxml")

# infile = open(infile_name)
#
# outfile = open(outfile_name, "w")
# outfile.close()

# lines = infile.readlines()

# for word in lines:
#     while True:
#         try:
#             word = word.strip()
#             if len(word) < 2 or len(word) > 6:
#                 continue
#
#             driver.get(website_url)
#             time.sleep(1)
#
#             search_input = driver.find_element_by_id("quick-combo__combo")
#             search_input.send_keys(word)
#             search_input.send_keys(Keys.ENTER)
#
#             time.sleep(1)
#
#             soup = BeautifulSoup(driver.page_source, "lxml")
#             result_text = soup.find("div", {"class": "quick-combo__form-outer dimmable"}).find("h2").text.strip().lower()
#
#             if result_text == "your combo is available!":
#                 outfile = open(outfile_name, "a")
#
#                 print(f"{word} : Available")
#                 outfile.write(f"{word}\n")
#                 outfile.close()
#
#
#             else:
#                 print(f"{word} : Not Available")
#
#             break
#
#         except:
#             continue
#
# driver.close()
# infile.close()
