import tkinter as tk
from tkinter import ttk, messagebox

# Create main window
root = tk.Tk()
root.title("Sorting Algorithm Visualizer")
root.geometry("500x300")
root.resizable(False, False)

# Title Label
title = tk.Label(root, text="Sorting Algorithm Visualizer", font=("Helvetica", 16, "bold"))
title.pack(pady=10)

# Frame for inputs
input_frame = tk.Frame(root)
input_frame.pack(pady=10)

# Dropdown menu for sorting algorithm
tk.Label(input_frame, text="Choose Algorithm:", font=("Helvetica", 12)).grid(row=0, column=0, padx=10, pady=5, sticky="e")

algo_var = tk.StringVar()
algo_choices = ["Bubble Sort", "Selection Sort", "Insertion Sort", "Merge Sort", "Quick Sort", "Heap Sort", "Radix Sort"]
algo_dropdown = ttk.Combobox(input_frame, textvariable=algo_var, values=algo_choices, state="readonly", width=25)
algo_dropdown.grid(row=0, column=1)
algo_dropdown.current(0)

# Entry for number of elements
tk.Label(input_frame, text="Number of Elements:", font=("Helvetica", 12)).grid(row=1, column=0, padx=10, pady=5, sticky="e")

num_elements_var = tk.StringVar()
num_elements_entry = tk.Entry(input_frame, textvariable=num_elements_var, width=28)
num_elements_entry.grid(row=1, column=1)

# Dummy Start Button
def start_sorting():
    selected_algo = algo_var.get()
    num_elements = num_elements_var.get()

    if not num_elements.isdigit() or int(num_elements) <= 0:
        messagebox.showerror("Invalid Input", "Please enter a valid positive integer.")
        return

    messagebox.showinfo("Sorting Started", f"Sorting {num_elements} elements using {selected_algo}...\n(This is a placeholder)")

start_button = tk.Button(root, text="Start Sorting", font=("Helvetica", 12), bg="#4CAF50", fg="white", command=start_sorting)
start_button.pack(pady=20)

# Placeholder visualization frame
visual_frame = tk.Frame(root, bg="#ddd", height=100)
visual_frame.pack(fill="x", padx=20, pady=10)

tk.Label(visual_frame, text="(Visualization Area Placeholder)", bg="#ddd", font=("Helvetica", 10, "italic")).pack()

# Run the GUI
root.mainloop()
