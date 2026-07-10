/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 14:16:39 by julauren          #+#    #+#             */
/*   Updated: 2026/07/10 15:50:27 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

int	tab_len(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

static char	*in_line(char *str, int n)
{
	char	*line;
	int		end;
	int		i;

	end = end_of_file(str, 0);
	line = malloc(sizeof(*line) * (end - n + 2));
	if (!line)
		return (NULL);
	i = 0;
	end -= n;
	while (i <= end)
		line[i++] = str[n++];
	line[i] = '\0';
	return (line);
}

char	**clear_map(char **tab, int n, t_param param)
{
	char	**map;
	int		len;
	int		i;

	len = tab_len(tab);
	map = malloc(sizeof(*map) * (len + 1));
	if (!map)
		free_error(NULL, param, tab, MALLOC);
	i = 0;
	while (i < len)
	{
		map[i] = in_line(tab[i], n);
		if (!map[i])
		{
			free_tab(map);
			free_error(NULL, param, tab, MALLOC);
		}
		i++;
	}
	map[i] = NULL;
	free_tab(tab);
	return (map);
}
