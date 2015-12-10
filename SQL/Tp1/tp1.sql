-- TP Numéro 1

-- 1. Quel est le nombre de casernes ?
SELECT COUNT(id_caserne) AS "Nombre de casernes"
	FROM CASERNE;

-- 2. Quels sont les pompiers des casernes situés a Draguignan ?
SELECT id_pompier, nom, prenom
	FROM POMPIER
	WHERE id_caserne IN (
		SELECT id_caserne
			FROM CASERNE
			WHERE nom_ville = 'Draguignan'
	);

-- 3. Quelles sont les casernes protégeant à la fois Draguignan et Le Luc ?
SELECT id_caserne, num_rue, nom_rue, cp, nom_ville
	FROM CASERNE
	WHERE id_caserne IN (
		SELECT id_caserne
			FROM protege
			WHERE nom_ville = 'Draguignan' AND id_caserne IN (
				SELECT id_caserne
					FROM protege
					WHERE nom_ville = 'Le Luc'
			)
	);

-- 4. Quels sont les pompiers de la caserne 3 habitant à plus de 5 kilomètres d’une caserne ?
SELECT id_caserne, id_pompier, nom, prenom FROM POMPIER NATURAL JOIN ADRESSE
	WHERE km > 5 AND id_caserne=3;

-- 5. Quels sont les pompiers habitant Le Luc ou des villes ≥ 20000 habitants ?
SELECT id_pompier, nom, prenom FROM POMPIER
	WHERE nom_ville = 'Le Luc' OR nom_ville IN (
		SELECT nom_ville 
			FROM VILLE
			WHERE nb_hab >= 20000
	);

-- 6. Quel est le délai moyen de livraison pour chaque fabricant de citernes de moins de 1000 litres ?
SELECT nom_fabricant, delai
	FROM CITERNE NATURAL JOIN CAMION C JOIN MODELE F ON (C.modele=F.nom_modele) NATURAL JOIN FABRICANT
	WHERE contenance < 1000
	GROUP BY nom_fabricant, delai;
;

-- 7. Classez par ordre décroissant le temps de livraison de camions moyen par caserne.
SELECT id_caserne, AVG(delai) 
	FROM CAMION C JOIN MODELE F ON (C.modele=F.nom_modele) NATURAL JOIN FABRICANT
	GROUP BY id_caserne;

-- 8. Quel est le nombre de pompiers par caserne ?
SELECT id_caserne, COUNT(id_pompier)
	FROM POMPIER
	GROUP BY id_caserne;


-- 9. Quelles sont les casernes n’ayant qu’un seul pompier ?
SELECT id_caserne
	FROM POMPIER
	GROUP BY id_caserne
	HAVING COUNT(id_pompier)=1;

-- 10. Dans quelle(s) ville(s) trouve-t-on la (les) caserne(s) avec la (les) citerne(s) de plus grosse contenance ?
SELECT nom_ville, contenance
	FROM caserne NATURAL JOIN camion NATURAL JOIN citerne
	GROUP BY nom_ville, contenance
	HAVING contenance >= ALL (
		SELECT contenance
			FROM caserne NATURAL JOIN camion NATURAL JOIN citerne
	);

-- 11. Quelles sont les casernes ayant atteint leur capacité maximale humaine ?
SELECT id_caserne
FROM CASERNE C, (SELECT COUNT(id_pompier) AS nb FROM POMPIER P WHERE P.id_caserne=C.id_caserne) TOTO
WHERE nb=capa_pompiers;
-- 12. Quels sont les pompiers qui ne travaillent pas dans la ville o`
-- u ils habitent ?
-- 13. Quelles sont les villes qui partagent leur code postal avec une autre ville ? Quelles sont les villes
-- auxquelles plusieurs codes postaux sont attribu ́es ?
-- 14. Quelles sont les marques des camions qui sont utilis ́ees dans toutes les casernes ?
-- 15. (a) Quelle est (sont) la (les) ville(s) contenant le moins de casernes ?
-- (b) Donnez le nombre de chaque type d’habitation pour chaque ville.
-- (c) Pour chaque ville, quelle est le type d’habitation le plus fr ́equent ? (fournir plusieurs types
-- d’habitation en cas d’ ́egalit ́e)
-- 16. (a) Listez par ordre d ́ecroissant les casernes en fonction du nombre des pompiers y travaillant
-- (b) Quelle est la premi`ere caserne de la liste pr ́ecedente ?
-- 17. Donnez pour chaque caserne le volume total d’eau de ses citernes (y compris les casernes ne
-- poss ́edant pas de citerne).