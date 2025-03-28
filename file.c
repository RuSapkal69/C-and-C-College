#include <stdio.h>
#include <stdlib.h>

void createFile() {
    FILE *file;
    char filename[100], data[1000];

    printf("Enter the filename to create (with .txt extension): ");
    scanf("%s", filename);

    // Create and open the file for writing
    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error in creating file!\n");
        return;
    }

    printf("Enter content to write in the file (max 1000 characters):\n");
    getchar();  // To consume the newline character left in buffer
    fgets(data, sizeof(data), stdin);

    fprintf(file, "%s", data);  // Write data to file
    fclose(file);               // Close file
    printf("File '%s' created and content written successfully!\n", filename);
}

void readFile() {
    FILE *file;
    char filename[100], c;

    printf("Enter the filename to read (with .txt extension): ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: File not found!\n");
        return;
    }

    printf("Content of the file '%s':\n", filename);
    while ((c = fgetc(file)) != EOF) {
        putchar(c);  // Print each character from the file
    }

    fclose(file);  // Close file
}

void appendToFile() {
    FILE *file;
    char filename[100], data[1000];

    printf("Enter the filename to append to (with .txt extension): ");
    scanf("%s", filename);

    // Open the file in append mode
    file = fopen(filename, "a");
    if (file == NULL) {
        printf("Error: File not found!\n");
        return;
    }

    printf("Enter content to append (max 1000 characters):\n");
    getchar();  // To consume the newline character left in buffer
    fgets(data, sizeof(data), stdin);

    fprintf(file, "%s", data);  // Append data to file
    fclose(file);               // Close file
    printf("Content appended to '%s' successfully!\n", filename);
}

int main() {
    int choice;

    while (1) {
        printf("\nFile Handling Operations\n");
        printf("1. Create and Write to a File\n");
        printf("2. Read a File\n");
        printf("3. Append to a File\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createFile();
                break;
            case 2:
                readFile();
                break;
            case 3:
                appendToFile();
                break;
            case 4:
                exit(0);

            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}
