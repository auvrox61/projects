const readline=require('readline-sync');

console.log("Press R,P,S respectively for Rock,Paper and Scissor.Press x for ejection from the game. First to 5 points win the game!");


let playerScore=0;
let compScore=0;

while(1){
    if(playerScore==5){
        console.log("Congratulations! You have won the game!");
        break;
    }

    if(compScore==5){
        console.log("You Lose :((");
        break;
    }

    if((playerScore==5)&&(compScore==5)){
        console.log("Match Tied!");
        break;
    }

    let playerMove=readline.question("Enter your move : ");

    if(playerMove=='x'){
        console.log("Ejecting from the game! Thanks for playing.");
        break;
    }

    let compResponse=Math.floor(Math.random()*3);

    let compMove;

    if(compResponse==0){
        compMove="R";
    } else if(compResponse==1){
        compMove="P";
    } else{
        compMove="S";
    }

    if((playerMove=='R'&&compMove=='R')||(playerMove=='P'&&compMove=='P')||(playerMove=='S'&&compMove=='S')){
        playerScore++;
        compScore++;
        console.log("Player : ",`${playerScore}`);
        console.log("Computer : ",`${compScore}`);
    } else if((playerMove=='R'&&compMove=='S')||(playerMove=='P'&&compMove=='R')||(playerMove=='S'&&compMove=='P')){
        playerScore++;
        console.log("Player : ",`${playerScore}`);
        console.log("Computer : ",`${compScore}`);
    } else{
        compScore++;
        console.log("Player : ",`${playerScore}`);
        console.log("Computer : ",`${compScore}`);
    }
}