/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 22:17:43 by ljacquet          #+#    #+#             */
/*   Updated: 2019/07/25 01:12:42 by ljacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include "ft_list.h"

#define BUF_SIZE 4096

int ft_display_file (char *str)
{
	int fd;
	int red;
	char buf[BUF_SIZE + 1];

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		write(1, "open() error", 12);
		return (1);
	}
//	ft_putnbr (fd);
	red = read(fd, buf, BUF_SIZE);
	while (red != 0 && red != -1)
	{
//		buf[red] = '\0';
		write(1, buf, red);
	}
//	buf[red] = '\0';
	if (close(fd) == -1)
	{
		write(1, "close() error", 13);
		return (1);
	}
	return (0);
}


int main (int argc, char **argv)
{
	ft_display_file(argv[1]);
	return (0);
}
