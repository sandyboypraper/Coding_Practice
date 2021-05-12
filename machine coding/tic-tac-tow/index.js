import TicTacToeGameService from "./services/TicTacToeGameService.js";

let player1,player2;

function inputPlayers(){
    player1 = window.prompt("Enter first user name: ");
    player2 = window.prompt("Enter second user name: ");
}

inputPlayers();

let ticTacToeGameService = new TicTacToeGameService({
    players : [player1, player2],
    boardDimension : 3
})

function next(){
    ticTacToeGameService.nextStep();
}

document.getElementById("next-button").addEventListener('click', event => {
    next();
})


