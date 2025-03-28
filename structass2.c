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
    printf("Enter the number of components to add: "); 
    scanf("%d", &count); 

    if (count > Max_Components) {
        printf("Error: Exceeds maximum number of components.\n");
        count = Max_Components;
    }
     
    for (int i = 0; i < count; i++) { 
        struct Component *comp = &components[i]; // Pointer to current component
        printf("\nEntering details for Component %d:\n", i + 1);
        comp->sr_no = i + 1; 
        printf("Name: "); 
        scanf("%s", comp->name); 
        printf("Symbol: "); 
        scanf(" %c", &comp->symbol); 
        printf("Value: "); 
        scanf("%f", &comp->value); 
        printf("Cost(in Rs.): "); 
        scanf("%f", &comp->cost); 
    } 
} 

void display() { 
    printf("\n+----+-------------------------+--------+--------+---------+\n"); 
    printf("| Sr | Name                    | Symbol | Value  | Cost    |\n"); 
    printf("+----+-------------------------+--------+--------+---------+\n"); 
    for (int i = 0; i < count; i++) { 
        struct Component *comp = &components[i]; // Pointer to current component
        printf("| %-2d | %-23s | %-6c | %-6.2f | %-7.2f |\n",  
            comp->sr_no, comp->name, comp->symbol,  
            comp->value, comp->cost); 
    } 
    printf("+----+-------------------------+--------+--------+---------+\n"); 
} 

void modify() { 
    int index; 
    printf("Enter Sr. No. of the component to modify: "); 
    scanf("%d", &index); 

    if (index > 0 && index <= count) { 
        struct Component *comp = &components[index - 1]; // Pointer to the component to modify
        printf("Enter new details for Component %d:\n", index); 
        printf("Name: "); 
        scanf("%s", comp->name); 
        printf("Symbol: "); 
        scanf(" %c", &comp->symbol); 
        printf("Value: "); 
        scanf("%f", &comp->value); 
        printf("Cost(in Rs.): "); 
        scanf("%f", &comp->cost); 
    } else { 
        printf("Error: Invalid Sr. No.!\n"); 
    } 
} 

void append() { 
    if (count >= Max_Components) {
        printf("Error: Cannot add more components. Maximum limit reached.\n");
        return;
    }

    struct Component *comp = &components[count]; // Pointer to the new component
    printf("Enter details for new component:\n"); 
    comp->sr_no = count + 1; 
    printf("Name: "); 
    scanf("%s", comp->name); 
    printf("Symbol: "); 
    scanf(" %c", &comp->symbol); 
    printf("Value: "); 
    scanf("%f", &comp->value); 
    printf("Cost(in Rs.): "); 
    scanf("%f", &comp->cost); 
    count++; 
}

void search() { 
    char name[20]; 
    printf("Enter the name of the component to search for: "); 
    scanf("%s", name); 
     
    for (int i = 0; i < count; i++) { 
        struct Component *comp = &components[i]; // Pointer to current component
        if (strcmp(comp->name, name) == 0) { 
            printf("\nComponent found:\n"); 
            printf("Sr. No.: %d\nName: %s\nSymbol: %c\nValue: %.2f\nCost: %.2f\n",  
                    comp->sr_no, comp->name, comp->symbol, 
                    comp->value, comp->cost); 
            return; 
        } 
    } 
    printf("Component not found!\n"); 
} 

void sort() { 
    struct Component *temp; 
    for (int i = 0; i < count - 1; i++) { 
        for (int j = i + 1; j < count; j++) { 
            struct Component *comp1 = &components[i]; // Pointer to first component
            struct Component *comp2 = &components[j]; // Pointer to second component
            if (comp1->value > comp2->value) { 
                temp = comp1; 
                comp1 = comp2; 
                comp2 = temp; 
                *comp1 = *comp2; // Swap the values
                *comp2 = *temp; // Swap the values
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
