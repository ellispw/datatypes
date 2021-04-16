#include "queue.h"

#define DT_QUEUE_DEFINE_CREATE_IMPL(type) \
struct dt_queue_##type *dt_create_queue_##type() { \
	struct dt_queue_##type *res = malloc(sizeof *res); \
	res->data = malloc(sizeof *res->data); \
	res->queue_size = 0; \
	return res; \
}

#define DT_QUEUE_DEFINE_DESTROY_IMPL(type) \
void dt_destroy_queue_##type(struct dt_queue_##type *q) { \
	free(q->data); \
	free(q); \
}

#define DT_QUEUE_DEFINE_ENQUEUE_IMPL(type) \
size_t dt_queue_enqueue_##type(struct dt_queue_##type *q, type v) { \
	q->queue_size = q->queue_size + 1; \
	q->data = realloc(q->data, sizeof *q->data * q->queue_size); \
	q->data[q->queue_size - 1] = v; \
	return q->queue_size; \
 }

#define DT_QUEUE_DEFINE_DEQUEUE_IMPL(type) \
type dt_queue_dequeue_##type(struct dt_queue_##type *q) { \
	type res = q->data[0]; \
	q->queue_size = q->queue_size - 1; \
	if (q->queue_size < 1) { \
		q->data = realloc(q->data, sizeof *q->data); \
		memset(q->data, 0, sizeof *q->data); \
		return res; \
	} \
\
	type *new = malloc(sizeof *q->data * q->queue_size); \
	memcpy(new, &q->data[1], sizeof *q->data * q->queue_size); \
	q->data = realloc(q->data, sizeof *q->data * q->queue_size); \
	memcpy(q->data, new, sizeof *q->data * q->queue_size); \
	free(new); \
	return res; \
}

#define DT_QUEUE_DEFINE_FRONT_IMPL(type) \
type dt_queue_front_##type(struct dt_queue_##type *q) { \
	return q->data[0]; \
}

#define DT_QUEUE_DEFINE_BACK_IMPL(type) \
type dt_queue_back_##type(struct dt_queue_##type *q) { \
	return q->data[q->queue_size - 1]; \
}

DT_QUEUE_DEFINE_CREATE_IMPL(int)
DT_QUEUE_DEFINE_CREATE_IMPL(float)
DT_QUEUE_DEFINE_CREATE_IMPL(double)

DT_QUEUE_DEFINE_DESTROY_IMPL(int)
DT_QUEUE_DEFINE_DESTROY_IMPL(float)
DT_QUEUE_DEFINE_DESTROY_IMPL(double)

DT_QUEUE_DEFINE_ENQUEUE_IMPL(int)
DT_QUEUE_DEFINE_ENQUEUE_IMPL(float)
DT_QUEUE_DEFINE_ENQUEUE_IMPL(double)

DT_QUEUE_DEFINE_DEQUEUE_IMPL(int)
DT_QUEUE_DEFINE_DEQUEUE_IMPL(float)
DT_QUEUE_DEFINE_DEQUEUE_IMPL(double)

DT_QUEUE_DEFINE_FRONT_IMPL(int)
DT_QUEUE_DEFINE_FRONT_IMPL(float)
DT_QUEUE_DEFINE_FRONT_IMPL(double)

DT_QUEUE_DEFINE_BACK_IMPL(int)
DT_QUEUE_DEFINE_BACK_IMPL(float)
DT_QUEUE_DEFINE_BACK_IMPL(double)
