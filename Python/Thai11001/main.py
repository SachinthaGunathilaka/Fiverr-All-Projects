import time
from selenium import webdriver
from shutil import which
from bs4 import BeautifulSoup
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.chrome.options import Options

outfile_name = "output.txt"
infile_name = "input.txt"
website_url = "https://vplates.com.au/"

chrome_path = which("chromedriver")
chrome_options = Options()

driver = webdriver.Chrome(executable_path=chrome_path, options=chrome_options)

infile = open(infile_name)

outfile = open(outfile_name, "w")
outfile.close()

lines = infile.readlines()

for word in lines:
    while True:
        try:
            word = word.strip()
            if len(word) < 2 or len(word) > 6:
                continue

            driver.get(website_url)
            time.sleep(1)

            search_input = driver.find_element_by_id("quick-combo__combo")
            search_input.send_keys(word)
            search_input.send_keys(Keys.ENTER)

            time.sleep(1)

            soup = BeautifulSoup(driver.page_source, "lxml")
            result_text = soup.find("div", {"class": "quick-combo__form-outer dimmable"}).find("h2").text.strip().lower()

            if result_text == "your combo is available!":
                outfile = open(outfile_name, "a")

                print(f"{word} : Available")
                outfile.write(f"{word}\n")
                outfile.close()


            else:
                print(f"{word} : Not Available")

            break

        except:
            continue

driver.close()
infile.close()
