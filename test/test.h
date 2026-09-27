/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 21:00:00 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/02/08 21:00:00 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

void	test_invalid_fd(void);
void	test_empty_file(void);
void	test_no_permission(void);
void	test_short_file(void);
void	test_normal_file(void);
void	test_long_file(void);
void	test_multi_fd(void);

#endif
