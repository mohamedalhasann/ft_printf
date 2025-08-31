CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = 
OBJS = $(SRCS:.c = .o)
NAME = libftprintf.a
all : $(NAME)
$(NAME) : $(OBJS)
		ar rcs $@ $^
clean: 
		rm -f $(OBJS) 
fclean : clean
		rm -f $(NAME)
re : fclean all
.PHONY: all clean fclean re 