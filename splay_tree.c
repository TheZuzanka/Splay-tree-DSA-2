// Created by Susanka on 30/10/2019.

#include "header.h"

ELEMENT *add_element(int value, ELEMENT *root) {
    ELEMENT* new_element = create_element(value);

    if (is_tree_null(root)){
        return new_element;
    }


    /*if(is_presented_in_tree(value, root)){
        return root;
    }*/

    if(is_in_bigger_tree(root, value)){
        new_element->bigger = root->bigger;
        new_element->smaller = root;
        root->bigger = NULL;
    }

    else if(is_in_smaller_tree(root, value)) {
        new_element->smaller = root->smaller;
        new_element->bigger = root;
        root->smaller = NULL;
    }

    return new_element;
}


ELEMENT *splay_to_root(int value, ELEMENT *tree) {
    int tree_value;

    if (is_tree_null(tree)) {
        return NULL;
    }

    tree_value = tree->value;

    if (value == tree_value) {
        return tree;
    }

    if (value >= tree_value) {
        if (is_tree_null(tree->bigger)) {
            return tree;
        }

        tree_value = tree->bigger->value;

        if (tree_value < value) {
            //bigger bigger situacia -> rotacia dolava

            tree->bigger->bigger = splay_to_root(value, tree->bigger->bigger);
            // rekurzivne dostanem navrch bigger->bigger

            tree = left_rotation(tree);

        } else if (value >= tree->bigger->value) {
            //bigger smaller situacia -> rotacia doprava

            tree->bigger->smaller = splay_to_root(value, tree->bigger->smaller);
            // rekurzivne dostanem navrch bigger->smaller

            //spravim prve otocenie
            if (!is_tree_null(tree->bigger->smaller)) {
                tree->bigger = right_rotation(tree->bigger);
            }
        }
        //Potrebujem dalsie otocenie? Som aktualne root?
        if (need_rotation(tree->bigger)) {
            return left_rotation(tree);
        } else {
            return tree;
        }


    } else {
        if (is_tree_null(tree->smaller)) {
            return tree;
        }

        tree_value = tree->smaller->value;

        if (tree_value > value) {
            //smaller smaller situacia -> rotacia doprava

            tree->smaller->smaller = splay_to_root(value, tree->smaller->smaller);
            // rekurzivne dostanem navrch smaller->smaller

        } else if (tree_value < value) {
            //smaller bigger situacia -> rotacia doprava

            // rekurzivne dostanem navrch smaller->bigger
            tree->smaller->bigger = splay_to_root(value, tree->smaller->bigger);
            tree = right_rotation(tree);

            //spravim prve otocenie
            if (!is_tree_null(tree->smaller->bigger)) {
                tree->smaller = left_rotation(tree->smaller);
            }
        }

        //Potrebujem dalsie otocenie? Som aktualne root?
        if (need_rotation(tree->smaller)) {
            return right_rotation(tree);
        } else {
            return tree;
        }
    }
}

ELEMENT* search_element(int value, ELEMENT* tree){
    ELEMENT* element;

    if((element = is_presented_in_tree(value, tree)) == NULL){

        printf("Hodnota sa v strome nenachadza\n");
        return NULL;
    }
    else{
        printf("Hodnota sa v strome nachadza\n");
        return element;
    }
}

ELEMENT *left_rotation(ELEMENT *previous_root) {
    //hore pojde prvok nalavo
    ELEMENT *new_root = previous_root->bigger;

    previous_root->bigger = new_root->smaller;
    new_root->smaller = previous_root;
    return new_root;
}

ELEMENT *right_rotation(ELEMENT *previous_root) {
    //hore pojde prvok napravo
    ELEMENT *new_root = previous_root->smaller;

    previous_root->smaller = new_root->bigger;
    new_root->bigger = previous_root;

    return new_root;
}