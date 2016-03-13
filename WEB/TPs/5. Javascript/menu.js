/*
 *	menu.js
 * 		Display or hides a sub-menu
 *
 *		Created by Thomas COTTIN
 *		Work for studies @Polytech'Paris-Sud, App3, 2015-2016
 */



/**
 * Displays the menu having the id 'nb' and hides the other one
 * input : nb	The id of the sub-menu we want to display
 */
function displayMenu(nb) {
	if(nb == 2 || nb == 4){
		var smenu = document.getElementById('smenu'+nb);
		var othersmenu;
		if(nb == 2)
			othersmenu = document.getElementById('smenu4');
		else
			othersmenu = document.getElementById('smenu2');
		if(smenu.style.display == 'none')
			smenu.style.display = 'block';
		else
			smenu.style.display == 'none';
		othersmenu.style.display = 'none';
	}
	else{
		init();
	}

}

/**
 * Function call on page load. Hides all the sub-menues
 */
function init(){
	document.getElementById('smenu2').style.display = 'none';
	document.getElementById('smenu4').style.display = 'none';
}

document.onload = init();