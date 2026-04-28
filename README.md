# 🧠 42 C++ Modules (CPP00 → CPP09)

This repository contains all C++ modules from the 42 curriculum, covering the fundamentals of object-oriented programming, memory management, templates, and STL usage.

Each module introduces new concepts and builds on the previous ones, progressively moving from basic syntax to advanced abstractions.

---

## 📚 Modules Overview

### CPP00 — Basics of C++

Introduction to C++ syntax and paradigms:
- Namespaces
- Classes and member functions
- std::cout / std::cin
- Basic I/O handling

---

### CPP01 — Memory & References

Focus on memory handling and references:
- Stack vs Heap allocation
- Pointers vs References
- `new` / `delete`
- File streams (`ifstream`, `ofstream`)

---

### CPP02 — Ad-hoc Polymorphism

Operator overloading and canonical form:
- Orthodox Canonical Form
- Operator overloading (`<<`, `=`, etc.)
- Fixed-point number implementation

---

### CPP03 — Inheritance

Introduction to inheritance:
- Base and derived classes
- Constructors / destructors chaining
- Method overriding

---

### CPP04 — Subtype Polymorphism

Runtime polymorphism:
- Virtual functions
- Abstract classes
- Interfaces
- Deep vs shallow copies

---

### CPP05 — Exceptions

Error handling in C++:
- `try` / `catch` / `throw`
- Custom exception classes
- Nested exception handling

---

### CPP06 — C++ Casts

Type conversion mechanisms:
- `static_cast`
- `dynamic_cast`
- `reinterpret_cast`
- `const_cast`

---

### CPP07 — Templates

Generic programming:
- Function templates
- Class templates
- Template specialization

---

### CPP08 — Containers & Iterators

Introduction to STL:
- Containers (`vector`, `list`, `map`)
- Iterators
- Algorithms (`find`, `sort`, etc.)

---

### CPP09 — STL & Advanced Usage

Advanced STL usage and problem solving:
- Container manipulation
- Parsing and data processing
- Algorithmic problem solving
- Performance considerations

---

## 🧱 Compilation

Each module contains its own Makefile.

To compile a specific exercise:

    cd CPPXX/exYY
    make

---

## ▶️ Execution

Run the compiled program:

    ./program_name

(Some exercises require arguments depending on the subject.)

---

## 📁 Repository Structure

    .
    ├── CPP00/
    ├── CPP01/
    ├── CPP02/
    ├── CPP03/
    ├── CPP04/
    ├── CPP05/
    ├── CPP06/
    ├── CPP07/
    ├── CPP08/
    └── CPP09/

Each module contains multiple exercises (`ex00`, `ex01`, etc.).

---

## ⚠️ Notes

- All code follows the 42 subject constraints (C++98 standard unless specified)
- No external libraries are used unless allowed
- Focus is on understanding concepts rather than production-ready code

---

## 🧠 Concepts Covered

- Object-Oriented Programming (OOP)
- Memory management
- Polymorphism (compile-time & runtime)
- Exception handling
- Templates and generic programming
- Standard Template Library (STL)

---

## 🎯 Goal

The goal of these modules is to build a strong foundation in C++ and object-oriented design, progressing from low-level concepts to high-level abstractions and standard library usage.
