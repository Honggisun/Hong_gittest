/**
 * Created by KICT-12 on 2016-07-19.
 */

const net = require('net');
const PORT = 8080;

let solution;
let bSolved = false;
solution = Math.round(Math.random() * 100);

//console.log(solution);

net.createServer((socket)=> {

    console.log('connect :' + socket.remoteAddress +':'
        + socket.remotePort
    );

    socket.on('error',(evt)=>{
        console.log(evt);
    });
    socket.on('close',(evt)=>{
        console.log('connection closed!');
        console.log(evt);
    });
    socket.on('data',(evt)=>{
        //console.log(evt.toString());
        try {
            let data = JSON.parse(evt.toString());
            let resultObj = {};
            if(bSolved ==false ) {
                console.log( data.name + " try game...");

                if(data.value > solution) {
                    resultObj.txt = "high";
                    console.log(data.name + "님 실패!!!");
                }
                else if(data.value < solution) {
                    resultObj.txt = "low";
                    console.log(data.name + "님 실패!!!");
                }
                else {
                    console.log(data.name + "님 당첨!!!");
                    console.log("정답은 :" + solution);
                    resultObj.txt ="bingo"
                    bSolved = true;
                }
            }
            else {
                resultObj.txt = 'game over';
            }
            socket.write(JSON.stringify(resultObj));

        }
        catch (e) {
            console.log(e.toString())
        }

    });

}).listen(PORT);

console.log('server listen :' + PORT);


