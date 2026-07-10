/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 17:43:16 by julauren          #+#    #+#             */
/*   Updated: 2026/07/10 15:20:34 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void	print_data(t_data *data, char **map)
{
	printf("NO: %s\n", data->no);
	printf("SO: %s\n", data->so);
	printf("WE: %s\n", data->we);
	printf("EA: %s\n", data->ea);
	printf("F: %i\t%i\t%i\n", data->f[0], data->f[1], data->f[2]);
	printf("C: %i\t%i\t%i\n", data->c[0], data->c[1], data->c[2]);
	ft_printf_fd(1, "%t", map);
}

static void	error_input(char *file)
{
	if (!file || file[0] == '\0')
		error_parsing(INPUT);
}

char	**parsing(char *str, t_data *data)
{
	t_param	param;
	char	**map;
	int		i;

	map = NULL;
	param.file = ft_read_file(str);
	error_input(param.file);
	i = check_data(&param, data);
	create_map(&map, i, param);
	print_data(param.data, map);
	// map = check_map(param, i);
	return (map);
}
