#include "so_long.h"

void close_window(t_data *data)
{
    mlx_destroy_window(data->mlx, data->window);
    free_map(*data->map);
    free(data->game);
    free(data->mlx);
    exit(EXIT_SUCCESS);
}

void on_key_press(int code, t_data *data)
{
    t_point next_position;
    if (code == 65307)
        close_window(data);
    if (code == 97)
    {
        next_position.x = data->game->position.x - 1;
        next_position.y = data->game->position.y;
        move_player(data, next_position);
    } //a left
    if (code == 119)
    {
        next_position.x = data->game->position.x;
        next_position.y = (data->game->position.y - 1);
        move_player(data, next_position);
    } //w up
    if (code == 115)
    {
        next_position.x = data->game->position.x;
        next_position.y = data->game->position.y + 1;
        move_player(data, next_position);
    } //s down
    if (code == 100)
    {
        next_position.x = data->game->position.x + 1;
        next_position.y = data->game->position.y;
        move_player(data, next_position);
    } //d right
}

int refresh_window(t_data *data)
{
    return mlx_put_image_to_window(data->mlx, data->window, data->image, 0, 0);
}