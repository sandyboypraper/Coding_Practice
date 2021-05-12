export default class User{
    constructor(){
        this.name = "sandeep",
        this.surname = "sharma"
    }

    get fullName(){
        return this.name + " " + this.surname;
    }
}