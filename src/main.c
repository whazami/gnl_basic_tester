/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whazami <whazami@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 20:19:40 by whazami           #+#    #+#             */
/*   Updated: 2021/06/18 16:15:37 by whazami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../get_next_line.h"

int main()
{
	int fd = open("txt/file.txt", O_RDONLY);
	char *line = NULL;

	char ret;
	do
	{
		ret = get_next_line(fd, &line);
		ret += '0';
		write(1, "ret gnl : ", 10);
		write(1, &ret, 1);
		ret -= '0';
		write(1, "\tline : ", 8);
		(line) ? write(1, line, ft_strlen(line, '\0')) : write(1, "(null)", 6);
		write(1, "\n", 1);
	}
	while (ret == 1);
	return (0);
}
