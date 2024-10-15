export const board = [
  ["", ""],
  ["", ""]
]
export const initialState = [
  ["", ""],
  ["", ""]
]
export const finalState = [
  [1, 2],
  [3, 4]
]
export const square = (num, index) => {
  return `<div class="square square-${index}">${num}</div>`
}

export const info = (inicialState, repetitions) => {
  console.log(inicialState)
  return `<div class="info-container">
  <span class="inicial-state">Inicial state: [${inicialState}]</span>
  <p class="repetitions">Number of repetitions: ${repetitions}</p>
</div>`
}