export default class Player{
    constructor({id, name, sign}){
        this.id = id
        this.name = name;
        this.sign = sign;
    }

    getId(){
        return this.id;
    }

    getName(){
        return this.name;
    }

    setName(name){
        this.name = name;
    }

    getSign(){
        return this.sign
    }

    setSign(sign){
        this.sign = sign;
    }
}