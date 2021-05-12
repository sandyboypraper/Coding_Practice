import SnakeAndLadderBoard from "../models/SnakeAndLadderBoard.js"
import {createBoardInUI, changeSelectedPlayerInUI, addWinnerInUI, clearPreviousState} from "./UIService.js";

import Snake from "../models/Snake.js";
import Ladder from "../models/Ladder.js";
import Player from "../models/Player.js";

export default class SnakeAndLadderBoardService{
    constructor({snakes, players, ladders}){
        this.snakeAndLadderBoard = new SnakeAndLadderBoard({
            snakes,
            players,
            ladders
        });

        this.winner = null;
        this.selectedPlayer = null;
        this.diceValue = null;

        createBoardInUI.call(this);
    }

    chooseNextPlayer(){
        let players = this.snakeAndLadderBoard.getPlayers();
        if(this.selectedPlayer == null)
            this.selectedPlayer = players[0];
        else{
            let selectedIndex = 0;
            for(let index = 0;index < players.length;index++)
            {
                if(players[index].id == this.selectedPlayer.id)
                {
                    selectedIndex = index;
                    break;
                }
            }

            if(selectedIndex == players.length - 1)
                this.selectedPlayer = players[0];
            else    
                this.selectedPlayer = players[selectedIndex + 1];
        }

        changeSelectedPlayerInUI.call(this);
    }

    diceRolled(){
        this.diceValue = Math.floor((Math.random()*10)%6 + 1);
    }

    checkForWinner(position){
        if(position == 100)
        {
            this.winner = this.selectedPlayer;
            addWinnerInUI.call(this);
        }

        return position;
    }

    findFinalPosition(position, diceValue){
        let finalPosition = position + diceValue;
        if(finalPosition > 100)
            return position;

        let ladders = this.snakeAndLadderBoard.getLadders();
        let snakes = this.snakeAndLadderBoard.getSnakes();

        for(let index in ladders){
            if(ladders[index].getStart() == finalPosition)
            {
                return this.checkForWinner(ladders[index].getEnd());
            }
        }

        for(let index in snakes){
            if(snakes[index].getStart() == finalPosition)
            {
                return this.checkForWinner(snakes[index].getEnd());
            }
        }

        return this.checkForWinner(finalPosition);
    }

    changePos(){
        this.selectedPlayer.setPosition(this.findFinalPosition(this.selectedPlayer.getPosition(), this.diceValue));
    }

    startGame(){

        let gameTimeLine = setInterval(() => {
            clearPreviousState.call(this);

            this.chooseNextPlayer();
            this.diceRolled();
            this.changePos();

            console.log(`${this.selectedPlayer.getName()} rolled the dice and get ${this.diceValue} then he/she moved to ${this.selectedPlayer.getPosition()}`);

            if(this.winner != null)
            {
                clearInterval(gameTimeLine);
            }

        },1000)  
    }
}