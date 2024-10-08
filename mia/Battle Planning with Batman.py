import pygame
import os

pygame.init()

# Constants
WIDTH, HEIGHT = 800, 800
ROWS, COLS = 8, 8
SQUARE_SIZE = WIDTH // COLS

# Colors
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)

WIN = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption('Chess')

# Placeholder for piece images
PIECE_IMAGES = {}
PIECE_TYPES = ['pawn', 'rook', 'knight', 'bishop', 'queen', 'king']
PIECE_COLORS = ['white', 'black']

for color in PIECE_COLORS:
    for piece in PIECE_TYPES:
        try:
            PIECE_IMAGES[(color, piece)] = pygame.image.load(os.path.join('images', '{}_{}.png'.format(color, piece)))
            PIECE_IMAGES[(color, piece)] = pygame.transform.scale(PIECE_IMAGES[(color, piece)], (SQUARE_SIZE, SQUARE_SIZE))
        except pygame.error:
            PIECE_IMAGES[(color, piece)] = pygame.Surface((SQUARE_SIZE, SQUARE_SIZE))
            PIECE_IMAGES[(color, piece)].fill(WHITE if color == 'white' else BLACK)

def draw_board(win):
    win.fill(WHITE)
    for row in range(ROWS):
        for col in range(COLS):
            if (row + col) % 2 == 1:
                pygame.draw.rect(win, BLACK, (col * SQUARE_SIZE, row * SQUARE_SIZE, SQUARE_SIZE, SQUARE_SIZE))

def draw_pieces(win, board):
    for row in range(ROWS):
        for col in range(COLS):
            piece = board.board[row][col]
            if piece:
                image = PIECE_IMAGES[(piece.color, type(piece).__name__.lower())]
                rect = image.get_rect(center=(col * SQUARE_SIZE + SQUARE_SIZE // 2, row * SQUARE_SIZE + SQUARE_SIZE // 2))
                win.blit(image, rect)

class Piece:
    def __init__(self, color):
        self.color = color

    def get_valid_moves(self, board, x, y):
        pass

class Pawn(Piece):
    def get_valid_moves(self, board, row, col):
        moves = []
        direction = 1 if self.color == 'white' else -1
        if row + direction in range(ROWS) and board[row + direction][col] is None:
            moves.append((row + direction, col))
        if (row == 6 and self.color == 'white') or (row == 1 and self.color == 'black'):
            if board[row + 2 * direction][col] is None and board[row + direction][col] is None:
                moves.append((row + 2 * direction, col))
        for dc in [-1, 1]:
            if col + dc in range(COLS) and board[row + direction][col + dc] and board[row + direction][col + dc].color != self.color:
                moves.append((row + direction, col + dc))
        return moves

class Rook(Piece):
    def get_valid_moves(self, board, row, col):
        moves = []
        directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        for dr, dc in directions:
            r, c = row + dr, col + dc
            while 0 <= r < ROWS and 0 <= c < COLS:
                if board[r][c] is None:
                    moves.append((r, c))
                elif board[r][c].color != self.color:
                    moves.append((r, c))
                    break
                else:
                    break
                r += dr
                c += dc
        return moves

class Knight(Piece):
    def get_valid_moves(self, board, row, col):
        moves = []
        deltas = [(2, 1), (2, -1), (-2, 1), (-2, -1), (1, 2), (1, -2), (-1, 2), (-1, -2)]
        for dr, dc in deltas:
            r, c = row + dr, col + dc
            if 0 <= r < ROWS and 0 <= c < COLS and (board[r][c] is None or board[r][c].color != self.color):
                moves.append((r, c))
        return moves

class Bishop(Piece):
    def get_valid_moves(self, board, row, col):
        moves = []
        directions = [(1, 1), (1, -1), (-1, 1), (-1, -1)]
        for dr, dc in directions:
            r, c = row + dr, col + dc
            while 0 <= r < ROWS and 0 <= c < COLS:
                if board[r][c] is None:
                    moves.append((r, c))
                elif board[r][c].color != self.color:
                    moves.append((r, c))
                    break
                else:
                    break
                r += dr
                c += dc
        return moves

class Queen(Piece):
    def get_valid_moves(self, board, row, col):
        moves = Rook.get_valid_moves(self, board, row, col) + Bishop.get_valid_moves(self, board, row, col)
        return moves

class King(Piece):
    def get_valid_moves(self, board, row, col):
        moves = []
        deltas = [(1, 0), (-1, 0), (0, 1), (0, -1), (1, 1), (1, -1), (-1, 1), (-1, -1)]
        for dr, dc in deltas:
            r, c = row + dr, col + dc
            if 0 <= r < ROWS and 0 <= c < COLS and (board[r][c] is None or board[r][c].color != self.color):
                moves.append((r, c))
        return moves

class ChessBoard:
    def __init__(self):
        self.board = self.initialize_board()
        self.white_king = None
        self.black_king = None
        self.current_turn = 'white'
        self.selected_piece = None

    def initialize_board(self):
        board = [[None for _ in range(COLS)] for _ in range(ROWS)]
        pieces = ['Rook', 'Knight', 'Bishop', 'Queen', 'King', 'Bishop', 'Knight', 'Rook']
        for col in range(COLS):
            board[0][col] = globals()[pieces[col]]('black')
            board[7][col] = globals()[pieces[col]]('white')
            board[1][col] = Pawn('black')
            board[6][col] = Pawn('white')
        self.white_king = board[7][4]
        self.black_king = board[0][4]
        return board

    def move_piece(self, start_row, start_col, end_row, end_col):
        piece = self.board[start_row][start_col]
        if piece and self.is_valid_move(piece, start_row, start_col, end_row, end_col):
            self.board[start_row][start_col] = None
            self.board[end_row][end_col] = piece
            self.current_turn = 'white' if self.current_turn == 'black' else 'black'
            return True
        return False

    def is_valid_move(self, piece, start_row, start_col, end_row, end_col):
        if end_row < 0 or end_row >= ROWS or end_col < 0 or end_col >= COLS:
            return False
        if self.board[end_row][end_col] and self.board[end_row][end_col].color == piece.color:
            return False
        valid_moves = piece.get_valid_moves(self.board, start_row, start_col)
        return (end_row, end_col) in valid_moves

    def select_piece(self, row, col):
        if self.board[row][col] and self.board[row][col].color == self.current_turn:
            self.selected_piece = (row, col)

    def move_selected_piece(self, row, col):
        if self.selected_piece:
            start_row, start_col = self.selected_piece
            if self.move_piece(start_row, start_col, row, col):
                self.selected_piece = None

def main():
    run = True
    clock = pygame.time.Clock()
    board = ChessBoard()

    while run:
        clock.tick(60)
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                run = False
            elif event.type == pygame.MOUSEBUTTONDOWN:
                pos = pygame.mouse.get_pos()
                row, col = pos[1] // SQUARE_SIZE, pos[0] // SQUARE_SIZE
                if board.selected_piece:
                    board.move_selected_piece(row, col)
                else:
                    board.select_piece(row, col)
        draw_board(WIN)
        draw_pieces(WIN, board)
        pygame.display.update()
    pygame.quit()
if __name__ == "__main__":
    main()