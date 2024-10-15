import { renderBoard, updateBoard } from "./js/game.js";
import { board, initialState, finalState, info, square } from "./js/const.js";

const game = document.querySelector('.game');
const modal = document.querySelector('.modal')
const modalBtn = document.getElementById('modal-btn');
const boxes = document.querySelectorAll('.box');
const startBtn = document.querySelector('.start-btn');
const restartBtn = document.querySelector('.restart-btn');
const results = document.querySelector('.text-content');
const historyBtn = document.querySelector('.history-btn');
const clearBtn = document.querySelector('.clear-btn');

let counter = 0;

let data = []

function initializeState() {
  let modalCounter = 1
  boxes.forEach(box => {
    box.addEventListener('click', () => {
      if (modalCounter > 4) modalCounter = 1;
      if (box.textContent == '') {
        box.textContent = modalCounter;
        modalCounter++
        console.log(modalCounter)
      }
    })
  })
}
function checkValid(boxes) {
  const boxArray = Array.from(boxes);
  return boxArray.some(box => box.textContent === '');
}


renderBoard(board, game, square)
initializeState();

modalBtn.addEventListener('click', () => {
  if (!checkValid(boxes)) {
    boxes.forEach((box, index) => {
      const row = Math.floor(index / 2);
      const column = index % 2;
      board[row][column] = box.textContent;
      initialState[row][column] = box.textContent;
    })
    modal.classList.add('hidden')
    renderBoard(board, game, square)
  }
})

startBtn.addEventListener('click', () => {
  updateBoard(counter, board, finalState, game, square).then(result => {
    results.innerHTML = info(initialState, result);
    const initialStateCopy = JSON.parse(JSON.stringify(initialState)); // Copia de initialState
    data.push({ "initialState": initialStateCopy, "repetitions": result });
    localStorage.setItem('data', JSON.stringify(data));
  })
})

restartBtn.addEventListener('click', () => {
  counter = 0;
  for (let i = 0; i < board.length; i++) {
    for (let j = 0; j < board[i].length; j++) {
      board[i][j] = '';
      initialState[i][j] = '';
    }
  }
  boxes.forEach(box => {
    box.textContent = '';
  })
  modal.classList.toggle('hidden');
})

historyBtn.addEventListener('click', () => {
  let historyContent = '';
  data.forEach(dataItem => {
    historyContent += info(dataItem?.initialState, dataItem?.repetitions);
  });
  results.innerHTML = historyContent;
});

clearBtn.addEventListener('click', () => {
  localStorage.clear();
  results.innerHTML = '';
})

document.addEventListener('DOMContentLoaded', () => {
  const storedData = localStorage.getItem('data');
  if (storedData) {
    data = JSON.parse(storedData);
    console.log('Recover data:', data);
  } else {
    console.log('No data found in cache');
  }
});