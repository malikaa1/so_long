#include "so_long.h"

int check_walls(t_map map)
{
    int i;
    int j;
    char **tmp;

    j = 0;
    tmp = map.map;
    while (j < map.nb_lines)
    {
        i = 0;
        while (tmp[j][i] != '\0')
        {
            if (j == 0 || j == (map.nb_lines - 1))
            {
                if (tmp[j][i] != '1')
                    return (-1);
            }
            else
            {
                if (tmp[j][0] != '1' || tmp[j][ft_strlen(tmp[j]) - 1] != '1')
                    return (-1);
            }
            i++;
        }
        j++;
    }
    return (0);
}

int check_char(t_map map, char c)
{
    char **tmp;
    int i;
    int j;
    int nb_col;

    tmp = map.map;
    j = 1;
    nb_col = ft_strlen(tmp[j]);
    while (j < (map.nb_lines - 1))
    {
        i = 1;
        while (i < nb_col - 1)
        {
            if (tmp[j][i] == c)
                return (1);
            i++;
        }
        j++;
    }
    return (-1);
}

int check_map(t_map *map)
{
    if (check_walls(*map) == -1)
    {
        map->error_message = "map must be surrounded by walls";
        map->success = 0;
        return (-1);
    }
    if (check_char(*map, 'E') == -1)
    {
        map->error_message = "map must have one exit";
        map->success = 0;
        return (-1);
    }
    if (check_char(*map, 'C') == -1)
    {
        map->error_message = "map must have at least one collectible";
        map->success = 0;
        return (-1);
    }
    if (check_char(*map, 'P') == -1)
    {
        map->error_message = "map must have one starting position";
        map->success = 0;
        return (-1);
    }
    return (1);
}