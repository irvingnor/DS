#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int tipo_dato;

struct node
{
    tipo_dato value;
    struct node* next;
};

void inserta_final(struct node** ref_head,tipo_dato val)
{
    struct node* new_ = malloc(sizeof(struct node));
    new_->next = NULL;
    new_->value = val;

    struct node* tmp = *ref_head;
    while(tmp->next != NULL)
    {
        tmp = tmp->next;
    }

    tmp->next = new_;
    (*ref_head)->value++;
}

void inserta_principio(struct node** ref_head,tipo_dato val)
{
    struct node* new_ = malloc(sizeof(struct node));
    new_->next = (*ref_head)->next;
    new_->value = val;
    (*ref_head)->next =  new_;
    (*ref_head)->value++;
}

void inserta_nth(struct node** ref_head,tipo_dato val,int posicion)
{
    struct node* new_ = malloc(sizeof(struct node));
    new_->value = val;

    struct node* tmp = *ref_head;
    int posicion_lista = 0;

    while(tmp->next != NULL && posicion_lista < posicion)
    {
        tmp = tmp->next;
        posicion_lista++;
    }
    new_->next = tmp->next;
    tmp->next = new_;
    (*ref_head)->value++;
}

void tamanio(struct node** ref_head)
{
    printf("%d\n",(*ref_head)->value);
}

void muestra(struct node** ref_head)
{
    struct node* tmp = (*ref_head)->next;
    while(tmp != NULL)
    {
        printf("%d\t",tmp->value);
        tmp = tmp->next;
    }
    printf("\n");
}

void elimina_nth(struct node** ref_head,int posicion)
{
    int posicion_lista = 0;
    struct node* tmp = (*ref_head);
    while(tmp->next != NULL && posicion_lista < posicion)
    {
        tmp = tmp->next;
        posicion_lista++;
    }

    if(tmp->next != NULL)
    {
        struct node* borrar = tmp->next;
        tmp->next = borrar->next;
        free(borrar);
        (*ref_head)->value--;
    }
}

void elimina_numero(struct node** ref_head,tipo_dato val)
{
    struct node* tmp = (*ref_head);
    while(tmp->next != NULL && (tmp->next)->value != val)
    {
        tmp = tmp->next;
    }

    if(tmp->next != NULL && (tmp->next)->value == val)
    {
        struct node* borrar = tmp->next;
        tmp->next = borrar->next;
        free(borrar);
        (*ref_head)->value--;
    }
}

void elimina_repetidos(struct node** ref_head,tipo_dato val)
{
    struct node* tmp =(*ref_head);
    struct node* borrar;

    while(tmp->next != NULL)
    {
        if((tmp->next)->value == val)
        {
            borrar = tmp->next;
            tmp->next = borrar->next;//---
            free(borrar);
            (*ref_head)->value--;
        }
        else
            tmp = tmp->next;
    }
}

void elimina_lista(struct node** ref_head)
{
    struct node* tmp = (*ref_head);
    while(tmp->next != NULL)
    {
        struct node* b = tmp->next;
        tmp->next = b->next;
        free(b);
        (*ref_head)->value--;
    }
}

int main()
{
    struct node* head = malloc(sizeof(struct node));
    head->next = NULL;
    head->value = 0;
    int opcion_menu = 1,val = 1,posicion = 0;
    while(opcion_menu)
    {
        system("cls");//////////////////////////////////////////////
        printf("0.-Salir\n");
        printf("1.-Insertar al final\n");
        printf("2.-Insertar al principio\n");
        printf("3.-Insertar en la nth posicion\n");
        printf("4.-Mostrar\n");
        printf("5.-Borrar nth posicion\n");
        printf("6.-Borrar numero especifico\n");
        printf("7.-Borrar todas las ocurrencias de un numero\n");
        printf("8.-Tamanio de la lista\n");
        printf("9.-Eliminar lista completa\n");
        scanf("%d",&opcion_menu);
        switch(opcion_menu)
        {
            case 0:
                {
                    printf("Gracias por utilizar el programa\n");
                    break;
                }
            case 1:
                {
                    printf("Numero a insertar\n");
                    scanf("%d",&val);
                    inserta_final(&head,val);
                    break;
                }
            case 2:
                {
                    printf("Numero a insertar\n");
                    scanf("%d",&val);
                    inserta_principio(&head,val);
                    break;
                }
             case 3:
                {
                    printf("Numero a insertar\n");
                    scanf("%d",&val);
                    printf("Posicion a insertar\n");
                    scanf("%d",&posicion);
                    inserta_nth(&head,val,posicion);
                    break;
                }
            case 4:
                {
                    muestra(&head);
                    system("pause");/////////////////////////////////
                    break;
                }
            case 5:
                {
                    printf("Posicion a eliminar\n");
                    scanf("%d",&val);
                    elimina_nth(&head,val);
                    break;
                }
            case 6:
                {
                    printf("Numero a buscar y eliminar?\n");
                    scanf("%d",&val);
                    elimina_numero(&head,val);
                    break;
                }
            case 7:
                {
                    printf("Numero para eliminar repetidos\n");
                    scanf("%d",&val);
                    elimina_repetidos(&head,val);
                    break;
                }
            case 8:
                {
                    tamanio(&head);
                    system("pause");////////////////////////////////
                    break;
                }
            case 9:
                {
                    elimina_lista(&head);
                    break;
                }
            default:
                printf("La opcion solicitada no existe\n");
        }//Final switch
    }//Final while
    elimina_lista(&head);
    free(head);
    return 0;
}
