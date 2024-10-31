type Player = 'X' | 'O';

class TicTacToe {
    private board: (Player | null)[][];
    private currentPlayer: Player;
    private gameBoard: HTMLElement;
    private resetButton: HTMLElement;
    private gameOver: boolean;

    constructor() {
        this.board = [
            [null, null, null],
            [null, null, null],
            [null, null, null]
        ];
        this.currentPlayer = 'X';
        this.gameOver = false;

        this.gameBoard = document.getElementById("game-board")!;
        this.resetButton = document.getElementById("reset-button")!;

        this.initializeGame();
    }

    initializeGame() {
        this.gameBoard.innerHTML = ''; // Clear previous cells
        this.board = this.board.map(row => row.map(() => null)); // Reset board
        this.gameOver = false;

        // Create cells for the game board
        for (let row = 0; row < 3; row++) {
            for (let col = 0; col < 3; col++) {
                const cell = document.createElement("div");
                cell.classList.add("cell");
                cell.addEventListener("click", () => this.handleCellClick(row, col));
                this.gameBoard.appendChild(cell);
            }
        }

        // Reset button
        this.resetButton.addEventListener("click", () => this.initializeGame());
    }

    handleCellClick(row: number, col: number) {
        if (this.board[row][col] || this.gameOver) return; // Ignore if cell is already occupied or game over

        this.board[row][col] = this.currentPlayer;
        this.updateBoard();
        
        if (this.checkWin(row, col)) {
            alert(`${this.currentPlayer} wins!`);
            this.gameOver = true;
        } else if (this.checkDraw()) {
            alert("It's a draw!");
            this.gameOver = true;
        } else {
            this.currentPlayer = this.currentPlayer === 'X' ? 'O' : 'X';
        }
    }

    updateBoard() {
        const cells = this.gameBoard.getElementsByClassName("cell");
        for (let i = 0; i < cells.length; i++) {
            const row = Math.floor(i / 3);
            const col = i % 3;
            cells[i].textContent = this.board[row][col];
        }
    }

    checkWin(row: number, col: number): boolean {
        const player = this.board[row][col];
        if (!player) return false;

        // Check row, column, and diagonals
        return (
            this.board[row].every(cell => cell === player) ||
            this.board.every(r => r[col] === player) ||
            (row === col && this.board.every((_, i) => this.board[i][i] === player)) ||
            (row + col === 2 && this.board.every((_, i) => this.board[i][2 - i] === player))
        );
    }

    checkDraw(): boolean {
        return this.board.every(row => row.every(cell => cell !== null));
    }
}

// Initialize the game
document.addEventListener("DOMContentLoaded", () => {
    new TicTacToe();
});
