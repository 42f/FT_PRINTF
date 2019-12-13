# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/06 10:24:51 by bvalette          #+#    #+#              #
#    Updated: 2019/11/19 16:39:58 by bvalette         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS += ft_atoi.c
SRCS += ft_bzero.c
SRCS += ft_calloc.c
SRCS += ft_isalnum.c
SRCS += ft_isalpha.c
SRCS += ft_isascii.c
SRCS += ft_isdigit.c
SRCS += ft_isprint.c
SRCS += ft_itoa.c
SRCS += ft_memccpy.c
SRCS += ft_memchr.c
SRCS += ft_memcmp.c
SRCS += ft_memcpy.c
SRCS += ft_memmove.c
SRCS += ft_memset.c
SRCS += ft_putchar_fd.c
SRCS += ft_putendl_fd.c
SRCS += ft_putnbr_fd.c
SRCS += ft_putstr_fd.c
SRCS += ft_split.c
SRCS += ft_strchr.c
SRCS += ft_strdup.c
SRCS += ft_strjoin.c
SRCS += ft_strlcat.c
SRCS += ft_strlcpy.c
SRCS += ft_strlen.c
SRCS += ft_strmapi.c
SRCS += ft_strncmp.c
SRCS += ft_strnstr.c
SRCS += ft_strrchr.c
SRCS += ft_strtrim.c
SRCS += ft_substr.c
SRCS += ft_tolower.c
SRCS += ft_toupper.c

SRCS_BONUS += ft_lstadd_back_bonus.c
SRCS_BONUS += ft_lstadd_front_bonus.c
SRCS_BONUS += ft_lstclear_bonus.c
SRCS_BONUS += ft_lstdelone_bonus.c
SRCS_BONUS += ft_lstiter_bonus.c
SRCS_BONUS += ft_lstlast_bonus.c
SRCS_BONUS += ft_lstmap_bonus.c
SRCS_BONUS += ft_lstnew_bonus.c
SRCS_BONUS += ft_lstsize_bonus.c


OBJS	 =	$(SRCS:.c=.o)

OBJS_BONUS  = $(SRCS_BONUS:.c=.o)

CC		 =	clang

CFLAGS 	+= -Wall
CFLAGS	+= -Wextra
CFLAGS	+= -Werror

NAME	 =	libft.a

INC = ./

HEAD = $(INC)libft.h

all:	$(NAME)

$(NAME): $(OBJS) 
	ar rcs $@ $^

bonus:	$(OBJS) $(OBJS_BONUS)
	ar rcs $(NAME) $^

$(OBJS): %.o: %.c $(HEAD)
	$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(OBJS_BONUS): %.o: %.c $(HEAD)
	$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	clean all fclean re bonus
