# 🧭 File Explorer Application (Linux OS)

## 📘 Objective
The goal of this project is to *develop a console-based file explorer application in C++* that interacts with the *Linux Operating System* to manage files and directories.  
The application performs essential file operations such as *listing, copying, moving, deleting, creating, searching, and managing file permissions* through a simple text-based interface.

---

## 🧩 Overview
This File Explorer acts like a mini command-line interface built using C++.  
It allows the user to perform Linux-like file operations programmatically using *system calls* and *C++ standard libraries*.

---

## 🗓️ Day-wise Task Implementation

### 🗓️ *Day 1 – Application Setup and Basic File Listing*
- Designed the structure of the application.
- Set up the Linux-based C++ environment.
- Implemented the listFiles() function to display files and directories in the current folder using opendir() and readdir().

### 🗓️ *Day 2 – Directory Navigation*
- Added directory traversal and basic navigation features.
- Implemented reading directory contents dynamically using dirent.h.
- Displayed directory structures with user-friendly formatting.

### 🗓️ *Day 3 – File Manipulation*
- Added major file management operations:
  - *Copy file* using ifstream and ofstream.
  - *Move file* using the rename() function.
  - *Delete file* using the remove() function.
  - *Create file* using ofstream.

### 🗓️ *Day 4 – Search Functionality*
- Implemented a recursive file search function using:
  - *searchFile()* – Traverses all subdirectories to find a file or folder name containing a given keyword.
  - Utilized *recursion* and stat() to identify directory and file types.

### 🗓️ *Day 5 – File Permission Management*
- Implemented *permission viewing and modification features*:
  - *viewPermissions()* displays file permissions in symbolic form (rwxr-xr-x).
  - *changePermissions()* allows the user to modify file permissions using numeric octal input (e.g., 644, 755).
- Used chmod() and stat() system calls for permission handling.

---

## ⚙️ Features Implemented

| Feature | Description |
|----------|--------------|
| *List Files* | Lists all files and directories in the current path. |
| *Copy File* | Copies a file from source to destination. |
| *Move File* | Moves or renames a file to a new location. |
| *Delete File* | Removes a file permanently from the system. |
| *Create File* | Creates a new empty file in the directory. |
| *Search File* | Recursively searches files or directories by name. |
| *View Permissions* | Displays symbolic file permission format (rwxr-xr-x). |
| *Change Permissions* | Updates file permission using octal values (e.g., chmod 755 file.txt). |
| *Exit* | Closes the application gracefully. |

---

## 🧮 Command Reference

| Command | Description |
|----------|-------------|
| list | Displays all files and folders in the current directory. |
| copy | Prompts for source and destination paths to copy a file. |
| move | Moves or renames a file. |
| delete | Deletes a specified file. |
| create | Creates a new file. |
| search | Searches for a file or directory by keyword. |
| perm | Shows the permission string and size of a file. |
| chmod | Changes file permissions (octal input like 644 or 755). |
| exit | Exits the File Explorer program. |

---

## 🖥️ How to Run the Application

### 🔧 *Step 1: Compile*
Open your Linux terminal and run:
bash
g++ sai.cpp -o explorer
`

### ▶️ *Step 2: Execute*

Run the program:

bash
./explorer


### 💬 *Step 3: Use Commands*

Example session:

bash
Available commands: list | copy | move | delete | create | search | perm | chmod | exit
Enter command: list
file1.txt
Documents
main.cpp

Enter command: create
Enter new file name: newfile.txt
File created successfully!

Enter command: search
Enter file name or keyword to search: main
Found: ./main.cpp

Enter command: perm
Enter file or path to view permissions: main.cpp
-rw-r--r--  1024 bytes  main.cpp

Enter command: chmod
Enter file or path to change permissions: main.cpp
Enter numeric mode (e.g. 644 or 0755): 755
Permissions changed successfully.
-rwxr-xr-x  1024 bytes  main.cpp


---

## 🧠 Technical Concepts Used

* *File I/O:* ifstream, ofstream
* *Directory Access:* opendir(), readdir(), closedir()
* *File Metadata:* stat() structure to fetch file type, size, and permissions
* *File Permission Handling:* chmod() and symbolic representation (rwx)
* *Recursive Search:* Depth-first search for file name matching
* *Error Handling:* perror() and input validation
* *C++ String and I/O Manipulation:* string, setw, stoi, etc.

---

## 🧰 Libraries Used

cpp
#include <iostream>
#include <fstream>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <iomanip>
#include <cstring>
#include <string>


---

## 📄 Example Output


Available commands: list | copy | move | delete | create | search | perm | chmod | exit
Enter command: list
main.cpp
notes.txt
data/
Enter command: copy
Enter source file: notes.txt
Enter destination file: backup_notes.txt
File copied successfully!
Enter command: exit
Exiting File Explorer...


---

## 🧰 System Requirements

* *Operating System:* Linux / Ubuntu / WSL
* *Compiler:* g++ (GNU Compiler Collection)
* *Language Standard:* C++11 or above

---

## 🏁 Conclusion

The *File Explorer Application* effectively simulates fundamental file management operations in a Linux environment.
It demonstrates how *C++ interacts with the underlying Linux file system* using system calls and standard libraries to perform file handling and permission management operations efficiently.
