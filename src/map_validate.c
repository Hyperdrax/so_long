#include "so_long.h"

static int  is_valid_char(char c)
{
    return (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P');
}

static void check_borders(char **map, int h, int w)
{
    int i;

    i = 0;
    while (i < w)
        if (map[0][i] != '1' || map[h - 1][i] != '1')
            error_exit("Map border must be walls");
        else
            i++;
    i = 0;
    while (i < h)
    {
        if (map[i][0] != '1' || map[i][w - 1] != '1')
            error_exit("Map border must be walls");
        i++;
    }
}

static void flood(char **map, int h, int w, int y, int x, int **vis, int *got_c, int *got_e)
{
    if (y < 0 || y >= h || x < 0 || x >= w)
        return ;
    if (map[y][x] == '1' || vis[y][x])
        return ;
    vis[y][x] = 1;
    if (map[y][x] == 'C')
        (*got_c)++;
    if (map[y][x] == 'E')
        *got_e = 1;
    flood(map, h, w, y + 1, x, vis, got_c, got_e);
    flood(map, h, w, y - 1, x, vis, got_c, got_e);
    flood(map, h, w, y, x + 1, vis, got_c, got_e);
    flood(map, h, w, y, x - 1, vis, got_c, got_e);
}

void    validate_map(char **map, int h, int w)
{
    int p_cnt;
    int e_cnt;
    int c_cnt;
    int y;
    int x;
    int px;
    int py;

    if (!map || h <= 0 || w <= 0)
        error_exit("Invalid map dimensions");
    p_cnt = e_cnt = c_cnt = 0;
    y = 0;
    while (y < h)
    {
        if ((int)ft_strlen(map[y]) != w)
            error_exit("Map must be rectangular");
        x = 0;
        while (x < w)
        {
            if (!is_valid_char(map[y][x]))
                error_exit("Map contains invalid character");
            if (map[y][x] == 'P' && ++p_cnt)
            { px = x; py = y; }
            if (map[y][x] == 'E')
                e_cnt++;
            if (map[y][x] == 'C')
                c_cnt++;
            x++;
        }
        y++;
    }
    if (p_cnt != 1 || e_cnt != 1 || c_cnt < 1)
        error_exit("Map needs 1 player, 1 exit, and at least 1 collectable");
    check_borders(map, h, w);
    int **vis = ft_calloc(h, sizeof(int *));
    if (!vis)
        error_exit("Allocation failed");
    y = 0;
    while (y < h)
    {
        vis[y] = ft_calloc(w, sizeof(int));
        if (!vis[y])
            error_exit("Allocation failed");
        y++;
    }
    int got_c = 0;
    int got_e = 0;
    flood(map, h, w, py, px, vis, &got_c, &got_e);
    y = 0;
    while (y < h)
        free(vis[y++]);
    free(vis);
    if (got_c != c_cnt || !got_e)
        error_exit("Not all collectables/exit reachable");
}
