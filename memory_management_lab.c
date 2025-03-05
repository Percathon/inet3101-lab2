#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a part
struct Part {
    int partNumber;
    char partName[50];
    float partSize;
    char sizeMetric[10];
    float partCost;
};

// Function prototypes
void printAllRecords(struct Part *database, int recordCount);
void addRecord(struct Part **database, int *recordCount);
void deleteRecord(struct Part **database, int *recordCount);
void printNumberOfRecords(int recordCount);
void printDatabaseSize(int recordCount);
void freeMemory(struct Part **database, int recordCount);

int main() {
    struct Part *database = NULL;  
    int recordCount = 0;           
    int choice;

    while (1) {
        printf("\nMENU\n");
        printf("=======\n");
        printf("1. Print all records\n");
        printf("2. Print number of records\n");
        printf("3. Print size of database\n");
        printf("4. Add record\n");
        printf("5. Delete record\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printAllRecords(database, recordCount);
                break;
            case 2:
                printNumberOfRecords(recordCount);
                break;
            case 3:
                printDatabaseSize(recordCount);
                break;
            case 4:
                addRecord(&database, &recordCount);
                break;
            case 5:
                deleteRecord(&database, &recordCount);
                break;
            case 6:
                freeMemory(&database, recordCount);  // Free all allocated memory
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

// Function to print all records
void printAllRecords(struct Part *database, int recordCount) {
    if (recordCount == 0) {
        printf("No records to display.\n");
        return;
    }

    for (int i = 0; i < recordCount; i++) {
        printf("\nRecord %d:\n", i + 1);
        printf("Part Number: %d\n", database[i].partNumber);
        printf("Part Name: %s\n", database[i].partName);
        printf("Part Size: %.2f %s\n", database[i].partSize, database[i].sizeMetric);
        printf("Part Cost: $%.2f\n", database[i].partCost);
    }
}

// Function to add a record
void addRecord(struct Part **database, int *recordCount) {
    struct Part *newDatabase = (struct Part *)malloc((*recordCount + 1) * sizeof(struct Part));
    if (newDatabase == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    // Copy the old records to the new memory
    for (int i = 0; i < *recordCount; i++) {
        newDatabase[i] = (*database)[i];
    }
    free(*database);
    *database = newDatabase;
    printf("Enter part number: ");
    scanf("%d", &(*database)[*recordCount].partNumber);
    printf("Enter part name: ");
    scanf(" %[^\n]", (*database)[*recordCount].partName);
    printf("Enter part size: ");
    scanf("%f", &(*database)[*recordCount].partSize);
    printf("Enter size metric: ");
    scanf("%s", (*database)[*recordCount].sizeMetric);
    printf("Enter part cost: ");
    scanf("%f", &(*database)[*recordCount].partCost);

    (*recordCount)++;
    printf("Record added successfully.\n");
}

// Function to delete the last record
void deleteRecord(struct Part **database, int *recordCount) {
    if (*recordCount == 0) {
        printf("No records to delete.\n");
        return;
    }
    struct Part *newDatabase = (struct Part *)malloc((*recordCount - 1) * sizeof(struct Part));
    if (newDatabase == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    for (int i = 0; i < *recordCount - 1; i++) {
        newDatabase[i] = (*database)[i];
    }
    free(*database);
    *database = newDatabase;
    (*recordCount)--;
    printf("Last record deleted successfully.\n");
}

// Function to print the number of records
void printNumberOfRecords(int recordCount) {
    printf("Number of records: %d\n", recordCount);
}

// Function to print the size of the database in bytes
void printDatabaseSize(int recordCount) {
    printf("Database size: %lu bytes\n", recordCount * sizeof(struct Part));
}

// Function to free the memory when exiting the program
void freeMemory(struct Part **database, int recordCount) {
    if (*database != NULL) {
        free(*database);
        *database = NULL;
        printf("Memory freed for %d records.\n", recordCount);
    }
}
