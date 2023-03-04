from tkinter import *
from tkinter import ttk
from tkinter import filedialog

file_paths = []

def browseFiles():
    # clearFiles()
    # for widget in scrollable_frame.winfo_children():
    #     widget.destroy()

    filename = filedialog.askopenfilename(initialdir="/", title="Select the file path",
                                          filetypes=(("Doc files", "*.docx"),))

    file_paths.append(filename)
    reCreateUI()


def reCreateUI():
    global second_frame

    for widget in root.winfo_children():
        widget.destroy()

    # Create A Main Frame
    main_frame = Frame(root)
    main_frame.pack(fill=BOTH, expand=1)

    # Create A Canvas
    my_canvas = Canvas(main_frame)
    # my_canvas.place(relx=0.5, rely=0.5, anchor=CENTER)
    #
    my_canvas.pack(side=LEFT, fill=BOTH, expand=1, pady=75, padx=100)
    # my_canvas.place(relx=0.5, rely=0.5, anchor=CENTER)

    # Add A Scrollbar To The Canvas
    my_scrollbar = ttk.Scrollbar(main_frame, orient=VERTICAL, command=my_canvas.yview)
    my_scrollbar.pack(side=RIGHT, fill=Y, padx=10)

    # Configure The Canvas
    my_canvas.configure(yscrollcommand=my_scrollbar.set)
    my_canvas.bind('<Configure>', lambda e: my_canvas.configure(scrollregion=my_canvas.bbox("all")))

    # Scroll on mousewheel (By adjusting 120 scrolling speed can be controlled)
    def on_mousewheel(event):
        my_canvas.yview_scroll(-1 * int((event.delta / 120)), "units")

    root.bind_all("<MouseWheel>", on_mousewheel)

    # Create ANOTHER Frame INSIDE the Canvas
    second_frame = Frame(my_canvas)

    # Add that New frame To a Window In The Canvas
    my_canvas.create_window((0, 0), window=second_frame, anchor="nw")

    # second_frame.place(relx=0.5, rely=0.5, anchor=CENTER)

    for i in range(len(file_paths)):
        Label(second_frame, text=file_paths[i], pady=5,
              font=("consolas", 12)).grid(row=i, column=0, padx=100, pady=10)

    Button(second_frame, text='Insert File Path', command=browseFiles, bg=button_bg_color, fg=button_text_color,
           font=('consolas', 12, 'bold'), padx=20, pady=4).grid(row=len(file_paths), column=0, padx=100, pady=20)


title = "TITLE"
bg_color = "#3F3F3F"
button_bg_color = "#18800A"
button_text_color = "white"

root = Tk()
root.title(title)
width = root.winfo_screenwidth()
height = root.winfo_screenheight()
root.geometry("%dx%d" % (width, height))
# root.attributes("-fullscreen", True)


# Create A Main Frame
main_frame = Frame(root)
main_frame.pack(fill=BOTH, expand=1)

# Create A Canvas
my_canvas = Canvas(main_frame)
my_canvas.pack(side=LEFT, fill=BOTH, expand=1, pady=75, padx=100)
# my_canvas.place(relx=0.5, rely=0.5, anchor=CENTER)

# Add A Scrollbar To The Canvas
my_scrollbar = ttk.Scrollbar(main_frame, orient=VERTICAL, command=my_canvas.yview)
my_scrollbar.pack(side=RIGHT, fill=Y, padx=10)

# Configure The Canvas
my_canvas.configure(yscrollcommand=my_scrollbar.set)
my_canvas.bind('<Configure>', lambda e: my_canvas.configure(scrollregion=my_canvas.bbox("all")))


# Scroll on mousewheel (By adjusting 120 scrolling speed can be controlled)
def on_mousewheel(event):
    my_canvas.yview_scroll(-1 * int((event.delta / 120)), "units")


root.bind_all("<MouseWheel>", on_mousewheel)

# Create ANOTHER Frame INSIDE the Canvas
second_frame = Frame(my_canvas)

# Add that New frame To a Window In The Canvas
my_canvas.create_window((0, 0), window=second_frame, anchor="nw")

# second_frame.place(relx=0.5, rely=0.5, anchor=CENTER)

for i in range(len(file_paths)):
    Label(second_frame, text=file_paths[i], pady=5,
          font=("consolas", 12)).grid(row=i, column=0, padx=100, pady=10)

Button(second_frame, text='Insert File Path', command=browseFiles, bg=button_bg_color, fg=button_text_color,
       font=('consolas', 12, 'bold'), padx=20, pady=4).grid(row=len(file_paths), column=0, padx=100, pady=20)
