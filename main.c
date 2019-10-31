#include "header.h"

int main() {
    ELEMENT* tree = NULL;
    add_value(100, &tree);
    add_value(50, &tree);
    add_value(200, &tree);
    add_value(40, &tree);
    add_value(10, &tree);
    add_value(20, &tree);
    tree = search_element(20, tree);
    print2D(tree);

    return 0;
} 