#include "linkedlist.h"

#define DT_LINKEDLIST_DEFINE_CREATE_IMPL(type) \
struct dt_list_##type *dt_create_list_##type() { \
	struct dt_list_##type *res = malloc(sizeof *res); \
	res->head = NULL; \
	return res; \
} 

#define DT_LINKEDLIST_DEFINE_DESTROY_IMPL(type) \
void dt_destroy_list_##type(struct dt_list_##type *l) { \
	struct dt_list_node_##type **curr = &l->head; \
	while (*curr) { \
		struct dt_list_node_##type *temp = *curr; \
		*curr = (*curr)->next; \
		free(temp); \
	} \
	free(l); \
} 

#define DT_LINKEDLIST_DEFINE_ADD_IMPL(type) \
struct dt_list_node_##type *dt_list_add_##type(struct dt_list_##type *l, type v) { \
	struct dt_list_node_##type *new = malloc(sizeof *new); \
	new->data = v; \
	struct dt_list_node_##type *curr = l->head; \
	if (!curr) { \
		l->head = new; \
		return; \
	} \
	while (curr->next) { /*get tail*/ \
		curr = curr->next; \
	} \
	curr->next = new; \
	return new; \
}

#define DT_LINKEDLIST_DEFINE_REMOVE_IMPL(type) \
void dt_list_remove_##type(struct dt_list_##type *l, struct dt_list_node_##type *n) { \
	if (!l || !n || !l->head) \
		return; \
	struct dt_list_node_##type *curr = l->head; \
	while (curr->next != n) { \
		if (!curr->next) \
			return; \
		curr = curr->next; \
	} \
	curr->next = n->next; \
}

DT_LINKEDLIST_DEFINE_CREATE_IMPL(int)
DT_LINKEDLIST_DEFINE_CREATE_IMPL(float)
DT_LINKEDLIST_DEFINE_CREATE_IMPL(double)

DT_LINKEDLIST_DEFINE_DESTROY_IMPL(int)
DT_LINKEDLIST_DEFINE_DESTROY_IMPL(float)
DT_LINKEDLIST_DEFINE_DESTROY_IMPL(double)

DT_LINKEDLIST_DEFINE_ADD_IMPL(int)
DT_LINKEDLIST_DEFINE_ADD_IMPL(float)
DT_LINKEDLIST_DEFINE_ADD_IMPL(double)

DT_LINKEDLIST_DEFINE_REMOVE_IMPL(int)
DT_LINKEDLIST_DEFINE_REMOVE_IMPL(float)
DT_LINKEDLIST_DEFINE_REMOVE_IMPL(double)
