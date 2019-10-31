#include "header.h"

int main() {
    ELEMENT* tree = NULL;
    add_value(8, &tree);
    add_value(3, &tree);
    add_value(1, &tree);
    add_value(6, &tree);
    add_value(4, &tree);
    add_value(7, &tree);
    add_value(10, &tree);
    add_value(7, &tree);
    add_value(13, &tree);
    //print_in_order(tree);
    print2D(tree);

    is_in_tree(tree, 200);
    return 0;
} 