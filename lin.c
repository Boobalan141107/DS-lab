#include <stdio.h>
#include <stdlib.h>

struct node
{
int data;
struct node *next;
};
struct node *createNode(int data);
void insertAtEnd(struct node **head, int data);
void insertAtPosition(struct node **head, int data, int position);
int searchElement(struct node *head, int data);
void deleteElement(struct node **head, int position);
void displayList(struct node *head);

int main()
{
struct node *head = NULL;
int choice, data, position, result;
while (1)
{  
printf("\nSingly Linked List Operations Menu:\n");
printf("1. Insert at End\n");
printf("2. Insert at Position\n");
printf("3. Search Element\n");
printf("4. Delete Element\n");
printf("5. Display List\n");
printf("6. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice)
{
case 1:
printf("Enter data to insert at end: ");
scanf("%d", &data);
insertAtEnd(&head, data);
break;
case 2:
printf("Enter data to insert: ");
scanf("%d", &data);
printf("Enter position (0-based index): ");
scanf("%d", &position);
insertAtPosition(&head, data, position);
break;
case 3:
printf("Enter element to search: ");
scanf("%d", &data);
result = searchElement(head, data);
if (result != -1)
printf("Element found at position %d\n", result);
else
printf("Element not found.\n");
break;
case 4:
printf("Enter position to delete(0-Based index): ");
scanf("%d", &position);
deleteElement(&head, position);
break;
case 5:
displayList(head);
break;
case 6:
while(head!=NULL){

struct node *temp=head;
head=head->next;
free (temp);
}
return 0;
default:
printf("Invalid choice!\n");
}
}
return 0;
}
struct node *createNode(int data)
{
struct node *newNode = (struct node *)malloc(sizeof(struct node));
if (newNode == NULL)
{
printf("Memory allocation failed.\n");
}
exit(EXIT_FAILURE);
newNode->data = data;
newNode->next = NULL;
return newNode;
}
void insertAtEnd(struct node **head, int data)
{
struct node *newNode = createNode(data);
if (*head == NULL)
{
*head = newNode;
return;
}
struct node *temp = *head;
while (temp->next != NULL)
{
temp = temp->next;
}
temp->next = newNode;
}
void insertAtPosition(struct node **head, int data, int position)
{
if (position < 0)
{
printf("Invalid position.\n");
return;
}
struct node *newNode = createNode(data);
if (position == 0)
{
newNode->next = *head;
*head = newNode;
return;
}
struct node *current = *head;
struct node *previous = NULL;
int currentPos = 0;
while (current != NULL && currentPos < position)
{
previous = current;
current = current->next;
currentPos++;
}
if (currentPos != position)
{
printf("Invalid position.\n");
free(newNode);
return;
}
newNode->next = current;
previous->next = newNode;
}
int searchElement(struct node *head, int data)
{
int position = 0;
while (head != NULL)
{
if (head->data == data)
return position;
head = head->next;
position++;
}
return -1;
}
void deleteElement(struct node **head, int position)
{
if (*head == NULL)
{
printf("List is empty.\n");
return;
}
if (position < 0)
{
printf("Invalid position.\n");
return;
}
struct node *temp = *head;
if (position == 0)
{
*head = temp->next;
free(temp);
return;
}
struct node *previous = NULL;
int currentPos = 0;
while (temp != NULL && currentPos < position)
{
previous = temp;
temp = temp->next;
currentPos++;
}
if (temp == NULL)
{
printf("Invalid position.\n");
return;
}
previous->next = temp->next;
free(temp);
}
void displayList(struct node *head)
{
if (head == NULL)
{
printf("List is empty.\n");
return;
}
printf("Linked List: ");
while (head != NULL)
{
printf("%d -> ", head->data);
head = head->next;
}
printf("NULL\n");
}
