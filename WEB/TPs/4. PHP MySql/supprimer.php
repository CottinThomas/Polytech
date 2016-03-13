<?php
require_once('pdo_db_connect.php');

$errorCode = 0;

if(!empty($_GET['titre'])){
	delete_film($_GET['titre']);
	header('Location: affichage.php?delete=1');
}
else{
	header('Location: affichage.php?delete=2');
}
