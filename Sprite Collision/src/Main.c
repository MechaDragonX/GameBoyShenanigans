#include <gb/gb.h>
#include <stdio.h>
#include "src/GameCharacter.c"
#include "src/SpriteTiles.c"

GameCharacter spin;
GameCharacter fire;
UBYTE spriteSize = 8;
UINT8 speed = 5;

void perfomantDelay(UINT8 loops)
{
    UINT8 i;
    for(i = 0; i < loops; i++)
        wait_vbl_done();
}
UBYTE checkCollision(GameCharacter* one, GameCharacter* two)
{
    return (one->x >= two->x && one->x <= two->x + two->width) && (one->y >= two->y && one->y <= two->y + two->height) ||
    (two->x >= one->x && two->x <= one->x + one->width) && (two->y >= one->y && two->y <= one->y + one->height);
}
void moveGameCharacter(GameCharacter* character, UINT8 x, UINT8 y)
{
    move_sprite(character->spriteIds[0], x, y);
    move_sprite(character->spriteIds[1], x + spriteSize, y);
    move_sprite(character->spriteIds[2], x, y + spriteSize);
    move_sprite(character->spriteIds[3], x + spriteSize, y + spriteSize);
}
void setupSpin()
{
    spin.x = 80;
    spin.y = 130;
    spin.width = 16;
    spin.height = 16;

    set_sprite_tile(0, 0);
    spin.spriteIds[0] = 0;
    set_sprite_tile(1, 1);
    spin.spriteIds[1] = 1;
    set_sprite_tile(2, 2);
    spin.spriteIds[2] = 2;
    set_sprite_tile(3, 3);
    spin.spriteIds[3] = 3;

    moveGameCharacter(&spin, spin.x, spin.y);
}
void setupFire()
{
    if(spin.x == 0)
        fire.x = 30;
    else
        fire.x = spin.x;
    fire.y = 0;
    fire.width = 16;
    fire.height = 16;

    set_sprite_tile(4, 4);
    fire.spriteIds[0] = 4;
    set_sprite_tile(5, 5);
    fire.spriteIds[1] = 5;
    set_sprite_tile(6, 6);
    fire.spriteIds[2] = 6;
    set_sprite_tile(7, 7);
    fire.spriteIds[3] = 7;

    moveGameCharacter(&fire, fire.x, fire.y);
}
void setupSprites()
{
    setupSpin();
    setupFire();
}

void main()
{
    set_sprite_data(0, 8, Sprites);
    setupSprites();
    SHOW_SPRITES;
    DISPLAY_ON;

    while(!checkCollision(&spin, &fire))
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

        fire.y += 5;
        if(fire.y >= 144)
        {
            fire.y = 0;
            fire.x = spin.x;
        }
        moveGameCharacter(&fire, fire.x, fire.y);

        perfomantDelay(5);
    }
    printf("\n \n \n \n \n \n \n \n \n === GAME OVER ===");
}
