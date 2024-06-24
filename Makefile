# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erwfonta <erwfonta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/23 15:33:07 by erwfonta          #+#    #+#              #
#    Updated: 2024/06/23 15:39:55 by erwfonta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Target executable
TARGET = push_swap

# Source files for push_swap
SRCS_PUSH_SWAP = 

# Object files for push_swap
OBJS_PUSH_SWAP = $(SRCS_PUSH_SWAP:.c=.o)

# Compiler
CC = cc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror

# Libraries
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBS = -L$(LIBFT_DIR) -lft

# Rules
all: $(LIBFT) $(TARGET)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(TARGET): $(OBJS_PUSH_SWAP) $(LIBFT)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS_PUSH_SWAP) $(LIBS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS_PUSH_SWAP)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(TARGET)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all