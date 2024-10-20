#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contact { 
    char name[50];
    char phone[20];
    char email[50];
    struct Contact *next; //for link list
};


/*Contact Insertion Operation*/

void insertContact(struct Contact **head, char name[], char phone[], char email[]) {
    struct Contact *newContact = malloc(sizeof(struct Contact));
    strcpy(newContact->name, name);
    strcpy(newContact->phone, phone);
    strcpy(newContact->email, email);
    newContact->next = *head;     
    *head = newContact;
}

/*Contact Display Operation*/

void displayContacts(struct Contact *head) {
    while (head) {
        printf("Name: %s\nPhone: %s\nEmail: %s\n\n", head->name, head->phone, head->email);
        head = head->next;
    }
}

/*Contact Search Operation*/

struct Contact* searchContact(struct Contact *head, char name[]) {
    while (head && strcmp(head->name, name) != 0) {
        head = head->next;
    }
    return head;
}

/*Contact Delete Operation*/

void deleteContact(struct Contact **head, char name[]) {
    struct Contact *temp = *head, *prev = NULL;

    while (temp && strcmp(temp->name, name) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp) {
        if (prev) prev->next = temp->next;
        else *head = temp->next;
        free(temp);
    }
}

/*Contact Update Operation*/

void updateContact(struct Contact *head, char name[]) {
    struct Contact *contact = searchContact(head, name);
    
    if (contact) {
        printf("Enter new Name: ");
        scanf(" %[^\n]", contact->name);
        printf("Enter new Phone: ");
        scanf(" %[^\n]", contact->phone);
        printf("Enter new Email: ");
        scanf(" %[^\n]", contact->email);
        printf("Contact updated successfully.\n");
    } else {
        printf("Contact not found.\n");
    }
}


/*Contact Sorting Operation*/

void sortContacts(struct Contact **head) {
    struct Contact *i, *j;
    char tempName[50], tempPhone[20], tempEmail[50];

    for (i = *head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (strcmp(i->name, j->name) > 0) {
                // Swap data
                strcpy(tempName, i->name);
                strcpy(tempPhone, i->phone);
                strcpy(tempEmail, i->email);

                strcpy(i->name, j->name);
                strcpy(i->phone, j->phone);
                strcpy(i->email, j->email);

                strcpy(j->name, tempName);
                strcpy(j->phone, tempPhone);
                strcpy(j->email, tempEmail);
            }
        }
    }
}

/*Contact  Operation*/

void traverseContacts(struct Contact *head) {
    displayContacts(head);
}

void UserGuide(){

    printf("\n\n1. **Adding a Contact:**\n\n- Select option 1 to add a new contact.\n\n- Enter the contact's name, phone number, and email when prompted.\n\n2. **Displaying Contacts:**\n\n- Choose option 2 to view all contacts in the system.\n\n- The system will display a list of names, phone numbers, and emails.\n\n3. **Searching for a Contact:**\n\n- Opt for option 3 to search for a specific contact.\n\n- Enter the name of the contact you are looking for.\n\n4. **Deleting a Contact:**\n\n- Select option 4 to delete a contact.\n\n- Provide the name of the contact you wish to remove.\n\n5. **Updating a Contact:**\n\n- Choose option 5 to update a contact's information.\n\n- Enter the name of the contact you want to modify and provide the new details.\n\n6. **Sorting Contacts:**\n\n- Opt for option 6 to sort contacts alphabetically.\n\n- The system will arrange contacts based on their names.\n\n7. **Traversing Contacts:**\n\n- Select option 7 to traverse through all contacts.\n\n- The system will display details for each contact one by one.\n\n8. **Exiting the System:**\n\n- To exit the system, choose option 8.\n\n9. **User Guidelines:**\n\n- A proper guidelines about how my user can access my CONTACT MANAGEMENT SYSTEM.\n\n. **About Us:**\n\n- In this section you can know more about us.\n\n");
}

void AboutUS(){

    printf("\n\nNAME: Abdullah Sardar\nCourse Name: Data Structured Lab\nSection:D7\nCourse Teacher Name: Fairuz Shaiara\n");
}

int main() {
    struct Contact *head = NULL;
    int choice;

    do {
        printf("\nWelcome to the Contact Management System of Abdullah Sardar\n");
        printf("\n\nPlease select your desirable option or if you're a new user then select option 9.........\n");

        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Update Contact\n");
        printf("6. Sort Contacts\n");
        printf("7. Traverse Contacts(Same as 2 but do it in a modular way)\n");
        printf("8. Exit\n");
        printf("9. User Guide\n");
        printf("10. About Us\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char name[50], phone[20], email[50];
                printf("Enter Name: ");
                scanf(" %[^\n]", name);
                printf("Enter Phone: ");
                scanf(" %[^\n]", phone);
                printf("Enter Email: ");
                scanf(" %[^\n]", email);
                insertContact(&head, name, phone, email);
                printf("Contact added successfully.\n");
                break;
            }
            case 2:
                displayContacts(head);
                break;
            case 3: {
                char searchName[50];
                printf("Enter Name to search: ");
                scanf(" %[^\n]", searchName);
                struct Contact *result = searchContact(head, searchName);
                if (result) printf("Contact found.\n");
                else printf("Contact not found.\n");
                break;
            }
            case 4: {
                char deleteName[50];
                printf("Enter Name to delete: ");
                scanf(" %[^\n]", deleteName);
                deleteContact(&head, deleteName);
                printf("Contact deleted successfully.\n");
                break;
            }
            case 5: {
                char updateName[50];
                printf("Enter Name to update: ");
                scanf(" %[^\n]", updateName);
                updateContact(head, updateName);
                break;
            }
            case 6:
                sortContacts(&head);
                printf("Contacts sorted successfully.\n");
                break;
            case 7:
                traverseContacts(head);
                break;
            case 8:
                printf("Exiting the program.\n");
                break;
            case 9:
            UserGuide();
            break;    
            case 10: 
            AboutUS();
            break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 10);
     
    return 0;
}