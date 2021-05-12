import Player from "../models/Player.js";
import Board from "../models/Board.js";

export default class TicTacToeGameService{
    constructor({players, boardDimension}){
        this.players = [];
        for(let index in players){
            let player = new Player({
                name : players[index],
                id : Math.floor(Math.random() * 10000),
                sign : (index == 0) ? 'X' : 'O'
            })

            this.players = [...this.players, player]
        }

        this.board = new Board({dimenssion : boardDimension});
        this.selectedPlayer = null;
        this.inputRow = null;
        this.inputCol = null;
        this.isGameEnd = false;

        this.printGrid();
    }


    printGrid(){
        let grid = document.getElementById("grid");
        let html = ``;
        for(let index = 0;index < this.board.getDimenssion(); index++)
        {
            for(let index1 = 0;index1 < this.board.getDimenssion(); index1++)
                html += `<span class = "grid-cell">${this.board.getGrid()[index][index1]}</span>`

            html += `<br/>`;
        }

        grid.innerHTML = html

        //then add eventListner to every grid-cell

        return true;
    }

    selectNextPlayer(){
        if(this.selectedPlayer == null)
            this.selectedPlayer = this.players[0];

        else this.selectedPlayer = this.players.filter(item => item.getId() != this.selectedPlayer.getId())[0];
    }

    getInput(){
        let inputRowCol = document.getElementById("row-col-input").value;
        this.inputRow = inputRowCol.split(" ")[0] - 1;
        this.inputCol = inputRowCol.split(" ")[1] - 1;
        document.getElementById("row-col-input").value = ""
    }

    checkIfGameEnds(){
        let lastRow = this.inputRow;
        let lastCol = this.inputCol;
        let selectedPlayerSign = this.selectedPlayer.getSign();
        let grid = this.board.getGrid();
        let dimenssion = this.board.getDimenssion();
        let index = 0;

        for(index = 0;index < dimenssion;index++)
        {
            if(grid[lastRow][index] != selectedPlayerSign)
            {
                break;
            }
        }
        if(index == dimenssion)
            {
                this.isGameEnd = true;
                return;
            }

        for(index = 0;index < dimenssion;index++)
        {
            if(grid[index][lastCol] != selectedPlayerSign)
            {
                break;
            }
        }    
        if(index == dimenssion)
            {
                this.isGameEnd = true;
                return;
            }
            
        if(lastCol == lastRow)
        {
            for(index = 0;index < dimenssion;index++)
            {
               if(grid[index][index] != selectedPlayerSign)
                {
                    break;
                }   
            } 
            if(index == dimenssion)
            {
                this.isGameEnd = true;
                return;
            }
        }

        if(lastCol + lastRow == dimenssion - 1)
        {
            for(index = 0;index < dimenssion;index++)
            {
               if(grid[index][dimenssion - index - 1] != selectedPlayerSign)
                {
                    break;
                }   
            } 
            if(index == dimenssion)
            {
                this.isGameEnd = true;
                return;
            }
        }
    }

    updateGrid(){
        let previousGrid = this.board.getGrid();
        console.log(previousGrid[this.inputRow]);
        previousGrid[this.inputRow][this.inputCol] = this.selectedPlayer.getSign();
        this.checkIfGameEnds();
        this.printGrid();
    }

    nextStep(){
        //while game end;
        //choose next player;
        //Get Values;
        //Update Grid
        console.log("sasas");
        this.selectNextPlayer();
        this.getInput();
        this.updateGrid();

        if(this.isGameEnd)
        {   
            alert(`${this.selectedPlayer.getName()} wins the game..`)
            return;
        }
    }
}