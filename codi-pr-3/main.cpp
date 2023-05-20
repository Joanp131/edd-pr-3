//
// Created by Joanp on 4/5/2023.
//
#include <chrono>
#include "ArbreBinari.h"
#include "CercadorMoviesAB.h"
#include "CercadorMoviesHeap.h"
#include "MinHeap.h"

void prova_ex_1();

int obte_opcio_menu(vector<string> &desc);

void mainArbreBinari();

void mainHeap();

void casDeProvaExercici3();

int main() {

//    prova_ex_1();

    //mainArbreBinari();
    mainHeap();
    return 0;
}

int obte_opcio_menu(vector<string> &desc) {

    int opcio;

    cout << "******************** MENU ********************" << endl;
    for (int i = 0; i < desc.size(); i++) {
        cout << i + 1 << "_ " << desc[i] << endl;
    }

    cout << "-> ";
    cin >> opcio;

    while (opcio < 1 || opcio > desc.size()) {
        cout << "\nL'opció entrada és incorrecta, torna-ho a provar: ";
        cin >> opcio;
    }

    return opcio;
}

void prova_ex_1() {
    // Arbre binari buit
    ArbreBinari<int, int> tree1 = ArbreBinari<int, int>();

    int testKeys[] = {2, 0, 8, 45, 76, 5, 3, 40};
    int testValues[] = {5, 5, 1, 88, 99, 12, 9, 11};

    // Omplim l'arbre amb els valors i claus donades
    for (int i = 0; i < 8; i++) {
        tree1.insert(testKeys[i], testValues[i]);
    }

    tree1.imprimirPreordre();
    tree1.imprimirInordre();
    tree1.imprimirPostordre();

    vector<NodeBinari<int, int> *> vect = tree1.obteValorsRang(5, 45);
    cout << "\nObteValorsRang = {";
    for (NodeBinari<int, int> *i: vect) {
        cout << i->getKey() << ", ";
    }
    cout << "\b\b}" << endl;

    ArbreBinari<int, int> tree2 = ArbreBinari<int, int>(tree1);
    tree2.imprimirPostordre();

    tree2.imprimirCami(40);

    tree2.eliminaMinim();
    tree2.imprimirInordre();
    tree2.eliminaMinim();
    tree2.imprimirInordre();
    tree2.eliminaMinim();
    tree2.imprimirInordre();
    tree2.eliminaMinim();
    tree2.imprimirInordre();

//    delete &tree1;
}

void mainArbreBinari() {

    CercadorMoviesAB cerca = CercadorMoviesAB();

    vector<string> desc{
            "Llegeix dades d'un fitxer",
            "Mostra l'arbre per ID creixent",
            "Cerca per ID",
            "Mostra la profunditat",
            "Esborra les n pel·lícules més petites",
            "Surt"
    };

    int opcio = obte_opcio_menu(desc);

    ifstream ids("cercaPelicules.txt");

    while (opcio != 6) {

        switch (opcio) {
            /**
             * Case 1:
             *  Llegeix un fitxer i guarda les dades de les pel·lícules dins el cercador
             */
            case 1:
                char opt;
                cout << "\nQuin fitxer vols? (P/G): ";
                cin >> opt;

                if (opt == 'P' || opt == 'p') {
                    cout << "\nLlegint el fitxer 'movie_rating_small.txt'" << endl;

                    chrono::steady_clock::time_point begin = chrono::steady_clock::now();
                    cerca.appendMovies("movie_rating_small.txt");
                    chrono::steady_clock::time_point end = chrono::steady_clock::now();

                    cout << "Temps transcorregut: "
                         << chrono::duration_cast<chrono::microseconds>(end - begin).count() << " micro s."
                         << endl;
                } else {
                    cout << "\nLlegint el fitxer 'movie_rating.txt'" << endl;

                    chrono::steady_clock::time_point begin = chrono::steady_clock::now();
                    cerca.appendMovies("movie_rating.txt");
                    chrono::steady_clock::time_point end = chrono::steady_clock::now();

                    cout << "Temps transcorregut: "
                         << chrono::duration_cast<chrono::microseconds>(end - begin).count() << " micro s."
                         << endl;
                }

                break;

            case 2:
                /**
                 * <b>Case 2:</b>
                 *  Mostra l'arbre per ID creixent. Cada 40 linies, pregunta a l'usuari si vol seguir imprimint.
                 */
//                cerca.imprimirInordre();
                break;

            case 3:
                /**
                 * Case 3:
                 *  Llegeix el fitxer "cercaPelicules.txt", i per cada ID imprimeix informació de la pel·lícula
                 */
                if (ids.is_open()) {
                    int found = 0, total = 0;
                    while (ids) {
                        int id;
                        ids >> id;

                        try {
                            cout << cerca.buscarMovie(id).print() << endl;
                            found++;
                        } catch (exception ex) {
                            // cout << ex.what() << endl;
                        }
                        total++;
                    }

                    cout << "\nCerca finalitzada. S'han trobat " << found << " pel·lícules de " << total << " buscades"
                         << endl;
                } else {
                    cout << "No s'ha pogut obrir el fitxer 'cercaPelicules.txt'" << endl;
                }

                break;

            case 4:
                /**
                 * Case 4:
                 *  Mostra per pantalla la profunditat de l'arbre
                 */
                cout << "Profunditat de l'arbre: " << cerca.height() << endl;
                break;

            case 5:
                /**
                 * Case 5:
                 *  Esborra les n pel·lícules amb l'ID més petit.
                 *  El valor de n es demana a l'usuari
                 */
                int num;
                cout << "Quantes pel·lícules vols eliminar? ";
                cin >> num;
                cerca.eliminarMinimaMovie(num);
            default:
                break;
        }

        opcio = obte_opcio_menu(desc);
    }

}

void mainHeap() {

    // Min Heap
    CercadorMoviesHeap cerca = CercadorMoviesHeap();

    vector<string> desc{
            "Llegeix dades d'un fitxer",
            "Mostra l'arbre per ID creixent",
            "Cerca per ID",
            "Mostra la profunditat",
            "Esborra les n pel·lícules més petites",
            "Surt"
    };

    int opcio = obte_opcio_menu(desc);

    ifstream ids("cercaPelicules.txt");

    while (opcio != 6) {

        switch (opcio) {

            case 1:
                /**
                 * Llegeix les dades del fitxer
                 */
                char opt;
                cout << "\nQuin fitxer vols? (P/G): ";
                cin >> opt;

                if (opt == 'P' || opt == 'p') {
                    cout << "\nLlegint el fitxer 'movie_rating_small.txt'" << endl;

                    chrono::steady_clock::time_point begin = chrono::steady_clock::now();
                    cerca.appendMovies("movie_rating_small.txt");
                    chrono::steady_clock::time_point end = chrono::steady_clock::now();

                    cout << "Temps transcorregut: "
                         << chrono::duration_cast<chrono::microseconds>(end - begin).count() << " micro s."
                         << endl;
                } else {
                    cout << "\nLlegint el fitxer 'movie_rating.txt'" << endl;

                    chrono::steady_clock::time_point begin = chrono::steady_clock::now();
                    cerca.appendMovies("movie_rating.txt");
                    chrono::steady_clock::time_point end = chrono::steady_clock::now();

                    cout << "Temps transcorregut: "
                         << chrono::duration_cast<chrono::microseconds>(end - begin).count() << " micro s."
                         << endl;
                }
                break;

            case 2:
                /**
                 * Mostra l'arbre per ID creixent
                 */
                break;

            case 3:
                /**
                 * Cerca per ID
                 */
                if (ids.is_open()) {
                    int found = 0, total = 0;
                    while (ids) {
                        int id;
                        ids >> id;

                        try {
                            cout << cerca.buscarMovie(id).print() << endl;
                            found++;
                        } catch (exception ex) {
                            // cout << ex.what() << endl;
                        }
                        total++;
                    }

                    cout << "\nCerca finalitzada. S'han trobat " << found << " pel·lícules de " << total << " buscades"
                         << endl;
                } else {
                    cout << "No s'ha pogut obrir el fitxer 'cercaPelicules.txt'" << endl;
                }
                break;

            case 4:
                /**
                 * Retorna l'alçada de l'arbre
                 */
                cout << "Profunditat de l'arbre: " << cerca.height() << endl;
                break;

            case 5:
                /**
                 * Esborra les n pel·lícules més petites
                 */
                int num;

                cout << "Quantes pel·lícules vols eliminar? ";
                cin >> num;

                cerca.eliminarMinimaMovie(num);
            default:
                break;
        }

        opcio = obte_opcio_menu(desc);
    }

}

void casDeProvaExercici3() {
    std::cout << " ------------- cas de prova exercici 3 ----------- " << std::endl;
    MinHeap<int, int> heap1;
    int testKeys[] = {2, 0, 8, 45, 76, 5, 3, 40};
    int testValues[] = {5, 5, 1, 88, 99, 12, 9, 11};
    for (int i = 0; i < 8; i++) {
        heap1.inserir(testKeys[i], testValues[i]);
    }
    cout << "heap1 ={ ";
    heap1.imprimir();
    cout << "}" << endl;
    cout << "Mida Heap recent creat: " << heap1.tamany() << endl;
    cout << "Alçada Heap recent creat: " << heap1.altura() << endl;
    cout << "Heap recent creat. is esBuit? (0/1): " << heap1.esBuit() << endl;
    cout << "Clau minima " << heap1.minim() << endl;

    cout << "EliminaMinim" << endl;
    heap1.eliminaMinim();
    cout << "Heap despres eliminar 1. Print: " << endl;
    heap1.imprimir();
    cout << "Mida Heap recent creat: " << heap1.tamany() << endl;
    cout << "Alçada Heap recent creat: " << heap1.altura() << endl;
    heap1.eliminaMinim();
    cout << "Heap despres eliminar 2. Print: " << endl;
    heap1.imprimir();
    cout << "Mida Heap recent creat: " << heap1.tamany() << endl;
    cout << "Alçada Heap recent creat: " << heap1.altura() << endl;
}
