#include <stdio.h> 
#include <string.h> 

#define Max_Components 100

struct Component { 
    int sr_no; 
    char name[20]; 
    char symbol; 
    float value; 
    float cost; 
};

struct Component components[Max_Components];  
int count = 0;

void create() { 
    printf("Enter the number of components to add:- "); 
    scanf("%d", &count); 

    if (count > Max_Components) {
        printf("Error: Exceeds maximum number of components.\n");
        count = Max_Components;
    }
     
    for (int i = 0; i < count; i++) { 
        printf("\nEntering details for Component %d:\n", i + 1);
        components[i].sr_no = i + 1; 
        printf("Name: "); 
        scanf("%s", components[i].name); 
        printf("Symbol: "); 
        scanf(" %c", &components[i].symbol); 
        printf("Value: "); 
        scanf("%f", &components[i].value); 
        printf("Cost(in Rs.): "); 
        scanf("%f", &components[i].cost); 
    } 
} 

void display() { 
    printf("\n+----+-------------------------+--------+--------+---------+\n"); 
    printf("| Sr | Name                    | Symbol | Value  | Cost    |\n"); 
    printf("+----+-------------------------+--------+--------+---------+\n"); 
    for (int i = 0; i < count; i++) { 
        printf("| %-2d | %-23s | %-6c | %-6.2f | %-7.2f |\n",  
            components[i].sr_no, components[i].name, components[i].symbol,  
            components[i].value, components[i].cost); 
    } 
    printf("+----+-------------------------+--------+--------+---------+\n"); 
} 

void modify() { 
    int index; 
    printf("Enter Sr. No. of the component to modify: "); 
    scanf("%d", &index); 

    if (index > 0 && index <= count) { 
        printf("Enter new details for Component %d:\n", index); 
        printf("Name: "); 
        scanf("%s", components[index - 1].name); 
        printf("Symbol: "); 
        scanf(" %c", &components[index - 1].symbol); 
        printf("Value: "); 
        scanf("%f", &components[index - 1].value); 
        printf("Cost(in Rs.): "); 
        scanf("%f", &components[index - 1].cost); 
    } else { 
        printf("Error: Invalid Sr. No.!\n"); 
    } 
} 

void append() { 
    if (count >= Max_Components) {
        printf("Error: Cannot add more components. Maximum limit reached.\n");
        return;
    }

    printf("Enter details for new component:\n"); 
    components[count].sr_no = count + 1; 
    printf("Name: "); 
    scanf("%s", components[count].name); 
    printf("Symbol: "); 
    scanf(" %c", &components[count].symbol); 
    printf("Value: "); 
    scanf("%f", &components[count].value); 
    printf("Cost(in Rs.): "); 
    scanf("%f", &components[count].cost); 
    count++; 
}

void search() { 
    char name[20]; 
    printf("Enter the name of the component to search for: "); 
    scanf("%s", name); 
     
    for (int i = 0; i < count; i++) { 
        if (strcmp(components[i].name, name) == 0) { 
            printf("\nComponent found:\n"); 
            printf("Sr. No.: %d\nName: %s\nSymbol: %c\nValue: %.2f\nCost: %.2f\n",  
                    components[i].sr_no, components[i].name, components[i].symbol, 
                    components[i].value, components[i].cost); 
            return; 
        } 
    } 
    printf("Component not found!\n"); 
} 

void sort() { 
    struct Component temp; 
    for (int i = 0; i < count - 1; i++) { 
        for (int j = i + 1; j < count; j++) { 
            if (components[i].value > components[j].value) { 
                temp = components[i]; 
                components[i] = components[j]; 
                components[j] = temp; 
            } 
        } 
    } 
    printf("Components have been sorted by value.\n"); 
}

int main() {
    int choice;
     
    while (1) { 
        printf("\nMenu:\n");
        printf("1. Create\n");
        printf("2. Display\n");
        printf("3. Modify\n");
        printf("4. Append\n");
        printf("5. Search\n");
        printf("6. Sort\n");
        printf("7. Exit\n");
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
        switch (choice) { 
            case 1: create(); break; 
            case 2: display(); break; 
            case 3: modify(); break; 
            case 4: append(); break; 
            case 5: search(); break; 
            case 6: sort(); break; 
            case 7: return 0; 
            default: printf("Invalid choice! Please enter a number between 1 and 7.\n"); 
        }
    }
}
