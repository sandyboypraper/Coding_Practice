obj1 = {
    name : "sandeep"
}

const printName = {
    printname(){
        console.log(this);
        console.log(this.name);
    }
}

Object.assign(obj1, printName);
obj1.printname()