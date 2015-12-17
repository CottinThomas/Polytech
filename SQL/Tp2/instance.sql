START transaction;

INSERT INTO article
VALUES (
	'Adding Structure to Unstructured Data',
	 'We develop a new schema for unstructured data. Traditional schemas resemble the type systems of programming languages.', 
	'Recherche-long');
INSERT INTO article
VALUES (
	'A User-centric Framework for Accessing Biological Sources and Tools',
	 'We study the representation and querying of XML with incomplete information. We consider a simple model for XML data and their DTDs, a very simple query language, and a representation system for incomplete information in the spirit of the representations systems developed by Imielinski and Lipski for relational databases.',
	'Recherche-long');
INSERT INTO article
VALUES (
	'PDiffView: Viewing the Difference in Provenance of Workflow Results',
	'Provenance Difference Viewer (PDiffView) is a prototype based on these algorithms for differencing runs of SPFL specifications',
	'Research-court');
INSERT INTO article
VALUES (
	'Automata and Logics for Words and Trees over an Infinite Alphabet',
	'In a data word or a data tree each position carries a label from a finite alphabet and a data value from some infinite domain. These models have been considered in the realm of semistructured data, timed automata and extended temporal logics.
This paper survey several know results on automata and logics manipulating data words and data trees, the focus being on their relative expressive power and decidability',
	'Research-long');
INSERT INTO article
VALUES (
	'Representing and Querying XML with Incomplete Information',
	'We study the representation and querying of XML with incomplete information. We consider a simple model for XML data and their DTDs, a very simple query language, and a representation system for incomplete information in the spirit of the representations systems developed by Imielinski and Lipski for relational databases. In the scenario we consider, the incomplete information about an XML document is continuously enriched by successive queries to the document.',
	'Research-long');
INSERT INTO siteweb
VALUES('http://homepages.inf.ed.ac.uk/opb/');
INSERT INTO siteweb
VALUES(	'http://www.lri.fr/~lucie');
INSERT INTO siteweb
VALUES('http://www.lri.fr/~christiane/');
INSERT INTO siteweb
VALUES('http://www.cis.upenn.edu/~susan/');
INSERT INTO siteweb
VALUES(	'http://www-rocq.inria.fr/~segoufin/');
INSERT INTO siteweb
VALUES(
	'http://www.cse.psu.edu/');
INSERT INTO siteweb
VALUES(	
	'http://www.lri.fr/');
INSERT INTO siteweb
VALUES(	'http://www.lsv.ens-cachan.fr/');

INSERT INTO auteur
VALUES (
	'peter@cis.upenn.edu',
	'Buneman',
	'Peter',
 	'http://homepages.inf.ed.ac.uk/opb/');
INSERT INTO auteur
VALUES (
	'lucie@lri.fr',
	'Jolie',
	'Lucie',
	'http://www.lri.fr/~lucie');
INSERT INTO auteur
VALUES (
	'christiane@lri.fr',
	'Dupont',
	'Christiane',
	'http://www.lri.fr/~christiane/');
INSERT INTO auteur
VALUES (
	'susan@cis.upenn.edu',
	'Davidson',
	'Susan',
	'http://www.cis.upenn.edu/~susan/');
INSERT INTO auteur
VALUES (
	'luc.segoufin@inria.fr',
	'Segoufin',
	'Luc',
	'http://www-rocq.inria.fr/~segoufin/');

INSERT INTO laboratoire
VALUES (
	'Laboratory for Foundations of Computer Science',
	'LFCS',
	'LFCS, School of Informatics Crichton Stree Edinburgh EH8 9LE');
INSERT INTO laboratoire
VALUES (
	'Department of Computer and Information Science University of Pennsylvania',
	'CIS',
	' Address: 305 Levine/572 Levine North Department of Computer and Information Science  University of Pennsylvania  Levine Hall  3330 Walnut Street  Philadelphia, PA 19104-6389'
); 
INSERT INTO laboratoire
VALUES (
	'Laboratoire de Recherche en Informatique',
	'LRI',
	'Bât 490 Université Paris-Sud 11 91405 Orsay Cedex France'
);			
INSERT INTO laboratoire
VALUES (
	'Laboratoire Spécification et Vérification',
	'LSV',
	'ENS de Cachan, 61 avenue du Président Wilson, 94235 CACHAN Cedex, FRANCE' 
);
INSERT INTO laboratoire
VALUES (
	'Dahu INRIA Saclay - Ile-de-France',
	'LSV',
	'ENS de Cachan, 61 avenue du Président Wilson, 94235 CACHAN Cedex, FRANCE' 
);

INSERT INTO support
VALUES (
	'ICDT',
	'Conference');
INSERT INTO support
VALUES (
	'DILS',
	'Conference'
);
INSERT INTO support
VALUES (
	'TODS',
	'Journal'
);
INSERT INTO support
VALUES (
	'VLDB',
	'Conference'
);
INSERT INTO support
VALUES (
	'CLS',
	'Conference'
);
commit;







START transaction;
INSERT INTO utilisateur
VALUES (
	'peter@cis.upenn.edu');
INSERT INTO utilisateur
VALUES ('lucie@lri.fr');
INSERT INTO utilisateur
VALUES ('christiane@lri.fr');
INSERT INTO utilisateur
VALUES ('susan@cis.upenn.edu');
INSERT INTO utilisateur
VALUES ('luc.segoufin@inria.fr');


INSERT INTO travaille
VALUES (
	'peter@cis.upenn.edu',	'Laboratory for Foundations of Computer Science'
);
INSERT INTO travaille
VALUES (
	'susan@cis.upenn.edu', 	'Department of Computer and Information Science University of Pennsylvania'
);
INSERT INTO travaille
VALUES (
	'peter@cis.upenn.edu',	'Department of Computer and Information Science University of Pennsylvania'
);
INSERT INTO travaille
VALUES (
	'lucie@lri.fr',
	'Laboratoire de Recherche en Informatique'
);
INSERT INTO travaille
VALUES (
	'christiane@lri.fr',
	'Laboratoire de Recherche en Informatique'
);
INSERT INTO travaille
VALUES (
	'luc.segoufin@inria.fr',
	'Laboratoire Spécification et Vérification'
);
INSERT INTO travaille
VALUES (
	'luc.segoufin@inria.fr',
	'Dahu INRIA Saclay - Ile-de-France'
);
INSERT INTO supportArticle
VALUES(
	'Adding Structure to Unstructured Data',
	'ICDT',
	1997
);
INSERT INTO supportArticle
VALUES(
	'A User-centric Framework for Accessing Biological Sources and Tools',
	'DILS',
	2005
);
INSERT INTO supportArticle
VALUES(
	'Representing and Querying XML with Incomplete Information',
	'TODS',
	2006
);
INSERT INTO supportArticle
VALUES(
	'PDiffView: Viewing the Difference in Provenance of Workflow Results',
	'VLDB',
	2009
);
INSERT INTO supportArticle
VALUES(
	'Automata and Logics for Words and Trees over an Infinite Alphabet',
	'CLS',
	2006
);
INSERT INTO urllabo
VALUES(
	'Department of Computer and Information Science University of Pennsylvania',
	'http://www.cse.psu.edu/'
);
INSERT INTO urllabo
VALUES(
	'Laboratoire de Recherche en Informatique',
	'http://www.lri.fr/'
);
INSERT INTO urllabo
VALUES(
	'Laboratoire Spécification et Vérification',
	'http://www.lsv.ens-cachan.fr/'
);
INSERT INTO urllabo
VALUES (
	'Dahu INRIA Saclay - Ile-de-France',
	'http://www.lsv.ens-cachan.fr/'
);
INSERT INTO aecrit
VALUES (
	'Adding Structure to Unstructured Data',
	'peter@cis.upenn.edu'
);
INSERT INTO aecrit
VALUES (
	'Adding Structure to Unstructured Data',
	'susan@cis.upenn.edu'
);
INSERT INTO aecrit
VALUES (
	'A User-centric Framework for Accessing Biological Sources and Tools',	'susan@cis.upenn.edu'
);
INSERT INTO aecrit
VALUES (
	'A User-centric Framework for Accessing Biological Sources and Tools',	
	'lucie@lri.fr'
);
INSERT INTO aecrit
VALUES (
	'A User-centric Framework for Accessing Biological Sources and Tools',	
	'christiane@lri.fr'
);
INSERT INTO aecrit
VALUES (
	'Automata and Logics for Words and Trees over an Infinite Alphabet',	
	'luc.segoufin@inria.fr'
);
INSERT INTO aecrit
VALUES (
	'Representing and Querying XML with Incomplete Information',	
	'luc.segoufin@inria.fr'
);

commit;



START transaction;

INSERT INTO APourNote
VALUES ('luc.segoufin@inria.fr',
	'Adding Structure to Unstructured Data',4);
INSERT INTO APourNote
VALUES ('luc.segoufin@inria.fr',
	'Automata and Logics for Words and Trees over an Infinite Alphabet',1);
INSERT INTO APourNote
VALUES ( 'luc.segoufin@inria.fr',
	'A User-centric Framework for Accessing Biological Sources and Tools',4);
INSERT INTO APourNote
VALUES ('luc.segoufin@inria.fr',
	'PDiffView: Viewing the Difference in Provenance of Workflow Results',
	5);
INSERT INTO APourNote
VALUES ('luc.segoufin@inria.fr',
	'Representing and Querying XML with Incomplete Information',1);
INSERT INTO APourNote
VALUES ( 'peter@cis.upenn.edu',
	'A User-centric Framework for Accessing Biological Sources and Tools',2);
INSERT INTO APourNote
VALUES ('peter@cis.upenn.edu',
	'PDiffView: Viewing the Difference in Provenance of Workflow Results',
	1);
INSERT INTO APourNote
VALUES ('peter@cis.upenn.edu',
	'Automata and Logics for Words and Trees over an Infinite Alphabet',1);
INSERT INTO APourNote
VALUES ('lucie@lri.fr',
	'Automata and Logics for Words and Trees over an Infinite Alphabet',3);
INSERT INTO APourNote
VALUES ( 'lucie@lri.fr',
	'A User-centric Framework for Accessing Biological Sources and Tools',2);
INSERT INTO APourNote
VALUES ('lucie@lri.fr',
	'PDiffView: Viewing the Difference in Provenance of Workflow Results',
	1);
INSERT INTO tag
VALUES ('data');
INSERT INTO tag
VALUES ('bio');
INSERT INTO tag
VALUES ('workflow');
INSERT INTO tag
VALUES ('theory');
INSERT INTO tag
VALUES ('XML');
INSERT INTO annot
VALUES ('luc.segoufin@inria.fr',
	'Adding Structure to Unstructured Data','data');
INSERT INTO annot
VALUES ( 'peter@cis.upenn.edu',
	'A User-centric Framework for Accessing Biological Sources and Tools','bio');
INSERT INTO annot
VALUES ( 'peter@cis.upenn.edu',
	'Adding Structure to Unstructured Data','XML');
INSERT INTO annot
VALUES ('peter@cis.upenn.edu',
	'PDiffView: Viewing the Difference in Provenance of Workflow Results',
	'workflow');
INSERT INTO annot
VALUES ('lucie@lri.fr',
	'Automata and Logics for Words and Trees over an Infinite Alphabet','theory');

commit;
