#include "so_long.h"

int is_valid_map_char(t_map map)
{
    char **tmp;
    int i;
    int j;

    tmp = map.map;
    j = 0;
    while (j < map.nb_lines)
    {
        i = 0;
        while (i < map.nb_col)
        {
            if (tmp[j][i] != '1' && tmp[j][i] != '0' && tmp[j][i] != 'E' &&
                tmp[j][i] != 'P' && tmp[j][i] != 'C')
            {
                return (-1);
            }
            i++;
        }
        j++;
    }
    return (1);
}

void create_map(int *line_count, t_map *map, char *line)
{
    char **temp;
    int i;

    i = 0;
    temp = NULL;
    if (line != NULL)
        *line_count = *line_count + 1;
    if (map->map != NULL)
        temp = map->map;
    map->map = malloc(*line_count * sizeof(char **));
    while (temp != NULL && i < *line_count - 1)
    {
        (map->map)[i] = temp[i];
        i++;
    }
    (map->map)[i] = line;
    if (temp != NULL)
        free(temp);
}

t_map new_map(void)
{
    t_map map;
    map.success = 0;
    map.map = NULL;
    map.nb_lines = 0;
    map.nb_col = -1;
    map.error_message = NULL;
    map.block_sizex = 50;
    map.block_sizey = 50;
    return (map);
}

void free_map(t_map map)
{
    printf("freeing map\n");
    int i;

    i = 0;
    if (map.map == NULL)
        return;
    while (i < map.nb_lines)
    {
        if (map.map[i] != NULL)
            free(map.map[i]);
        i++;
    }

    free(map.map);
}

void read_map(char *file_path, t_map *result)
{
    char *line;
    int fd;
    int has_line;
    int line_count;

    has_line = 1;
    line_count = 0;
    if ((fd = open(file_path, O_RDONLY)) == -1)
    {
        result->success = 0;
        result->error_message = "cannot open map file";
        return;
    }
    while (has_line == 1)
    {
        has_line = get_next_line(fd, &line);
        if (result->nb_col == -1)
            result->nb_col = ft_strlen(line);
        create_map(&line_count, result, line);
    }
    result->nb_lines = line_count;
    result->success = 1;
    result->error_message = NULL;
}

void set_block_size(t_data *data)
{

    int x;
    int y;
    mlx_get_screen_size(data->mlx, &x, &y);

    if (data->map->nb_col * data->map->block_sizex > x)
    {
        data->map->block_sizex = x / data->map->nb_col;
    }
    if (data->map->nb_lines * data->map->block_sizey > y)
    {
        data->map->block_sizey = y / data->map->nb_lines;
    }
}
