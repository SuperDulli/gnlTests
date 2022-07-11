/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_file_get_next_line.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelmerd <chelmerd@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:00:53 by chelmerd          #+#    #+#             */
/*   Updated: 2022/06/03 17:00:40 by chelmerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	char	*line;
	char	*line2;
	char	*line3;
	FILE	*f;
	int		fd;

	f = fopen("Makefile", "r");
	fd = fileno(f);
	line = "";
	while (line)
	{
		line = get_next_line(fd);
		line2 = get_next_line(0);
		line3 = get_next_line(42);
		printf("lines: |%s|, |%s|, |%s|", line, line2, line3);
		if (!line || !line2 || !line3)
			break ;
		free(line);
	}
	free(line);
	fclose(f);
	system("leaks test_file_get_next_line");
	return (0);
}
