const readline = require('readline-sync');

let books=[
    {Name : "The House of the Spirits", Author : "Isabel Allende", isAvailable : 1},
    {Name : "The Stranger", Author : "Albert Camus", isAvailable : 0},
    {Name : "Kafka on the Shore", Author : "Haruki Murakami", isAvailable : 1},
    {Name : "The Shadow Lines", Author : "Amitav Ghosh", isAvailable : 1},
    {Name : "One Hundred Years of Solitude", Author : "Gabriel García Márquez", isAvailable : 1}
];

books.push({
    Name : "Snow Country", Author : "Yasunari Kawabata", isAvailable : 1
});

function showStatus(){
    console.log("Current Collection of the Library and Status : \n");
    for(let i=0;i<books.length;i++){
    let bookName=books[i].Name;
    let authorName=books[i].Author;
    let status=(books[i].isAvailable)?"Available":"Not Available";
    console.log(`${i+1}. ${bookName},${authorName},${status}`);
    }
}

function buyBook(bookIndex){
    if(bookIndex>=0&&bookIndex<books.length){
        books[bookIndex].isAvailable=0;
        setTimeout(()=>{
            console.log(`You have bought ${books[bookIndex].Name}, written by ${books[bookIndex].Author}!`);
        },2000);
    } else{
        console.log("Index of this book currently does not match with our library catalogue! Please Try again.");
    }
}

while(1){
    let bookIndex=readline.question("Enter the Index of Your Desired Book : (N.B : Press x to terminate from here!)");

    if(bookIndex=='x'){
        setTimeout(()=>{
            console.log("Terminating from the program. Thanks for Visiting us!")
        },1000);
        break;
    }
    else {
        let bookIn=parseInt(bookIndex); 
        if(isNaN(bookIndex)){
            console.log("Invalid input! Please enter a valid number.");
            continue;
        }
        bookIn-=1;
        buyBook(bookIn);
        showStatus();
    }
}
