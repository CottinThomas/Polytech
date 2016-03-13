\echo ###########################################################
\echo #             Bases de données - TP n°2                   #
\echo ###########################################################
\echo
\echo Tp réalisé par Thomas COTTIN
\echo Polytech Paris Sud - 2015-2016 - App3
\echo
\echo
\echo
\echo #1. Quel est l'e-mail de Peter Buneman ?
SELECT email 
FROM auteur
WHERE UPPER(nomaut)='BUNEMAN' AND UPPER(prenomaut)='PETER';
\echo
\echo #2. Quels sont les articles dont Susan Davidson est l'un des auteur ?
SELECT titre
FROM aecrit JOIN auteur ON aecrit.email = auteur.email
WHERE UPPER(nomaut)='DAVIDSON' AND UPPER(prenomaut)='SUSAN'
ORDER BY titre;
\echo
\echo #3. Quels sont les laboratoires qui ont la même url (donnez la liste des laboratoires qui partagent une url commun avec un autre laboratoire) ?
SELECT u.nomlabo 
FROM urllabo AS u, urllabo AS v 
WHERE u.nomlabo <> v.nomlabo AND u.url = v.url
ORDER BY u.nomlabo;
\echo
\echo #4. Quels sont les co-auteurs de Susan Davidson ?
SELECT nomaut,prenomaut, auteur.email
FROM aecrit JOIN auteur ON aecrit.email = auteur.email
WHERE UPPER(nomaut)<>'DAVIDSON' AND UPPER(prenomaut) <> 'SUSAN' AND titre IN (
	SELECT titre
	FROM aecrit JOIN auteur ON aecrit.email = auteur.email
	WHERE UPPER(nomaut)='DAVIDSON' AND UPPER(prenomaut)='SUSAN'
)
ORDER BY nomaut;
\echo
\echo #5. Pour chaque auteur, donnez le nombre de laboratoires dans lesquel il travaille.
SELECT nomaut, prenomaut, auteur.email, COUNT(nomlabo) AS "Nombre de laboratoire"
FROM travaille JOIN auteur ON auteur.email = travaille.email
GROUP BY nomaut,prenomaut, auteur.email
ORDER BY nomaut;
\echo
\echo #6. Quels sont les auteurs ayant annoté au moins un article ?
SELECT nomaut, prenomaut, email
FROM auteur
WHERE email IN (
	SELECT email
	FROM apournote
);
\echo
\echo #7. Quelle est la moyenne des notes données par Luc Segoufin ?
SELECT AVG(note) AS "Moyenne des notes données"
FROM apournote
WHERE email = (
	SELECT email
	FROM auteur
	WHERE UPPER(nomaut)='SEGOUFIN' AND UPPER(prenomaut)='LUC'
);
\echo
\echo #8. Pour chaque article, quelle est la moyenne des notes données à cette article par ses propres auteurs ?
SELECT aecrit.titre, AVG(note) AS "Moyenne des notes"
FROM apournote JOIN aecrit ON apournote.titre = aecrit.titre
WHERE apournote.email = aecrit.email
GROUP BY aecrit.titre
ORDER BY aecrit.titre;
\echo
\echo #9. Quels sont les auteurs n'ayant annoté aucun de leur propre article ?
SELECT nomaut, prenomaut, email
FROM auteur
WHERE email NOT IN (
	SELECT apournote.email
	FROM apournote JOIN aecrit ON apournote.titre = aecrit.titre
	WHERE apournote.email = aecrit.email
)
ORDER BY nomaut;
\echo
\echo #10. Quels sont les auteurs qui ont notés tous les articles ?
SELECT nomaut, prenomaut, auteur.email
FROM auteur JOIN apournote ON apournote.email = auteur.email
GROUP BY nomaut, prenomaut, auteur.email
HAVING COUNT(auteur.email) >= (SELECT COUNT(*) FROM article)
ORDER BY nomaut;
\echo
\echo #11. Quels sont les auteurs qui ont notés tous les articles ?
SELECT nomaut, prenomaut, auteur.email, COUNT(titre) AS "Nombre d'article écrits"
FROM aecrit JOIN auteur ON aecrit.email = auteur.email
GROUP BY nomaut, prenomaut, auteur.email
ORDER BY "Nombre d'article écrits" DESC;
\echo
\echo #12. Quel est le premier auteur de la liste de la question précésdente ?
SELECT nomaut, prenomaut, auteur.email, COUNT(titre) AS "Nombre d'article écrits"
FROM aecrit JOIN auteur ON aecrit.email = auteur.email
GROUP BY nomaut, prenomaut, auteur.email
ORDER BY "Nombre d'article écrits" DESC
LIMIT 1;
\echo
\echo #12. Quels sont les auteurs ayant le plus publiés ?
SELECT nomaut, prenomaut, aecrit.email
FROM auteur JOIN aecrit ON aecrit.email = auteur.email
GROUP BY nomaut, prenomaut, aecrit.email
HAVING COUNT(titre) >= ALL (
	SELECT COUNT(titre)
	FROM aecrit
	GROUP BY email
)
ORDER BY nomaut;
\echo