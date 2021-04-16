#include "../src/types.h"

#include <stdio.h>

int main(void) {
	struct dt_list_int *list = dt_create_list_int();
	dt_list_add_int(list, 10);
	dt_list_add_int(list, 20);
	struct dt_list_node_int *n = dt_list_add_int(list, 30);
	dt_list_add_int(list, 40);

	dt_list_remove_int(list, n);	

	struct dt_list_node_int *temp = list->head;
	while (temp) {	
		printf("List: %d\n", temp->data);
		temp = temp->next;
	}

	dt_destroy_list_int(list);

	struct dt_stack_int *stack = dt_create_stack_int();	
	dt_stack_push_int(stack, 10);
	dt_stack_push_int(stack, 20);

	printf("Stack: %d\n", dt_stack_peek_int(stack));
	dt_stack_pop_int(stack);
	printf("Stack: %d\n", dt_stack_peek_int(stack));

	dt_destroy_stack_int(stack);

	struct dt_queue_int *queue = dt_create_queue_int();
	dt_queue_enqueue_int(queue, 10);
	dt_queue_enqueue_int(queue, 20);
	
	printf("Queue: %d\n", dt_queue_front_int(queue));
	dt_queue_dequeue_int(queue);
	
	printf("Queue: %d\n", dt_queue_front_int(queue));

	dt_destroy_queue_int(queue);
}
