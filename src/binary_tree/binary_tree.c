#include "../../headers/_data_structures.h"

/* TODO MANAGE PRINTING TYPED OBJECTS */

void binary_tree_inorder_search(binary_tree_node *node) {
    /* Left node first
        Visit node
        Right node last */
    if(node->left) {
        printf("OK\n");
        binary_tree_inorder_search(node->left);
        printf("PK\n");
    }
    printf("%d ", node->item);
    if(node->right) binary_tree_inorder_search(node->right);
}

void binary_tree_preorder_search(binary_tree_node *node) {
    /* Visit node first
        Left node
        Right node last */
    printf("%d ", node->item);
    if(node->left) binary_tree_preorder_search(node->left);
    if(node->right) binary_tree_preorder_search(node->right);
}

void binary_tree_postorder_search(binary_tree_node *node) {
    /* Left node first
        Right node
        Visit node last */
    if(node->left) binary_tree_postorder_search(node->left);
    if(node->right) binary_tree_postorder_search(node->right);
    printf("%d ", node->item);
}

/**
 * @func: binary_tree_insert
 * @desc: A recusive function for finding the right place to add a new node
 * @param root -> The address of the root node pointer
 * @param child -> The newly created node to add
 **/
static void binary_tree_insert(binary_tree_node **root, binary_tree_node *child) {
    /* In case root does not exist yet */
	if(!*root) *root = child;
    else {
        /* In case the unique element exists already */
        if(child->item == (*root)->item)
            return;
        /* Recursively search for the right spot in the tree */
        if(child->item <= (*root)->item) {
            binary_tree_insert(&(*root)->left, child);
            printf("TRAVERSING THE LEFT\n");
        }
        else
            binary_tree_insert(&(*root)->right, child);
    }
}

binary_tree *binary_tree_create(void) {
    /* Create a new tree and set the base elements */
    binary_tree *tree = malloc(sizeof(binary_tree));
    tree->head = NULL;
    tree->length = 0;

    /* Return the tree */
    return tree;
}

binary_tree_node *binary_tree_search(binary_treeT *obj, int item) {
    /* Typecast the value to a binary_tree so that it can be manipulated */
    binary_tree *tree = (binary_tree*)object_get_value(obj);

    /* In case of empty inputs */
    if(tree == NULL || item == NULL) return;

    /* Recursively search for the correct node */
    if(tree->head != NULL) {
        /* Return once we have found the correct node */
        if(tree->head->item == item) return tree->head;
        else {
            if(item > tree->head->item)
                binary_tree_search(tree->head->right, item);
            else
                binary_tree_search(tree->head->left, item);
        }
    }
}

void binary_tree_add(binary_treeT *obj, int item) {
    /* Typecast the value to a binary_tree so that it can be manipulated */
    binary_tree *tree = (binary_tree*)object_get_value(obj);

    /* In case of empty inputs */
    if(tree == NULL || item == NULL) return;

    /* Create a new node */
    /* Allocate size for the node as well as its contents */
    binary_tree_node *newnode = malloc(sizeof(binary_tree_node));
    newnode->item = malloc(sizeof(item));

    /* Set the value in the new node */
    newnode->item = item;

    /* Set the left and right children */
    newnode->left = NULL;
    newnode->right = NULL;

    /* Call a recursive insert */
    /* TODO FIX TO BE TAIL RECURSIVE */
    binary_tree_insert(&(tree->head), newnode);

    /* Insert the size of the binary tree */
    tree->length++;
}

void binary_tree_set(binary_treeT *obj, void *original, void *new_item) {
    /* Typecast the value to a binary_tree so that it can be manipulated */
    binary_tree *tree = (binary_tree*)object_get_value(obj);

    /* In case of empty inputs */
    if(tree == NULL || original == NULL || new_item == NULL) return;

    /* Search and retreive the node to be changed */
    binary_tree_node *to_change = binary_tree_search(tree, original);

    /* Change the value */
    to_change->item = new_item;
}

void binary_tree_delete(binary_treeT *obj, int item) {
    /* Typecast the value to a binary_tree so that it can be manipulated */
    binary_tree *tree = (binary_tree*)object_get_value(obj);

    /* In case of empty inputs */
    if(tree == NULL || item == NULL) return;

    /* Search and retreive the node to delete */
    binary_tree_node *to_delete = binary_tree_search(tree, item);

    /* TODO ALGORITHM FOR DELETE */
}

size_t binary_tree_length(binary_treeT *obj) {
    /* Typecast the value to a binary_tree so that it can be manipulated */
    binary_tree *tree = (binary_tree*)object_get_value(obj);

    /* In case of empty inputs */
    if(tree == NULL) return;

    /* Return the length */
    return tree->length;
}

void binary_tree_free(binary_treeT *obj) {
    /* Typecast the value to a binary_tree so that it can be manipulated */
    binary_tree *tree = (binary_tree*)object_get_value(obj);

    /* In case of empty inputs */
    if(tree == NULL) return;

    /* Free the tree and its pointers */
    free(tree->head);
    free(tree);
}
