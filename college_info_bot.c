#include <stdio.h>
#include <string.h>
#include <ctype.h>

void displayFileContent(const char *filename) {
    FILE *file = fopen(filename, "r");
    char line[200];

    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return;
    }

    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    fclose(file);
}

int main() {
    char input[50];

    printf("=== Welcome to College Inquiry Chatbot ===\n");
    printf("Type one of the following: courses | admission | facilities | contact | exit\n");

    while (1) {
        printf("\nYour query : ");
        scanf("%s", input);
        printf("\n");
        // Convert input to lowercase for case-insensitive comparison
        for (int i = 0; input[i]; i++) {
            input[i] = tolower(input[i]);
        }

        if (strcmp(input, "courses") == 0) {
            displayFileContent("courses.txt");
        } else if (strcmp(input, "admission") == 0) {
            displayFileContent("admission.txt");
        } else if (strcmp(input, "facilities") == 0) {
            displayFileContent("facilities.txt");
        } else if (strcmp(input, "contact") == 0) {
            displayFileContent("contact.txt");
        } else if (strcmp(input, "exit") == 0) {
            printf("Thank you for using the chatbot!\n");
            break;
        } else {
            printf("Invalid input. Please try again.\n");
        }
    }

    return 0;
}
