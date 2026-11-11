# File Organization Projects

A collection of beginner-friendly C++ exercises focused on file input/output, text processing, and data persistence. The projects in this repository demonstrate how to create files, read from them, modify their contents, and process structured data using `ofstream`, `ifstream`, `fstream`, and string handling.

## Overview

This repository is designed for learning the fundamentals of file operations in C++. Each project is a small standalone example that focuses on a specific concept such as:

- Writing user input to a text file
- Reading structured data from a file
- Finding minimum and maximum values from a dataset
- Editing text inside a file at a specific position
- Storing and retrieving student records

## Repository Structure

```text
file_org_projects-
├── README.md
├── No_AI_Generators_As_Make_Professional_With_Advanced_Readme.md
├── foundational/
│   ├── AgeAnalyzer/
│   ├── AgeAnalyzer with Full name/
│   ├── From Everybody to Everyone/
│   ├── Read from Fruit File/
│   └── Student File with String and Fstream/
└── Rokkie/
    ├── AgeAnalyzer/
    ├── From Everybody to Everyone/
    ├── Read from Fruit File/
    └── Switch from Everybody to Everyone in File/
```

## Included Projects

### 1. Age Analyzer
Reads a list of people with names and ages, stores the data in a file, identifies the youngest and oldest entries, and writes the result to `results.txt`.

### 2. From Everybody to Everyone
Demonstrates how to write and modify text in a file using file pointer operations (`tellp()` and `seekp()`).

### 3. Read from Fruit File
Reads fruit names from a text file and prints them to the console.

### 4. Student File with String and Fstream
Collects a student's full name, ID, and grade, then saves the data in a plain text file.

### 5. Switch from Everybody to Everyone in File
Loads content from a text file, replaces a phrase, and writes the updated text back to the same file.

## Learning Goals

By exploring these examples, you can practice:

- File creation and writing with `ofstream`
- File reading with `ifstream`
- File updates with `fstream`
- Delimited data parsing using commas and line breaks
- String manipulation and basic text replacement
- Handling user input and persistence in console applications

## Prerequisites

- A C++ compiler such as `g++`, `clang++`, or MinGW
- An IDE such as Code::Blocks, Visual Studio, or CLion
- Basic understanding of variables, loops, and functions in C++

## Getting Started

### Option 1: Using an IDE
1. Open the desired project folder in your C++ IDE.
2. Open the project file (`.cbp` for Code::Blocks projects, if available).
3. Build and run the program.

### Option 2: Using the command line
From the project directory, compile the source file:

```bash
g++ main.cpp -o app
./app
```

On Windows with MinGW:

```bash
g++ main.cpp -o app.exe
app.exe
```

## Example Workflow

A typical program in this repository follows this pattern:

```cpp
ofstream out("data.txt");
if (!out) {
    cerr << "Error opening file" << endl;
    return 1;
}

out << "Example content" << endl;
out.close();
```

Then the data is read back using `ifstream` or modified using `fstream`.

## Notes

This repository focuses on hands-on, educational examples and is ideal for beginners learning file handling in C++. Each example is intentionally small and easy to follow, making it suitable for classroom instruction, self-study, and practice exercises.

## License

This project is provided as a learning resource and may be used for educational purposes.
