/**
 * Created by KICT-10 on 2016-07-19.
 */

const net = require('net');
const PORT = 8080;

net.createServer((socket)=> {

    console.log('connect :' + socket.remoteAddress +':'
        + socket.remotePort
    );

    socket.on('error',(evt)=> {
        console.log(evt);
    });
    socket.on('close',(evt)=>{
        console.log(evt);
    });
    socket.on('data',(evt)=>{
        console.log();
    });

}).listen(PORT);

console.log('server listen :' + PORT);