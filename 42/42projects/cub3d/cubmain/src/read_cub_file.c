#include "cub3d.h"

// int		ft_strchar(char *s, char *line)
// {
// 	int i;

// 	i = 0;
// 	while (s[i] != '\0')
// 	{
// 		if (s[i] == line[0])
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }
int		ft_strchr(char *str, char c)
{
	while (str && *str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

// void	put_num_info(t_game *g, char *line, int cheak)
// {
// 	int flag;

// 	flag = 0;
// 	while (*line)
// 	{
// 		if (*line == ' ')
// 			*line++;
// 		if (flag == 0 && ft_strchar("123456789", line) == 0)
// 		{
// 			g->win_wid = (g->win_wid * 10) + (g->win_wid + 48);
// 			if (line[1] == ' ')
// 				flag = 1;
// 		}
// 		else if (flag == 1 && ft_strchar("123456789", line) == 0)
// 			g->win_hei = (g->win_hei * 10) + (g->win_hei + 48);
// 		else
// 			return ;
// 	}
// }

void	put_num_info1(t_game *g, char *line)
{
	while (line[g->indent_info.indent] == ' ')
		g->indent_info.indent++;
	while (ft_strchr("123456789", line[g->indent_info.indent]))
	{
			g->win_hei = g->win_hei * 10 + (line[g->indent_info.indent] - '0');
			g->indent_info.indent++;
	}
}

void	put_num_info(t_game *g, char *line, int cheak)
{
	while (line[g->indent_info.indent] == ' ')
		g->indent_info.indent++;
	while (ft_strchr("123456789", line[g->indent_info.indent]))
	{
		g->win_wid = g->win_wid * 10 + (line[g->indent_info.indent] - '0');
		g->indent_info.indent++;
	}
	put_num_info1(g, line + g->indent_info.indent + 1);
}

void	put_str_info(t_wall_texture *info, char *line)
{
	info->path = line;
}

void	cub_f_init(t_game	*g)
{
	g->indent_info.indent = 0;
	g->win_hei = 0;
	g->win_wid = 0;
	g->no_info.path = NULL;
	g->so_info.path = NULL;
	g->we_info.path = NULL;
	g->ea_info.path = NULL;
	g->s_info.path = NULL;
	g->f_info.color[0] = 0;
	g->f_info.color[1] = 0;
	g->f_info.color[2] = 0;
	g->file_info.file_name = NULL;
}

int divide_line(t_game *g, char *line)
{
    int i;

    i = 0;
    if (line[0] == 'R' && line[1] == ' ')
		put_num_info(g, line + 2);
	// if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
	// 	put_str_info(&g->no_info, line + 3);
	// if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
	// 	put_str_info(&g->so_info, line + 3);
	// if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
	// 	put_str_info(&g->we_info, line + 3);
	// if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
	// 	put_str_info(&g->ea_info, line + 3);
	// if (line[0] == 'S' && line[1] == ' ')
	// 	put_str_info(&g->s_info, line + 2);
	// if (line[0] == 'F' && line[1] == ' ')
	// 	put_num_info(&g->f_info, line + 2, 1);
	// if (line[0] == 'C' && line[1] == ' ')
	// 	put_num_info(&g->f_info, line + 2, 1);
	else
		return (0);
	return (1);
		// if (line[i] == 'R' && line[i + 1] == ' ')
}

int main(int argc, char **argv)
{
    char            *line;
    int             fd;
    int             ret;
    t_game          g;
	char 			tmp[200];
	int				i;

	// printf("ss\n");
	if (argc == 2)
	{
		i = 0;
		cub_f_init(&g);
		while (argv[1][i])
		{
			tmp[i] = argv[1][i];
			i++;
		}
		tmp[i] = 0;
		g.file_info.file_name = tmp;
		// printf("hei=%s\n", g.file_info.file_name);
		fd = open(g.file_info.file_name, O_RDWR);
		if (fd < 0)
			// ft_error(p, ERROR_FD);
			return (0);
		while ((ret = get_next_line(fd, &line)) > 0)
		{
			divide_line(&g, line);
			// printf("hei=%d\n", 99);
			// printf("hei=%d\n", g.win_hei);
			// printf("wid=%d\n", g.win_wid);
			// if (ft_strlen(line) > 500)
			//     ft_error(p, 10);
		}
	}
    // divide_line(p, line);
    // if (ft_strlen(line) > 500)
    //     ft_error(p, 10);
    // if (p->cf->player != 1)
    //     ft_error(p, 8);
	return 0;
}

// int        read_map(t_player *p)
// {
//     t_check_file    check_file;

//     p->cf = &check_file;
//     init_check_file(p);
//     p->file_name = p->pass_ptr;
//     p->map = malloc(sizeof(char *) * (600 + 1));
//     if (p->map == NULL)
//         ft_error(p, 2);
//     p->map_check = malloc(sizeof(char *) * (600 + 1));
//     if (p->map == NULL)
//         ft_error(p, 2);
//     p->map_index = 0;
//     read_map2(p);
//     return (0);
// }
