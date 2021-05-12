export default class Player{
    constructor({name, id, position}){
        this.name = name;
        this.id = id;
        this.position = position;
    }

    getName(){
        return this.name;
    }

    getPosition(){
        return this.position;
    }

    setPosition(position){
        this.position = position
    }
}