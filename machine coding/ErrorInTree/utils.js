export default function dfs({initialNodeId, alreadyVisitedMap, cycleDetectedCallBack}){
    alreadyVisitedMap[initialNodeId] = true;
    for(let index in this.data[initialNodeId].childs)
    {
        let child = this.data[initialNodeId].childs[index];
        if(alreadyVisitedMap[child]) 
           {
            cycleDetectedCallBack();
             return;
           }
        else 
            dfs.call(this,{
                initialNodeId : child,
                alreadyVisitedMap,
                cycleDetectedCallBack
            });
    }
}