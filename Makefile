
SRCS_FOLDER = ./srcs

SRCS += $(SRCS_FOLDER)/ft_printf.c

OBJS	 =	$(SRCS:.c=.o)

CC		 =	clang

CFLAGS 	+= -Wall
CFLAGS	+= -Wextra
CFLAGS	+= -Werror
CFLAGS	+= -g

NAME	=	libftprintf.a

LIBFT 	=	libft

INC = ./includes/

HEAD = $(INC)libftprintf.h

all:	$(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT)
	ar rcs $@ $^

$(OBJS): %.o: %.c $(HEAD)
	$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(OBJS_BONUS): %.o: %.c $(HEAD)
	$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

f:	$(NAME)
	$(CC) -I$(INC) -g main_ft_printf.c $(NAME) $(LIBFT)/libft.a
	./a.out

fs:	$(NAME)
	$(CC) -I$(INC) -fsanitize=address main_ft_printf.c $(NAME) $(LIBFT)/libft.a
	./a.out

norme:
	norminette libft/*.c
	norminette $(SRCS_FOLDER)/*.c

clean:
	$(RM) $(OBJS)
	make clean -C $(LIBFT) 

fclean:	clean	
	$(RM) $(NAME)
	make fclean -C $(LIBFT) 

execlean:
	$(RM) a.out
		
re:	execlean fclean all

.PHONY:	execlean clean all fclean re bonus
