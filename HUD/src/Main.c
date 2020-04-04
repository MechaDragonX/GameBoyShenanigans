#include <gb/gb.h>
#include <stdio.h>
#include <gb/font.h>
#include "src/BackgroundTiles.c"
#include "src/BackgroundMap.c"
#include "src/WindowMap.c"

void main()
{
    font_t font;
    font_init();
    font = font_load(font_min); // 36 tiles
    font_set(font);
    set_bkg_data(37, 7, BackgroundTiles);
    set_bkg_tiles(0, 0, 40, 18, BackgroundMap);
    set_win_tiles(0, 0, 3, 1, WindowMap);
    move_win(7, 120);
    SHOW_BKG;
    SHOW_WIN;
    DISPLAY_ON;

    while(1)
    {
        scroll_bkg(1, 0);
        delay(100);
    }
}
