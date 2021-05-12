import dfs from "./utils.js"

export default function TreeScanner(){
    let e1 = () => {
        for(let key in this.data){
            let childs = this.data[key].childs;
            let childs_set = new Set(childs);

            if(childs.length != childs_set.size)
                console.log('E2');
            
            if(childs_set.size > 2)
                console.log('E1');
        }
    }

    let e3 = () => {
        let visited = {};
        let number_of_roots = 0;
        for(let key in this.data)
        {
            if(!visited[key])
            {
                dfs.call(this,{
                    initialNodeId : key,
                    alreadyVisitedMap : visited,
                    cycleDetectedCallBack : () => {
                        console.log('E3');
                    }   
                })
                number_of_roots++;
            }
        }

        if(number_of_roots > 1)
            console.log('E4');
    }

    let e5 = () => {
        for(let key in this.data){
            let parents = this.data[key].parents;
            if((new Set(parents)).size > 1){
                console.log('E5')
                return;
            }
        }
    }

    e1();
    e3();
    e5();
}
