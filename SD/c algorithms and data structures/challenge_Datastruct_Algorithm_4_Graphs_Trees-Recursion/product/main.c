#include "Tree.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

//TODO make and move to parse.h
int ParseNumTests(int* t);
int ParseInputData(int* n, int* m);
int ParseTreeData(Tree* tree, int m);
void PrintTree(Tree* tree);

#define dbPrint 0
#define dbPrintTree 1

int sig = 0;

void handleSigInt(int inSig) {
    sig = inSig;
    printf("caught sigint\n");
}

int main(int argc, char* argv[]) {
    if(signal(SIGINT, handleSigInt) == SIG_ERR ||
        signal(SIGTERM, handleSigInt) == SIG_ERR
        ) {
        printf("failed setting up signals\n");
        return -1;
    }

    if (argc != 2) {
        printf("Please provide argument to select assignment.\n");
        return -1;
    }

    char selectedAssignment = atoi(argv[1]);

    int tTests = 0; // amount of cases
    int nFindNum = 0; // max value(?)
    int mNumDataLines = 0; // lines of x,y points

    if (ParseNumTests(&tTests) == -1) {
        printf("faild to parse t");
        return -1;
    }

    #if dbPrint
    printf("nTests: %d\n", tTests);
    #endif

    for (int i = 0; i < tTests && !sig; i++) {
        if (ParseInputData(&nFindNum, &mNumDataLines) == -1) {
            printf("failed to parse input\n");
            return -1;
        }

        #if dbPrint
        printf("%d data lines, %s: %d\n", mNumDataLines, "\U0001F50D", nFindNum);
        #endif

        Tree tree = CreateTree();

        if (ParseTreeData(&tree, mNumDataLines) == -1) {
            return -1;
        }

        #if dbPrint || dbPrintTree
        PrintTree(&tree);
        #endif

        if (!sig) {
        if (selectedAssignment == 3) {
            int shortestPath = 0;
            FindShortestPathInGraphTree(&tree, &shortestPath, nFindNum);

            printf("%d\n", shortestPath);
        }
        else if (selectedAssignment == 4) {
            int difference = -1;
            // recursive thing...

            printf("%d\n", difference);
            }
        }

        ChopDownTree(&tree);
    }

    return 0;
}

int ParseNumTests(int* t) {
    if (t == NULL) {
        return -1;
    }

    if (scanf("%d", t) < 1) {
        printf("failed to parse T\n");
        return -1;
    }

    return 0;
}

int ParseInputData(int* n, int* m) {
    if (n == NULL || m == NULL) {
        printf("NUll passed to ParseTreeData\n");
        return -1;
    }

    if (scanf("%d %d", n, m) < 1) {
        printf("failed to parse nm\n");
        return -1;
    }

    return 0;
}

int ParseTreeData(Tree* tree, int m) {
    if (tree == NULL) {
        printf("NUll passed to ParseTreeData\n");
        return -1;
    }

    for (int i = 0; i < m && !sig; i++) {
        int x = 0;
        int y = 0;

        if (scanf("%d %d", &x, &y) < 1) {
            printf("failed to parse xy\n");
            return -1;
        }

        if (tree->root.head == NULL) {
            if (TreeAddNode(&tree->root, x) == -1) {
                return -1;
            }
        }

        TreeNode* nodeX = FindNodeWithValue(&tree->root, x, NULL);
        TreeNode* nodeY = FindNodeWithValue(&tree->root, y, NULL);

        if (nodeX == NULL) {
            TreeAddNode(&tree->root, x);
            nodeX = FindNodeWithValue(&tree->root, x, NULL);
        }

        if (nodeY == NULL) {
            TreeNode* newNode = CreateNode(y, nodeX);
            TreeAddChildNode(nodeX, newNode);
        }
        else {
            TreeAddChildNode(nodeY, nodeX);
            TreeAddChildNode(nodeX, nodeY);
        }
    }

    return 0;
}

void printLeaf(TreeNode* leaf, int indent) {
    if (leaf == NULL) {
        return;
    }

    for (int i = 0; i < indent; i++) {
        printf("\t");
    }
    
    printf("{% 3d (% 2d)}\n", leaf->data, leaf->branches.size);
}

void printBranch(TreeNode* node, int indent) {
    if (node == NULL) {
        return;
    }

    printLeaf(node, indent);

    if (node->branches.size > 0) {
        TreeNode* branch = node->branches.head;
        int count = node->branches.size;

        while (branch != NULL && count != 0) {
            count--;
            if (branch->parrent == node) {
                printBranch(branch, indent + 1);
            }
            else {
                printLeaf(branch, indent + 1); //TODO fix indent
            }

            branch = branch->next;
        }
    }
}

void PrintTree(Tree* tree) {
    if (tree == NULL) {
        return;
    }

    printBranch(tree->root.head, 0);
}
