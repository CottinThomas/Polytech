<?php
require_once('pdo_db_connect.php');

$errorCode = 0;

if(empty($_POST['titre'])){
	$errorCode += 1;
}
if(!empty($_POST['annee']) && !preg_match('/((^19[0-9]{2}$)|(^20(0|1){1}[0-9]{1}$))/',$_POST['annee'])){
	$errorCode += 2;
}
if(empty($_POST['pays'])){
	$errorCode += 4;
}
if($errorCode != 0){
	header('Location: affichage.php?error='.$errorCode);
}
else{
	$titre = $_POST['titre'];
	if(empty($_POST['annee']))
		$annee=null;
	else 
		$annee = intval($_POST['annee']);
	$pays = $_POST['pays'];

	insert($titre,$annee,$pays);
	header('Location:affichage.php?insert=1');
}

