var http = require('http');
var url = require('url');
var fs = require('fs');


var server = http.createServer(function(req, res) {
	fs.readFile('./index.html','utf-8', function(error, content){
		res.writeHead(200, {'Content-Type':'text/html'});
		res.end(content);
	});
});

var io = require('socket.io').listen(server);

io.sockets.on('connection', function(socket){
	var pseudo_user;
	socket.on('sendMessage', function(message){
		console.log(message);
		io.sockets.emit('recive',{'user': pseudo_user,'message':message});
	});
	socket.on('petit_nouveau', function(pseudo){
		pseudo_user = pseudo;
	});

})

server.listen(8080);