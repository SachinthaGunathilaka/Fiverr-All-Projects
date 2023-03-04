if __name__ == '__main__':

    from selenium import webdriver
    from shutil import which
    from selenium.webdriver.chrome import options
    from selenium.webdriver.common.keys import Keys
    import nltk


    # Import options
    from selenium.webdriver.chrome.options import Options

    # Create Options object
    chrome_options = Options()
    # Add argument to Options to use headless browser
    # chrome_options.add_argument("--headless")

    chrome_path = which("chromedriver")

    # Add options argument to Chrome driver to use headless browser
    driver = webdriver.Chrome(executable_path=chrome_path, options=chrome_options)

    driver.get("https://www.bybit.com/copyTrade/trade-center/detail?leaderMark=ZIFBeYBreTZKNwkw/7Dobg==")

    # search_input = driver.find_element_by_id("search_form_input_homepage")
    # search_input.send_keys("My User Agent")
    # search_input.send_keys(Keys.ENTER)

    # Print the html markup
    print(driver.page_source)

    # Close the driver
    # driver.close()
