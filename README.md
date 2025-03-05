# inet3101-lab2
## Program Features
Dynamic memory allocation: The application performs memory allocation through malloc() together with manual resizing techniques instead of relying on realloc().
Record management: The program offers a record management system which allows users to print the entire record set and display database length information while showing record count.

## Functionality

Add: The system provides a function for users to create new records which automatically allocates sufficient memory space.
Delete: Programs erase the last stored record from memory while readjusting the size of allocated space.
Print: The system shows every record stored in the database through the print records function.
Exit: The program exits to free all allocated memory in a proper manner.

## Design
Through its menu system users can access the following features from the interfaces.
1. Print all records
2. Print number of records
3. Print size of database
4. Add a record
5. Delete the last record
6. Exit the program

The program implements manual memory copying functions to replace `realloc()` because the assignment included manual resizing as an extra credit requirement.
