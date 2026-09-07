#include <stdio.h>

int size;
int tree[]={10, 8, 29, 52, 16, 35, 44};

void inorder(int index) {
    if (index>=size) return;
    inorder(2*index+1);
    printf("%d ", tree[index]);
    inorder(2*index+2);
}

void preorder(int index) {
    if (index>=size) return;
    printf("%d ", tree[index]);
    preorder(2*index+1);
    preorder(2*index+2);
}

void postorder(int index) {
    if (index>=size) return;
    postorder(2*index+1);
    postorder(2*index+2);
    printf("%d ", tree[index]);
}

int main() {
    size=sizeof(tree)/sizeof(tree[0]);
    printf("\nInorder Traversal: ");
    inorder(0);

    printf("\nPreorder Traversal: ");
    preorder(0);

    printf("\nPostorder Traversal: ");
    postorder(0);

    return 0;
}
