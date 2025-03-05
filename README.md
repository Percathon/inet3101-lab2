# inet3101-lab2
## Program Features
Dynamic memory allocation: The application performs memory allocation through malloc() together with manual resizing techniques instead of relying on realloc().
Record management: The program offers a record management system which allows users to print the entire record set and display database length information while showing record count.

## Functionality
Add a record: Users can add new records by using this option which creates memory space for the new entry.
Delete a record: Users have the option to accomplish deletion of one record by removing the last entry and rebalancing allocated memory space.
Print records: The program displays entire database content through its print records function.
Exit: The program terminates before exiting while it frees all memory allocations properly.

## Design
Through its menu system users can access the following features from the interfaces.
1. Print all records
2. Print number of records
3. Print size of database
4. Add a record
5. Delete the last record
6. Exit the program

The program implements manual memory copying functions to replace `realloc()` because the assignment included manual resizing as an extra credit requirement.
