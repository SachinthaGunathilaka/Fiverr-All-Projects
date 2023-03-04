import os

path = 'Input'

text = "REPLACE-THIS-WITH-YOUR-URL"
replace_text = "ipfs://QmR8UJbpCi6utj14HB1NbGTzmZ4ryp85xUj1fj58HQ6piz"


for root, dirs, files in os.walk(path, topdown=False):
    for name in files:
        filename = os.path.join(root, name)
        f = open(filename)
        content = f.read()
        content = content.replace(text, replace_text)

        write_file = open(f"Output/{name}", "w")
        write_file.write(content)
        write_file.close()
