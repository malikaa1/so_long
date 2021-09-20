#include "so_long.h"
void close_window(t_data *data)
{
    mlx_destroy_window(data->mlx, data->window);
}

void on_key_press(int code, t_data *data)
{
    t_point next_position;

    if (code == 97)
    {
        next_position.x = data->game->position.x - 1;
        next_position.y = data->game->position.y;
        move_left(data, next_position);
    } //a left
    if (code == 119)
    {
        move_up(data);
    } //w up
    if (code == 115)
    {
        move_down(data);
    } //s down
    if (code == 100)
    {
        move_right(data);
    } //d right

    printf("%d\n", data->game->moves);
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

    if (can_move(*data, next_position) == 0)
        return;
    draw_block(next_position, WHITE, data);
    data->game->moves++;
    draw_block(data->game->position, BLACK, data);
    data->game->position = next_position;

    mlx_put_image_to_window(data->mlx, data->window, data->image, 0, 0);
}

void move_down(t_data *data)
{
    t_point next_position;

    next_position.x = data->game->position.x;
    next_position.y = data->game->position.y + 1;

    if (can_move(*data, next_position) == 0)
        return;
    draw_block(next_position, WHITE, data);
    data->game->moves++;
    draw_block(data->game->position, BLACK, data);
    data->game->position = next_position;

    mlx_put_image_to_window(data->mlx, data->window, data->image, 0, 0);
}

void move_right(t_data *data)
{
    t_point next_position;

    next_position.x = data->game->position.x + 1;
    next_position.y = data->game->position.y;

    if (can_move(*data, next_position) == 0)
        return;
    draw_block(next_position, WHITE, data);
    data->game->moves++;
    draw_block(data->game->position, BLACK, data);
    data->game->position = next_position;

    mlx_put_image_to_window(data->mlx, data->window, data->image, 0, 0);
}
void move_left(t_data *data, t_point next_position)
{

    if (can_move(*data, next_position) == 0)
        return;
    draw_block(next_position, WHITE, data);
    data->game->moves++;
    draw_block(data->game->position, BLACK, data);
    data->game->position = next_position;

    mlx_put_image_to_window(data->mlx, data->window, data->image, 0, 0);
}