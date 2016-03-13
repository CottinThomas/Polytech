<?php
/**
 * Created by: Thomas Cottin
 * Date: 01/03/16
 */

?>
<!DOCTYPE html>
<html lang="fr">
    <head>
        <title>Tp 3 - PHP</title>
        <meta charset="UTF-8"/>
        <link rel="stylesheet" type="text/css" href="style.css"/>
    </head>
    <body>
    <h1>Recherche de films</h1>
    <form action="test_formulaire_film.php" method="post" enctype="multipart/form-data">

        <div>
            <input name="type" value="recherche" type="hidden" />
            <label for="password">Mot de passe :</label>
            <input id="password" name="password" type="password" />
        </div>

        <div>
            <label for="titre">Titre :</label>
            <input name="titre" id="titre" type="text" />
        </div>

        <fieldset>
            <legend>Type de film</legend>
            <input name="genre[]" value="action" id="genre_action" type="checkbox" /> <label for="genre_action">Action</label>
            <input name="genre[]" value="comedie" id="genre_comedie" type="checkbox" /> <label for="genre_comedie">Comédie</label>
            <input name="format" value="long" id="format_long" checked="checked" type="radio" /> <label for="format_long">Long métrage</label>
            <input name="format" value="short" id="format_short" type="radio" /> <label for="format_short">Court métrage</label>
        </fieldset>

        <fieldset>
            <legend>Compléments</legend>
            <label for="pays">Pays :</label>
            <select id="pays" name="pays">
                <option value="DE">Allemagne</option>
                <option value="FR" selected="selected">France</option>
                <option value="IT">Italie</option>
                <option value="US">U.S.A.</option>
            </select>

            <label for="acteurs">Acteurs :</label>
            <select id="acteurs" name="acteurs[]" multiple="multiple" size="5">
                <option value="bb">Brigitte Bardot</option>
                <option value="tc">Tom Cruise</option>
                <option value="ad">Alain Delon</option>
                <option value="cd">Catherine Deneuve</option>
                <option value="jd">Jane Fonda</option>
                <option value="jlc">Jamee Lee Curtis</option>
                <option value="rw">Robin Williams</option>
                <option value="bw">Bruce Willis</option>
            </select>
        </fieldset>

        <div>
            <label for="resume">Résumé :</label>
            <textarea id="resume" name="resume" cols="80" rows="5" placeholder="Entrez votre résumé."></textarea>
        </div>

        <div>
            <label for="affiche">Affiche :</label>
            <input id="affiche" name="affiche" type="file" />
        </div>

        <div>
            <input value="Réinitialiser" type="reset" />
            <input value="Rechercher" type="submit" />
        </div>
    </form>
    </body>
    <h1>Vérification d'emails : </h1>
    <iframe src="verifyMail.php?email=toto"></iframe>
    <iframe src="verifyMail.php?email=toto@exemple.com"></iframe>
    <iframe src="verifyMail.php?email=toto@exemple"></iframe>
    <iframe src="verifyMail.php?email=toto@monmail.com"></iframe>


</html>
