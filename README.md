# Chess Game with Pygame

This project is a basic implementation of a chess game using the Pygame library in Python. It includes a graphical interface for the board and pieces, and basic functionality for moving pieces according to the rules of chess.

## Requirements

- Python 3.6 or higher
- Pygame library

## Installation

1. **Clone the repository**:
   ```sh
   git clone https://github.com/yourusername/chess-game.git
   cd chess-game
2.	**Install Pygame**:   
   pip install pygame
3.	**Download the piece images**:
   Place the images for the chess pieces in a folder named images within the project directory. The images should be named in the format color_piece.png (e.g., white_pawn.png, black_rook.png).

## Running the Game

To run the game, execute the following command:
python main.py

## Code Structure

### Main Modules

- **main.py**: The main script to run the game.
- **Piece Classes**: Classes representing each type of chess piece (Pawn, Rook, Knight, Bishop, Queen, King), including methods for determining valid moves.
- **ChessBoard Class**: Manages the state of the board, piece positions, and turn-based gameplay.

### Constants

- **WIDTH**: Width of the game window (default 800 pixels).
- **HEIGHT**: Height of the game window (default 800 pixels).
- **ROWS, COLS**: Number of rows and columns in the chess board (default 8 each).
- **SQUARE_SIZE**: Size of each square on the board, calculated as WIDTH // COLS.

### Colors

- **WHITE**: RGB tuple for white color (255, 255, 255).
- **BLACK**: RGB tuple for black color (0, 0, 0).

### Functions

- **draw_board(win)**: Draws the chess board.
- **draw_pieces(win, board)**: Draws the pieces on the board based on their current positions.

### Classes

#### Piece

- **__init__(self, color)**: Initializes a piece with a color.
- **get_valid_moves(self, board, x, y)**: Returns a list of valid moves for the piece from the given position.

#### Pawn, Rook, Knight, Bishop, Queen, King

- Inherits from Piece class.
- **get_valid_moves(self, board, row, col)**: Implements piece-specific move logic.

#### ChessBoard

- **__init__(self)**: Initializes the board with pieces in their starting positions.
- **initialize_board(self)**: Sets up the initial board layout.
- **move_piece(self, start_row, start_col, end_row, end_col)**: Moves a piece if the move is valid.
- **is_valid_move(self, piece, start_row, start_col, end_row, end_col)**: Checks if a move is valid.
- **select_piece(self, row, col)**: Selects a piece to move.
- **move_selected_piece(self, row, col)**: Moves the selected piece to a new position.

## Game Flow

1. **Initialization**: The game window is created, and the board is initialized with pieces in their starting positions.
2. **Event Handling**: The game listens for user input, such as mouse clicks, to select and move pieces.
3. **Drawing**: The board and pieces are drawn on the screen.
4. **Game Loop**: The game runs in a loop, updating the display and handling events until the user quits.

## Future Improvements

- Implementing additional rules and constraints of chess (e.g., castling, en passant, check, checkmate).
- Adding a more sophisticated user interface.
- Implementing AI for single-player mode.
- Adding sound effects and animations.