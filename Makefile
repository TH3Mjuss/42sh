##
## Makefile for 42sh in /home/gysc0/rendu/PSU_2013_minishell2
##
## Made by Zackary Beaugelin
## Login   <beauge_z@epitech.net>
##
## Started on  Mon Apr  7 20:08:22 2014 Zackary Beaugelin
## Last update Mon Jun  2 07:42:54 2014 Zackary Beaugelin
##

NAME	=	42sh

CC	=	gcc

CFLAGS	+=	-W -Wall -Wextra -Werror
CFLAGS	+=	-I./Headers/ -g3

LDFLAGS	=

RM	=	rm -rf

SRCDIR	=	./Sources
BIDIR	=	$(SRCDIR)/built_in
BTDIR	=	$(SRCDIR)/btree
FDIR	=	$(SRCDIR)/functions
PDIR	=	$(SRCDIR)/parser


SRCS	=	$(SRCDIR)/main.c \
		$(BIDIR)/my_built_in.c \
		$(BIDIR)/my_cd.c \
		$(BIDIR)/my_echo.c \
		$(SRCDIR)/my_exec.c \
		$(FDIR)/my_getnbr.c \
		$(BIDIR)/my_help.c \
		$(BIDIR)/my_exit.c \
		$(FDIR)/my_putnbr.c \
		$(FDIR)/my_putstr.c \
		$(FDIR)/my_strcat.c \
		$(FDIR)/my_strchr.c \
		$(FDIR)/my_strcmp.c \
		$(FDIR)/my_strcpy.c \
		$(FDIR)/my_strncmp.c \
		$(FDIR)/my_strncpy.c \
		$(SRCDIR)/my_str_to_wordtab.c \
		$(FDIR)/xmalloc.c \
		$(PDIR)/parser.c \
		$(PDIR)/my_preparser.c \
		$(PDIR)/parser_tok.c \
		$(FDIR)/xread.c \
		$(SRCDIR)/rediretions.c \
		$(SRCDIR)/my_epur_str.c \
		$(SRCDIR)/my_check_env.c

OBJS	=	$(SRCS:.c=.o)

all:	$(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
