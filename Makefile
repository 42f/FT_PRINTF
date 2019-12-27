
SRCS_FOLDER = ./srcs
LIBFT_FOLDER = ./libft

SRCS += $(SRCS_FOLDER)/ft_printf.c
SRCS += $(SRCS_FOLDER)/ft_digit_manager_utils.c
SRCS += $(SRCS_FOLDER)/ft_unsigned_manager.c
SRCS += $(SRCS_FOLDER)/ft_alpha_manager.c
SRCS += $(SRCS_FOLDER)/ft_digit_manager.c
SRCS += $(SRCS_FOLDER)/ft_hex_manager.c
SRCS += $(LIBFT_FOLDER)/ft_atoi.c
SRCS += $(LIBFT_FOLDER)/ft_bzero.c
SRCS += $(LIBFT_FOLDER)/ft_calloc.c
SRCS += $(LIBFT_FOLDER)/ft_isalnum.c
SRCS += $(LIBFT_FOLDER)/ft_isalpha.c
SRCS += $(LIBFT_FOLDER)/ft_isascii.c
SRCS += $(LIBFT_FOLDER)/ft_isdigit.c
SRCS += $(LIBFT_FOLDER)/ft_isprint.c
SRCS += $(LIBFT_FOLDER)/ft_itoa.c
SRCS += $(LIBFT_FOLDER)/ft_itoa_base.c
SRCS += $(LIBFT_FOLDER)/ft_memccpy.c
SRCS += $(LIBFT_FOLDER)/ft_memchr.c
SRCS += $(LIBFT_FOLDER)/ft_memcmp.c
SRCS += $(LIBFT_FOLDER)/ft_memcpy.c
SRCS += $(LIBFT_FOLDER)/ft_memmove.c
SRCS += $(LIBFT_FOLDER)/ft_memset.c
SRCS += $(LIBFT_FOLDER)/ft_putendl_fd.c
SRCS += $(LIBFT_FOLDER)/ft_putchar.c
SRCS += $(LIBFT_FOLDER)/ft_putnbr.c
SRCS += $(LIBFT_FOLDER)/ft_putstr.c
SRCS += $(LIBFT_FOLDER)/ft_putchar_fd.c
SRCS += $(LIBFT_FOLDER)/ft_putnbr_fd.c
SRCS += $(LIBFT_FOLDER)/ft_putstr_fd.c
SRCS += $(LIBFT_FOLDER)/ft_split.c
SRCS += $(LIBFT_FOLDER)/ft_strchr.c
SRCS += $(LIBFT_FOLDER)/ft_strdup.c
SRCS += $(LIBFT_FOLDER)/ft_strjoin.c
SRCS += $(LIBFT_FOLDER)/ft_strlcat.c
SRCS += $(LIBFT_FOLDER)/ft_strlcpy.c
SRCS += $(LIBFT_FOLDER)/ft_strlen.c
SRCS += $(LIBFT_FOLDER)/ft_strmapi.c
SRCS += $(LIBFT_FOLDER)/ft_strncmp.c
SRCS += $(LIBFT_FOLDER)/ft_strnstr.c
SRCS += $(LIBFT_FOLDER)/ft_strrchr.c
SRCS += $(LIBFT_FOLDER)/ft_strtrim.c
SRCS += $(LIBFT_FOLDER)/ft_substr.c
SRCS += $(LIBFT_FOLDER)/ft_tolower.c
SRCS += $(LIBFT_FOLDER)/ft_toupper.c
SRCS += $(LIBFT_FOLDER)/ft_putnbr_base.c

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
	ar rcs $@ $^

$(OBJS): %.o: %.c $(HEAD)
	$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(OBJS_BONUS): %.o: %.c $(HEAD)
	$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

f:	$(NAME)
	$(CC) -I$(INC) $(CFLAGS)  -g main_ft_printf.c $(NAME) 
	./a.out

fs:	$(NAME)
	$(CC) -I$(INC) -fsanitize=address main_ft_printf.c $(NAME)
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
