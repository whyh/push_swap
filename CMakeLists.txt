cmake_minimum_required(VERSION 3.13)

project(push_swap)

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS "-Wall -Wextra -Werror")

AUX_SOURCE_DIRECTORY(libft LIBFT)
AUX_SOURCE_DIRECTORY(libft/ft_printf FT_PRINTF)
AUX_SOURCE_DIRECTORY(libft/ft_gnl FT_GNL)
AUX_SOURCE_DIRECTORY(libft/vis VIS)

add_executable(push_swap_clion
        ${LIBFT}
        ${FT_GNL}
        ${FT_PRINTF}
        ${VIS}
        fpush_swap/checker.c
#       fpush_swap/push_swap.c
        fpush_swap/shared_funs.c
        fpush_swap/push_swap_operations.c
        fpush_swap/push_swap_utils.c
        fpush_swap/operations.c
        fpush_swap/vis.c
        fpush_swap/vis_draw_bg.c
        fpush_swap/vis_draw_stack.c
        fpush_swap/vis_utils.c
        fpush_swap/shared_parse.c)

target_link_libraries(push_swap_clion "-framework OpenGL" "-framework AppKit" "-lmlx")