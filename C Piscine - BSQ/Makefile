SRCS	= srcs/ft_check.c srcs/ft_compute.c srcs/ft_error.c srcs/ft_max.c srcs/ft_output.c srcs/ft_read.c srcs/ft_stdin_read.c srcs/main.c
OBJS	= $(SRCS:.c=.o)
INCS	= includes
NAME	= bsq
CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I$(INCS)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re .c.o
