/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whazami <whazami@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 20:19:40 by whazami           #+#    #+#             */
/*   Updated: 2021/06/18 18:33:15 by whazami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../get_next_line.h"

void print_ret(char ret)
{
	if (ret < 0)
	{
		write(1, "-", 1);
		ret = -ret;
	}
	ret += '0';
	write(1, &ret, 1);
}

int main()
{
	int fd = open("txt/file.txt", O_RDONLY);
	char *line = NULL;

	char ret;
	do
	{
		ret = get_next_line(fd, &line);
		write(1, "ret gnl : ", 10);
		print_ret(ret);
		write(1, "\tline : ", 8);
		(line) ? write(1, line, ft_strlen(line, '\0')) : write(1, "(null)", 6);
		write(1, "\n", 1);
	}
	while (ret == 1);
	return (0);
}
