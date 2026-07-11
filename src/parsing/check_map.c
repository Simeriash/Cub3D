/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 08:24:18 by julauren          #+#    #+#             */
/*   Updated: 2026/07/11 13:39:28 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

static int	top_bottom(char **map, int n)
{
	int	i;

	i = 0;
	while (map[n][i] == ' ')
		i++;
	while (map[n][i])
	{
		if (map[n][i] != ' ' && map[n][i] != '1')
			return (1);
		i++;
	}
	return (0);
}

static int	valid_char(char c)
{
	if (c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

static int	neighbor(char **map, int i, int j)
{
	if (!valid_char(map[i][j]) || !valid_char(map[i - 1][j - 1])
		|| !valid_char(map[i - 1][j]) || !valid_char(map[i - 1][j + 1])
		|| !valid_char(map[i + 1][j - 1]) || !valid_char(map[i + 1][j])
		|| !valid_char(map[i + 1][j + 1]) || !valid_char(map[i][j - 1])
		|| !valid_char(map[i][j + 1]))
		return (1);
	return (0);
}

static int	wrong_char(char **map, int n)
{
	int	i;
	int	j;

	i = 1;
	while (i < n)
	{
		j = 0;
		while (map[i][j] == ' ' || map[i][j] == '1')
			j++;
		if (j == 0)
			return (1);
		while (map[i][j])
		{
			if (map[i][j] == '1' || map[i][j] == ' ')
			{
				j++;
				continue ;
			}
			if (neighbor(map, i, j))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	check_map(char **map, t_param param)
{
	int	n;
	int	i;
	int	j;
	int	player;

	n = tab_len(map) - 1;
	if (n < 3 || top_bottom(map, 0) || top_bottom(map, n) || wrong_char(map, n))
		free_error(NULL, param, map, MAP);
	i = -1;
	player = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W'
				|| map[i][j] == 'E')
				player++;
			if (player > 1)
				break ;
		}
	}
	if (player != 1)
		free_error(NULL, param, map, MAP);
}
