#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cstring>
extern "C"{
#include "bst.h"
#include "avl_ntudsa.h"
#include "rb.h"
}

using namespace std;

void postorder_integer_avl(const struct avl_node *node){
	if (node == NULL)
		return;
	printf("%s ", ((char *)node->avl_data));
	if (node->avl_link[0] != NULL || node->avl_link[1] != NULL){
		putchar('(');
		postorder_integer_avl(node->avl_link[0]);
		putchar(',');
		putchar(' ');
		postorder_integer_avl(node->avl_link[1]);
		putchar(')');
	}
}

void postorder_integer_bst(const struct bst_node *node){
	if (node == NULL)
		return;
	printf("%s ", ((char *)node->bst_data));
	if (node->bst_link[0] != NULL || node->bst_link[1] != NULL){
		putchar('(');
		postorder_integer_bst(node->bst_link[0]);
		putchar(',');
		putchar(' ');
		postorder_integer_bst(node->bst_link[1]);
		putchar(')');
	}
}

void postorder_integer_rb(const struct rb_node *node){
	if (node == NULL)
		return;
	printf("%s ", ((char *)node->rb_data));
	if (node->rb_link[0] != NULL || node->rb_link[1] != NULL){
		putchar('(');
		postorder_integer_rb(node->rb_link[0]);
		putchar(',');
		putchar(' ');
		postorder_integer_rb(node->rb_link[1]);
		putchar(')');
	}
}

int int_compare(const void *pa, const void *pb, void *param){
	const char * a = (const char *)pa;
	const char * b = (const char *)pb;

	return strcmp(a, b);

}

int main(){

	char name[32][10] = {
		"Chuang", "Chou", "Chang", "Chao", "Chen", "Cheng", "Chu", "Fu", "Fuh", "Hsiang", "Hsu", "Hsueh",
		"Hung", "Jang", "Kao", "Kuo", "Lai", "Lee", "Liao", "Lin", "Liou", "Liu", "Lu", "Lyuu", "Ouhyoung",
		"Oyang", "Shih", "Tsai", "Tseng", "Wang", "Wu", "Yang"};
	struct avl_table *tree_avl;
	tree_avl = avl_create(int_compare, NULL, NULL);
	struct bst_table *tree_bst;
	tree_bst = bst_create(int_compare, NULL, NULL);
	struct rb_table *tree_rb;
	tree_rb = rb_create(int_compare, NULL, NULL);



	int i;
	for (i = 0; i < 32; i++){
		char * element = name[i];
		void **p1 = avl_probe(tree_avl, element);
		void **p2 = bst_probe(tree_bst, element);
		void **p3 = rb_probe(tree_rb, element);
	}

	cout << "bst:\n\n";
	postorder_integer_bst(tree_bst->bst_root);
	cout << "\n\navl:\n\n";
	postorder_integer_avl(tree_avl->avl_root);
	cout << "\n\nrb:\n\n";
	postorder_integer_rb(tree_rb->rb_root);
	cout << "\n";
	return 0;
}
