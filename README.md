# C and C++ Programming Exercises

A collection of C and C++ source code files covering fundamental to intermediate programming concepts. These exercises were developed as part of coursework and practice sessions.


## Table of Contents

- [Overview](#overview)
- [Topics Covered](#topics-covered)
- [File Categories](#file-categories)
- [How to Compile and Run](#how-to-compile-and-run)
- [Requirements](#requirements)


## Overview

This repository contains over 200 C++ source files organized by topic. The exercises range from basic syntax and I/O operations to advanced data structures such as linked lists, stacks, and polynomial manipulation. The codebase also includes object-oriented programming examples using classes, operator overloading, and templates.


## Topics Covered

### Basics
- Variable declaration, input/output
- Conditional statements (if/else, switch-case)
- Loops (for, while, do-while)
- Functions and recursion

### Arrays and Strings
- One-dimensional and two-dimensional arrays
- Array sorting (Bubble Sort)
- String manipulation and formatting

### Structs and Object-Oriented Programming
- Struct-based data management (student records, employee records, patient records)
- Classes with constructors and destructors
- Operator overloading (fractions, complex numbers)
- Templates and generic programming

### Data Structures
- Singly linked lists
- Stack implementation
- Polynomial representation and arithmetic using linked lists

### Applied Projects
- Employee management system (array-based and linked-list-based)
- Student record management
- Patient record management
- Fraction calculator with operator overloading
- Complex number arithmetic
- Discrete mathematics operations


## File Categories

| Category | Example Files | Description |
|---|---|---|
| Introduction | `C++_mo_dau.cpp`, `heloww.cpp` | Basic syntax and first programs |
| Practice Sessions | `thuchanh_cau1.cpp` to `thuchanh_cau20.cpp` | Numbered lab exercises |
| Homework | `baitapvenha.cpp`, `baitapvenha2.cpp` | Take-home assignments |
| Exercises | `bai1.cpp` to `bai10.cpp`, `cau1.cpp` to `cau5.12.cpp` | Graded exercises by chapter |
| Templates | `template.cpp` to `template (42).cpp` | Template and generic programming exercises |
| Data Structures | `DSLK.cpp`, `DSKL_Benh_Nhan.cpp`, `stack.cpp` | Linked lists and stacks |
| OOP | `So_phuc.cpp`, `Phan_so_cua_diep.cpp`, `testclass.cpp` | Classes and operator overloading |
| Management Systems | `Quan_ly_nhan_su.cpp`, `Danh_sach_hoc_sinh.cpp` | Full CRUD applications |
| Algorithms | `sapxep_bubblesort.cpp`, `songuyento.cpp` | Sorting and number theory |


## How to Compile and Run

Using g++ (MinGW on Windows or GCC on Linux/macOS):

```bash
g++ -o output filename.cpp
./output
```

Example:

```bash
g++ -o nhansu Quan_ly_nhan_su.cpp
./nhansu
```

Some files use C-style I/O (`stdio.h`) and can also be compiled with gcc:

```bash
gcc -o output filename.cpp -lstdc++
```


## Requirements

- A C++ compiler supporting C++11 or later (g++, MSVC, or Clang)
- No external libraries required -- all programs use the C/C++ standard library


## License

This project is for educational purposes.
