Sorting Algorithms GUI Application
Overview

This project is a GUI application that implements and compares six sorting algorithms:

Bubble Sort

Insertion Sort

Selection Sort

Merge Sort

Quick Sort

Radix Sort

The application can:

Generate large random datasets

Sort data from input files using selected algorithms

Save sorted output to files

Measure and display sorting time

Plot performance graphs comparing algorithm efficiencies

Features

GUI interface using Tkinter for easy user interaction

Supports sorting datasets of various sizes, including 10,000+ elements

Implements classic and efficient sorting algorithms

Performance benchmarking with graphical visualization

Modular code structure for easy maintenance and extension

File Structure
sorting_gui_project/
│
├── main.py                  # GUI application entry point
├── sorting_algorithms.py    # Implementations of sorting algorithms
├── utils.py                 # Utility functions: file I/O, random data generation, timing
├── performance_plot.py      # Benchmarking and plotting sorting times
├── input_files/             # Sample input files with random numbers
├── output_files/            # Sorted output files saved here
├── analysis.md              # Manual analysis of algorithms (time, space, pros/cons)
└── README.md                # This file

Requirements

Python 3.x

Required packages:

matplotlib

Install dependencies with:

pip install matplotlib

How to Use

Run the GUI application:

python main.py


Use the GUI to:

Generate random input files

Load input files for sorting

Select the sorting algorithm

Save sorted output files

View sorting time for each operation

To benchmark all algorithms and visualize performance:

python performance_plot.py

Algorithm Analysis

For detailed time and space complexity, pros, cons, and typical use cases of each algorithm, see the analysis.md file.

License

This project is open-source and free to use.

Contact

For questions or contributions, contact [anjneegouria/anjnigouria2004@gmail.com].
