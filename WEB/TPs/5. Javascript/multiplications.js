/*
 *	multiplications.js
 * 		Play with multiplications
 *
 *		Created by Thomas COTTIN
 *		Work for studies @Polytech'Paris-Sud, App3, 2015-2016
 */


var score=0;
var nbQuestion = 0;
var nb1;
var nb2;

/**
 * Initialisation function.
 */
function init(lastAnswerCorrect){
	document.getElementById('answer').value = "";
	document.getElementById('nbQuestion').innerHTML = nbQuestion;
	document.getElementById('score').innerHTML = score;
	changeScoreColor(lastAnswerCorrect);
	changeNbValue(1);
	changeNbValue(2);
}

/**
 * Change the value of the number and it's display
 * Input : nb 	the number to change
 */ 
function changeNbValue(nb){
	switch(nb){
		case 1:
			nb1 = getRandNumber();
			document.getElementById('nb1').innerHTML = nb1;
			break;
		case 2:
			nb2 = getRandNumber();
			document.getElementById('nb2').innerHTML = nb2;
			break;
		default:
			console.error('Bad usage of changeNbValue: invalid entry');
			break;
	}
}

/**
 *	Returns a random number between 1 and 10
 */
function getRandNumber(){
	return Math.floor((Math.random() * 10) + 1);
}

/**
 * Verifies if the 'input' field contains a number.
 * Output : boolean		True if a number, false if not.
 */
function verifInputNumber(){
	var rep = document.getElementById('answer').value;
	if(isNaN(rep)){
		alert('Merci de saisir un nombre');
		return false;
	}
	return true;
}

/**
 * Verifies if the 'input' contains the good answer.
 * Output : boolean		True if correct answer, false if not.
 */
function verifReponseCorrecte(){
	var goodAnswer = nb1*nb2;
	var rep = document.getElementById('answer').value;
	return goodAnswer==rep ? true : false;
}

/**
 * Change the color of the score in green or red
 * Input : boolean		True > green, false > red.
 */
function changeScoreColor(estCorrect){
	if(estCorrect)
		document.getElementById('result').style.color='green';
	else
		document.getElementById('result').style.color='red';
}

/**
 * Verifies the answer
 */
function verif(){
	if(!verifInputNumber())
		return;
	nbQuestion +=1;
	if(verifReponseCorrecte()){
		score += 1;
		alert("Bonne réponse !");
		init(true);
	}
	else{
		alert("Raté ! La bonne réponse était "+nb1*nb2);		
		init(false);
	}
}


document.onload = init(true);