const http = require("http");

const server = http.createServer((req, res) => {
    res.statusCode = 200;
    res.setHeader("Content-Type", "text/plain");
    res.end("Hello nodejs! it is yoenghun's server.\n");
})

server.listen(8080, "127.0.0.1", () => {
    console.log("server is runnig...");
})