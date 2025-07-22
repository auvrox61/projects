const readline=require('readline-sync');

let groceryPrice=parseFloat(readline.question("Enter The amount spent on buying groceries : "));
let foodPrice=parseFloat(readline.question("Enter The amount spent on buying foods : "));
let medPrice=parseFloat(readline.question("Enter The amount spent on buying medicines : "));

let couponNum=Math.floor(Math.random()*101);
let couponwin=0;

let count=0;

while(1){
    let guess=parseInt(readline.question("Guess the 3 digit (Max) coupon code and see if u can get 10% discount : (You have max 3 chances,Guess any number from 0 to 100)"));

    if(couponNum-guess>10){
        console.log("Try Again!");
        count++;
    }
    if(couponNum-guess<=10&&((count<3))){
        console.log("Congratulations on winning 10% discount!");
        couponwin=1;
        break;
    }
    if(count==3){
        console.log("Unlucky!");
        break;
    }
}

let total=groceryPrice+foodPrice+medPrice;
let disTotal=total-(total*0.1);

if(couponwin){
    console.log("Original Total : ",`${total}`);
    console.log("Discount Applied : 10%");
    console.log("Grand Total : ",`${disTotal}`);
} else{
    console.log("Original Total : ",`${total}`);
    console.log("Discount Applied : 0%");
    console.log("Grand Total : ",`${total}`);
}

