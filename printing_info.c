// Created by Susanka on 29/10/2019.

#include "header.h"

#define COUNT 10

void print2DUtil(ELEMENT *root, int space) {
    if (root == NULL)
        return;

    space += COUNT;

    print2DUtil(root->bigger, space);

    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->value);

    print2DUtil(root->smaller, space);
}

void print2D(ELEMENT *root) {
    print2DUtil(root, 0);
}

void print_in_order(ELEMENT *element) {
    if (element != NULL){
        print_in_order(element->smaller);
        printf("%d ", element->value);
        print_in_order(element->bigger);
    }
}

void is_in_tree(ELEMENT *tree, int value){
    if(search_value(tree, value) != NULL){
        printf("Cislo %d sa nachadza v strome\n", value);
    }
    else{
        printf("Cislo %d sa nenachadza v strome\n", value);
    }
}