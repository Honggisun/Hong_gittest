/**
 * Created by KICT-10 on 2016-07-15.
 */
const http = require('http')

const server = http.createServer(function  (req, res) {
    res.statusCode = 200;
    res.setHeader("Contet-Type","text/plain");
    res.end("<h1> hello world Jun ju <h1>")
} );

server.listen(8081,function ()  {
    console.log("http server start")
});
