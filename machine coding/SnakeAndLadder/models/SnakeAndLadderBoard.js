export default class SnakeAndLadderBoard{
    constructor({snakes, ladders, players}){
        this.snakes = snakes;
        this.ladders = ladders;
        this.players = players;
    }

    getPlayers(){
        return this.players;
    }

    getLadders(){
        return this.ladders;
    }

    getSnakes(){
        return this.snakes;
    }
}