/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stdin_get_next_line.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelmerd <chelmerd@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:00:53 by chelmerd          #+#    #+#             */
/*   Updated: 2022/06/03 16:47:43 by chelmerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	char	*line;

	line = get_next_line(0);
	printf("line: |%s|\n", line);
	while (line)
	{
		printf("line: |%s|\n", line);
		free(line);
		line = get_next_line(0);
	}
	free(line);
	system("leaks test_stdin_get_next_line");
	return (0);
}
