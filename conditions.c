// Created by Susanka on 27/10/2019.

#include "header.h"

int is_tree_null(ELEMENT *tree){
    if(tree == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int is_smaller_empty(ELEMENT* root){
    if(root->smaller == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int is_bigger_empty(ELEMENT* root){
    if(root->bigger == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int is_in_smaller_tree(ELEMENT* root, int value){
    if(root->value > value){
        return 1;
    }
    else{
        return 0;
    }
}

int is_in_bigger_tree(ELEMENT* root, int value){
    if(root->value <= value){
        return 1;
    }
    else{
        return 0;
    }
}

int need_rotation(ELEMENT* tree){
    if(is_tree_null(tree)){
        return  0;
    }
    else{
        return 1;
    }
}

ELEMENT* is_presented_in_tree(int value, ELEMENT* tree){
    ELEMENT* element;

    if((element = splay_to_root(value, tree)) == NULL){
        return NULL;
    }
    else{
        return  element;
    }
}