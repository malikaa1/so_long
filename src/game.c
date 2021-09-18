#include "so_long.h"

void init_game(t_data* data)
{
    data->game->position = find_position(*data->map);
}