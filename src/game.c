#include "so_long.h"
int nb_of_collectible(t_map map)
{
    char **tmp;
    int i;
    int j;
    int nb_col;
    int count;

    tmp = map.map;
    count = 0;
    j = 1;
    nb_col = ft_strlen(tmp[j]);
    while (j < (map.nb_lines - 1))
    {
        i = 1;
        while (i < nb_col - 1)
        {
            if (tmp[j][i] == 'C')
                count++;
            i++;
        }
        j++;
    }
    return (count);
}

void init_game(t_data *data)
{
    data->game->position = find_position(*data->map, 'P');
    data->game->moves = 0;
    data->game->playing = 1;
    data->game->score = 0;
    data->game->nb_collectible = nb_of_collectible(*data->map);
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
    if (find_at(*data->map, next_position) == 'E')
    {
        if (data->game->score == data->game->nb_collectible)
        {
            return end_of_game(data);
        }
    }
    if (find_at(*data->map, next_position) != 'E')
    {
        draw_block(next_position, WHITE, data);
        draw_block(data->game->position, BLACK, data);
        data->game->moves++;
        data->game->position = next_position;
        if (find_at(*data->map, next_position) == 'C')
        {
            data->game->score++;
            data->map->map[next_position.y][next_position.x] = '0';
        }
    }

    mlx_put_image_to_window(data->mlx, data->window, data->image, 0, 0);
    printf("%d\n", data->game->moves);
}

void end_of_game(t_data *data)
{
    char *str;
    char *score;
    char *moves;

    data->game->playing = 0;
    mlx_clear_window(data->mlx, data->window);
    mlx_string_put(data->mlx, data->window, 100, 20, WHITE, "Done");
    score = ft_itoa(data->game->score);
    str = ft_strjoin("Score : ", score);
    mlx_string_put(data->mlx, data->window, 100, 40, WHITE, str);
    free(str);
    free(score);
    moves = ft_itoa(data->game->moves);
    str = ft_strjoin("Moves : ", moves);
    mlx_string_put(data->mlx, data->window, 100, 60, WHITE, str);
    free(moves);
    free(str);
}
