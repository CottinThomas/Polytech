/**
 * Displays the browser informations.
 */
function writeBrowserInformations(){
	var appName = navigator.appName;
	var codeName = navigator.appCodeName;
	var appVersion = navigator.appVersion;
	var userAgent = navigator.userAgent;

	document.getElementById('appName').innerHTML = appName;
	document.getElementById('codeName').innerHTML = codeName;
	document.getElementById('appVersion').innerHTML = appVersion;
	document.getElementById('userAgent').innerHTML = userAgent;
}

document.onload =writeBrowserInformations();