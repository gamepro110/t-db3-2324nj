#include "Tree.h"

#include <stdlib.h>
#include <stdbool.h>

#if 1 // linkedList

/* function: ListAddTail
 * pre: -
 * post: an element is added to the end of the linked list
 * returns: 0 on success, -1 on fail
 */
int ListAddTail(LinkedList* list, int data) {
    if (list == NULL) {
        return -1;
    }

    list->size++;
    TreeNode* node = calloc(1, sizeof(TreeNode));
    node->data = data;
    node->parrent = NULL;
    node->next = NULL;
    node->branches.head = NULL;
    node->branches.size = 0;

    if(list->head == NULL) {
        list->head = node;
        return 0;
    }

    TreeNode* curNode = list->head;

    while (curNode != NULL) {
        if (curNode->next == NULL) {
            break;
        }

        curNode = curNode->next;
    }

    curNode->next = node;
    node->parrent = curNode;
    return 0;
}

int ListAddNodeTail(LinkedList* list, TreeNode* node) {
    if (list == NULL || node == NULL) {
        return -1;
    }

    TreeNode* head = list->head;

    if (head == NULL) {
        list->head = node;
    }
    else {
        while (head->next != NULL) {
            head = head->next;
        }

        head->next = node;
    }

    list->size++;

    return 0;
}

/* function: ListAddAfter
 * pre: -
 * post: a new element with given data is added after element
 *       in the linked list. If element is NULL, the new element
 *       is added to the front of the list.
 * returns: 0 on success, -1 on fail
 */
int ListAddAfter(LinkedList* list, int data, TreeNode* element) {
    if (list == NULL) {
        return -1;
    }

    TreeNode* new = calloc(1, sizeof(TreeNode));
    new->data = data;
    new->next = element;
    new->branches.head = NULL;
    new->branches.size = 0;

    if (element != NULL) {
        TreeNode* next = element->next;
        new->next = next;
        element->next = new;
    }
    else {
        new->next = list->head;
        list->head = new;
    }

    list->size++;

    return 0;
}

/* function: ListGetHead
 * pre: -
 * post: first element in linked list is returned
 * returns: first element on success, NULL if list is empty
 */
TreeNode* ListGetHead(LinkedList* list) {
    if (list == NULL) {
        return NULL;
    }

    return list->head;
}

/* function: ListRemoveTail
 * pre: -
 * post: last element is removed from list
 * returns: 0 on success, -1 on fail
 */
int ListRemoveTail(LinkedList* list) {
    if (list == NULL) {
        return -1;
    }

    TreeNode* current = list->head;
    TreeNode* last = NULL;

    if (current == NULL) {
        return -1;
    }

    while (current->next != NULL) { 
        last = current;
        current = current->next;
    }

    free(current); 

    if (last != NULL) {
        last->next = NULL; 
    }
    else {
        // could not assign last, means list is empty
        list->head = NULL;
    }

    list->size--;
    return 0;
}

/* function: ListRemove
 * pre: -
 * post: element is removed from list, pointer from callee is made NULL
 * returns: 0 on success, -1 on fail
 */
int ListRemove(LinkedList* list, TreeNode** element) {
    if (list == NULL || element == NULL) {
        return -1;
    }

    TreeNode** prev = &list->head;

    // if head != element
    if ((*prev)->data != (*element)->data) {
        while ((*prev)->next != (*element) && (*prev)->next != NULL) {
            (*prev) = (*prev)->next;
        }

        (*prev)->next = (*element)->next;
    }
    else {
        // if head == element
        list->head = (*element)->next;
    }

    free(*element);
    (*element) = NULL;

    list->size--;
    return 0;
}

/* function: ListRemoveAll
 * pre: -
 * post: all existing elements from list are removed
 */
void ListRemoveAll(LinkedList* list) {
    if (list == NULL) {
        //failed to empty list, provided NULL
        return;
    }

    TreeNode* elem = list->head;
    TreeNode* next = elem;

    while (next != NULL) {
        next = elem->next;
        free(elem);
        elem = next;
    }

    list->size = 0;
    list->head = NULL;
}

#endif

TreeNode* CreateNode(int data, TreeNode* parent) {
    if (data < 1) {
        return NULL;
    }

    TreeNode* new = calloc(1, sizeof(TreeNode));
    new->data = data;
    new->next = NULL;
    new->branches.head = NULL;
    new->branches.size = 0;
    new->parrent = parent;

    return new;
}

int TreeAddNode(LinkedList *root, int data)
{
    if (root == NULL || data < 1) {
        return -1;
    }

    return ListAddTail(root, data);
}

int TreeAddNodeAfter(TreeNode* root, int data, TreeNode* after) {
    return ListAddAfter(&root->branches, data, after);
}

int TreeAddChildNode(TreeNode* root, TreeNode* child) {
    return ListAddNodeTail(&root->branches, child);
}

void ChopDownBranch(TreeNode* node) {
    if (node == NULL) {
        return;
    }

    TreeNode* branch = node->branches.head;
    TreeNode* freeNode = NULL;

    while (branch != NULL) {
        if (branch->parrent == node) {
            if (branch->branches.size > 0) {
                ChopDownBranch(branch);
            }
            freeNode = branch;
        }

        branch = branch->next;

        if (freeNode != NULL) {
            free(freeNode);
            freeNode = NULL;
        }
    }
}

void ChopDownTree(Tree *tree) {
    if (tree == NULL) {
        return;
    }

    TreeNode* branch = tree->root.head;
    TreeNode* freeNode = NULL;

    while (branch != NULL) {
        ChopDownBranch(branch);
        freeNode = branch;
        branch = branch->next;

        if (freeNode != NULL) {
            free(freeNode);
            freeNode = NULL;
        }
    }
}

Tree CreateTree() {
    Tree tree;
    tree.root.head = NULL;
    tree.root.size = 0;
    return tree;
}

TreeNode* FindNode(TreeNode* root, int val) {
    if (root == NULL || val < 1) {
        return NULL;
    }

    TreeNode* node = root->branches.head;

    while (node != NULL && node->data != val) {
        node = node->next;
    }

    return node;    
}

TreeNode* FindNodeWithValue(TreeNode* node, int value) {
    if (node == NULL) {
        return NULL;
    }
    
    if (node->data == value) {
        return node;
    }

    TreeNode* child = node->branches.head;
    TreeNode* found = NULL;

    while (child != NULL && found == NULL) {
        found = FindNodeWithValue(node->branches.head, value);
        child = child->next;
    }

    return found;
}

TreeNode* TreeFindNodeWithValue(Tree* tree, int value) {
    if (tree == NULL || value < 1) {
        return NULL;
    }

    return FindNodeWithValue(tree->root.head, value);
}

//TODO figure out where in3_1 test 2 depth 1 comes from.
//TODO fix logic
//!INCOMPLETE
int FindShortestPath(TreeNode* node, int findNum, int depth) {
    if (node == NULL) {
        return -1;
    }

    if (node->data == findNum) {
        return depth;
    }

    TreeNode* loopNode = node->branches.head;
    int smallestFound = 1<<30;

    while (loopNode != NULL) {
        int found = 1<<30;

        if (loopNode->parrent == node) {
            found = FindShortestPath(loopNode, findNum, depth + 1);
        }
        else {
            found = depth + 1;
        }

        if (found < smallestFound) {
            smallestFound = found;
        }

            loopNode = loopNode->next;
        // if (loopNode->parrent == node) {
        // }
    }

    return smallestFound;
}

int FindShortestPathInGraphTree(Tree* tree, int* shortestPath, int findNum) {
    if (tree == NULL || shortestPath == NULL) {
        return -1;
    }

    (*shortestPath) = FindShortestPath(tree->root.head, findNum, 0);
    return (*shortestPath);
}
