/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 09:36:28 by julauren          #+#    #+#             */
/*   Updated: 2026/07/10 15:34:56 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void	free_tab(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	end_of_file(char *file, int n)
{
	int	len;

	len = ft_strlen(file);
	len--;
	while (len > n && ft_isspace(file[len]))
		len--;
	return (len);
}

static char	**first_tab(t_param param, int n)
{
	int		end;
	char	*str;
	char	**tab;

	end = end_of_file(param.file, n);
	str = ft_substr(param.file, n, end - n + 1);
	if (!str)
		free_error(NULL, param, NULL, MALLOC);
	if (ft_strnstr(str, "\n\n", ft_strlen(str)) >= 0)
		free_error(str, param, NULL, INPUT);
	tab = ft_split(str, '\n');
	if (!tab)
		free_error(str, param, NULL, MALLOC);
	free(str);
	return (tab);
}

static int	empty_row(char **tab)
{
	int	i;
	int	j;
	int	nb;

	j = 0;
	nb = 0;
	while (true)
	{
		i = 0;
		while (tab[i] && ft_isspace(tab[i][j]))
			i++;
		if (tab[i])
			break ;
		j++;
		nb++;
	}
	return (nb);
}

void	create_map(char ***map, int n, t_param param)
{
	char	**tab;
	int		nb;

	tab = first_tab(param, n);
	nb = empty_row(tab);
	*map = clear_map(tab, nb, param);
	free(param.file);
	param.file = NULL;
}
