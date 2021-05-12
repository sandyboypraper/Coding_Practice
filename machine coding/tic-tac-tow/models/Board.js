export default class Board{
    constructor({dimenssion}){
        this.dimenssion = dimenssion;
        this.grid = [];
        for(let index = 0;index < this.dimenssion;index++)
        {
            let subArr = [];
            for(let index1 = 0;index1 < this.dimenssion;index1++)
            {
                subArr = [...subArr, '-'];
            }
            this.grid = [...this.grid, subArr];
        }
    }

    getGrid(){
        return this.grid;
    }

    setGrid(grid){
        this.grid = grid;
    }

    getDimenssion(){
        return this.dimenssion;
    }
}