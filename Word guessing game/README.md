## Objective
The goal of the game is to a word whose letters have been mixed.


## Prerequisites

- Strings
- Vectors
- Files manipulation
- Conditional statements and iterations
- Functions and modular programming


## Structure

A word randomly selected from a word dictionary and whose letters have been mixed up is displayed on the screen.
The player is then given 5 chances to guess which word it is. 

**Example** : The word `PLANET` can be displayed as `NPTEAL`

### Rules
- If the player enters the wright word, a congratulatory message is displayed on the screen.
- If the player enters a wrong word, the number of chances is decreased by one (1). 
- If the number of chances reaches zero (0), the player loses the game.

At the end, the player is prompted to start a new game or exit the game.

- The game is restarted (*and a new word selected*) as long as the player chooses to start a new game.
- If the player chooses to exit the game, the average score of all of the played games is displayed on the screen.

**Note** : The player does not have to worry about case sensitivity when entering the word. (*See sample output*)


## Adding words to the dictionary

The dictionary of words is a file that contains several words from which one will be randomly picked.

To add a word to the dictionary, the following rules must be respected :

- The file should contain a single word on each line.
- All the words in the dictionary must be capitalized (written in capital letters).
- There must be one (1) empty line at the end of the file.

```
MORNING
XYLOPHONE
CHAMPIONSHIP

```


## Sample output
![output](https://i.ibb.co/h8pDS2p/wgg-cpp-img.png)
