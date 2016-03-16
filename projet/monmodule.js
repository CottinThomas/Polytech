var direBonjour = function() {
	console.log('Bonjour !');
}
var direByeBye = function() {
	console.log('Bye bye !');
}

//exports rends publique l'accès aux fonctions
exports.direBonjour = direBonjour;
exports.direByeBye = direByeBye;