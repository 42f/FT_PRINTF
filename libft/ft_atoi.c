/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:27:47 by bvalette          #+#    #+#             */
/*   Updated: 2019/11/20 08:19:54 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	RETRY = clarification des condition dans la partie de la gestion des
**	signes + - : y >= 2 et if (str[i++] == '-'), passage de y++; avant les
**	deux if. Current version = vue par fred.
*/

static const char		*get_skipped_input(const char *str)
{
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	return (str);
}

int						ft_atoi(const char *str)
{
	int			output;
	size_t		i;

	output = 0;
	i = 0;
	str = get_skipped_input(str);
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		output = output * 10 + (str[i++] - 48);
	return (str[0] == '-' ? -output : output);
}
