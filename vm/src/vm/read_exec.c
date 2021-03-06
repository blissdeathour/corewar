/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torange <@student.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 14:29:43 by torange           #+#    #+#             */
/*   Updated: 2020/08/25 15:51:18 by torange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	*read_exec(t_player *p, size_t idx)
{
	if (idx > CHAMP_MAX_SIZE)
		return (NULL);
	return (p->exec + idx);
}
