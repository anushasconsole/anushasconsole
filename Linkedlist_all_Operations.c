#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* link;
};

struct node* head = NULL; // Global head pointer
struct node* c = NULL;    // For reversed list
int len;

void create();
void append(void);
void addatbegin(void);
void addatafter(void);
int numberofnode();
void deleteNode(void);
void display(void);
struct node* reverse(struct node*);
void displayr(struct node*);
void reverselist(struct node*);

int main() {
    printf("Operations on single linked list\n");
    int ch;

    while (1) {
        printf("\n1. Create\n");
        printf("2. Append\n");
        printf("3. Add at beginning\n");
        printf("4. Add after\n");
        printf("5. Number of nodes\n");
        printf("6. Delete\n");
        printf("7. Display\n");
        printf("8. Reverse\n");
        printf("9. Display reversed linked list\n");
        printf("10. printinf in reverse order\n");
        printf("Enter your choice:\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                if (head != NULL) {
                    printf("List already created\n");
                } else {
                    create();
                }
                break;
            case 2: append(); break;
            case 3: addatbegin(); break;
            case 4: addatafter(); break;
            case 5:
                len = numberofnode();
                printf("Length: %d\n\n", len);
                break;
            case 6: deleteNode(); break;
            case 7: display(); break;
            case 8: reverse(head); break;
            case 9: displayr(c); break;
            case 10:reverselist(head);break;
            default: printf("Invalid choice\n");
        }
    }
}

void create() {
    int n, i;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        struct node* temp = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &temp->data);
        temp->link = NULL;

        if (head == NULL) {
            head = temp;
        } else {
            struct node* p = head;
            while (p->link != NULL) {
                p = p->link;
            }
            p->link = temp;
        }
    }
}

void append() {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter the element: ");
    scanf("%d", &temp->data);
    temp->link = NULL;

    if (head == NULL) {
        head = temp;
    } else {
        struct node* p = head;
        while (p->link != NULL) {
            p = p->link;
        }
        p->link = temp;
    }
}

int numberofnode() {
    int count = 0;
    struct node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->link;
    }
    return count;
}

void display() {
    struct node* temp = head;
    if (temp == NULL) {
        printf("List is empty, no nodes\n\n");
    } else {
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->link;
        }
        printf("NULL\n\n");
    }
}

void addatbegin() {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &temp->data);
    temp->link = head;
    head = temp;
    display();
}

void addatafter() {
    int loc, len, i = 1;
    printf("Enter location of node: ");
    scanf("%d", &loc);
    len = numberofnode();

    if (loc > len) {
        printf("Invalid location. Currently, list has %d nodes\n", len);
    } else {
        struct node* c = head;
        while (i < loc) {
            c = c->link;
            i++;
        }

        struct node* temp = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &temp->data);
        temp->link = c->link;
        c->link = temp;
        display();
    }
}

void deleteNode() {
    int loc;
    printf("Enter location: ");
    scanf("%d", &loc);

    if (loc > numberofnode()) {
        printf("Invalid location\n");
    } else if (loc == 1) {
        struct node* temp = head;
        head = temp->link;
        free(temp);
        display();
    } else {
        int i = 1;
        struct node* c = head;
        struct node* d;
        
        while (i < loc - 1) {
            c = c->link;
            i++;
        }
        d = c->link;
        c->link = d->link;
        free(d);
        display();
    }
}

struct node* reverse(struct node* head) {
    struct node* temp;
    while (head != NULL) {
        temp = head;
        head = head->link;
        temp->link = c;
        c = temp;
    }
    printf("Reversed successfully\n");
    return c;
}

void displayr(struct node* c) {
    struct node* temp = c;
    printf("Reversed linked list is\n");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}
void reverselist(struct node* head) {
    
    if (head == NULL) {
        return;
    }
    
    reverselist(head->link);
    
    printf("%d -> ", head->data);
}
