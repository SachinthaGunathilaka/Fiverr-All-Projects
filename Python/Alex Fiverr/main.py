from requests import get
import socket
import pandas as pd

with open('urls.txt') as f:
    url_list = f.readlines()

url_list = [x.strip() for x in url_list]

details = []

for url in url_list:
    ip = ""
    try:
        ip = socket.gethostbyname(url.lstrip("www.").split("/")[0])

    except:
        continue

    message = ""
    i = 0
    for x in ["http://", "https://", "www.http://", "www.https://"]:
        try:

            response = get(x + url)
            status = response.status_code
            if status == 200:
                message = "OK"
            elif status == 201:
                message = "CREATED"

            elif status == 202:
                message = "ACCEPTED"
            elif status == 203:
                message = "PARTIAL INFORMATION"

            elif status == 204:
                message = "NO RESPONSE"

            elif 200 <= status < 300:
                message = "Success!"

            elif status == 400:
                message = "BAD REQUEST"

            elif status == 401:
                message = "UNAUTHORIZED"

            elif status == 402:
                message = "PAYMENT REQUIRED"

            elif status == 403:
                message = "FORBIDDEN"

            elif status == 404:
                message = "NOT FOUND"

            elif status == 500:
                message = "INTERNAL ERROR"

            elif status == 501:
                message = "NOT IMPLEMENTED"

            elif status == 502:
                message = "SERVICE TEMPORARILY OVERLOADED"

            elif status == 503:
                message = "GATEWAY TIMEOUT"

            elif 400 < status < 600:
                message = "ERROR"

            elif status == 301:
                message = "MOVED"

            elif status == 302:
                message = "FOUND"

            elif status == 303:
                message = "METHOD"

            elif status == 304:
                message = "NOT MODIFIED"

            elif 300 < status < 400:
                message = "REDIRECTION"
            else:
                pass

            details.append({"ip": ip, "url": url, "status": status, "message": message})
            break

        except:
            i += 1
            if i == 4:
                details.append({"ip": ip, "url": url, "status": 0, "message": "CONNECTION CANNOT ESTABLISHED"})

            continue

details_df = pd.DataFrame(details)
details_df.to_excel('output.xlsx')
