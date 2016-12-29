var http = require('http');

var server = http.createServer(function(req, res) {
	res.writeHead(200);
	res.end('Hello from Node.js simple web server');

	console.log('Request Serviced');
});

console.log('Starting server on port 8765...');

server.listen(8765);

