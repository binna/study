#include<stdio.h>
#include<stdlib.h>

// ��� ������ ���� ����ü ����
typedef struct NODE {
	int data;
	struct NODE* left;
	struct NODE* right;
}N;

// ��� ����
N* create(N* node, int data) {
	if (node == NULL) {
		node = (N*)malloc(sizeof(N));
		node->data = data;
		node->left = NULL;
		node->right = NULL;
	}
	else {
		if (node->data > data) {
			node->left = create(node->left, data);
		}
		else {
			node->right = create(node->right, data);
		}
	}
	return node;
}

// ������ȸ
void preorder(N* node) {
	if (node != NULL) {
		printf("%d ", node->data);
		preorder(node->left);
		preorder(node->right);
	}
}
// ������ȸ
void inorder(N* node) {
	if (node != NULL) {
		inorder(node->left);
		printf("%d ", node->data);
		inorder(node->right);
	}
}
// ������ȸ
void postorder(N* node) {
	if (node != NULL) {
		postorder(node->left);
		postorder(node->right);
		printf("%d ", node->data);
	}
}

// ��� ����
void del(N* node, int data) {

	// TODO

}

int main() {
	N* root = NULL;

	int act;
	while (1) {
		printf("1.������ 2.������ȸ 3.������ȸ 4.������ȸ 5.������ 6.����\n");
		scanf("%d", &act);
		if (act == 1) {
			int data;
			printf("�������Է�: ");
			scanf("%d", &data);
			root = create(root, data);
		}
		else if (act == 2) {
			preorder(root); // ������ȸ
			printf("\n");
		}
		else if (act == 3) {
			inorder(root); // ������ȸ
			printf("\n");
		}
		else if (act == 4) {
			postorder(root); // ������ȸ
			printf("\n");
		}
		else if (act == 5) {
			int data;
			printf("�����ҵ������Է�: ");
			scanf("%d", &data);
			del(root, data);
		}
		else {
			printf("���α׷�����\n");
			break;
		}
	}

	return 0;
}