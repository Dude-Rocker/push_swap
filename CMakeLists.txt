cmake_minimum_required(VERSION 3.9)
project(push_swap)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")

file(GLOB INC_LIB ./libft/includes/*.h)
file(GLOB INC_PROJ ./includes/*.h)
file(GLOB PUSH_SWAP ./srcs_push_swap/*.c)
file(GLOB CHECKER ./srcs_checker/*.c)
file(GLOB SRC ./srcs/*.c)
file(GLOB SRCS_LIB ./libft/srcs/*.c)
set(INC ${INC_LIB} ${INC_PROJ})
set(LIBFT ${SRCS_LIB})

include_directories("./libft/includes" "./includes")
add_executable(checker ${INC} ${LIBFT} ${CHECKER} ${SRC})
add_executable(push_swap ${INC} ${LIBFT} ${PUSH_SWAP} ${SRC})
