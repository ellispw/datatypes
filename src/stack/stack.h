#ifndef DT_STACK_H
#define DT_STACK_H

#include <stdlib.h>

#define DT_STACK_DEFINE_STACK(type) \
struct dt_stack_##type { \
	type *data; \
	size_t stack_size; \
};

DT_STACK_DEFINE_STACK(int)
DT_STACK_DEFINE_STACK(float)
DT_STACK_DEFINE_STACK(double)

#define DT_STACK_DEFINE_CREATE(type) \
extern struct dt_stack_##type *dt_create_stack_##type();

#define DT_STACK_DEFINE_DESTROY(type) \
extern void dt_destroy_stack##type(struct dt_stack_##type *s);

#define DT_STACK_DEFINE_PUSH(type) \
extern size_t dt_stack_push_##type(struct dt_stack_##type *s, type v);

#define DT_STACK_DEFINE_POP(type) \
extern type dt_stack_pop_##type(struct dt_stack_##type *s);

#define DT_STACK_DEFINE_PEEK(type) \
extern type dt_stack_peek_##type(struct dt_stack_##type *s);

DT_STACK_DEFINE_CREATE(int)
DT_STACK_DEFINE_CREATE(float)
DT_STACK_DEFINE_CREATE(double)

DT_STACK_DEFINE_PUSH(int)
DT_STACK_DEFINE_PUSH(float)
DT_STACK_DEFINE_PUSH(double)

DT_STACK_DEFINE_POP(int)
DT_STACK_DEFINE_POP(float)
DT_STACK_DEFINE_POP(double)

DT_STACK_DEFINE_PEEK(int)
DT_STACK_DEFINE_PEEK(float)
DT_STACK_DEFINE_PEEK(double)

#endif //DT_STACK_H
