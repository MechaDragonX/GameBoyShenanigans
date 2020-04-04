#include <gb/gb.h>
#include <stdio.h>
#include "src/BackgroundTiles.c"
#include "src/BackgroundMap.c"

void main()
{
    set_bkg_data(0, 7, BackgroundTiles);
    set_bkg_tiles(0, 0, 40, 18, BackgroundMap);
    SHOW_BKG;
    DISPLAY_ON;

    while(1)
    {
        scroll_bkg(1, 0);
        delay(100);
    }
}
