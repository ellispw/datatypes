#include "../src/types.h"

#include <stdio.h>

int main(void) {
	struct dt_list_int *list = dt_create_list_int();
	dt_list_add_int(list, 10);
	dt_list_add_int(list, 20);
	dt_list_add_int(list, 30);
	dt_list_add_int(list, 40);

	struct dt_list_node_int *temp = list->head;
	while (temp) {	
		printf("%d\n", temp->data);
		temp = temp->next;
	}

	dt_destroy_list_int(list);
}
