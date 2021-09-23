#include "so_long.h"

void init_game(t_data *data)
{
    data->game->position = find_position(*data->map, 'P');
    data->game->moves = 0;
    data->game->playing = 1;
    data->game->score = 0;
}

int can_move(t_data data, t_point next)
{
    char c;

    c = find_at(*data.map, next);
    if (c == '1')
        return (0);
    return (1);
}

void move_player(t_data *data, t_point next_position)
{
    if (data->game->playing == 0)
        return;
    if (can_move(*data, next_position) == 0)
        return;
    draw_block(next_position, WHITE, data);
    data->game->moves++;
    draw_block(data->game->position, BLACK, data);
    data->game->position = next_position;
    if (find_at(*data->map, next_position) == 'C')
        data->game->score++;
    if (find_at(*data->map, next_position) == 'E')
    {
        end_of_game(data);
        return;
    }
    mlx_put_image_to_window(data->mlx, data->window, data->image, 0, 0);
    printf("%d\n", data->game->moves);
}

void end_of_game(t_data *data)
{
    char *str;

    data->game->playing = 0;
    mlx_clear_window(data->mlx, data->window);
    mlx_string_put(data->mlx, data->window, 100, 20, WHITE, "Done");
    str = ft_strjoin("Score : ", ft_itoa(data->game->score));
    mlx_string_put(data->mlx, data->window, 100, 40, WHITE, str);
    free(str);
    str = ft_strjoin("Moves : ", ft_itoa(data->game->moves));
    mlx_string_put(data->mlx, data->window, 100, 60, WHITE, str);
    free(str);
}
