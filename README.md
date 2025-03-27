# **PhoneBook – Interactive Contact Management Application**  

A Qt/C++ desktop application for managing contact information, featuring a table-based interface with data validation, file operations, and search/sort functionality.  

## **Features**  

### **1. Contact Management**  
- **Add new contacts** with fields:  
  - Full name  
  - Date of birth  
  - Email  
  - Phone numbers (multiple per contact)  
- **Edit existing contacts**  
- **Delete contacts** (single or batch)  
- **Dynamic phone number fields** (add/remove numbers per contact)  

### **2. Data Validation**  
- **Input checks** for:  
  - Name format (valid characters, length)  
  - Email format (basic regex validation)  
  - Phone number format (correct digits, length)  
  - Date validity  
- **Error messages** displayed for invalid inputs  

### **3. File Operations**  
- **Save contacts** to a text file (tab-separated format)  
- **Load contacts** from a file (with error handling)  
- **File selection dialog** for save/load operations  

### **4. Search & Sorting**  
- **Search contacts** by:  
  - Name  
  - Email  
  - Phone number  
- **Sort contacts** by:  
  - Name (A-Z, Z-A)  
  - Date of birth (ascending/descending)  

### **5. User Interface**  
- **Table-based display** (QTableWidget) for clear contact visualization  
- **Interactive buttons** for all operations (add, edit, delete, save, load, search, sort)  
- **Dynamic error labels** for input validation feedback  

## **Implemented Algorithms**  
- **Input validation** (regex, manual checks)  
- **File I/O** (QFile, QTextStream for reading/writing)  
- **Table manipulation** (inserting, updating, deleting rows)  
- **Search & sort** (QTableWidget filtering, custom comparators)  

## **Interface (Phone Class)**  

### **UI Controls**  
- **Input fields (QLineEdit, QDateEdit):**  
  - `pName` (Full name)  
  - `pBirthday` (Date of birth)  
  - `pEmail` (Email)  
  - `PhoneNum` (Dynamic phone number fields)  
- **Buttons (QPushButton):**  
  - `NewPerson` – Open "Add Contact" form  
  - `addButton` – Confirm new contact  
  - `change` – Edit selected contact  
  - `saveChange` – Save edited contact  
  - `del`, `del2` – Delete contact(s)  
  - `saveFile`, `saveFile2` – Save to file  
  - `loadFile`, `loadFile2` – Load from file  
  - `sort1`, `sort2` – Sort contacts  
  - `Serch1`, `Serch2` – Search contacts  
  - `back`, `sortback`, `serchback` – Navigation buttons  
- **Table (QTableWidget):**  
  - `tableWidget` – Main contacts table  
  - `tableSerch` – Search results table  
- **Error labels (QLabel):**  
  - `errorName`, `errorEmail`, `errorData` – Input validation errors  
  - `a` – General operation feedback  

### **Logic**  
- **Data validation** (`wrongName()`, `wrongEmail()`, `wrongNumber()`, etc.)  
- **File handling** (`saveToFile()`, `loadFromFile()`)  
- **Table updates** (`addPerson()`, `changePerson()`, `delPerson()`)  
- **Search & sort** (`serch1()`, `sortTab()`)  

## **Dependencies**  
- **Qt 5.x / Qt 6.x** (Widgets, Core)  
- **C++17** (STL, filesystem for path handling)  

## **Build & Run**  
```sh
git clone <repository>  
cd PhoneBook  
cmake -B build && cmake --build build  
./build/PhoneBook  
```

## **How it looks:**  
