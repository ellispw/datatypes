#include "stack.h"

#define DT_STACK_DEFINE_CREATE_IMPL(type) \
struct dt_stack_##type *dt_create_stack_##type() { \
	struct dt_stack_##type *res = malloc(sizeof *res); \
	res->data = malloc(sizeof res->data); \
	res->stack_size = 0; \
	return res; \
}

#define DT_STACK_DEFINE_DESTROY_IMPL(type) \
void dt_destroy_stack_##type(struct dt_stack_##type *s) { \
	free(s->data); \
	free(s); \
}

#define DT_STACK_DEFINE_PUSH_IMPL(type) \
size_t dt_stack_push_##type(struct dt_stack_##type *s, type v) { \
	s->stack_size = s->stack_size + 1; \
	s->data = realloc(s->data, sizeof *s->data * s->stack_size); \
	s->data[s->stack_size - 1] = v; \
	return s->stack_size; \
}

#define DT_STACK_DEFINE_POP_IMPL(type) \
type dt_stack_pop_##type(struct dt_stack_##type *s) { \
	type res = s->data[s->stack_size - 1]; \
	s->stack_size = s->stack_size - 1; \
	s->data = realloc(s->data, sizeof *s->data * s->stack_size); \
	return res; \
}

#define DT_STACK_DEFINE_PEEK_IMPL(type) \
type dt_stack_peek_##type(struct dt_stack_##type *s) { \
	return s->data[s->stack_size - 1]; \
}

DT_STACK_DEFINE_CREATE_IMPL(int)
DT_STACK_DEFINE_CREATE_IMPL(float)
DT_STACK_DEFINE_CREATE_IMPL(double)

DT_STACK_DEFINE_DESTROY_IMPL(int)
DT_STACK_DEFINE_DESTROY_IMPL(float)
DT_STACK_DEFINE_DESTROY_IMPL(double)

DT_STACK_DEFINE_PUSH_IMPL(int)
DT_STACK_DEFINE_PUSH_IMPL(float)
DT_STACK_DEFINE_PUSH_IMPL(double)

DT_STACK_DEFINE_POP_IMPL(int)
DT_STACK_DEFINE_POP_IMPL(float)
DT_STACK_DEFINE_POP_IMPL(double)

DT_STACK_DEFINE_PEEK_IMPL(int)
DT_STACK_DEFINE_PEEK_IMPL(float)
DT_STACK_DEFINE_PEEK_IMPL(double)
