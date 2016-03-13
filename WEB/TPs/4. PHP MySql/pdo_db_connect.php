<?php

function connect(){
	$user = 'root';
	$pass = '';

	try {
	    $dbh = new PDO('mysql:host=localhost;dbname=tp4', $user, $pass);
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

function getArrayFilms(){
	$pdo = connect();
	$ret = $pdo->query('SELECT * FROM films ORDER BY titre ASC');
	$pdo = close($pdo);
	return $ret;
}

function insert($titre, $annee, $pays){
	$pdo = connect();
	$stm = $pdo->prepare('INSERT INTO films VALUES (:titre, :annee, :pays)');
	$stm->bindParam(':titre',$titre);
	$stm->bindParam(':annee',$annee);
	$stm->bindParam(':pays',$pays);
	$stm->execute();
	$pdo = close($pdo);
}

function delete_film($titre){
	$pdo=connect();
	$stm = $pdo->prepare('DELETE FROM films WHERE titre = :titre');
	$stm->bindParam(':titre',$titre);
	$stm->execute();
	$pdo = close($pdo);
}