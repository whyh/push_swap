# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/21 20:30:28 by dderevyn          #+#    #+#              #
#    Updated: 2019/02/05 12:46:58 by dderevyn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

OBJS_DIR = .$(patsubst %.a,%,$(NAME))_objects
CC = clang
CFLAGS = -Wall -Wextra -Werror
CLIBS = -lmlx -framework OpenGL -framework AppKit
RM = /bin/rm -rf
CP = cp -rf

LIBFT_PATH = libft/
LIBFT = libft.a

FDF_PATH = ffdf/
FDF_INCS = 		fdf.h\
				fdf_typedefs.h
FDF_SRCS =		fdf.c\
				fdf_parse.c\
				fdf_projections.c\
				fdf_draw.c\
				fdf_interact.c\
				fdf_interface.c\
				fdf_gradient.c\
				fdf_help_menu.c\
				fdf_mouse_control.c\
				fdf_key_control.c\
				fdf_inits.c\
				fdf_complete_map.c
FDF_OBJS = $(FDF_SRCS:%.c=$(FDF_OBJS_DIR)/%.o)
FDF_OBJS_DIR = $(OBJS_DIR)

all: libft $(NAME)

$(NAME): $(FDF_OBJS)
	@$(CC) $(CFLAGS) $^ $(CLIBS) -L $(LIBFT_PATH) -l$(patsubst %.a,%,$(LIBFT:lib%=%)) -o $(NAME)

$(FDF_OBJS_DIR)/%.o: $(FDF_PATH)%.c
	@mkdir -p $(FDF_OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< $(addprefix -I.,$(addprefix $(FDF_PATH),$(FDF_INCS))) -o $@

libft:
	@cd libft && make $(LIBFT)

clean:
	@cd libft && make clean
	@$(RM) $(OBJS_DIR)

fclean: clean
	@cd libft && make fclean
	@$(RM) $(NAME)

re: fclean all

norm:
	@cd libft && make norm
	@norminette $(addprefix $(FDF_PATH),$(FDF_SRCS)) \
	$(addprefix $(FDF_PATH),$(FDF_INCS))

run:
	@./fdf maps/42.fdf

test: rmt
	@mkdir -p test
	@$(CP) $(LIBFT_PATH) test/$(LIBFT_PATH)
	@$(CP) $(FDF_PATH) test/$(FDF_PATH)
	@$(CP) author test/author
	@$(CP) Makefile test/Makefile

rmt:
	@$(RM) test

.PHONY: all clean fclean re norm libft run test rmt
