/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torange <@student.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 20:31:55 by torange           #+#    #+#             */
/*   Updated: 2020/08/11 19:11:08 by torange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_arrlen(char **arr)
{
	int i;

	i = 0;
	while (*arr++)
		i++;
	return (i);
}