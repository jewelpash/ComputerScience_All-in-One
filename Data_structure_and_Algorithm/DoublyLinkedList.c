#include <stdio.h>
#include <malloc.h>

typedef struct node{
    int key;
    struct node *prev;
    struct node *next;
}NODE;

void insert_node( NODE **, int);
int delete_node( NODE **, int);
void display_node( NODE *);

int main( void)
{
    NODE *H = NULL; // HEAD

    insert_node( &H, 10);
    insert_node( &H, 30);
    insert_node( &H, 20);
    insert_node( &H, 50);

    display_node( H);

    delete_node( &H, 10);

    display_node( H);

    delete_node( &H, 20);

    display_node( H);

    delete_node( &H, 30);

    display_node( H);

    delete_node( &H, 50);

    display_node( H);
    return 0;
}

/*
    insert_node( NODE **, int)
    insert a key on the back of the linked list.
*/
void insert_node( NODE **n, int key)
{
    NODE *new_node  = (NODE *)malloc(sizeof(NODE));
    NODE *temp      = *n;
    
    new_node->next  = NULL;
    new_node->prev  = NULL;
    new_node->key   = key;

    printf("INSERT [%d]\n", key);

    // there is not any node.
    if( temp == NULL)
    {
        *n  = new_node;

        return;
    }

    // find the last node in the linked list.
    while( temp->next != NULL)
    {
        temp    = temp->next;
    }

    temp->next      = new_node;
    new_node->prev  = temp;
}

/* 
    delete_node( NODE **, int)
    delete the key that you want from the linked list.
    if the key is removed, this function will return 0.
    if it is not, this function will return -1.
*/
int delete_node( NODE **n, int key)
{
    NODE *temp  = *n;
    NODE *f     = NULL;

    printf("DELETE [%d]\n", key);

    // if the key that you want to remove is located firstly.
    if( (*n)->key == key)
    {
        if( (*n)->next != NULL)
        {
            *n  = (*n)->next;
    
            (*n)->prev  = NULL;
        }
        else
        {
            *n  = NULL;
        }

        free(temp);

        return 0;
    }

    while( temp->next != NULL)
    {
        // if find the key that you want to remove
        if( (temp->next)->key == key)
        {
            f   = temp->next;

            temp->next          = (temp->next)->next;
            (temp->next)->prev  = temp;

            free(f);

            return 0;
        }

        temp    = temp->next;
    }

    printf("Can't find the key!\n");

    return -1;
}

/*
    display_node( NODE *)
    display all node in the linked list.
*/
void display_node( NODE *n)
{
    NODE *temp  = n;
    NODE *p     = NULL;

    printf("HEAD > ");

    // print all nodes from the left to the right.
    while( temp != NULL)
    {
        printf("%3d", temp->key);

        p       = temp;
        temp    = temp->next;
    }

    printf(" || ");

    // print all nodes from the right to the left.
    while( p != NULL)
    {
        printf("%3d", p->key);

        p       = p->prev;
    }

    printf(" END.\n");
}