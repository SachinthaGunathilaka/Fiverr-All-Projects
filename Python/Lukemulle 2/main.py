if __name__ == '__main__':

    import os
    import json

    path = 'Input'
    output = "Output"


    def line_to_dict(split_Line):
        # Assumes that the first ':' in a line
        # is always the key:value separator

        line_dict = {}
        for part in split_Line:
            key, value = part.split(":", maxsplit=1)
            line_dict[key] = value

        return line_dict


    def convert(f1, f2):
        f = open(f1, "r")
        content = f.read()
        splitcontent = content.splitlines()

        # Split each line by pipe
        lines = [line.split(' | ') for line in splitcontent]

        # Convert each line to dict
        lines = [line_to_dict(l) for l in lines]

        # Output JSON
        with open(f2, 'w') as fout:
            json.dump(lines, fout, indent=4)


    for root, dirs, files in os.walk(path, topdown=False):
        for name in files:
            dict1 = {}

            filename = os.path.join(root, name)
            text = open(filename).read()
            stud_obj = json.loads(text)
            with open(f"Output/{name}.json", 'w') as f:
                json.dump(stud_obj, f, indent = 4, ensure_ascii=False)
