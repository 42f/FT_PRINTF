/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 09:32:31 by Brian             #+#    #+#             */
/*   Updated: 2019/11/19 07:44:36 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** RETRY = Usage de calloc plutot que malloc pour ne pas avoir a
**	gerer la terminaison de la chaine retournée
**	changement du return en cas de int n = 0 plus propre
*/

static char	*ft_fill(char *r, unsigned int n_val, int negsign, int i)
{
	while (n_val > 0 && i >= 0)
	{
		r[i] = (n_val % 10) + '0';
		n_val = n_val / 10;
		i--;
	}
	if (negsign == -1)
		r[i] = '-';
	return (r);
}

char		*ft_itoa(int n)
{
	char			*r;
	int				len;
	int				negsign;
	unsigned int	n_val;

	len = 0;
	negsign = 1;
	if (n < 0)
		negsign = -1;
	n_val = n * negsign;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	if (negsign == -1 || n_val == 0)
		len++;
	if (!(r = (char *)ft_calloc(sizeof(char), len + 1)))
		return (NULL);
	if (n_val == 0)
	{
		r[0] = '0';
		return (r);
	}
	return (ft_fill(r, n_val, negsign, len - 1));
}
