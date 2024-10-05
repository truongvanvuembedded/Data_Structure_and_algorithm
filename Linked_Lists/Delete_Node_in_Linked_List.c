#include"stdio.h"
#include"stdlib.h"

// Create struct for single linked list
typedef struct st_single_node
{
    int u4_data;
    struct st_single_node* st_next_node; 
}st_single_node;

// Create funtion to through and print list
void through_and_print(st_single_node* head)
{
    if (head != NULL)
    {
        printf("\nBefore deletion\n");
        st_single_node* temp = head;
        while (temp->st_next_node != NULL)
        {
            printf("%d -> ",temp->u4_data);
            temp = temp->st_next_node;
        }
        printf("NULL");
    }
    else{
        printf("\nYou chose null node");
    }   
}
// Create funtion to delete list

// Create funtion to create new node
st_single_node* create_new_node(int data)
{
    st_single_node* st_new_node = (st_single_node*)malloc(sizeof(st_single_node));
    st_new_node->u4_data = data;
    st_new_node->st_next_node = NULL;
    return st_new_node;
}

int main(){

    // Create new node
    st_single_node* node_1 = create_new_node(1);
    st_single_node* node_2 = create_new_node(5);
    st_single_node* node_3 = create_new_node(7);
    st_single_node* node_4 = create_new_node(13);
    st_single_node* node_5 = create_new_node(9);
    st_single_node* node_6 = create_new_node(6);

    // Link nodes each other
    node_1->st_next_node = node_2;
    node_2->st_next_node = node_3;
    node_3->st_next_node = node_4;
    node_4->st_next_node = node_5;
    node_5->st_next_node = node_6;

    // Print before deltee
    through_and_print(node_1);

    return 0;
}