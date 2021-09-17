#include "so_long.h"

void draw_pixel(int x, int y, int color, t_data *data)
{
    char *pixel;
    pixel = data->image_addr + (y * data->size_line) + (x * (data->bits_per_pixel / 8));
    *(unsigned int *)pixel = color;
}

void draw_block(int x, int y, int color, t_data *data)
{
    const int block_size = 50;

    int current_x;
    int current_y;

    current_y = y;

    while (current_y < (y + block_size))
    {
        current_x = x;
        while (current_x < (x + block_size))
        {
            draw_pixel(current_x, current_y, color, data);
            current_x++;
        }
        current_y++;
    }
}