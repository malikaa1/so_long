#include "so_long.h"

t_point find_position(t_map map, char c)
{
    int y;
    int x;
    t_point result;

    result.x = 0;
    result.y = 0;
    y = 0;
    while (y < map.nb_lines)
    {
        x = 0;
        while (x < map.nb_col)
        {
            if (map.map[y][x] == c)
            {
                result.x = x;
                result.y = y;
                return result;
            }
            x++;
        }
        y++;
    }

    return (result);
}

char find_at(t_map map, t_point point)
{
    int y;
    int x;

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
    return (0);
}
