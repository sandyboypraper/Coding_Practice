let createBoardInUI = function(){
    let board = document.getElementById("snake-and-ladder-board");
    let html = ``;
    for(let index = 0;index < 100;index ++)
    {
        if(index % 10 == 0)
            html += `<br/>`

        html += `
            <div id = "position-${index+1}" class = "position">${index+1}</div>
        `;
    }

    board.innerHTML = html;
}

let changeSelectedPlayerInUI = function(){
    // console.clear();
    document.getElementById("selected-player").innerHTML = "Selected Player - " + this.selectedPlayer.getName();
    if(this.selectedPlayer.getPosition() != 0)
    {
        document.getElementById("position-"+this.selectedPlayer.getPosition()).innerHTML = `${this.selectedPlayer.getPosition()} ${this.selectedPlayer.getName()}`
    }
}

let addWinnerInUI = function(){
    document.getElementById("winner").innerHTML = "Winner Is - " + this.winner.getName();
}

let clearPreviousState = function(){
    if(this.selectedPlayer && this.selectedPlayer.getPosition() != 0)
    {
        document.getElementById("position-"+this.selectedPlayer.getPosition()).innerHTML = `${this.selectedPlayer.getPosition()}`
    }
}

export {createBoardInUI, changeSelectedPlayerInUI, addWinnerInUI, clearPreviousState}