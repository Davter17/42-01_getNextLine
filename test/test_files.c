/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_files.c                                       :+:      :+:    :+:   */
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

void	test_empty_file(void)
{
	int		fd;
	char	*line;

	printf("\n=== Test: Empty File ===\n");
	fd = open("test/files/empty.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("\033[31m[ERROR]\033[0m Cannot open file\n");
		return ;
	}
	line = get_next_line(fd);
	if (!line)
		printf("\033[32m[PASS]\033[0m Returns NULL for empty file\n");
	else
	{
		printf("\033[31m[FAIL]\033[0m Should return NULL, got: %s\n", line);
		free(line);
	}
	close(fd);
}

void	test_no_permission(void)
{
	int		fd;
	char	*line;

	printf("\n=== Test: No Permission ===\n");
	fd = open("test/files/noperm.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("\033[32m[PASS]\033[0m Cannot open (permission denied)\n");
		return ;
	}
	line = get_next_line(fd);
	if (!line)
		printf("\033[32m[PASS]\033[0m Returns NULL when read fails\n");
	else
	{
		printf("\033[31m[FAIL]\033[0m Should return NULL\n");
		free(line);
	}
	close(fd);
}

void	test_short_file(void)
{
	int		fd;
	char	*line;
	int		count;

	printf("\n=== Test: Short File (no newline) ===\n");
	fd = open("test/files/short.txt", O_RDONLY);
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
	if (count == 1)
		printf("\033[32m[PASS]\033[0m Read 1 line without newline\n");
	else
		printf("\033[31m[FAIL]\033[0m Expected 1 line, got %d\n", count);
	close(fd);
}
