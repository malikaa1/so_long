#include "so_long.h"
int check_shape(t_map map)
{
    int j;
    j = 0;
    while (j < map.nb_lines)
    {
        if (j != 0)
        {
            if (ft_strlen(map.map[j]) != ft_strlen(map.map[j - 1]))
            {
                map.success = 0;
                map.error_message = "map must be rectangular";
                return (-1);
            }
        }
        j++;
    }
    return (1);
}
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

int count_char(t_map map, char c)
{
    char **tmp;
    int i;
    int j;
    int nb_col;
    int count;

    count = 0;
    tmp = map.map;
    j = 1;
    nb_col = ft_strlen(tmp[j]);
    while (j < (map.nb_lines - 1))
    {
        i = 1;
        while (i < nb_col - 1)
        {
            if (tmp[j][i] == c)
                count++;
            i++;
        }
        j++;
    }
    return (count);
}

int set_error(t_map *map, char *error)
{
    map->error_message = error;
    map->success = 0;
    return (-1);
}
int check_map(t_map *map)
{
    if (check_shape(*map) == -1)
        return (set_error(map, "Error\n map must be rectangular"));
    if (check_walls(*map) == -1)
        return (set_error(map, "Error\n map must be surrounded by walls"));
    if (is_valid_map_char(*map) == -1)
        return (set_error(map, "Error\n map must contain only E 1 C 0 P"));
    if (count_char(*map, 'E') <= 0)
        return (set_error(map, "Error\n map must have one exit"));
    if (count_char(*map, 'C') <= 0)
        return (set_error(map, "Error\n map must have at least one collectible"));
    if (count_char(*map, 'P') != 1)
        return (set_error(map, "Error\n map must have one starting position"));
    return (1);
}