#ifndef DT_LINKEDLIST_H
#define DT_LINKEDLIST_H

#include <stdlib.h>

#define DT_LINKEDLIST_DEFINE_LIST_NODE(type) \
struct dt_list_node_##type { \
	struct dt_list_node_##type *next; \
	type data; \
}; 

#define DT_LINKEDLIST_DEFINE_LIST(type) \
struct dt_list_##type { \
	struct dt_list_node_##type *head; \
};

DT_LINKEDLIST_DEFINE_LIST_NODE(int)
DT_LINKEDLIST_DEFINE_LIST_NODE(float)
DT_LINKEDLIST_DEFINE_LIST_NODE(double)
DT_LINKEDLIST_DEFINE_LIST(int)
DT_LINKEDLIST_DEFINE_LIST(float)
DT_LINKEDLIST_DEFINE_LIST(double)

#define DT_LINKEDLIST_DEFINE_CREATE(type) \
extern struct dt_list_##type *dt_create_list_##type();

#define DT_LINKEDLIST_DEFINE_DESTROY(type) \
extern void dt_destroy_list_##type(struct dt_list_##type *l);

#define DT_LINKEDLIST_DEFINE_ADD(type) \
extern void dt_list_add_##type(struct dt_list_##type *l, type v);

DT_LINKEDLIST_DEFINE_CREATE(int)
DT_LINKEDLIST_DEFINE_CREATE(float)
DT_LINKEDLIST_DEFINE_CREATE(double)

DT_LINKEDLIST_DEFINE_DESTROY(int)
DT_LINKEDLIST_DEFINE_DESTROY(float)
DT_LINKEDLIST_DEFINE_DESTROY(double)

DT_LINKEDLIST_DEFINE_ADD(int)
DT_LINKEDLIST_DEFINE_ADD(float)
DT_LINKEDLIST_DEFINE_ADD(double)

#endif //DT_LINKEDLIST_H
