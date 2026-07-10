/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 17:43:16 by julauren          #+#    #+#             */
/*   Updated: 2026/07/10 08:45:57 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void	print_data(t_data *data)
{
	printf("NO: %s\n", data->no);
	printf("SO: %s\n", data->so);
	printf("WE: %s\n", data->we);
	printf("EA: %s\n", data->ea);
	printf("F: %i\t%i\t%i\n", data->f[0], data->f[1], data->f[2]);
	printf("C: %i\t%i\t%i\n", data->c[0], data->c[1], data->c[2]);
}

char	**parsing(char *str, t_data *data)
{
	t_param	param;
	char	**map;
	int		i;

	map = NULL;
	param.file = ft_read_file(str);
	if (!param.file)
		error_parsing(MALLOC);
	i = check_data(param, data);
	// printf("%i\t%c\n", i, param.file[i]);
	print_data(data);
	free(param.file);
	return (map);
}
