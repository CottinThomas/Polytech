<?php
/**
 * Created by: Thomas Cottin
 * Date: 01/03/16
 */
$DEBUG = false;


if($DEBUG){
    ini_set('display_errors', 1);
    print "Password : ".$_POST['password']."<br/>";
    print "Titre : ".$_POST['titre']."<br/>";
    print "Genres : "; print_r($_POST['genre']); print "<br/>";
    print "Format : ".$_POST['format']."<br/>";
    print "Pays : ".$_POST['pays']."<br/>";
    print "Acteurs : "; print_r($_POST['acteurs']); print "<br/>";
    print "Resumé : ".$_POST['resume']."<br/>";
    print_r($_FILES);
}

?>
<!DOCTYPE html>
<html lang="fr">
<head>
    <title>Tp 3 - PHP</title>
    <meta charset="UTF-8"/>
    <link rel="stylesheet" type="text/css" href="style.css"/>
</head>
<body>
    <h1>Résultat du formulaire :</h1>
    <ul>
        <?php
        if(!empty($_POST['password'])){
        ?>
            <li><b>Password : </b> <?php echo $_POST['password'];?></li>
        <?php
        }
        if(!empty($_POST['titre'])){
        ?>
            <li><b>Titre : </b><?php echo $_POST['titre'];?></li>
        <?php
        }
        if(!empty($_POST['genre'])){
        ?>
            <li><b>Genre(s) : </b>
                <ul>
                    <?php foreach($_POST['genre'] as $genre){ ?>
                        <li><?php echo $genre;?></li>
                    <?php } ?>
                </ul>
            </li>
        <?php
        }
        if(!empty($_POST['format'])){
        ?>
            <li><b>Format : </b><?php echo $_POST['format'];?></li>
        <?php
        }
        if(!empty($_POST['pays'])){
        ?>
            <li><b>Pays : </b><?php echo $_POST['pays'];?></li>
        <?php
        }
        if(!empty($_POST['acteurs'])){
        ?>
            <li><b>Acteur(s) : </b>
                <ul>
                    <?php foreach($_POST['acteurs'] as $acteur){ ?>
                        <li><?php echo $acteur;?></li>
                    <?php } ?>
                </ul>
            </li>
        <?php
        }
        if(!empty($_POST['resume'])){
        ?>
            <li><b>Resume : </b><?php echo $_POST['resume'];?></li>
        <?php
        }
        if(sizeof($_FILES)!= 0) {
            $uploaddir = 'uploads/';
            $uploadfile = $uploaddir . rand().'-'.$_FILES['affiche']['name'];
            $res =move_uploaded_file($_FILES['affiche']['tmp_name'], $uploadfile);
            if ($res) {
                ?>
                <li><b>Affiche : </b><br/><img src="<?php echo $uploadfile; ?>"/></li>
            <?php
            }
        }
        ?>
    </ul>
</body>
</html>