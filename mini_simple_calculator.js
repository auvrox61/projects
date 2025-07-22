const readline=require('readline-sync');

console.log("This is a mini calculator. Press x to eject from the program");

while(1){
    let operation=readline.question("Enter the operation that you wanna perform : ");

    if(operation=='x'){
        console.log("Terminating from the program.Thanks for using me!");
        break;
    }

    let a=parseFloat(readline.question("Enter your first number :"));
    let b=parseFloat(readline.question("Enter your second number :"));

    switch(operation){
        case '+':
            console.log(`${a+b}`);
            break;
        case '-':
            console.log(`${a-b}`);
            break;
        case '*':
            console.log(`${a*b}`);
            break;
        case '/':
            if(b==0){
                console.log("Math Error!");
                break;
            } else{
                console.log(`${a/b}`);
                break;
            }
        default:
            console.log("Check your syntax and try again!");
            break;
    }
}