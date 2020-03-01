#ifndef __BINARY_TREE_H_
#define __BINARY_TREE_H_

#include "../_data_structures.h"

/**
 * @struct: binary_tree_node
 * @desc: A binary tree structure node
 * @param left -> The left child of the node
 * @param right -> The right child of the node
 * @param item -> The item contained in the node
 **/
typedef struct binary_tree_node {
    struct binary_tree_node *left;
    struct binary_tree_node *right;
    int item;
    /* TODO TRY TO MAKE A GENERIC TREE, ONLY WORKS FOR INTS FTM */
} binary_tree_node;

/**
 * @struct: binary_tree
 * @desc: A binary tree structure
 * @param head -> The head node of the tree
 * @param length -> The number of nodes inserted in the tree
 **/
typedef struct binary_tree {
    struct binary_tree_node *head;
    size_t length;
} binary_tree;

/**
 * @func: binary_tree_create
 * @desc: Allocate new space for a binary tree
 * @return The pointer to the newly created tree
 **/
binary_tree *binary_tree_create(void);

/**
 * @func: binary_tree_search
 * @desc: Search recursively for a node
 * @param obj -> The tree to search
 * @param item -> The item to search for
 * @return The node of the item we found
 **/
binary_tree_node *binary_tree_search(binary_treeT *obj, int item);

/**
 * @func: binary_tree_add
 * @desc: Adds a new node to the tree
 * @param obj -> The tree to add to
 * @param child -> The child node to add to the tree
 **/
void binary_tree_add(binary_treeT *obj, int item);

/**
 * @func: binary_tree_set
 * @desc: Searche and set the value of a node on the tree
 * @param obj -> The tree which value to set
 * @param original -> The original value to change
 * @param new_item -> The new value to set
 **/
void binary_tree_set(binary_treeT *obj, void *original, void *new_item);

/**
 * @func: binary_tree_delete
 * @desc: Search and delete an item from the tree
 * @param obj -> The tree to delete from
 * @param item -> The item to delete
 **/
void binary_tree_delete(binary_treeT *obj, int item);

/**
 * @func: binary_tree_length
 * @desc: Get the total number of values inserted in the tree
 * @param obj -> The tree
 * @return The number of items in the tree
 **/
size_t binary_tree_length(binary_treeT *obj);

/**
 * @func: binary_tree_free
 * @desc: Free the tree object
 * @param obj -> The tree to free
 **/
void binary_tree_free(binary_treeT *obj);

void binary_tree_inorder_search(binary_tree_node *node);
void binary_tree_preorder_search(binary_tree_node *node);
void binary_tree_postorder_search(binary_tree_node *node);

#endif