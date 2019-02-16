cmake_minimum_required(VERSION 3.13)

project(push_swap)

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS "-Wall -Wextra -Werror")

AUX_SOURCE_DIRECTORY(push_swap PUSH_SWAP)
AUX_SOURCE_DIRECTORY(push_swap/operations OPERATIONS)
AUX_SOURCE_DIRECTORY(libft LIBFT)
AUX_SOURCE_DIRECTORY(libft/ft_printf FT_PRINTF)
AUX_SOURCE_DIRECTORY(libft/ft_gnl FT_GNL)

add_executable(push_swap_clion
        ${LIBFT}
        ${FT_GNL}
        ${FT_PRINTF}
        ${PUSH_SWAP}
        ${OPERATIONS})