# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/21 20:30:28 by dderevyn          #+#    #+#              #
#    Updated: 2019/02/17 21:24:27 by dderevyn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME1 = checker

OBJS_DIR = .$(patsubst %.a,%,$(NAME))_objects
CC = clang
CFLAGS = -Wall -Wextra -Werror
RM = /bin/rm -rf
CP = cp -rf
ARG = 2 1 3 6 8 5

LIBFT_PATH = libft/
LIBFT = libft.a

PUSH_SWAP_PATH = fpush_swap/
PUSH_SWAP_INCS = 		push_swap.h\
                        push_swap_typedefs.h
PUSH_SWAP_SRCS =		push_swap.c\
						operations.c\
						shared_funs.c\
						push_swap_operations.c\
						push_swap_utils.c
PUSH_SWAP_OBJS_DIR = $(OBJS_DIR)
PUSH_SWAP_OBJS = $(PUSH_SWAP_SRCS:%.c=$(PUSH_SWAP_OBJS_DIR)/%.o)

CHECKER_PATH = fpush_swap/
CHECKER_INCS = 		push_swap.h\
					push_swap_typedefs.h
CHECKER_SRCS =		checker.c\
					operations.c\
					shared_funs.c
CHECKER_OBJS_DIR = $(OBJS_DIR)
CHECKER_OBJS = $(CHECKER_SRCS:%.c=$(CHECKER_OBJS_DIR)/%.o)

all: libft $(NAME) $(NAME1)

$(NAME): $(PUSH_SWAP_OBJS)
	@$(CC) $(CFLAGS) $^ -L $(LIBFT_PATH) -l$(patsubst %.a,%,$(LIBFT:lib%=%)) -o $(NAME)

$(NAME1): $(CHECKER_OBJS)
	@$(CC) $(CFLAGS) $^ -L $(LIBFT_PATH) -l$(patsubst %.a,%,$(LIBFT:lib%=%)) -o $(NAME1)

$(PUSH_SWAP_OBJS_DIR)/%.o: $(PUSH_SWAP_PATH)%.c
	@mkdir -p $(PUSH_SWAP_OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< $(addprefix -I.,$(addprefix $(PUSH_SWAP_PATH),$(PUSH_SWAP_INCS))) -o $@

$(CHECKER_OBJS_DIR)/%.o: $(CHECKER_PATH)%.c
	@mkdir -p $(CHECKER_OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< $(addprefix -I.,$(addprefix $(CHECKER_PATH),$(CHECKER_INCS))) -o $@

libft:
	@cd libft && make $(LIBFT)

clean:
	@cd libft && make clean
	@$(RM) $(OBJS_DIR)

fclean: clean
	@cd libft && make fclean
	@$(RM) $(NAME)
	@$(RM) $(NAME1)

re: fclean all

norm:
	@cd libft && make norm
	@norminette $(addprefix $(PUSH_SWAP_PATH),$(PUSH_SWAP_SRCS)) \
	$(addprefix $(PUSH_SWAP_PATH),$(PUSH_SWAP_INCS))

runp:
	@./push_swap $(ARG) || true

run:
	@./push_swap $(ARG) | ./checker $(ARG) || true
	@./push_swap $(ARG) | wc -l

frun: run
	####
	@./push_swap $(ARG) || true
	####

test: rmt
	@mkdir -p test
	@$(CP) $(LIBFT_PATH) test/$(LIBFT_PATH)
	@$(CP) $(PUSH_SWAP_PATH) test/$(PUSH_SWAP_PATH)
	@$(CP) author test/author
	@$(CP) Makefile test/Makefile

rmt:
	@$(RM) test

.PHONY: all clean fclean re norm libft run test rmt
