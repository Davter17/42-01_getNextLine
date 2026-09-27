/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_multi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 21:00:00 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/02/08 21:00:00 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void	read_alternating(int fd1, int fd2, int *c1, int *c2)
{
	char	*line1;
	char	*line2;

	*c1 = 0;
	*c2 = 0;
	line1 = get_next_line(fd1);
	line2 = get_next_line(fd2);
	while (line1 || line2)
	{
		if (line1)
		{
			free(line1);
			(*c1)++;
			line1 = get_next_line(fd1);
		}
		if (line2)
		{
			free(line2);
			(*c2)++;
			line2 = get_next_line(fd2);
		}
	}
}

void	test_multi_fd(void)
{
	int		fd1;
	int		fd2;
	int		c1;
	int		c2;

	printf("\n=== Test: Multi-FD Alternating ===\n");
	fd1 = open("test/files/normal.txt", O_RDONLY);
	fd2 = open("test/files/short.txt", O_RDONLY);
	if (fd1 < 0 || fd2 < 0)
	{
		printf("\033[31m[ERROR]\033[0m Cannot open files\n");
		return ;
	}
	read_alternating(fd1, fd2, &c1, &c2);
	if (c1 == 5 && c2 == 1)
		printf("\033[32m[PASS]\033[0m Read fd1:%d fd2:%d correctly\n", c1, c2);
	else
		printf("\033[31m[FAIL]\033[0m Expected fd1:5 fd2:1, got fd1:%d fd2:%d\n", c1, c2);
	close(fd1);
	close(fd2);
}
