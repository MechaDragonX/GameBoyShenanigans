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
    delay(1000);

    while(1)
    {
        switch(joypad())
        {
            case J_UP:
                scroll_sprite(0, 0, -10);
                break;
            case J_DOWN:
                scroll_sprite(0, 0, 10);
                break;
            case J_LEFT:
                scroll_sprite(0, -10, 0);
                break;
            case J_RIGHT:
                scroll_sprite(0, 10, 0);
                break;
            case J_A:
                if(currentSpriteIndex == 0)
                    currentSpriteIndex = 1;
                else
                    currentSpriteIndex = 0;
                set_sprite_tile(0, currentSpriteIndex);
                break;
        }
        delay(100);
    }
}
