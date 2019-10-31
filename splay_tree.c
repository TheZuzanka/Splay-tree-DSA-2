// Created by Susanka on 30/10/2019.

#include "header.h"

ELEMENT *insert(ELEMENT *root, int k) {
    // Simple Case: If tree is empty
    if (root == NULL) return create_element(k);

    // Bring the closest leaf node to root
    root = search_element(k, root);

    // If value is already present, then return
    if (root->value == k) return root;

    // Otherwise allocate memory for new node
    ELEMENT *newnode = create_element(k);

    // If root's value is greater, make root as bigger child
    // of newnode and copy the smaller child of root to newnode
    if (root->value > k) {
        newnode->bigger = root;
        newnode->smaller = root->smaller;
        root->smaller = NULL;
    }

        // If root's value is smaller, make root as smaller child
        // of newnode and copy the bigger child of root to newnode
    else {
        newnode->smaller = root;
        newnode->bigger = root->bigger;
        root->bigger = NULL;
    }

    return newnode; // newnode becomes new root
}


ELEMENT *search_element(int value, ELEMENT *tree) {
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

            tree->bigger->bigger = search_element(value, tree->bigger->bigger);
            // rekurzivne dostanem navrch bigger->bigger

            tree = left_rotation(tree);

        } else if (value >= tree->bigger->value) {
            //bigger smaller situacia -> rotacia doprava

            tree->bigger->smaller = search_element(value, tree->bigger->smaller);
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
        tree_value = tree->smaller->value;

        if (is_tree_null(tree->smaller)) {
            return tree;
        }

        if (tree_value > value) {
            //smaller smaller situacia -> rotacia doprava

            tree->smaller->smaller = search_element(value, tree->smaller->smaller);
            // rekurzivne dostanem navrch smaller->smaller
            tree = right_rotation(tree);

        } else if (tree_value < value) // Zig-Zag (Left Right)
        {
            // rekurzivne dostanem navrch smaller->bigger
            tree->smaller->bigger = search_element(value, tree->smaller->bigger);
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