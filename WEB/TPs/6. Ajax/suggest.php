<?php
header("Content-Type: text/plain");
function connect(){
	$user = 'tcottin_a';
	$pass = 'tcottin_a';

	$options = array(
	  PDO::MYSQL_ATTR_INIT_COMMAND => 'SET NAMES utf8'
	);

	try {
	    $dbh = new PDO('mysql:host=tp-sgbd;dbname=tcottin_a', $user, $pass, $options);
	    return $dbh;
	} catch (PDOException $e) {
	    print "Erreur !: " . $e->getMessage() . "<br/>";
	    die();
	}
}

function close(PDO $dbh){
	$dbh = null;
	return $dbh;
}

function getActors(){
	$pdo = connect();
	$ret = $pdo->query('SELECT * FROM Acteur ORDER BY Nom ASC;');
	$pdo = close($pdo);
	return $ret;
}


function getCountries(){
	$pdo = connect();
	$ret = $pdo->query('SELECT DISTINCT Pays FROM Film ORDER BY Pays ASC;');
	$pdo = close($pdo);
	return $ret;
}

function executeQuery($query){
	$pdo = connect();
	$ret = $pdo->query($query);
	$pdo = close($pdo);
	return $ret;
}


if(!empty($_GET['init'])){
	if(!empty($_GET['getActors'])){
		foreach (getActors() as $actor) {
			echo('<option value="'.$actor['Id'].'">'.$actor['Nom'].'</option>');
		}
	}
	else if(!empty($_GET['getCountries'])){
		foreach (getCountries() as $country) {
			echo('<option value="'.$country['Pays'].'">'.$country['Pays'].'</option>');
		}
	}
}
else {
	$select = 'SELECT Titre';
	$from = 'FROM Film F';
	$where = 'WHERE 1';

	if(!empty($_GET['actors'])){
		$actorsIdsList = urldecode($_GET['actors']);
		$actorsIdsArray = explode(',', $actorsIdsList);

		$i = 0;
		foreach ($actorsIdsArray as $actorId) {
			$from .= ' JOIN Film_Acteur FA'.$i.' ON F.Id = FA'.$i.'.IdFilm';
			$where .=' AND FA'.$i.'.IdActeur='.$actorId;
			$i++;
		}
	}
	if(!empty($_GET['country'])){
		$where .=' AND Pays="'.urldecode($_GET['country']).'"';
	}
	if(!empty($_GET['start'])){
		$where .= ' AND Annee > '.urldecode($_GET['start']);
	}
	if(!empty($_GET['end'])){
		$where .= ' AND Annee < '.urldecode($_GET['end']);
	}
	if(!empty($_GET['title'])){
		$where .= ' AND Titre LIKE "%'.urldecode($_GET['title']).'%"';
	}

	$query = $select.' '.$from.' '.$where;
	echo($query);
	echo('<ul>');
	foreach ( executeQuery($query) as $retour) {
		echo('<li>'.$retour['Titre'].'</li>');
	}
	echo('</ul>');
}