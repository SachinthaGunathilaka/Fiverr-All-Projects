import requests

input_filename = "urls.txt"
file = open(input_filename, "r")

write_file_name = "valid_urls.txt"
write_file = open(write_file_name, "w")

lines = file.readlines()

print("Active URLs")
print("--------------------")
for url in lines:
    try:
        url = url.strip()

        if len(url) == 0:
            continue
        response = requests.get(url, timeout=1)
        if response.status_code == 200:
            print(f"{url}")
            write_file.write(f"{url}\n")

    except:
        continue

file.close()
write_file.close()


