<?php
session_start();

if(!empty($_POST['uname']))
    $_SESSION['uname'] = $_POST['uname'];
?>
<!DOCTYPE html>
<html lang="fr">
<head>
    <title>Tp 3 - PHP</title>
    <meta charset="UTF-8"/>
    <link rel="stylesheet" type="text/css" href="style.css"/>
</head>
<body>
    <?php if(!empty($_SESSION['uname'])){
    ?>
    <h1>Bonjour <?php echo $_SESSION['uname']; ?> !</h1> <p>Pour se déco, c'est <a href="quitter.php">là</p>
    <?php } else {?>
    <h1>Bonjour !</h1><p>Si tu souhaites te connecter, c'est <a href="login.php">par ici</a> ;)</p>
    <?php } ?>
</body>
</html>