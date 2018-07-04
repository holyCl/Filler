# Filler
A bot that can fight another bots in popular (or not) game Filler

### The world famous (or infamous) board Filler

## SHORT INTRODUCTION:

The aim of this project is to create a bot which will fight other bots in the popular (or not) game Filler.

The rules are very simple. There is Virtual Machine (VM) wich takes 3 parameters: two bots and a board.
At the beginning of the game VM gives (via stdin) map with 2 dots on it - 'O' and 'X' in accordance for first and second players.
Also it gives random figure which must be placed on the board.

First bot reads the map, analyzes it and gives back the coordinates of next step.

Then VM try to put figure on the board. If it was valid coordinates second bot take updated map and another figure to make next move.
Then it continues again and again.

The game ends when the figure cannot be placed anymore.
So, if one bot gave invalid coordinates another will play until it finds free space on the map.

Every time bot place figure it earns 1 point.
The winner is the one who scored more points.

You can find full description in subject [filler.en.pdf](filler.en.pdf) file.

## HOW TO LAUNCH AND TEST:

First clone git repository (type in console):
```

git clone https://github.com/holyCl/filler.git filler

```

Than go to the project folder and launch:
```

cd filler

make

make bonus

./resources/filler_vm -f resources/maps/map01 -p1 ./ivoloshi.filler -p2 ./resources/players/carli.filler | ./visual.c

```

You can change map from resources/maps/(map00, map01, map02), opponent bot from /resources/players or you can fight my bot against your own.

GOOD FIGHT
