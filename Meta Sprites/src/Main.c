#include <gb/gb.h>
#include <stdio.h>
#include "src/GameCharacter.c"
#include "src/SpriteTiles.c"

struct GameCharacter smiley;
struct GameCharacter spin;
UBYTE spriteSize = 8;
UINT8 speed = 5;

void perfomantDelay(UINT8 loops)
{
    UINT8 i;
    for(i = 0; i < loops; i++)
        wait_vbl_done();
}
void moveGameCharacter(struct GameCharacter* character, UINT8 x, UINT8 y)
{
    move_sprite(character->spriteIds[0], x, y);
    move_sprite(character->spriteIds[1], x + spriteSize, y);
    move_sprite(character->spriteIds[2], x, y + spriteSize);
    move_sprite(character->spriteIds[3], x + spriteSize, y + spriteSize);
}
void setupSmiley()
{
    smiley.x = 80;
    smiley.y = 130;
    smiley.width = 16;
    smiley.height = 16;

    set_sprite_tile(0, 0);
    smiley.spriteIds[0] = 0;
    set_sprite_tile(1, 1);
    smiley.spriteIds[1] = 1;
    set_sprite_tile(2, 2);
    smiley.spriteIds[2] = 2;
    set_sprite_tile(3, 3);
    smiley.spriteIds[3] = 3;

    moveGameCharacter(&smiley, smiley.x, smiley.y);
}
void setupSpin()
{
    spin.x = 54;
    spin.y = 100;
    spin.width = 16;
    spin.height = 16;

    set_sprite_tile(4, 4);
    spin.spriteIds[0] = 4;
    set_sprite_tile(5, 5);
    spin.spriteIds[1] = 5;
    set_sprite_tile(6, 6);
    spin.spriteIds[2] = 6;
    set_sprite_tile(7, 7);
    spin.spriteIds[3] = 7;

    moveGameCharacter(&spin, spin.x, spin.y);
}

void main()
{
    set_sprite_data(0, 8, Sprites);
    // setupSmiley();
    setupSpin();
    SHOW_SPRITES;
    DISPLAY_ON;

    while(1)
    {
        switch(joypad())
        {
            case J_LEFT:
                spin.x -= speed;
                moveGameCharacter(&spin, spin.x, spin.y);
                break;
            case J_RIGHT:
                spin.x += speed;
                moveGameCharacter(&spin, spin.x, spin.y);
                break;
            case J_UP:
                spin.y -= speed;
                moveGameCharacter(&spin, spin.x, spin.y);
                break;
            case J_DOWN:
                spin.y += speed;
                moveGameCharacter(&spin, spin.x, spin.y);
                break;
        }
        perfomantDelay(5);
    }
}
