import time
from selenium import webdriver
from shutil import which
from bs4 import BeautifulSoup
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.chrome.options import Options
import pandas as pd

columns = ["Name", "Location", "Job Title", "About", "Experiences", "Education"]
df2 = pd.DataFrame(columns=columns)


def getDetails(url, df2):
    driver.get(url)
    time.sleep(3)
    soup = BeautifulSoup(driver.page_source, "lxml")

    name = soup.find("h1", {"class": "text-heading-xlarge inline t-24 v-align-middle break-words"}).text.strip()
    job_title = soup.find("div", {"class": "text-body-medium break-words"}).text.strip()
    location = soup.find("div", {"class": "pv-text-details__left-panel mt2"}).find("span").text.strip()

    headers = soup.findAll("div", {"class": "pvs-header__container"})

    about_text = ""
    exp_data = ""
    edu_data = ""
    for header in headers:
        title = header.find("h2", {"class": "pvs-header__title text-heading-large"}).find("span").text.lower()

        if title == "about":
            about_text = header.findNext("div", {"class": "display-flex ph5 pv3"}).text.strip()

        elif title == "experience":
            experiences_section = header.findNext("div", {"class": "pvs-list__outer-container"})
            experiences = experiences_section.findAll("div", {"class": "display-flex flex-row justify-space-between"})

            for experience in experiences:
                exp_result = experience.find("div", {"class": "display-flex align-items-center"}).find("span").find(
                    "span").text.strip()

                for j in experience.find("div").find_all("span", recursive=False):
                    exp_result += "\n" + j.find("span").text.strip()

                exp_data += exp_result + "\n\n"


        elif title == "education":
            edu_section = header.findNext("div", {"class": "pvs-list__outer-container"})
            edus = edu_section.findAll("div", {"class": "display-flex flex-row justify-space-between"})

            for edu in edus:
                edu_result = edu.find("div", {"class": "display-flex align-items-center"}).find("span").find(
                    "span").text.strip()
                for j in edu.find("a").find_all("span", recursive=False):
                    edu_result += "\n" + j.find("span").text.strip()

                edu_data += edu_result + "\n\n"

    new_row = {}
    new_row["Name"] = name
    new_row["Location"] = location
    new_row["Job Title"] = job_title
    new_row["About"] = about_text
    new_row["Experiences"] = exp_data
    new_row["Education"] = edu_data

    df2 = df2.append(new_row, ignore_index=True)
    return df2


username = "<username>"
password = "<password>"
website_url = "https://www.linkedin.com"

chrome_path = which("chromedriver")
chrome_options = Options()

driver = webdriver.Chrome(executable_path=chrome_path, options=chrome_options)
driver.delete_all_cookies()

driver.get(website_url)
time.sleep(1)

# print(driver.page_source)
username_field = driver.find_element_by_id("session_key")
username_field.send_keys(username)

password_field = driver.find_element_by_id("session_password")
password_field.send_keys(password)

sign_in_btn = driver.find_element_by_class_name("sign-in-form__submit-button")
sign_in_btn.send_keys(Keys.ENTER)

time.sleep(2)
f = open("input_urls.txt")
lines = f.readlines()
for line in lines:
    line = line.strip()

    if len(line) == 0:
        continue

    df2 = getDetails(line, df2)

df2.to_excel("linkedin.xlsx")
driver.close()
