
CREATE TABLE article (titre VARCHAR(255), 	
resume VARCHAR(500),	
typeArticle VARCHAR(255),PRIMARY KEY (titre));


CREATE TABLE siteweb(url VARCHAR(255), 
PRIMARY KEY  (url));

CREATE TABLE auteur (email VARCHAR(255),	
nomAut VARCHAR(255), 	
prenomAut VARCHAR(255),	
urlAuteur VARCHAR(255),
PRIMARY KEY (email),
CONSTRAINT fka FOREIGN KEY (urlAuteur) 

REFERENCES siteweb (url));

CREATE TABLE  utilisateur (email VARCHAR(255),	
PRIMARY KEY (email),	
CONSTRAINT fku FOREIGN KEY  (email) REFERENCES 

auteur (email));

CREATE TABLE laboratoire(nomLabo VARCHAR(255),	
sigle VARCHAR(255),	
adresse VARCHAR(200),
PRIMARY KEY (nomLabo));

CREATE TABLE support (nomSup VARCHAR(255),	
typeSupport VARCHAR(255),
PRIMARY KEY (nomSup));	

CREATE TABLE tag (libelle VARCHAR(255),
PRIMARY KEY (libelle));



CREATE TABLE aecrit (titre VARCHAR(255),	
email VARCHAR(255),
PRIMARY KEY (titre, email),
CONSTRAINT fkaet FOREIGN KEY (titre) 

REFERENCES article (titre),
CONSTRAINT fkaee FOREIGN KEY (email) 

REFERENCES auteur (email));

CREATE TABLE supportArticle (titre VARCHAR

(255),	
nomSup VARCHAR(255),	
annee INTEGER,
CHECK (annee >1800 AND annee<2010),
PRIMARY KEY (titre,nomSup),
CONSTRAINT fksat FOREIGN KEY (titre) 

REFERENCES article (titre),
CONSTRAINT fksan FOREIGN KEY (nomSup) 

REFERENCES support (nomSup));

CREATE TABLE travaille (email VARCHAR(255),	
nomLabo VARCHAR(255),
PRIMARY KEY (email,nomLabo),
CONSTRAINT fkte FOREIGN KEY (nomLabo) 

REFERENCES laboratoire (nomLabo),
CONSTRAINT fktau FOREIGN KEY (email) 

REFERENCES auteur (email));

CREATE TABLE annot (email VARCHAR(255),	
titre VARCHAR(255),	
libelle VARCHAR(255),
PRIMARY KEY (email,titre,libelle),
CONSTRAINT fkane FOREIGN KEY (email) 

REFERENCES utilisateur (email),
CONSTRAINT fkant FOREIGN KEY (titre) 

REFERENCES article (titre),
CONSTRAINT fkanl FOREIGN KEY (libelle) 

REFERENCES tag (libelle));

CREATE TABLE APourNote(email VARCHAR(255),	
titre VARCHAR(255),	
note  INTEGER,
CHECK  (note <6 AND note>0), 
PRIMARY KEY (email,titre),
CONSTRAINT fkne FOREIGN KEY  (email) 

REFERENCES utilisateur (email),
CONSTRAINT fknt FOREIGN KEY  (titre) 

REFERENCES article (titre));

CREATE TABLE urllabo (nomLabo VARCHAR(255),	
url VARCHAR(255),
PRIMARY KEY (nomLabo),
CONSTRAINT ful FOREIGN KEY (nomLabo) 

REFERENCES laboratoire (nomLabo),
CONSTRAINT fkuu FOREIGN KEY (url) REFERENCES 

siteweb (url));

