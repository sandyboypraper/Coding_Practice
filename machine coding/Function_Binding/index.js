class A{
    constructor(name){
        this.name = name;
    }

    printName(){
        console.log(this.name);
    }
}

let a = new A("Sandeep");
a.printName();

setTimeout(a.printName, 1000);
//it is like let f = a.printName | setTimeout(f,1000);

setTimeout(() => {
    a.printName();
},1000) 

let f = a.printName.bind(a);
setTimeout(f,1000)

a = {
    name : "gagan",
    printName : function(){
        console.log(this.name);
    }
}
