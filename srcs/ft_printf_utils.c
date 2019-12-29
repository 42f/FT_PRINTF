/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 09:48:03 by bvalette          #+#    #+#             */
/*   Updated: 2019/12/29 16:04:09 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>
#include <stdarg.h>

int		ft_printer_str(t_format *format, char *str_buffer);

//toremove
//
/*
void *xmalloc(size_t n, size_t size)
 {
	int r = rand() % 200;      // Returns a pseudo-random integer between 0 and RAND_MAX.
	int alloc_number = 0;
	int fail_after = r;

	if (fail_after > 0 && r < 100)
 	{
 		printf("MALLOC FAIL @ the malloc number = [%d]{r = %d}\n", alloc_number, r);
		r = rand() % 30; 
		alloc_number++;
 		return NULL;
 	}
 	alloc_number++;

 	return ft_calloc(n, size);
 }
 #define ft_calloc(x, y) xmalloc(x, y)
*/
void	print_format(t_format *format)
{
	if (format == NULL)
		return ;
	printf("\n\n========= FORMAT =========\n");
	printf("flag string  =    |%s|\n", format->flag);
	printf("flag 0 =    |%c|\n", format->flag[0]);
	printf("flag 1 =    |%c|\n", format->flag[1]);
	printf("flag 2 =    |%c|\n", format->flag[2]);
	printf("flag 3 =    |%c|\n", format->flag[3]);
	printf("flag 4 =    |%c|\n", format->flag[4]);
	printf("flag 5 =    |%c|\n", format->flag[5]);
	printf("flag 6 =    |%c|\n", format->flag[6]);
	printf("min_w = |%d|\n", format->min_w);
	printf("pre = |%d|\n", format->pre);
	printf("conv = |%c|\n", format->conv);
	//	system ("leaks a.out");
	printf("\n===== [END FORMAT] ======\n");

}
//
// REMOVE ABOVE


t_format	*ft_format_init(void)
{
	t_format	*new_format;

	new_format = (t_format*)malloc(sizeof(t_format) * 1);
	if (new_format== NULL)
		return (NULL);
	new_format->flag = (char *)ft_calloc(6, sizeof(char));
	new_format->min_w = -1;
	new_format->pre = -1;
	new_format->spec = (char *)ft_calloc(2, sizeof(char));
	new_format->conv = '\0';
	return (new_format);
}

void		ft_fill_spec(t_format *format, char c)
{
	int			i;
	i = 0;
	while (i <= 4)
	{
		if (format->spec[i] == 0)
		{
			format->spec[i] = c;
			return ;
		}
		i++;
	}
}

void		ft_fill_flag(t_format *format, char c)
{
	int			i;
	i = 0;
	while (i <= 4)
	{
		if (format->flag[i] == 0 && ft_char_set(c, format->flag) == 0)
		{
			format->flag[i] = c;
			return ;
		}
		i++;
	}
}

char		*ft_str_set(char* str, char *set)
{
	int			i;
	int			y;

	i = 0;
	y = 0;

	while (str[y] != '\0')
	{
		while (set[i] != '\0')
		{
			if (str[y] == set[i])
				return (str + y);
			i++;
		}
		i = 0;
		y++;
	}
	return (0);
}

char		ft_char_set(char c, char *set)
{
	int			i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (c);
		i++;
	}
	return (0);
}

