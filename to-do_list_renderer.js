const readline = require('readline-sync');

let tasks=[
    {name:"Finishing upto DOM",completed:0},
    {name:"Finishing chemistry chapter 5",completed:0},
    {name:"Studying DLD",completed:0}
];

function showTasks(){
    console.log("To do List : ");
    for(i=0;i<tasks.length;i++){
        let status=(tasks[i].completed)?'Y':'N';
        console.log(`${i+1}. ${tasks[i].name} ${status}`);
    }
}

function markDone(input){
    if(input>=0&&input<tasks.length){
        tasks[input].completed=1;
        console.log(`Task ${input+1} is done!`);
    } else{
        console.log("Incorrect Input for Index Number");
    }
}

while(1){
    showTasks();
    let input=readline.question("Enter your Index Number for marking it as completed : ");
    if(input=='x'){
        console.log("Terminating from the to-do list renderer!");
        break;
    } else{
        input-=1;
        markDone(input);
        showTasks();
    }
}