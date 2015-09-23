#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
    int val;
    struct node* next;
}node_t;

void insert_end(node_t **head,int value)
{
    node_t* actual = *head;
    node_t* new_node = malloc(sizeof(node_t));
    new_node->val = value;
    new_node->next = NULL;
    
    while(actual->next != NULL)
    {
        actual = actual->next;
    }
    actual->next = new_node;
    (*head)->val++;
}

void print_list(node_t **head)
{
    node_t * actual = (*head)->next;
    while(actual != NULL)
    {
        printf(" %d ",actual->val);
        actual = actual->next;
    }
    printf("\n");
}

void size(node_t ** head)
{
    printf("%d\n",(*head)->val);
}

void print_menu()
{
    printf("0.-Exit\n");
    printf("1.-Print List\n");
    printf("2.-Size of the list\n");
    printf("3.-Insert in the end of the list\n");
    printf("4.-Insert in the beginning of the list\n");
}

void free_mem(node_t * head)
{
    node_t * actual = head;
    while(actual != NULL)
    {
        actual = actual->next;
        free(actual);
    }
    printf("Free memory\n");
}

void insert_beginning(node_t** head,int val)
{
    node_t * new_value = malloc(sizeof(node_t));
    new_value->val = val;
    new_value->next = (*head)->next;
    (*head)->next = new_value;
    (*head)->val++;
}

int main()
{
    node_t * head= NULL;
    head = malloc(sizeof(node_t));
    if(head==NULL)return 1;
    head->val = 0;
    head->next = NULL;
    int opcion_menu = 1;
    while(opcion_menu)
    {
        print_menu();
        scanf("%d",&opcion_menu);
        switch(opcion_menu)
        {
            case 0:    
            {
                printf("Thanks for use our application\n");
                break;
            }
            case 1:
            {
                print_list(&head);
                break;
            }
            case 2:
            {
                size(&head);
                break;
            }
            case 3:
            {
                int tmp_number = 0;
                printf("Type the value\n");
                scanf("%d",&tmp_number);
                insert_end(&head,tmp_number);
                break;
            }    
            case 4:
            {
                int tmp_number = 0;
                printf("Type the value\n");
                scanf("%d",&tmp_number);
                insert_beginning(&head,tmp_number);
                break;
            }
            default:
                printf("Sorry, try again\n");
        }
    }
    free_mem(head);
    return 0;
}

//http://www.learn-c.org/en/Linked_lists
