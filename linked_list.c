#include "linked_list.h"
node* create_link_with_string(char* string)
{
    node* link = malloc(sizeof(node));
    link->string = my_strdup(string);
    link->next = NULL;
    return link;
}

//starts a link with memory allocated to receive a string later on
node* create_link_with_max_string_length(int max_string_length)
{
    node* link = malloc(sizeof(node));
    link->string = malloc(max_string_length * sizeof(char));
    link->next = NULL;
    return link;
}

//adds a node before another node
node* prepend_link(node* new_link, node* head)
{
    new_link->next = head;
    head = new_link;
    return head;
}

//loops to very end of Linked list and adds passed as argument
void append_link(node* new_link, node* head)
{   
    node* current = head;
    while(current->next != NULL)
    {
        current = current->next;
    }
    current->next = new_link;
}

//Insert node in between two nodes
void insert_link(node* new_link, node* previous_link)
{
    new_link->next = previous_link->next;
    previous_link->next = new_link;
}

//How many links are in a given linked list
//Prints string to console
int read_list(node* head)
{  
    int index = 0;
    while (head != NULL)
    {
        index++;
        my_putstr(head->string);
        my_putstr("\n");
        head = head->next;
    }
    return index;
}

void free_linked_list(node* head)
{
    node* temp;
    while (head != NULL)
    {
        temp = head;
        free(temp->string);
        head = head->next;
        free(temp);
    }
}
