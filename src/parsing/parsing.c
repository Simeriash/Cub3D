/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 17:43:16 by julauren          #+#    #+#             */
/*   Updated: 2026/07/09 17:21:31 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void	print_data(t_data *data)
{
	printf("NO: %s\n", data->NO);
	printf("SO: %s\n", data->SO);
	printf("WE: %s\n", data->WE);
	printf("EA: %s\n", data->EA);
	printf("F: %i\t%i\t%i\n", data->F[0], data->F[1], data->F[2]);
	printf("C: %i\t%i\t%i\n", data->C[0], data->C[1], data->C[2]);
}

char	**parsing(char *str, t_data *data)
{
	t_param	param;
	char	**map;

	map = NULL;
	param.file = ft_read_file(str);
	if (!param.file)
		error_parsing(MALLOC);
	check_data(param, data);
	print_data(data);
	free_struct(data, NULL);
	free(param.file);
	return (map);
}
