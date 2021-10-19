#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "list.h"

int main()
{
    srand(time(NULL));
    struct Location *list = makeLocation("America", 37.0902, 95.7129);
    list = insert_front(list, "Russia", 61.5240, -103.3188);
    list = insert_front(list, "China", 35.8617, -104.1954);
    list = insert_front(list, "Madeupland", (((float)rand() / (float)(RAND_MAX)) * 360) - 180, (((float)rand() / (float)(RAND_MAX)) * 360) - 180);

    print_list(list);

    list = remove_node(list, "China", 35.8617, -104.1954);
    print_list(list);

    list = remove_node(list, list->name, list->latitude, list->longitude);
    print_list(list);


    list = free_list(list);
    print_list(list);
}
