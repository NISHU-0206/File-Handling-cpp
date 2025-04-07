# Student Record Management System (C++)

This is a console-based C++ application that allows basic management of student records using:

- Classes and Objects
- File Handling (`fstream`)
- Binary File Operations
- Basic Input/Output

---

## 💡 Features

- Create a new student record
- Store student details in a binary file (`student_database.txt`)
- Append new student entries to the file
- Read student records from the file
- Update a specific student record based on their ID

---

## 🧩 Class Structure

### 🔸 `Student` Class

Attributes:
- `int studentID` – Unique identifier for each student
- `string name` – Student's name
- `int age` – Student's age
- `string grade` – Grade assigned
- `double marks[5]` – Array storing marks of 5 subjects

Functions:
- `Student()` – Default constructor
- `Student(int, string, int, string, double[])` – Parameterized constructor
- `void getdata()` – To take student details from the user

---

## ⚙️ Program Flow

1. A predefined student (`s1`) is created using a parameterized constructor.
2. The student is written to a binary file.
3. User is prompted to enter another student's details via console input (`s2`), which is also written to the file.
4. File is then read and contents displayed.
5. The program allows updating a student’s record by ID.
6. File is rewritten with updated data.

---

## 📄 File Used

- `student_database.txt`: Stores the binary data of student records.

---

## ⚠️ Issues & Improvements

- ❌ `marks[5] = m[5];` inside the constructor doesn't copy arrays correctly. Needs a loop or `std::copy`.
- ❌ `cin >> marks[5];` in `getdata()` is incorrect. It should take 5 inputs using a loop.
- ❌ Reading/writing objects using `file.write((char*)&obj, sizeof(obj))` can cause issues due to strings (non-POD types).
- ❌ File update logic may not work correctly if student IDs are not sequential or start from 1.
- ⚠️ Data is read as binary but displayed using `getline`, which can cause display errors.

> ✅ These can be fixed by writing individual fields (like name, ID, marks, etc.) to the file as formatted text rather than binary.

---

## 🧑‍💻 How to Compile & Run

Save the file as `student_record.cpp`

### Compile:
g++ student_record.cpp -o student_record

### Run:
./student_record
