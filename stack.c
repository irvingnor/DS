#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef char tipo_dato;

struct node
{
    tipo_dato value;
    struct node* next;
};

typedef struct
{
    struct node* tope;
    int size_;
    int max_size;
}stack_;

void ini(stack_ * stack1)
{
    stack1->tope = NULL;
}

int isEmpty(stack_ * stack1)
{
    return (stack1->tope == NULL);
}

void push(stack_ * stack1, tipo_dato value_)
{
    struct node* new_ = malloc(sizeof(struct node));
    new_->value = value_;
    new_->next = NULL;

    if(isEmpty(stack1))
    {
        stack1->tope = new_;
        return;
    }
    struct node* tmp = stack1->tope;
    stack1->tope = new_;
    new_->next = tmp;
}

void print_all(stack_ * stack1)
{
    struct node* tmp = malloc(sizeof(struct node));
    tmp = stack1->tope;
    if(isEmpty(stack1)) return;

    while(tmp != NULL)
    {
        printf("%c\t",tmp->value);
        tmp = tmp->next;
    }
    printf("\n");
}

void erase_all(stack_ * stack1)
{
    if(isEmpty(stack1)) return;

    struct node* tmp = stack1->tope;
    while(tmp->next != NULL)
    {
        struct node* erase_ = tmp;
        tmp = erase_->next;
        free(erase_);
    }
    stack1->tope = NULL;
}

char pop(stack_ * stack1)
{
    if(isEmpty(stack1)) return '-';

    struct node* tmp = malloc(sizeof(struct node));
    tmp = stack1->tope;
    stack1->tope = tmp->next;
    char val = tmp->value;
    free(tmp);
    return val;
}

char peek(stack_ * stack1)
{
    if(isEmpty(stack1))return '-';
    return stack1->tope->value;
}

int main()
{
    int opc_menu = 1;
    char element = ' ';
    stack_ stack1;
    ini(&stack1);
    while(opc_menu)
    {
        system("cls"); /////////////////////////////////////
        printf("0.-Exit\n");
        printf("1.-Push\n");
        printf("2.-Pop\n");
        printf("3.-Peek\n");
        printf("4.-Print all elements\n");
        printf("5.-Is Empty\n");
        printf("6.-Erase\n");
        scanf("%d",&opc_menu);
        switch(opc_menu)
        {
            case 0:
            {
                printf("Thank you for use the program\n");
                break;
            }
            case 1:
            {
                printf("Type the element to push\n");
                scanf(" %c",&element);
                push(&stack1,element);
                break;
            }
            case 2:
            {
                printf("%c\n",pop(&stack1));
                system("pause");
                break;
            }
            case 3:
            {
                printf("%c\n",peek(&stack1));
                system("pause");
                break;
            }
            case 4:
            {
                    print_all(&stack1);
                    system("pause");
                    break;
            }
            case 5:
            {
                    if(isEmpty(&stack1))
                    {
                        printf("Empty\n");
                    }
                    else
                    {
                        printf("Is not Empty\n");
                    }
                    system("pause");
            }
            case 6:
            {
                erase_all(&stack1);
                break;
            }
            default:
                printf("Ingrese un numero valido\n");
        }//End switch
    }//End while
    erase_all(&stack1);
    return 0;
}
