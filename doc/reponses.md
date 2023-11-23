# Les coniques

par Tanya FRANCOIS et Mélodie KOUY

## Questions à répondre

- Pourquoi peut-on résoudre ce système avec uniquement 5 points ?

  ### Explication 1 :

  Le 6e point correpsond à une coordonnée homogène qui permettrait d'utiliser des décompositions en valeurs singulières (SVG) sur les matrices _ainsi il n'est pas nécessaire de la prendre en compte dans le système._

  ### Explication 2 :

  - la formule ax² + bxy + cy² + dx + ey + f = 0 a 6 paramètres : A, B, C, D, E, F
  - En divisant cette formule par l'un de ses paramètres (en supposant qu'elle est différentes de 0) on obtiendrait :
  - $\frac{a}{a}x² + \frac{b}{a}xy + \frac{c}{a}y² + \frac{d}{a}x + \frac{e}{a}y + \frac{e}{a} = \frac{0}{a}$
  - $x² + \frac{b}{a}xy + \frac{c}{a}y² + \frac{d}{a}x + \frac{e}{a}y + \frac{e}{a} = 0$
  - A partir de cette équivalence on obtient une équation à 5 paramètres : $x² + B'xy + C'y² + D'x + E'y + F' = 0$

`Note` : voir la relation avec les moindres carrés.  
 | avec au moins 5 points, on résout au sens des moindres carrés : noyau de la matrice (right nullspace) avec une SVD

---

- Montrez pourquoi la tangente $l$ d’une conique $C$ passant par le point $x ∈ C$ s’exprime sous la forme : $l = Cx$

  Par définition :

  - ~~une droite $l$ est tangente à la conique C ssi : l<sup>T</sup>C<sup>−1</sup>l = 0.~~
  - un point $x = (x, y, w)^T$ appartient à une conique $C$ ssi : $x^TCx = 0$
  - un point $x = (x, y, w)^T$ appartient à une droite $l$ ssi : $x^Tl = l^Tx = 0$

  Ainsi, en cherchant le point d'intersection entre une conique et une droite, on a :  
   $$x^Tl = x^T Cx$$
  par reconnaissance on obient :
  $$\Leftrightarrow l = Cx$$

---

- Différence entre la distance algébrique et la distance géométrique

  - La distance géométrique correspond à la distance minimale entre le point et la conique. Autrement dit :

    - En 2D : $\sqrt{(a_x-b_x)^2+(a_y-b_y)^2}$
    - Formule générale (norme) : $\lVert X \rVert_p = (\sum^n_{i=1} \mid X_i\mid^p)^{\frac{1}{p}}$

  - La distance algébrique  
     $$d = ax² + bxy + cy² + dxw + eyw + fw²$$

On remarque la distance géométrique est forcément positive par définition (valeurs absolue) alors qu'avec la distance algébrique, les signes sont conservés (ceux des <span style='color:blue;'>paramètres</span> et ceux des <span style='color:red;'>coordonnées</span>):

$$
d = \color{blue}a \color{white}x²
+ \color{blue}b \color{red}xy \color{white}
+ \color{blue}c \color{white}y²
+ \color{blue}d \color{red}xw \color{white}
+ \color{blue}e \color{red}yw \color{white}
+ \color{blue}f \color{white}w²
$$

## Mathématiques avancés

1. Comment peut-on construire une conique à partir de 5 tangentes ? (cf section 2.1)

On peut utiliser 5 tangentes pour construire une conique car cela revient à trouver 5 points appartenant à la fois à la conique et à ses 5 tangentes.

---

2. Dans certains cas, une conique peut être une paire de droites. Quelle est l’équation de cette conique ? Comment la construire ?

<u><b>Equation de la conique</b></u>

l'équation d'une droite est : $ax + by + c = 0$  
On joint alors l'équation de deux droites pour avoir :

$(ax_1+ by_1 +c) * (ax_2 + by_2 + c) = 0$

En développant on retrouve bien la formule de la conique générale :

$$
\begin{gather*}\\
(ax+by+c)(dx+ey+f)= \\
\color{red}ad \color{white}x^2 + \color{red}(ae+bd) \color{white}xy + \color{red}be \color{white}y^2 + \color{red}(af+cd) \color{white}x + \color{red}(bf+ce) \color{white}y+ \color{red}cf \\
= \\
Ax² + Bxy + Cy² + Dx + Ey + F
\end{gather*}
$$

<u><b>Comment la construire</b></u>

Pour le réaliser, il suffit d'avoir trois points sont alignés, on obtient une conique composée d'une paire de droites.

---

3. Il se trouve qu’une conique peut même être un point (un cercle de rayon nul). Quelle est l’équation de cette conique ?

L'équation d'un cercle est :

$$x^2+y^2=r^2$$
Pour avoir un point on doit avoir :
$$x^2+y^2=0$$

Donc dans le cas de la conique, on obtient l'équation :
$$Ax^2+Cy^2=0$$
