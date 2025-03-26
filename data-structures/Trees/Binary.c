#include <stdio.h>
#include <stdlib.h>

// 트리 노드 구조체 정의
typedef struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// 노드 생성 함수
TreeNode* createNode(int value) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    if (node == NULL) {
        printf("메모리 할당 실패\n");
        exit(1);
    }
    node->value = value;
    node->left = node->right = NULL;
    return node;
}

// BST 삽입 함수
TreeNode* bstInsert(TreeNode* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->value) {
        root->left = bstInsert(root->left, value);
    }
    else {
        root->right = bstInsert(root->right, value);
    }
    return root;
}

// BST 탐색 함수
TreeNode* bstSearch(TreeNode* root, int value) {
    if (root == NULL || root->value == value) {
        return root;
    }
    if (value < root->value)
        return bstSearch(root->left, value);
    else
        return bstSearch(root->right, value);
}

// 전위 순회 (Root, Left, Right)
void preorder(TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->value);
        preorder(root->left);
        preorder(root->right);
    }
}

int main() {
    TreeNode* root = NULL;
    int values[] = { 50, 30, 70, 20, 40, 60, 80 };
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++) {
        root = bstInsert(root, values[i]);
    }

    printf("전위 순회: ");
    preorder(root);
    printf("\n");

    int target = 40;
    if (bstSearch(root, target))
        printf("BST에서 %d를 찾았습니다.\n", target);
    else
        printf("BST에서 %d를 찾지 못했습니다.\n", target);

    // 메모리 해제는 재귀적으로 모든 노드를 free하는 별도의 함수가 필요합니다.

    return 0;
}