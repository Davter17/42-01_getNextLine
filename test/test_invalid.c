/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_invalid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 21:00:00 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/02/08 21:00:00 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

void	test_invalid_fd(void)
{
	char	*line;

	printf("\n=== Test: Invalid FD (-1) ===\n");
	line = get_next_line(-1);
	if (!line)
		printf("\033[32m[PASS]\033[0m Returns NULL for invalid fd\n");
	else
	{
		printf("\033[31m[FAIL]\033[0m Should return NULL\n");
		free(line);
	}
}
