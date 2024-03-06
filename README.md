The program contains one main class called tictactoe in a separate header file which is included
using #include <tictactoe.h> which has a default constructor, and 3 functions, the first is displayBoard
which displays the 3x3 grid for the player to choose from, the second is the getMove function which takes
the players input and checks if its a valid loop by converting the string to a char and checking. If valid it
moves on to the next line of code, if incorrect it prompts the user to correct their choice. Next is the
playGame function which simply places the entire game in a loop which allows players to play multiple
games after the other. We also have Private data members which are the board size, mxMoves so that the
game does not continue after 9 moves, and a minimum moves required for the program to even begin
checking if the player won or not. Then we have a multidimensional array of type char that acts as the 3x3
grid. Bool cWins uses the players input after the minimum 5 moves to check each square to see if a player
has won. cDraw checks to see if the maximum of 9 moves have been played by either player and states if
there is a draw or not. Fboard creates the initial blank spaces for the 3x3 grid and tPlayer uses the
conditional operator to toggle between 1st and 2nd player. The main function is simply going to initialize
the playGame function which is going to initialize all previous functions and take the 1st player’s input.
