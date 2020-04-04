#include <gb/gb.h>
#include <stdio.h>
#include "NoseSprites.c"

void main()
{
    UINT8 currentSpriteIndex = 0;

    set_sprite_data(0, 2, Nose);
    set_sprite_tile(0, 0);
    move_sprite(0, 20, 78);
    SHOW_SPRITES;

    while(1)
    {
        if(currentSpriteIndex == 0)
            currentSpriteIndex = 1;
        else
            currentSpriteIndex = 0;
        set_sprite_tile(0, currentSpriteIndex);
        scroll_sprite(0, 10, 0);
        delay(1000);
    }
}
