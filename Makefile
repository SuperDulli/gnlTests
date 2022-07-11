# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chelmerd <chelmerd@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/29 15:12:04 by chelmerd          #+#    #+#              #
#    Updated: 2022/07/11 17:49:03 by chelmerd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
BUFFER_SIZE = 12
CFLAGS = -Wall -Wextra -Werror -g -D BUFFER_SIZE=$(BUFFER_SIZE)

SRC_DIR = ../eval # change eval if cloned into diffrent folder
HEADER = $(SRC_DIR)/get_next_line.h
SRCS_MANDATORY	= $(SRC_DIR)/get_next_line.c $(SRC_DIR)/get_next_line_utils.c

TEST_DIR = .

OBJS_MANDATORY	= $(patsubst %.c, %.o, $(SRCS_MANDATORY))

all: test_stdin test_file

test_stdin: $(SRCS_MANDATORY) $(TEST_DIR)/test_stdin_get_next_line.c
	$(CC) $(CFLAGS) $^ -I $(SRC_DIR) -o test_stdin_get_next_line

test_file: $(SRCS_MANDATORY) $(TEST_DIR)/test_file_get_next_line.c
	$(CC) $(CFLAGS) $^ -I $(SRC_DIR) -o test_file_get_next_line

$(OBJS_MANDATORY): $(SRCS_MANDATORY) $(HEADERS)
	$(CC) -c $(CFLAGS) -o $@ $<

test%.o: test%.c $(HEADER)
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -f *.o
	rm -fr *.dSYM

fclean: clean
	rm -f test_stdin_get_next_line
	rm -f test_file_get_next_line

re: clean all

.PHONY: all clean fclean re test_stdin test_file
