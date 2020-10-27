# PacMan

Because learning to make this is easier than learning to make
a [3D rendering engine](https://github.com/ASSERT-game/ASSERT_game2). But only by a small margin. Your results
may vary. A Pacman recreation implemented in C and the SDL2.0 graphics Library.

The game plays fast, as I heard the original arcade one does. Ghost move according the rules by the original game, I based it on [this](https://gameinternals.com/understanding-pac-man-ghost-behavior).
The crosshairs are the target tiles of each ghost. Lives are gained after a certain amount of pellets are consumed, the player starts out with 5 displayed in the lower left corner, also there is a special attack with spacebar that freezes the ghost in place, but be careful to not run into them! The ghost have different states, Chasing, Frightened and Scatter mode.

<br>
<img height="700" src="https://github.com/ASSERT-game/pac_man/blob/master/resources/cookie.gif" />
<br>

There is quite a bit more that I would like to add, see [TODO](https://github.com/ASSERT-game/pac_man/blob/master/TODO) file. Was fun to play, and constantly get beaten by my own creation.