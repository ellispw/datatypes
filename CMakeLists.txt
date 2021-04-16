project(datatypes)
cmake_minimum_required(VERSION 3.0)
set(CMAKE_C_STANDARD 90)

add_executable(datatypes 
	example/main.c
	src/types.h
	src/linkedlist/linkedlist.c
	src/linkedlist/linkedlist.h
	src/stack/stack.c
	src/stack/stack.h
	src/queue/queue.c
	src/queue/queue.h
)
