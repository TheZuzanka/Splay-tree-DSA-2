// Created by Susanka on 27/10/2019.
#ifndef DSA_ZADANIE_2_SPLAY_TREE_HEADER_H
#define DSA_ZADANIE_2_SPLAY_TREE_HEADER_H

#endif //DSA_ZADANIE_2_SPLAY_TREE_HEADER_H

#include<stdio.h>
#include<stdlib.h>

typedef struct element {
    int value;
    struct element *smaller;
    struct element *bigger;
} ELEMENT;

//from BVS.c
ELEMENT* create_element(int value);
void add_value(int value, ELEMENT** tree);
ELEMENT *search_value(ELEMENT *tree, int value);
void remove_element(ELEMENT *tree, int value);

//from splay_tree.c
ELEMENT *add_element(int value, ELEMENT *root);
ELEMENT *splay_to_root(int value, ELEMENT *tree);
ELEMENT *left_rotation(ELEMENT *previous_root);
ELEMENT *right_rotation(ELEMENT *previous_root);

//from conditions.c
int is_tree_null(ELEMENT *tree);
int is_smaller_empty(ELEMENT* root);
int is_bigger_empty(ELEMENT* root);
int is_in_smaller_tree(ELEMENT* root, int value);
int is_in_bigger_tree(ELEMENT* root, int value);
int need_rotation(ELEMENT* tree);
ELEMENT* is_presented_in_tree(int value, ELEMENT* tree);

//from printing_info.c
void print2DUtil(ELEMENT *root, int space);
void print2D(ELEMENT *root);
void print_in_order(ELEMENT *element);
void is_in_tree(ELEMENT *tree, int value);