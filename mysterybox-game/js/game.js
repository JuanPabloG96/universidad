export function randomNumbers(board) {
  const availableNumbers = [1, 2, 3, 4];

  for (let i = 0; i < board.length; i++) {
    for (let j = 0; j < board[i].length; j++) {
      const randomIndex = Math.floor(Math.random() * availableNumbers.length);
      board[i][j] = availableNumbers.splice(randomIndex, 1)[0];
    }
  }
  return board
}
export function checkEnd(board, finalState) {
  for (let i = 0; i < board.length; i++) {
    for (let j = 0; j < board[i].length; j++) {
      if (board[i][j] !== finalState[i][j]) {
        return false;
      }
    }
  }

  return true;
}
export function renderBoard(board, game, square) {
  let index = 1;
  game.innerHTML = ''
  for (let i = 0; i < board.length; i++) {
    for (let j = 0; j < board[i].length; j++) {
      game.innerHTML += square(board[i][j], index)
      index++
    }
  }
  game.innerHTML += square('', index)
}

export async function updateBoard(counter, board, finalState, game, square) {
  while (!checkEnd(board, finalState)) {
    randomNumbers(board);
    renderBoard(board, game, square);
    await new Promise(resolve => setTimeout(resolve, 200));
    counter++;
  }
  return counter
}