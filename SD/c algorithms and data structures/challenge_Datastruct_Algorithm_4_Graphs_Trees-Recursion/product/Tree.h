#ifndef TREE_NODE_H_
#define TREE_NODE_H_

#include <stdlib.h>
#include <stdio.h>

typedef struct TreeNode TreeNode;
typedef struct Tree Tree;
typedef struct LinkedList LinkedList;

struct LinkedList {
    TreeNode* head;
    int size;
};

struct TreeNode {
    int data;
    LinkedList branches;
    TreeNode* next;
    TreeNode* parrent;
};

struct Tree {
    LinkedList root;
};

//static 
int ListAddTail(LinkedList* list, int data);
//static 
int ListAddNodeTail(LinkedList* list, TreeNode* node);
//static 
int ListAddAfter(LinkedList* list, int data, TreeNode* element);
//static 
TreeNode* ListGetHead(LinkedList* list);
//static 
int ListRemoveTail(LinkedList* list);
//static 
int ListRemove(LinkedList* list, TreeNode** element);
//static 
void ListRemoveAll(LinkedList* list);

TreeNode* CreateNode(int data, TreeNode* parent);
int TreeAddNode(LinkedList* root, int data);
int TreeAddNodeAfter(TreeNode* root, int data, TreeNode* after);
int TreeAddChildNode(TreeNode* root, TreeNode* child);
void ChopDownTree(Tree* root);

Tree CreateTree();

/// @deprecated 
TreeNode* FindNode(TreeNode* root, int val);
TreeNode* FindNodeWithValue(TreeNode* node, int value);
int FindShortestPathInGraphTree(Tree* tree, int* shortestPath, int findNum);

#endif
