# 🗓️ Organisation

## 💀 Deadline

- A finir pour le Mercredi 22 novembre
- Soutenance le Mercredi 22 ou Jeudi 23

## 🎯 Objectifs

### Semaine 1 (Deadline : Dimanche 12 novembre) :

- Répondre aux questions "simples"
- Réfléchir niveau classe et séparation de code

#### Organisation niveau programmation

⚠️**Conique** (= Coupe cone/plan) => `stocke les informations des coniques`⚠️ `Tanya`

- Constructeur (+ 5 points -> "...") ⚠️`Tanya`
      -> conique la + proche au sens des moindres carrés
- liste de ses coefficients : A, B, C, D, E, F ⚠️
      `Tanya`
  - Calcule coeff
- Type conique ⚠️ => TODO: meilleur AFFICHAGE

---

⚠️ **View** => s'occupe d'afficher sur géogébra ⚠️ `Mélodie`

- Lien Entry <=> Conique ⚠️ `Mélodie`
- Au lieu d'avoir le processus dans le main ⚠️ `Mélodie`
  - Dessiner les points
  - Dessiner la conique
  - [-] Dessiner les droites (tangente)

### Semaine 2 (Deadline : Mercredi 15 novembre) :

⚠️**Conique**

- [-] **(Bonus)** Constructeur (5 tangentes)

---

**Fichier**

- Récupérer les coordonnées depuis un fichier

---

**(Bonus)** Faisceau

---

**doctest** (cf. Semaine 2)

- avec un point à l'infini

---

- Affichez des coniques du faisceau C(t) et vérifiez que ces coniques passent toutes par les points d’intersection entre Ca et Cb.  
   $C(t) = cos(t)C_a + sin(t)C_b$ avec t ∈ [0, π]  
   faisceau == combinaison linéaire de 2 coniques  
   /!\ Pensez à normer les coniques Ca et Cb en divisant chacune de leur composante par leur norme respective : $‖C‖ = \sqrt{(a² + b² + c² + d² + e² + f²)}$

---

#### Exemple d'utilisation vers géogébra

**Point**

```C++
// draw points
  Eigen::VectorXd pt1(2), pt2(2);
  pt1 << 1.5, 2.0;
  pt2 << -2.0, -1.0;
  viewer.push_point(pt1, "p1", 200, 0, 0); //avec descriptions
  viewer.push_point(pt2, 200, 0, 0);
```

**Ligne**

```C++
// draw points
    viewer.push_line(pt1, pt2 - pt1, 200, 200, 0); //point, direction, couleur * 3
```

**Conique**

```C++
  // draw conic
  Eigen::VectorXd conic(6);
  conic << 1.4, -0.3, -1, -0.6, 0.0, 0.8; //coeff  conique - hyperbole
  viewer.push_conic(conic, 0, 0, 200);

  Eigen::VectorXd conic2(6);
  conic2 << -1.4, -0.3, -1, -0.6, 0.0, 0.8; //coeff conique - ellipse
  viewer.push_conic(conic2, 0, 0, 200);

```

### Semaine 2 (Deadline : Dimanche 19 novembre) :

- questions maths avancées
- Construction de conique
- [-] Exemples :

  - [-] cercle ($a = c$ et $b = 0$)

    ```C++
    Conic c = Conic(Point{1, 0}, Point{sqrt(3) / 2., 1 / 2.},
                  Point{sqrt(2) / 2., sqrt(2) / 2.},
                  Point{-sqrt(3) / 2., 1 / 2.}, Point{0, 1});

    ```

  - [-] ellipse ($b^2 − 4ac < 0$)

    ```C++

    ```

  - [-] parabole ($b^2 − 4ac = 0$)

    ```C++

    ```

  - [x] hyperbole ($b^2 − 4ac > 0$)
        `C++
 Conic c = Conic({3, 5}, Point{1, 2},
              Point{0, 4},
              Point{3, 3}, Point{2, 4});
`
        exemple marrant

  ```C++
     Conic c = Conic({3, 5}, Point{1, 2},
                  Point{0, 4},
                  Point{6, 6}, Point{2, 8});
  ```

### Semaine 3 (Deadline : Mardi 21 novembre) :

- Réunion Lundi 20 (vers 16h à la fac) : Revoir les questions non terminées
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

- [x] Pourquoi peut-on résoudre ce système avec uniquement 5 points ?
- [x] Montrez pourquoi la tangente l d’une conique C passant par le point x ∈ C s’exprime sous la forme : l = Cx
- [x] Différence entre la distance algébrique et géométrique  
   géométrique : distance minimale entre le point et la conique  
   algébrique : d = ax² + bxy + cy² + dxw + eyw + fw²
- [-] Explorer les propriétés des points et des droites en rapport avec les coniques

## Mathématiques avancés

- [x] Comment peut-on construire une conique à partir de 5 tangentes ? (cf section 2.1)
- [x] Affichez des coniques du faisceau C(t) et vérifiez que ces coniques passent toutes par les points d’intersection entre Ca et Cb.  
   C(t) = cos(t)Ca + sin(t)Cb avec t ∈ [0, π]  
   faisceau == combinaison linéaire de 2 coniques  
   /!\ Pensez à normer les coniques Ca et Cb en divisant chacune de leur composante par leur norme respective : ‖C‖ = sqrt(a² + b² + c² + d² + e² + f²)
- [x] Dans certains cas, une conique peut être une paire de droites. Quelle est l’équation de cette conique ? Comment la construire ?
- [x] Il se trouve qu’une conique peut même être un point (un cercle de rayon nul). Quelle est l’équation de cette conique ?

# Programmation

- [x] Calculer conique passant par 5 points (aléatoire ou depuis un fichier)
- [-] Cas de point à l'infini ( = $(x,y,0)^T$)
- [x] Extension du code : cas surdéterminée (+ de 5 points)
  - [x] Cas éventuel où aucune conique ne correspond => conique la + proche au sens des moindres carrés
- [-] Fournir des **exemples** pour montrer que le code marche (et pour aider à l'utilisation)
- [-] Tester le projet avec plusieurs compilateur (à noter dans le rapport ???)
- [x] Code lisible => bien séparer nos fichiers

## A utiliser dans notre code ✅

Voici ce qu’il serait bon de rencontrer dans votre projet :

- [x] polymorphisme
- [x] usage d’outils de la STL FOR_EACH
- [x] exceptions pour traiter les erreurs
- [-] asserts pour détecter et prévenir les erreurs de programmation
- [-] espaces de nommage (namespace)
- [-] fonctions lambdas constexpr
- [x] (bonus) fonctions variadics

## ⚠️ Attention ⚠️

- Mauvais organisation de fichier
- des variables, des fonctions ou des types mal nommés
- des références _non constantes_ alors qu’elles devraient l’être
- des _passages par copies non justiﬁés_
- des _erreurs de segmentation_
- des _fuites de mémoires_ => utiliser valgrind
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
