/*
Temaet er datastrukturer med fokus på, hvordan binære træer kan være praktiske.
Forestil jer følgende opgave:
Du er givet n kasser, som er nummereret fra 1 til n.
Til at starte med er der 1 glaskugle i hver kasse.
Programmet skal udføre m instruktioner. I hver instruktion skal programmet gøre en af følgende ting:
1. Putte x glaskugler i boks nr y.
2. Fortælle hvor mange glaskugler der i boks z, z+1, z+2, ..., w tilsammen.

Hvis man bruger et array til at huske, hvor mange glaskugler der er i hver kasse, så tager operation O(n) tid,
og man ender på en samlet tid der er O(n*m). Nedenunder er løsningen med et array implementeret.

For at i kan forstå, hvordan programmet læser input kommer her en specifikation:
På linie 1 er det to heltal: n og m henholdsvis.
Hver af linie 2,..,m+1 repræsenterer en instruktion og består af 3 heltal.
   Det første heltal repræsenterer typen af instruktion. 
     Hvis det første tal er 1: Så er de to næste tal x og y: 1 3 5 vil betyde at man skal putte 3 glaskugler i boks nr 5.
	 Hvis det første tal er 2: Så er de to næste tal z og w: 2 1 2 vil betyde at man skal udskrive hvor mange glaskugler der tilsammen er i boks 1 og 2.

Men det kan selvfølgelig gøres smartere end i O(n*m) tid. Det kan gøres i O(m*log(n)) tid ved at bruge et binært træ.
Lad os for eksemplets skyld antage at n = 4, og betragt følgende træ:

        A
	  /   \
	 B     C
	/ \   / \
   D  E   F  G

Ved hver knude skrives et tal. Ved D skrives antallet af kugler i boks 1. Ved E antallet i boks 2, F har antallet i boks 3 og G i boks 4.
B er summen af kuglerne i boks D og E. C er summen af F og G. A er sumen af B og C.
A dækker altså over kuglerne 1..4, B har 1..2, C har 3..4, D har 1..1, E har 2..2, F har 3..3, G har 4..4.

        A1..4
	  /       \
    B1..2     C3..4
   /   \       / \
  D1   E2     F3  G4

Når man skal tilføje x kugler til boks 3 skal man altså lægge x til F, C og A.
Skal man bygge træet for et generelt n, så gør man det således:
Regel 1. Roden dækker over kuglerne 1..n.
Regel 2. Hvis en knude dækker over i..j og i=j så er den et blad.
Regel 3. Hvis en knude dækker over i..j og i!=j så dækker det venstre barn over i..((i+j)/2) og det højre over ((i+j)/2+1)..j.

Rent praktisk så gemmer vi alle værdierne fra træets knuder i en vektor, som vi kalder tree.
tree[1] indeholder rodens værdi.
Hvis tree[p] indeholder en knudes værdi, og knuden ikke er et blad, så indeholder tree[2*p] det venstre blads værdi og tree[2*p+1] det højre blads værdi.
I tilfældet med n=4 vil vi altså have A = tree[1], B = tree[2], C = tree[3], D = tree[4], E = tree[5], F = tree[6], F = tree[7].


FLERE OPGAVER:
Opgave 1:
  Lav instruktion nr 3, hvor input er på formen 3 x y z. Der skal lægges x kugler i hver af boksene y,y+1,..,z. Det kan antages at y <= z.
Opgave 2:
  Lav instruktion nr 4, hvor input er på formen 3 x. Den skal udskrive det mindste y således at boksene 1, 2, .., y har mindst x kugler.
  Det kan antages at der er mindst x kugler i boksene 1, 2, ..., n.
Opgave 3:
  n mennesker står i en cirkel og de er nummereret fra 1 til n.
  En bødel går rundt i cirklen og dræber hver m'te person. Hvem overlever?
  Hvis fx n = 7 og m = 2, så dør menneskene i rækkefølgen 1, 3, 5, 7, 4, 2. Derfor overlever person nr 6 altså.

*/
/*
-------Array implementation af opgaven-------
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, m;
vector<int> boxContent;

int main() {
	cin >> n >> m;
	boxContent.resize(n+1);
	for(int i = 1;i <= n; ++i) {
		boxContent[i] = 1;
	}
	for(int i = 0;i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		if(a == 1) {
			boxContent[c] += b;
		} else {
			int sum = 0;
			for(int j = b; j <= c; ++j) {
				sum += boxContent[j];
			}
			cout << sum << endl;
		}
	}
	return 0;
}
*/
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, m;
vector<int> tree;

//Bygger indledningsvist træet, så tree indeholder de rigtige værdier
void buildTree(int p, int i, int j) {
	//tree[p] dækker over i..j, så den dækker over j-i+1 kasser, dvs. der er j-i+1 glaskugler
	// tree[p] = j-i+1;
	tree[p] = j-i+1;
	if(j > i) { 
    //Hvis p ikke er positionen på et blad, bygger vi den op rekursivt.
		buildTree(2*p,    i,         (i+j)/2);
		buildTree(2*p+1,  (i+j)/2+1, j);
	}
}
//Tilføjer x kugler til boks nr y. Vi modificerer kun træet fra position p og nedefter.
void addToTree(int p, int i, int j, int x, int y) {
	//Kun hvis i <= y og y <= j er denne del af træet berørt af ændringen.
	if(i <= y && y <= j) {
		tree[p] += x;
		if(j > i) { //Hvis knuden ikke er et blad skal børnene også modificeres.
			addToTree(  2*p,         i, (i+j)/2, x, y);//Kald rekursivt
			addToTree(2*p+1, (i+j)/2+1,       j, x, y);//Kald rekursivt
		}
	}
}

void addToRangeTree(int p, int i, int j, int x, int y, int a) {
  printf("In at %d..%d\n", i, j);
	if((i <= x && y <= j) || j - i == 0) { // included in range, or leaf
		tree[p] += (j - i + 1) * a;

		if(j - i != 0) {  // not leaf
			addToRangeTree(2*p,         i, (i+j)/2, x, y, a);
			addToRangeTree(2*p+1, (i+j)/2+1,       j, x, y, a);
		}
	}
}

//Returnerer summen fra boksene z,z+1,..,w.
int getSum(int p, int i, int j, int z, int w) {
	if(z <= i && j <= w) { 
		return tree[p];//Alle boksene som knuden dækker over skal tælles med.
	} else if(z > j || w < i) { 
		return 0;//Ingen af boksene som knuden dækker over skal tælles med.
	} else {
		return getSum(2*p,   i,         (i+j)/2,  z,  w) +  // venstre
			     getSum(2*p+1, (i+j)/2+1,       j,  z,  w); // højre
			   //Noget skal tælles med, men ikke det hele, så vi kalder rekursivt.
	}
}

int searchMinRangeTree(int s) {
  int bottom = 1;
  int top = n;
  int mid = top/2;

  while(top - bottom != 1) {
    mid = (top + bottom) / 2;

    if(getSum(1,1,n,1,mid) >= s) top = mid;
    else bottom = mid;
  }

  return top;
}

int main() {
	cin >> n >> m;
	tree.resize(4*n);
	//Først bygges træet, og det angives at roden, dvs. position 1, dækker over 1..n
	buildTree(1, 1, n);
	for(int i = 0;i < m; ++i) {
		int a, b, c, d;
    cin >> a;

		if(a == 1) {
      cin >> b >> c;
			addToTree(1, 1, n, b, c);
		} else if(a == 2) {
      cin >> b >> c;
			cout << getSum(1, 1, n, b, c) << endl;
    } else if(a == 3) {
      cin >> b >> c >> d;
      addToRangeTree(1, 1, n, c, d, b);
	  } else if(a == 4) {
      cin >> a;
      cout << searchMinRangeTree(a) << endl;
    } else if(a == 5) {
      // Opgave 3:
      //   q mennesker står i en cirkel og de er nummereret fra 1 til q.
      //   En bødel går rundt i cirklen og dræber hver p'te person. Hvem overlever?
      //   Hvis fx q = 7 og p = 2, så dør menneskene i rækkefølgen 
      //   1, 3, 5, 7, 4, 2. Derfor overlever person nr 6 altså.
      
      int p, q;
      cin >> p >> q;

      // O(n * log(n))
      // Lav træet så alle har værdien 1
      for(size_t i = 1; i <= p; i++)
        addToTree(1, 1, n, 1, i);
    }

  }

	return 0;
}
