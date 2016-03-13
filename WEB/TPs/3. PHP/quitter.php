<?php
session_start();
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
    <h1>Au revoir <?php echo $_SESSION['uname']; ?> !</h1>
<?php session_destroy(); $_SESSION = array(); } else {?>
    <h1>Bonjour !</h1><p>Si tu souhaites te connecter, c'est <a href="login.php">par ici</a> ;)</p>
<?php } ?>
</body>
</html>