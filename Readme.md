# 🗓️ Organisation

## 💀 Deadline

- A finir pour le Mercredi 22 novembre
- Soutenance le Mercredi 22 ou Jeudi 23

## 🎯 Objectifs

- Semaine 1 (Deadline : Dimanche 12 novembre) :
  - [-] Répondre aux questions "simples"
  - [-] début questions avancées
  - [-] Réfléchir niveau classe et séparation de code
- Semaine 2 (Deadline : Dimanche 19 novembre) :
  - [-] Construction de conique
  - [-] Exemples :
    - [-] cercle
    - [-] ellipse
    - [-] parabole
    - [-] hyperbole
  - [-] fin questions avancées
- Semaine 3 (Deadline : Mardi 21 novembre) :
  - [-] Cas de point à l'infini
  - [-] Cas surdéterminée

## 📚 Guide

- Nommage camelCase et en anglais (sauf commentaires éventuellement)
- Mettre en `const` dès que possible ⚠️
- Fichier `reponses.md` pour répondre aux questions (converti en pdf utltérieurement).
- Pour nous : `journalDeBord.md` pour préparer la soutenance
  - pourquoi on a fait tel truc, comment...
  - permet d'indiquer les conventions qu'on a suivi : méthode vu en cours, essais sur différents compilateurs...
- Utilisation de branches pour des expérimentations
  - Fusion/Merge dans le main quand implémentation complète

# Maths

## Questions à répondre

- [-] Pourquoi peut-on résoudre ce système avec uniquement 5 points ?
- [-] Montrez pourquoi la tangente l d’une conique C passant par le point x ∈ C s’exprime sous la forme : l = Cx
- [-] Différence entre la distance algébrique et géométrique  
   géométrique : distance minimale entre le point et la conique  
   algébrique : d = ax² + bxy + cy² + dxw + eyw + fw²
- [-] Explorer les propriétés des points et des droites en rapport avec les coniques

## Mathématiques avancés

- [-] Comment peut-on construire une conique à partir de 5 tangentes ? (cf section 2.1)
- [-] Affichez des coniques du faisceau C(t) et vérifiez que ces coniques passent toutes par les points d’intersection entre Ca et Cb.  
   C(t) = cos(t)Ca + sin(t)Cb avec t ∈ [0, π]  
   faisceau == combinaison linéaire de 2 coniques  
   /!\ Pensez à normer les coniques Ca et Cb en divisant chacune de leur composante par leur norme respective : ‖C‖ = sqrt(a² + b² + c² + d² + e² + f²)
- [-] Dans certains cas, une conique peut être une paire de droites. Quelle est l’équation de cette conique ? Comment la construire ?
- [-] Il se trouve qu’une conique peut même être un point (un cercle de rayon nul). Quelle est l’équation de cette conique ?

# Programmation

- [-] Calculer conique passaant par 5 points (aléatoire ou depuis un fichier)
- [-] Cas de point à l'infini
- [-] Extension du code : cas surdéterminée (+ de 5 points)
  - [-] Cas éventuel où aucune conique ne correspond => conique la + proche au sens des moindres carrés
- [-] Fournir des exemples pour montrer que le code marche (et pour aider à l'utilisation)
- [-] Tester le projet avec plusieurs compilateur (à noter dans le rapport ???)
- [-] Code lisible => bien séparer nos fichiers

## A utiliser dans notre code ✅

Voici ce qu’il serait bon de rencontrer dans votre projet :

- [-] polymorphisme
- [-] usage d’outils de la STL
- [-] exceptions pour traiter les erreurs
- [-] asserts pour détecter et prévenir les erreurs de programmation
- [-] espaces de nommage (namespace)
- [-] fonctions lambdas constexpr
- [-] (bonus) fonctions variadics

## ⚠️ Attention ⚠️

- Mauvais organisation de fichier
- des variables, des fonctions ou des types mal nommés
- des références _non constantes_ alors qu’elles devraient l’être
- des _passages par copies non justiﬁés_
- des _erreurs de segmentation_
- des _fuites de mémoires_ => utiliser valdgrind
- des bugs
- du **code de debug non retiré**
- du _code mort_ (= des portions de code non utilisés par le programme)
- du _code dupliqué_
- du _code illisible_ d’un point de vue sémantique (des for dans des for
  dans des if dans des for dans des else par exemple)
- du code illisible d’un point de vue esthétique (indentation irrégulière, mélange camelCase / snake case, mélange tabs / spaces)
- des mega fonctions de plus de 30 lignes
- des mega ﬁchiers de plus de 500 lignes
- des _variables globales non constexpr_
- des crashs lorsque l’utilisateur eﬀectue une opération non prévue
