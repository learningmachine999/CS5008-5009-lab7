#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Breadth-first traversal
void breadthFirstTraversal(struct Node* root) {
    if (root == NULL)
        return;

    struct Node* queue[100]; // Assuming a maximum of 100 nodes
    int front = 0;
    int rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        struct Node* node = queue[front++];
        printf("%d ", node->data);

        if (node->left != NULL)
            queue[rear++] = node->left;

        if (node->right != NULL)
            queue[rear++] = node->right;
    }

    printf("\n");
}

int main() {
    // Create the binary tree
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->left->left->left = createNode(8);
    root->left->left->right = createNode(9);
    root->left->right->left = createNode(10);
    root->left->right->right = createNode(11);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    root->right->left->left = createNode(12);
    root->right->left->right = createNode(13);
    root->right->right->left = createNode(14);
    root->right->right->right = createNode(15);

    breadthFirstTraversal(root);

    free(root);

    return 0;
}
