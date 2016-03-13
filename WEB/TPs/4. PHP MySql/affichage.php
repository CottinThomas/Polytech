<?php
	require_once('pdo_db_connect.php');
	$error = 0;
	if(!empty($_GET['error']))
		$error = $_GET['error'];

	$arrayErrorsTitre = array(1,3,5,7);
	$arrayErrorsAnnee = array(2,3,6,7);
	$arrayErrorsPays = array(4,5,6,7);
?>
<!DOCTYPE html>
<html lang="fr">
<head>
    <title>Tp 4 - PHP, MySQL</title>
    <meta charset="UTF-8"/>
    <link rel="stylesheet" type="text/css" href="style.css"/>
</head>
<body>
	<div id="list">
		<table>
			<tr>
				<th>Titre</th>
				<th>Année</th>
				<th>Pays</th>
				<th></th>
			</tr>
			<?php
				foreach (getArrayFilms() as $row){
					print('<tr>');
						print('<td>'.$row['titre'].'</td>');
						if($row['annee'] != null)
							print('<td>'.$row['annee'].'</td>');
						else
							print('<td></td>');
						print('<td>');
						switch($row['pays']){
							case 'FR':
								print('France');
								break;
							case 'US':
								print('USA');
								break;
							case 'UK':
								print('Royaume Uni');
								break;
							default:
								print('Pays inconnu');
						}
						print('</td>');
						print('<td>');
							print('<a href="supprimer.php?titre='.urlencode($row['titre']).'">Supprimer</a>');
						print('</td>');
					print('</tr>');
				}

		?>
		</table>
		<?php if(!empty($_GET['delete']) && $_GET['delete']=='2'){ ?>
			<div class="error">
				<p>Echec de la suppression.</p>
			</div>
		<?php } else if(!empty($_GET['delete']) && $_GET['delete']=='1'){ ?>
			<div class="success">
				<p>Suppression réussie.</p>
			</div>
		<?php } ?>
	</div>
	<div id="form">
		<form action='insert.php' method="post">
			<fieldset>
				<legend>Ajouter un film à la base</legend>
				<div>
					<label for="titre">Titre</label>
					<?php if(in_array($error, $arrayErrorsTitre)){ ?>
						<input type="text" class="error" name="titre" id="titre" required/>
					<?php } else { ?>
						<input type="text" name="titre" id="titre" required/>
					<?php } ?>
				</div>
				<div>
					<label for="annee">Année</label>
					<?php if(in_array($error, $arrayErrorsAnnee)){ ?>
						<input type="text" class="error" name="annee" id="annee"/>
					<?php } else { ?>
						<input type="text" name="annee" id="annee"/>
					<?php } ?>
				</div>
				<div>
					<label for="pays">Pays</label>
					<?php if(in_array($error, $arrayErrorsPays)){ ?>
						<select  class="error" name="pays" id="pays" required>
							<option value="FR">France</option>
							<option value="US">USA</option>
							<option value="UK">Royaume Uni</option>
						</select>
					<?php } else { ?>
						<select  class="errore" name="pays" id="pays">
							<option value="FR">France</option>
							<option value="US">USA</option>
							<option value="UK">Royaume Uni</option>
						</select>
					<?php } ?>
				</div>
				<div>
					<button type="submit">Envoyer</button>
					<button type="reset">Réinitialiser</button>
				</div>
			</fieldset>
		</form>
		<?php if(!empty($_GET['insert']) && $_GET['insert']=='1'){ ?>
			<div class="success">
				<p>Insertion réussie !</p>
			</div>
		<?php } ?>
	</div>
</body>