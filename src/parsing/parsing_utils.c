/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 11:18:26 by julauren          #+#    #+#             */
/*   Updated: 2026/07/09 17:24:08 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void	free_struct(t_data *data, char **map)
{
	int	i;

	if (data->NO)
		free(data->NO);
	if (data->SO)
		free(data->SO);
	if (data->WE)
		free(data->WE);
	if (data->EA)
		free(data->EA);
	if (data->F)
		free(data->F);
	if (data->C)
		free(data->C);
	if (map)
	{
		i = 0;
		while (map[i])
			free(map[i++]);
		free(map);
	}
}

int	empty_line(char *str, int start, int end)
{
	int	i;

	if (start > end)
		return (0);
	i = start;
	while (str[i] && ft_isspace(str[i]) && i <= end)
		i++;
	if (str[i] == '\0' || i == end + 1)
		return (1);
	return (0);
}

int	next_line(char *str, int start)
{
	int	end;

	end = start;
	while (str[end])
	{
		if (str[end] == '\n')
			return (end);
		end++;
	}
	return (-1);
}

void	free_error(char *str, t_param param, char **map, t_error error)
{
	if (str)
		free(str);
	free_struct(param.data, map);
	free(param.file);
	error_parsing(error);
}
