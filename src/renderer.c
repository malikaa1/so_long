#include "so_long.h"

void draw_pixel(t_point point, int color, t_data *data)
{
    char *pixel;
    pixel = data->image_addr + (point.y * data->size_line) + (point.x * (data->bits_per_pixel / 8));
    *(unsigned int *)pixel = color;
}

void draw_block(t_point point, int color, t_data *data)
{
    t_point current_point;

    current_point = point;

    while (current_point.y <= (point.y + BLOCK_SIZE))
    {
        current_point.x = point.x;
        while (current_point.x <= (point.x + BLOCK_SIZE))
        {
            draw_pixel(current_point, color, data);
            current_point.x++;
        }
        current_point.y++;
    }
}

void draw_map(t_data data)
{
    int x;
    int y;
    t_map *map;
    map = data.map;
    t_point p;

    y = 0;
    while (y < map->nb_lines)
    {
        x = 0;
        while (x < map->nb_col)
        {
            p.x = x * BLOCK_SIZE;
            p.y = y * BLOCK_SIZE;
            if (map->map[y][x] == '1')
                draw_block(p, BROWN, &data);
            else if (map->map[y][x] == '0')
                draw_block(p, BLACK, &data);
            else if (map->map[y][x] == 'E')
                draw_block(p, RED, &data);
            else if (map->map[y][x] == 'C')
                draw_block(p, BLUE, &data);
            else if (map->map[y][x] == 'P')
                draw_block(p, WHITE, &data);
            x++;
        }
        y++;
    }
}