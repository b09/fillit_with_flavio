/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_input.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/22 17:58:52 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/05/22 17:58:54 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	read_line(int fd, char *buf, char *line)
{
	int	ret;

	ret = read(fd, buf, CHARS_IN_LINE);
	line = ft_memdup(buf, CHARS_IN_LINE + 1);
	return (ret);
}

int			get_input(char **lines, char *filename)
{
	int		fd;
	int		n_lines;
	char	buf[CHARS_IN_LINE + 1];
	char	ret;

	ft_bzero(buf);
	fd = open(filename, O_RDONLY);
	if (fd <= 0)
	{
		lines = NULL;
		return (0);
	}
	n_lines = 0;
	ret = read_line(fd, buf, lines[n_lines]);
	n_lines++;
	while (n_lines <= MAX_TTRS && ret == CHARS_IN_LINE)
	{
		ret = read_line(fd, buf, lines[n_lines]);
		n_lines++;
		buf[ret] = 0;
	}
	if (n_lines == MAX_TTRS || ret != CHARS_IN_LINE - 1)
		return (free_lines(lines, n_lines));
	lines[n_lines] == NULL;
	return (n_lines);
}