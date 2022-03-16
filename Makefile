# Project file
NAME	=	cub3d

# Project builds
SRCDIR		= ./src/
SRCNAMES	= $(shell ls $(SRCDIR) | grep -E ".+\.c")
SRC 		= $(addprefix $(SRCDIR), $(SRCNAMES))
OBJ			= $(SRC:.c=.o)
INC 		= ./inc/
BUILDDIR 	= ./build/
BUILDOBJS 	= $(addprefix $(BUILDDIR), $(SRCNAMES:.c=.o))
FLAGS_MAC	= -framework OpenGL -framework AppKit

# Libft builds and dirs
LIBDIR 		= ./libft/
LIBFT 		= ./libft/libft.a
LIBINC 		= ./libft/
MLX			= ./minilibx_macos/libmlx.a

# Optimization and compiler flags
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra

# Debug flag
DEBUG 		= -g

# Main rule
all:		$(BUILDDIR) $(LIBFT) $(NAME)

# Object dir rule
$(BUILDDIR):
	mkdir -p $(BUILDDIR)

# Object dir rule
$(BUILDDIR)%.o:$(SRCDIR)%.c
	$(CC) -I$(LIBINC) -I$(INC) $(CFLAGS) -g -o $@ -c $<

# Project file rule
$(NAME): $(BUILDOBJS)
	$(CC) -g -o $(NAME) $(BUILDOBJS) $(LIBFT) $(MLX) $(FLAGS_MAC)

# Libft rule
$(LIBFT):
	make -C $(LIBDIR)

# Cleaning up the build files
clean:
	rm -rf $(SRCDIR)$(OBJ)
	make -C $(LIBDIR) clean

# Getting rid of the project file
fclean: clean
	rm -rf $(NAME)
	rm -rf $(BUILDDIR)
	make -C $(LIBDIR) fclean

# Do both of the above
re: fclean all

# Just in case those files exist in the root dir
.PHONY: all fclean clean re
