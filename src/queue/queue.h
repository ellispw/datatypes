#ifndef DT_QUEUE_H
#define DT_QUEUE_H

#include <stdlib.h>
#include <string.h>

#define DT_QUEUE_DEFINE_QUEUE(type) \
struct dt_queue_##type { \
	type *data; \
	size_t queue_size; \
};

DT_QUEUE_DEFINE_QUEUE(int)
DT_QUEUE_DEFINE_QUEUE(float)
DT_QUEUE_DEFINE_QUEUE(double)

#define DT_QUEUE_DEFINE_CREATE(type) \
extern struct dt_queue_##type *dt_create_queue_##type();

#define DT_QUEUE_DEFINE_DESTROY(type) \
extern void dt_destroy_queue_##type(struct dt_queue_##type *q);

#define DT_QUEUE_DEFINE_ENQUEUE(type) \
extern size_t dt_queue_enqueue_##type(struct dt_queue_##type *q, type v);

#define DT_QUEUE_DEFINE_DEQUEUE(type) \
extern type dt_queue_dequeue_##type(struct dt_queue_##type *q);

#define DT_QUEUE_DEFINE_FRONT(type) \
extern type dt_queue_front_##type(struct dt_queue_##type *q);

#define DT_QUEUE_DEFINE_BACK(type) \
extern type dt_queue_back_##type(struct dt_queue_##type *q);

DT_QUEUE_DEFINE_CREATE(int)
DT_QUEUE_DEFINE_CREATE(float)
DT_QUEUE_DEFINE_CREATE(double)

DT_QUEUE_DEFINE_DESTROY(int)
DT_QUEUE_DEFINE_DESTROY(float)
DT_QUEUE_DEFINE_DESTROY(double)

DT_QUEUE_DEFINE_ENQUEUE(int)
DT_QUEUE_DEFINE_ENQUEUE(float)
DT_QUEUE_DEFINE_ENQUEUE(double)

DT_QUEUE_DEFINE_DEQUEUE(int)
DT_QUEUE_DEFINE_DEQUEUE(float)
DT_QUEUE_DEFINE_DEQUEUE(double)

DT_QUEUE_DEFINE_FRONT(int)
DT_QUEUE_DEFINE_FRONT(float)
DT_QUEUE_DEFINE_FRONT(double)

DT_QUEUE_DEFINE_BACK(int)
DT_QUEUE_DEFINE_BACK(float)
DT_QUEUE_DEFINE_BACK(double)


#endif //DT_QUEUE_H
