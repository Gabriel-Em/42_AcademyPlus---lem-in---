# 42 Academy+Plus - lem-in

A 42 (school) project that required us to code an ant farm manager.

For more details regarding the project see 'lem-in - Subject(EN).pdf'

## How to use

Using a terminal from within the /lem-in directory:
- run `make` to generate the **lem-in** binary
- feed a map to the binary using `./lem-in < map`

The program will receive the data describing the ant farm in the following format:

```
number_of_ants
the_rooms
the_links
```

The ant farm is defined by the following links:

```
##start
1 23 3
2 16 7
#comment
3 16 3
4 16 5
5 9 3
6 1 5
7 4 8
##end
0 9 5
0-4
0-6
1-3
4-3
5-2
3-5
#another comment
4-2
2-1
7-6
7-2
7-4
6-5
```
Which coresponds to the following representation:

```
          _______________
         /               \
  ______[5]----[3]----[1] |
 /              |    /    |
[6]-----[0]----[4]  /     |
 \   __________/|  /      |
  \ /          [2]/______/
  [7]___________/
```

The goal of this project is to find the quickest way to get n ants across the farm.
  - Obviously, there are some basic constraints. To be the first to arrive, ants will need to take the shortest path (and that isn’t necessarily the simplest). They will also need to avoid traffic jams as well as walking all over their fellow ants.
  - At the beginning of the game, all the ants are in the room ##start. The goal is to bring them to the room ##end with as few turns as possible. Each room can only contain one ant at a time. (except at ##start and ##end which can contain as many ants as necessary.)
  - We consider that all the ants are in the room ##start at the beginning of the game.
  - At each turn you will only display the ants that moved.
  - At each turn you can move each ant only once and through a tube (the room at
the receiving end must be empty).

### Terminal output for above map:

- number_of_ants is 23
- L1-2 means ant with id 1 moves to room 2

```
L1-2 L2-3
L1-4 L2-5 L3-2 L4-3
L1-0 L2-6 L3-4 L4-5 L5-2 L6-3
L2-0 L3-0 L4-6 L5-4 L6-5 L7-2 L8-3
L4-0 L5-0 L6-6 L7-4 L8-5 L9-2 L10-3
L6-0 L7-0 L8-6 L9-4 L10-5 L11-2 L12-3
L8-0 L9-0 L10-6 L11-4 L12-5 L13-2 L14-3
L10-0 L11-0 L12-6 L13-4 L14-5 L15-2 L16-3
L12-0 L13-0 L14-6 L15-4 L16-5 L17-2 L18-3
L14-0 L15-0 L16-6 L17-4 L18-5 L19-2 L20-3
L16-0 L17-0 L18-6 L19-4 L20-5 L21-2 L22-3
L18-0 L19-0 L20-6 L21-4 L23-2
L20-0 L21-0 L22-4
L22-0 L23-4
L23-0
```