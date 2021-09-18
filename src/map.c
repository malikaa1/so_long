#include "so_long.h"

int is_valid_map_char(char *line)
{
    char *tmp;

    tmp = line;
    while (*tmp != '\0')
    {
        if (*tmp != '1' && *tmp != '0' && *tmp != 'E' &&
            *tmp != 'P' && *tmp != 'C')
            return (-1);
        tmp++;
    }
    return (1);
}

void create_map(int *line_count, t_map *result, char *line)
{
    char **temp;
    int i;

    temp = NULL;
    if (line != NULL)
        *line_count = *line_count + 1;
    if (line != NULL && is_valid_map_char(line) == -1)
    {
        result->success = 0;
        result->error_message = "map must contain only E 1 C 0 P";
    }
    if (result->map != NULL)
        temp = result->map;
    result->map = malloc(*line_count * sizeof(char **));
    i = 0;
    while (temp != NULL && i < *line_count - 1)
    {
        (result->map)[i] = temp[i];
        i++;
    }
    (result->map)[i] = line;
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
    return (map);
}

void free_map(t_map map)
{
    int i;
    if (map.map == NULL)
        return;

    i = 0;
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

t_point find_position(t_map map)
{
    int y;
    int x;
    t_point result;
    y = 0;
    while (y < map.nb_lines)
    {
        x = 0;
        while (x < map.nb_col)
        {
            if (map.map[y][x] == 'P')
            {
                result.x = x;
                result.y = y;
                return result;
            }
            x++;
        }
        y++;
    }
}

char find_at(t_map map, t_point point)
{
    int y;
    int x;
    t_point result;
    y = 0;
    while (y < map.nb_lines)
    {
        x = 0;
        while (x < map.nb_col)
        {
            if (y == point.y && x == point.x)
            {
                return map.map[y][x];
            }
            x++;
        }
        y++;
    }
}
