/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 11:18:26 by julauren          #+#    #+#             */
/*   Updated: 2026/07/04 13:31:50 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void	init_struct(t_path *path, t_color *color)
{
	ft_bzero(path, sizeof(*path));
	ft_bzero(color, sizeof(*color));
}

void	free_struct(t_path path, t_color color)
{
	if (path.NO)
		free(path.NO);
	if (path.SO)
		free(path.SO);
	if (path.WE)
		free(path.WE);
	if (path.EA)
		free(path.EA);
	if (color.F)
		free(color.F);
	if (color.C)
		free(color.C);
}
