##
## Makefile for 42sh in /home/gysc0/rendu/PSU_2013_minishell2
##
## Made by Zackary Beaugelin
## Login   <beauge_z@epitech.net>
##
## Started on  Mon Apr  7 20:08:22 2014 Zackary Beaugelin
## Last update Mon Apr  7 20:18:11 2014 Zackary Beaugelin
##

NAME	=	42sh

CC	=	gcc

CFLAGS	+=	-W -Wall -Wextra -Werror
CFLAGS	+=	-I. -g3

LDFLAGS	=

RM	=	rm -rf

SRCS	=	minishell.c \
		my_built_in.c \
		my_cd.c \
		my_exec.c \
		my_getnbr.c \
		my_help.c \
		my_putnbr.c \
		my_putstr.c \
		my_strcat.c \
		my_strchr.c \
		my_strcmp.c \
		my_strcpy.c \
		my_strncmp.c \
		my_strncpy.c \
		my_str_to_wordtab.c \
		xmalloc.c \
		xread.c

OBJS	=	$(SRCS:.c=.o)

all:	$(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
