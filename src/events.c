#include "so_long.h"

void on_key_press(int code, t_data *data)
{

    if (code == 97)
    {

    } //a left
    if (code == 119)
    {
        move_up(data);
    } //w up
    if (code == 115)
    {

    } //s down
    if (code == 100)
    {

    } //d right

    printf("%d\n", code);
}

int can_move(t_data data, t_point next)
{
    char c;
    c = find_at(*data.map, next);

    if (c == '1')
        return (0);
    return (1);
}

void move_up(t_data *data)
{

    t_point next_position;

    next_position.x = data->game->position.x;
    next_position.y = (data->game->position.y - 1);

    if (can_move(*data, next_position) == -1)
        return;
    draw_block(next_position, WHITE, data);
    //draw_block(data->game->position.x + BLOCK_SIZE, data->game->position.y + BLOCK_SIZE, BLACK, data);
    data->game->position = next_position;

    mlx_put_image_to_window(data->mlx, data->window, data->image, 0, 0);
}
