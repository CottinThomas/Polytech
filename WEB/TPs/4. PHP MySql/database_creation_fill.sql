CREATE DATABASE IF NOT EXISTS tp4;

USE tp4;

CREATE TABLE IF NOT EXISTS films (
	titre VARCHAR(30),
	annee INT,
	pays VARCHAR(2),
	CONSTRAINT pk_films PRIMARY KEY (titre)
);

INSERT INTO films VALUES
	('Forrest Gump',1994,'US'),
	('La ligne verte',2000,'US'),
	('Django Unchained',2013,'US'),
	('Gran Torino',2009,'US'),
	('La liste de Schindler',1994,'US'),
	('Dofus - Livre 1 : Julith', 2016, 'FR'),
	('Intouchable', 2011,'FR');