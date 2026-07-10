/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 11:18:26 by julauren          #+#    #+#             */
/*   Updated: 2026/07/10 08:45:57 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void	free_struct(t_data *data, char **map)
{
	int	i;

	if (data->no)
		free(data->no);
	if (data->so)
		free(data->so);
	if (data->we)
		free(data->we);
	if (data->ea)
		free(data->ea);
	if (data->f)
		free(data->f);
	if (data->c)
		free(data->c);
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
