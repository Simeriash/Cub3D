/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 11:18:26 by julauren          #+#    #+#             */
/*   Updated: 2026/07/04 15:12:45 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void	free_struct(t_data data, char **tab)
{
	int	i;

	if (data.NO)
		free(data.NO);
	if (data.SO)
		free(data.SO);
	if (data.WE)
		free(data.WE);
	if (data.EA)
		free(data.EA);
	if (data.F)
		free(data.F);
	if (data.C)
		free(data.C);
	if (tab)
	{
		i = 0;
		while (tab[i])
			free(tab[i++]);
		free(tab);
	}
}
