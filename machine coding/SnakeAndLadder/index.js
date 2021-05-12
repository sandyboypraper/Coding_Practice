import inputData from "./inputdata.js";

import Snake from "./models/Snake.js";
import Player from "./models/Player.js";
import Ladder from "./models/Ladder.js";

import SnakeAndLadderBoardService from "./services/SnakeAndLadderBoardService.js";

console.log("game started...")

const {snakes, players, ladders} = inputData;

let snakeObjects = [];
let ladderObjects = [];
let playreObjects = [];

for(let snakeIndex = 0; snakeIndex < snakes.length; snakeIndex++){
    let snake = new Snake({
        start : snakes[snakeIndex].start,
        end : snakes[snakeIndex].end
    })
    snakeObjects.push(snake);
}

for(let playerIndex = 0; playerIndex < players.length; playerIndex++)
{
    let player = new Player({
        id : Math.ceil(Math.random() * 10000),
        name : players[playerIndex].name,
        position : 0
    })
    playreObjects.push(player);
}

for(let ladderIndex = 0; ladderIndex < players.length; ladderIndex++)
{
    let ladder = new Ladder({
        start : ladders[ladderIndex].start,
        end : ladders[ladderIndex].end
    })
    ladderObjects.push(ladder);
}

let snakeAndLadderBoardService = new SnakeAndLadderBoardService({
    snakes : snakeObjects,
    ladders : ladderObjects,
    players : playreObjects
});

console.log("game started...");
snakeAndLadderBoardService.startGame();


