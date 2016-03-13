<?php
$EMAIL_REGEX = '/^.+[@].+[.][a-z]{2,4}/';


if(empty($_GET['email'])) {
    print 'Rien à afficher';
}
else {
    $res = preg_match($EMAIL_REGEX,$_GET['email']);
    if($res){
        echo 'L\'email '.$_GET['email'].' est valide.';
    }
    else{
        echo 'L\'email '.$_GET['email'].' n\'est pas valide.';
    }
}