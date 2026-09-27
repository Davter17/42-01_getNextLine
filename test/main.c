/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 20:55:00 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/02/08 20:55:00 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include <stdio.h>

static void	run_all_tests(void)
{
	test_invalid_fd();
	test_empty_file();
	test_no_permission();
	test_short_file();
	test_normal_file();
	test_long_file();
	test_multi_fd();
}

int	main(void)
{
	printf("========================================\n");
	printf("   GET_NEXT_LINE TEST SUITE\n");
	printf("========================================\n");
	run_all_tests();
	printf("\n========================================\n");
	printf("   ALL TESTS COMPLETED\n");
	printf("========================================\n");
	return (0);
}
