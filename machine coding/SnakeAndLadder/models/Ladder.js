export default class Ladder{
    constructor({start, end}){
        this.start = start;
        this.end = end;
    }

    getStart(){
        return this.start;
    }

    getEnd(){
        return this.end;
    }

    setStart(){
        this.start = start;
    }

    setEnd(){
        this.end = end;
    }
}