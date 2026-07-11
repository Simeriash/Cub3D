/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 14:16:39 by julauren          #+#    #+#             */
/*   Updated: 2026/07/11 11:39:14 by julauren         ###   ########.fr       */
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

static int	max_strlen(char **tab, int n)
{
	int	i;
	int	len;
	int	tmp;

	i = 0;
	tmp = 0;
	while (tab[i])
	{
		len = end_of_file(tab[i], n);
		if (len > tmp)
			tmp = len;
		i++;
	}
	return (tmp);
}

static char	*in_line(char *str, int n, int len)
{
	char	*line;
	int		i;

	line = malloc(sizeof(*line) * (len - n + 2));
	if (!line)
		return (NULL);
	i = 0;
	len -= n;
	while (str[n])
		line[i++] = str[n++];
	while (i <= len)
		line[i++] = ' ';
	line[i] = '\0';
	return (line);
}

char	**clear_map(char **tab, int n, t_param param)
{
	char	**map;
	int		size;
	int		i;
	int		len;

	size = tab_len(tab);
	len = max_strlen(tab, n);
	map = malloc(sizeof(*map) * (size + 1));
	if (!map)
		free_error(NULL, param, tab, MALLOC);
	i = 0;
	while (i < size)
	{
		map[i] = in_line(tab[i], n, len);
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
