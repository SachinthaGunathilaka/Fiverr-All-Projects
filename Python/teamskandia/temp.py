import os
import shutil
from concurrent.futures.thread import ThreadPoolExecutor

from selenium.common.exceptions import NoSuchElementException
from selenium import webdriver
from shutil import which
from fake_useragent import UserAgent
import time

from selenium.webdriver import Keys
from selenium.webdriver.chrome.options import Options
from bs4 import BeautifulSoup
from datetime import datetime
from math import ceil
import _thread
from tkinter import *
from tkinter import ttk, filedialog
from tkcalendar import Calendar

from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.by import By

# given_date_str = "2022/08/10"
sellers = []
url = "https://www.bybit.com/copyTrade/trade-center/detail?leaderMark=ZIFBeYBreTZKNwkw/7Dobg=="
fee_value = 0.12


def readTrades(url):
    time.sleep(5)
    ua = UserAgent()
    user_agent = ua.random

    # Import options

    # Create Options object
    chrome_options = Options()
    chrome_options.add_argument(f'user-agent={user_agent}')
    chrome_options.add_argument("--start-maximized")
    chrome_options.add_argument("disable-blink-features=AutomationControlled")
    chrome_options.add_experimental_option("useAutomationExtension", False)
    chrome_options.add_experimental_option("excludeSwitches", ["enable-automation"])

    # Add argument to Options to use headless browser
    # chrome_options.add_argument("--headless")

    chrome_path = which("chromedriver")

    # Add options argument to Chrome driver to use headless browser
    driver = webdriver.Chrome(executable_path=chrome_path, options=chrome_options)

    past_trades_pages = []

    driver.get(url)

    # time.sleep(1)
    # copy_trade_button = driver.find_element("xpath", "(//div[@class='ant-tabs-tab-btn'])[2]")
    # copy_trade_button.click()

    percentage = 0
    copy_trades_pages = []

    while True:
        try:
            time.sleep(3)

            copy_trades_page = driver.page_source

            soup = BeautifulSoup(copy_trades_page,
                                 "html.parser")  # If this line causes an error, run 'pip install html5lib' or install html5lib

            table = soup.findAll("tbody", {"class": "ant-table-tbody"})[1]
            rows = table.findAll("tr", {"class": "ant-table-row ant-table-row-level-0"})

            for row in rows:
                tds = row.findAll("td", {"class": "ant-table-cell"})
                outcome = float(tds[4].find("span").text.strip().split("%")[0])
                leverage = int(tds[0].text.strip().split()[1].strip().split("x")[0].strip())
                percentage += (outcome / leverage) - float(fee_value)

            print("\nCopy trades percentage done.. : ", percentage)

            next_button = driver.find_element("xpath",
                                              "(//li[@class='ant-pagination-next' and @aria-disabled='false']/button)[2]")

            next_button.click()



        except NoSuchElementException:
            break

        except:
            continue

    # time.sleep(1)
    # past_trade_button = driver.find_element("xpath", "(//div[@class='ant-tabs-tab-btn'])[1]")
    # past_trade_button.click()

    year_ = cal.get_date().split("/")[2]
    year_ = int(year_[0:2])
    if 59 <= year_ <= 99:
        year_ = '19' + str(year_)
    else:
        year_ = '20' + str(year_)

    done = False
    while True:
        try:
            if done:
                break
            time.sleep(3)
            past_trades_page = driver.page_source

            next_button = driver.find_element("xpath",
                                              "//li[@class='ant-pagination-next' and @aria-disabled='false']/button")

            new_date = cal.get_date().split("/")[0] + "/" + cal.get_date().split("/")[1] + "/" + year_
            given_date = datetime.strptime(new_date, '%m/%d/%Y')

            soup = BeautifulSoup(past_trades_page,
                                 "html.parser")  # If this line causes an error, run 'pip install html5lib' or install html5lib

            table = soup.findAll("tbody", {"class": "ant-table-tbody"})[0]
            rows = table.findAll("tr", {"class": "ant-table-row ant-table-row-level-0"})

            for row in rows:
                tds = row.findAll("td", {"class": "ant-table-cell"})
                outcome = float(tds[5].find("span").text.strip().split("%")[0])
                date_str = tds[4].text.strip()
                leverage = int(tds[0].text.strip().split()[1].strip().split("x")[0].strip())

                date = datetime.strptime(date_str, '%Y-%m-%d %H:%M:%S')

                # print(given_date, date)
                if given_date > date:
                    done = True
                    break

                percentage += (outcome / leverage) - float(fee_value)
                # print(outcome)
                # print(outcome / leverage)

            if not done:
                next_button.click()


        except NoSuchElementException:
            break

        except Exception as e:
            print(e)
            continue

    # COPY TRADES #

    print("Past trades pages : ", len(past_trades_pages))
    print("Copy trades pages : ", len(copy_trades_pages))

    driver.close()
    return percentage


def browseFiles():
    input_filename = "input.txt"

    if os.path.exists(input_filename):
        os.remove(input_filename)

    filename = filedialog.askopenfilename(initialdir="/", title="Select File", filetypes=(("Text File", "*.txt"),))

    # Change label contents
    shutil.copy(filename, input_filename)


def extractSeller(url):
    global sellers
    percentage = readTrades(url)
    count = 0

    while percentage == 0:
        if count == 5:
            break
        percentage = readTrades(url)
        count += 1

    sellers.append([url, round(percentage, 2)])

    sellers = sellers.sort(key=lambda x: x[1], reversed=True)

    rebuildUI()
    print("\nSeller " + url + " extracting completed..")


def startProcess():
    print(cal.get_date())
    print(fee.get())
    f = open("input.txt")
    lines = f.readlines()

    for line in lines:
        line = line.strip()
        if len(line) == 0:
            continue
        print(line)
    f.close()

    # try:
    #
    #     for line in lines:
    #         _thread.start_new_thread(extractSeller, (line,))
    # except:
    #     "Error: unable to start thread"

    pool = ThreadPoolExecutor(max_workers=1)
    for line in lines:
        # time.sleep(20)
        pool.submit(extractSeller, line)
        # extractSeller(line)

    # rebuildUI()
    # pool.shutdown(wait=True)

    # while 1:
    #     pass


def rebuildUI():
    for widget in scrollable_frame.winfo_children():
        widget.destroy()

    label1 = Label(scrollable_frame,
                   text="Select Starting Date ",
                   width=100, height=4,
                   fg="blue", font=('times new roman', 12, 'bold'))

    label1.pack()

    cal = Calendar(scrollable_frame, selectmode='day',
                   year=2022, month=8,
                   day=21)

    cal.pack()

    label2 = Label(scrollable_frame, text="Trading Fee ",
                   width=100,
                   fg="blue", font=('times new roman', 12, 'bold'))

    label2.pack(pady=20)

    fee = StringVar()
    Entry(scrollable_frame, textvariable=fee, font=('times new roman', 12, 'bold'), width=10).pack()
    fee.set(str(fee_value))

    button_explore = Button(scrollable_frame, text='Insert Document', command=browseFiles,
                            font=('times new roman', 12, 'bold'), padx=10, pady=3, fg="white", bg="blue")

    button_explore.pack(pady=20)

    submit_button = Button(scrollable_frame, text='Start', command=startProcess,
                           font=('times new roman', 14, 'bold'), padx=10, pady=3, fg="white", bg="purple")

    submit_button.pack(pady=20)

    Label(scrollable_frame, text='Sellers with Percentage', width=100, fg="green",
          font=('times new roman', 16, 'bold')).pack(pady=20)

    for i in range(len(sellers)):
        seller_name = sellers[i][0].split("leaderMark=")[1]
        # Link_Button(frame, text="Google Hyperlink", action=callback)
        spaces = 50 - len(seller_name)
        text_ = seller_name + ' ' * spaces + str(sellers[i][1])
        Label(scrollable_frame, text=text_ + "%", width=100, fg="blue",
              font=('times new roman', 12, 'bold')).pack(pady=20)


if __name__ == '__main__':

    # UI SECTION
    root = Tk()
    root.title('BYBIT TRADING')
    width = root.winfo_screenwidth()
    height = root.winfo_screenheight()
    root.geometry("%dx%d" % (width, height))

    container = ttk.Frame(root)
    right = ttk.Frame(root)

    canvas = Canvas(container, width=width - 100, height=height - 100)

    scrollbar = ttk.Scrollbar(container, orient="vertical", command=canvas.yview)
    scrollable_frame = ttk.Frame(canvas)
    frame_r = ttk.Frame(canvas)

    scrollable_frame.bind(
        "<Configure>",
        lambda e: canvas.configure(
            scrollregion=canvas.bbox("all")
        )
    )

    frame_r.bind(
        "<Configure>",
        lambda e: canvas.configure(
            scrollregion=canvas.bbox("all")
        )
    )

    canvas.create_window((0, 0), window=scrollable_frame, anchor="nw")
    canvas.create_window((0, 0), window=frame_r, anchor="nw")

    # LAB = Button(frame_r, text='Afficher', command=showChapters, bg=button_bg_color, fg="white",
    #                         font=('calibre', 10, 'bold'), padx=10, pady=3).grid(row=0, column=0,
    #                                                                             pady=30)

    canvas.configure(yscrollcommand=scrollbar.set)

    container.pack(anchor="center")
    canvas.pack(side="left", fill="both", expand=True, anchor="center")
    right.pack(side="right", fill="both", expand=True, anchor="center")
    scrollbar.pack(side="right", fill="both")

    # Label(frame_r, text="Titre", borderwidth=2, relief="solid", pady=5, padx=10,
    #       font=("Courier", 10),
    #       bg=chapter_bg_color).grid(row=1, column=0, pady=10)

    label1 = Label(scrollable_frame,
                   text="Select Starting Date ",
                   width=100, height=4,
                   fg="blue", font=('times new roman', 12, 'bold'))

    label1.pack()

    cal = Calendar(scrollable_frame, selectmode='day',
                   year=2022, month=8,
                   day=21)

    cal.pack()

    label2 = Label(scrollable_frame, text="Trading Fee ",
                   width=100,
                   fg="blue", font=('times new roman', 12, 'bold'))

    label2.pack(pady=20)

    fee = StringVar()
    Entry(scrollable_frame, textvariable=fee, font=('times new roman', 12, 'bold'), width=10).pack()
    fee.set(str(fee_value))

    button_explore = Button(scrollable_frame, text='Insert Document', command=browseFiles,
                            font=('times new roman', 12, 'bold'), padx=10, pady=3, fg="white", bg="blue")

    button_explore.pack(pady=20)

    submit_button = Button(scrollable_frame, text='Start', command=startProcess,
                           font=('times new roman', 14, 'bold'), padx=10, pady=3, fg="white", bg="purple")

    submit_button.pack(pady=20)

    Label(scrollable_frame, text='Sellers with Percentage', width=100, fg="green",
          font=('times new roman', 16, 'bold')).pack(pady=20)

    for i in range(len(sellers)):
        seller_name = sellers[i][0].split("leaderMark=")[1]
        # Link_Button(frame, text="Google Hyperlink", action=callback)
        spaces = 50 - len(seller_name)
        text_ = seller_name + ' ' * spaces + str(sellers[i][1])
        Label(scrollable_frame, text=text_ + "%", width=100, fg="blue",
              font=('times new roman', 12, 'bold')).pack(pady=20)

    scrollable_frame.mainloop()
