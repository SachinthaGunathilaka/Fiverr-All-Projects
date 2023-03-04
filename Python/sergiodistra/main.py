if __name__ == '__main__':
    import requests
    from selenium import webdriver
    from shutil import which
    from bs4 import BeautifulSoup
    from selenium.webdriver.common.by import By

    chrome_path = which("chromedriver")

    url = "https://open.spotify.com/search/%40hotmail.com%20techno/playlists"

    driver = webdriver.Chrome(executable_path=chrome_path)
    driver.get(url)

    el = driver.find_elements(by=By.XPATH, value="//div")
    print(el)

    # print(driver.page_source)
    # soup = BeautifulSoup(requests.get(url).text, "html.parser")

    # print(soup)
    # data = soup.findAll('div', attrs={'class': 'E1N1ByPFWo4AJLHovIBQ'})
    # print(data)
    # for div in data:
    #     links = div.findAll('a')
    #     for a in links:
    #         print(a)
