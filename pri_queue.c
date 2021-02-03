#include <stdlib.h>
#include <stdio.h>
#include "pri_queue.h"
/** @file pri_queue.c */
static Node_ptr_t head = NULL;
/**
 * Insert a Node into a priority queue.
 * @param priority
 * @param data
 * @author Daniel Sadig
 */
void PQ_insert(int priority, char * data) {
    
    Node_ptr_t entry = malloc(sizeof(Node_t));
    //Assigning values and data to knew node 
    entry->data = data;
    entry->priority = priority;
    
    Node_ptr_t itr = malloc(sizeof(Node_t));
    Node_ptr_t holder = malloc(sizeof(Node_t));
    
    if(PQ_get_size() == 0){
        //There is not entris This will create the fist node
        head = malloc(sizeof(Node_t));
        head = entry; //Head node is assigned
    }

    
    else{
        holder = malloc(sizeof(Node_t));
        //This iterates through the for loop
        
        for(itr=head; itr!=NULL; itr = itr->next){
            if(itr->priority <= priority){
            //memcpy( , , ) is used to copy a block of data from a
            //source address 
            memcpy(holder, itr, sizeof(Node_t));
            itr->data = data;
            itr->priority = priority;
            itr->next = holder;
            break;
        }
            else if(itr->data == NULL){
                itr->next = malloc(sizeof(Node_t));
                itr->next = entry;
        }
        
    }
  
    }
}
    
    
    // Good luck Charlie 
    //Maybe everything you did is wrong but at least you learned ore about pointers so
    //Always something goof right : )
    
    

/**
 * Delete and return the node with the highest priority.
 * @return The highest priority Node.
 */
Node_ptr_t PQ_delete() {
    Node_ptr_t holder = malloc(sizeof(Node_t));
    if(head != NULL){
        head = head->next;
        //Returns the head of the linked list
        return holder;
    }
    
    else{
        //Head is null so return nothing
        return NULL;
    }
    
}

/**
 * Do NOT modify this function.
 * @return A pointer to the head of the list.  (NULL if list is empty.)
 */
Node_ptr_t PQ_get_head() {
    return head;
}

/**
 * Do NOT modify this function.
 * @return the number of items in the queue
 */
int PQ_get_size() {
    int size = 0;
    Node_ptr_t tmp;
    for(tmp = head; tmp != NULL; tmp = tmp->next, size++)
        ;
    return size;
}


