/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_read.c                                        :+:      :+:    :+:   */
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

void	test_normal_file(void)
{
	int		fd;
	char	*line;
	int		count;

	printf("\n=== Test: Normal File (5 lines) ===\n");
	fd = open("test/files/normal.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("\033[31m[ERROR]\033[0m Cannot open file\n");
		return ;
	}
	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		count++;
		line = get_next_line(fd);
	}
	if (count == 5)
		printf("\033[32m[PASS]\033[0m Read 5 lines correctly\n");
	else
		printf("\033[31m[FAIL]\033[0m Expected 5 lines, got %d\n", count);
	close(fd);
}

void	test_long_file(void)
{
	int		fd;
	char	*line;
	int		count;

	printf("\n=== Test: Long File (1000 lines) ===\n");
	fd = open("test/files/long.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("\033[31m[ERROR]\033[0m Cannot open file\n");
		return ;
	}
	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		count++;
		line = get_next_line(fd);
	}
	if (count == 1000)
		printf("\033[32m[PASS]\033[0m Read 1000 lines correctly\n");
	else
		printf("\033[31m[FAIL]\033[0m Expected 1000 lines, got %d\n", count);
	close(fd);
}
