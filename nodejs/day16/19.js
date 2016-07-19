/**
 * Created by KICT-10 on 2016-07-19.
 */

const net = require('net');
const PORT = 8080;

let solution;
let Solved = false;
solution = Math.round(Math.random() * 100)

console.log(solution);

net.createServer((socket)=>{
    console.log('connect :' + socket.remoteAddress + ':'
    + socket.remotePort
});

socket.on('error',(evt)=>{
    console.log(evt);
});
socket.on('close',()=> {
    console.log('connection closed');
    console.log(evt);
});
socket.on('data',(evt)=>{
    let data = JSON.parse(evt.toString());
    if(Solved == false) {
    console.log(data.name + "try game")
    let resultObj = {};
    if(data.value > solution) {
        resultObj.txt = "high";
    }
    else if(data.value < solution) {
        resultObj.txt = "low";
    }
    else {
        resultObj.txt = "bingo"
        Solved = true;
    }
    else  {
        resultObj.txt = 'game over';
        }
        socket.write(JSON.stringify(resultObj))
    })
})