#include "header.h"

int main() {
    ELEMENT* tree = NULL;
    /*tree = add_element(8, tree);
    tree = add_element(3, tree);
    tree = add_element(1, tree);
    tree = add_element(6, tree);
    tree = add_element(4, tree);
    tree = add_element(7, tree);
    tree = add_element(10, tree);
    tree = add_element(7, tree);
    tree = add_element(13, tree);
    //print_in_order(tree);*/

    add_value(8, &tree);
    add_value(3, &tree);
    add_value(1, &tree);
    add_value(6, &tree);
    add_value(4, &tree);
    add_value(7, &tree);
    add_value(10, &tree);
    add_value(7, &tree);
    add_value(13, &tree);
    print2D(tree);
    return 0;
} 