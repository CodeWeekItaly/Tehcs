#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <windows.h>
#include "CppSQLite3.h"

using namespace std;

CppSQLite3DB db;

void clear_screen()
{
#ifdef _WIN32
    std::system("cls");
#else
    // Assume POSIX
    std::system ("clear");
#endif
}

void esciProgramma() {
    try {
        db.close();
    }
    catch (...){

    }
    exit(0);
}

int main()
{
    float logout, prodotto, prezzo, numordini;
    int tipologin;
    char nomeprodotto[128], utente[128], password[128], verificaut[128], verificapass[128], unita[128], nomeordini[128], regione[128], data[128];
    char query[128];
    char scelta;
    char registrazione;

    CppSQLite3Table q;

    string userId;
    string userName;
    string userTipo;

    cout << "SQLite Version: " << db.SQLiteVersion() << endl;

    db.open("database.db3");
    cout << db.execScalar("select count(*) from utenti;")
           << " record nella tabella 'utenti'" << endl;

    cout << "Inserire il tipo di operazione che si vuole fare" << endl;
    cout << "R=registrazione" << endl;
    cout << "A=accedi" << endl;
    cin >> registrazione;
    switch (registrazione) {
        case 'R':
            cout << "Inserire il nome Utente: ";
            scanf("%s",utente);
            cout << "Inserire la password: ";
            scanf("%s",password);
            cout << "Inserire la regione di provenienza: ";
            scanf("%s", regione);
            do
            {
                cout<<"Sei un venditore oppure un acquirente?"<<endl;
                cout<<"Digita 'V' per registrarti come Venditore"<<endl;
                cout<<"Digita 'A' per registrarti come Acquirente"<<endl;
                cin>>scelta;
                system ("CLS");
            }
            while(scelta!='V' && scelta!='A' && scelta!='v' && scelta!='a');
            cout << "Inserire la regione di provenienza";
            scanf("%s", regione);
            switch(scelta)
            {
                case 'V': tipologin= 1;
                break;
                case 'v': tipologin= 1;
                break;
                case 'A': tipologin= 2;
                break;
                case 'a': tipologin= 2;
                break;
            }

            // inserisco l'utente nella tabella utenti
            sprintf(query, "INSERT INTO utenti (username,password,tipo,regione) VALUES ('%s','%s','%u','%s');", utente , password , tipologin, regione);
            printf("%s",query);
            db.execDML(query);
            cout << " primary key: " << db.lastRowId() << endl;
            clear_screen();
            do {
                cout << "Effettuare il login" << endl;
                cout << "Inserire il nome utente: ";
                scanf("%s",verificaut);
                cout << "Inserire la password: ";
                scanf("%s",verificapass);

                sprintf(query, "SELECT * FROM utenti WHERE username='%s' AND password='%s';", verificaut , verificapass);
                q = db.getTable(query);


            } while (q.numRows()==0);

            userId = q.fieldValue(0);
            userName = q.fieldValue(1);
            userTipo = q.fieldValue(3);
            cout << userTipo;

            if (userTipo=="1") {
                cout << "Benvenuto nella pagina dedicata ai venditori";
                cout<<"Inserire il nome del prodotto \n";
                scanf("%s",nomeprodotto);
                cout<<"Inserire il prezzo unitario del prodotto \n";
                scanf("%f",&prezzo);
                cout<<"Inserire il peso unitario del prodotto \n";
                scanf("%s", unita);
                sprintf(query, "INSERT INTO prodotti (nome,prezzo,unita) VALUES ('%s','%f','%s');", nomeprodotto , prezzo , unita);
                printf("%s",query);
                db.execDML(query);
                cout << " primary key: " << db.lastRowId() << endl;
                esciProgramma();
            }
            else {
                cout << "Benvenuto nella pagina dedicata agli acquirenti" << endl;
                q = db.getTable("SELECT * FROM prodotti;");

                for (int row = 0; row < q.numRows(); row++)
                    {
                        q.setRow(row);
                        for (int fld = 0; fld < q.numFields(); fld++)
                        {
                            if (!q.fieldIsNull(fld))
                                cout <<q.fieldValue(fld) << "|";
                            else
                                cout << "NULL" << "|";
                        }
                        cout << endl;
                    }

                cout << "Inserire il nome dell'oggetto che si desidera acquistare: ";
                cin >> nomeordini;
                cout << "inserire il numero di unita da acquistare";
                cin >> numordini;
                sprintf(query, "INSERT INTO ordini (nome,numero,data) VALUES ('%s','%f','%s');", nomeordini , numordini, data);
                printf("%s",query);
            }
            break;

        case 'r':
            cout << "Inserire il nome Utente: ";
            scanf("%s",utente);
            cout << "Inserire la password: ";
            scanf("%s",password);
            cout << "Inserire la regione di provenienza: ";
            scanf("%s", regione);

            do
            {
                cout<<"Sei un venditore oppure un acquirente?"<<endl;
                cout<<"Digita 'V' per registrarti come Venditore"<<endl;
                cout<<"Digita 'A' per registrarti come Acquirente"<<endl;
                cin>>scelta;
                system ("CLS");
            }
            while(scelta!='V' && scelta!='A' && scelta!='v' && scelta!='a');

            switch(scelta)
            {
                case 'V': tipologin= 1;
                break;
                case 'v': tipologin= 1;
                break;
                case 'A': tipologin= 2;
                break;
                case 'a': tipologin= 2;
                break;
            }

            // inserisco l'utente nella tabella utenti
            sprintf(query, "INSERT INTO utenti (username,password,tipo,regione) VALUES ('%s','%s','%u','%s');", utente , password , tipologin, regione);
            printf("%s",query);
            db.execDML(query);
            cout << " primary key: " << db.lastRowId() << endl;
            clear_screen();
            do {
                cout << "Effettuare il login" << endl;
                cout << "Inserire il nome utente: ";
                scanf("%s",verificaut);
                cout << "Inserire la password: ";
                scanf("%s",verificapass);

                sprintf(query, "SELECT * FROM utenti WHERE username='%s' AND password='%s';", verificaut , verificapass);
                q = db.getTable(query);


            } while (q.numRows()==0);

            userId = q.fieldValue(0);
            userName = q.fieldValue(1);
            userTipo = q.fieldValue(3);
            cout << userTipo;

            if (userTipo=="1") {
                cout << "Benvenuto nella pagina dedicata ai venditori";
                cout<<"Inserire il nome del prodotto \n";
                scanf("%s",nomeprodotto);
                cout<<"Inserire il prezzo unitario del prodotto \n";
                scanf("%f",&prezzo);
                cout<<"Inserire il peso unitario del prodotto \n";
                scanf("%s", unita);
                sprintf(query, "INSERT INTO prodotti (nome,prezzo,unita) VALUES ('%s','%f','%s');", nomeprodotto , prezzo , unita);
                printf("%s",query);
                db.execDML(query);
                cout << " primary key: " << db.lastRowId() << endl;
                esciProgramma();
            }
            else {
                cout << "Benvenuto nella pagina dedicata agli acquirenti" << endl;
                q = db.getTable("SELECT * FROM prodotti;");

                for (int row = 0; row < q.numRows(); row++)
                    {
                        q.setRow(row);
                        for (int fld = 0; fld < q.numFields(); fld++)
                        {
                            if (!q.fieldIsNull(fld))
                                cout <<q.fieldValue(fld) << "|";
                            else
                                cout << "NULL" << "|";
                        }
                        cout << endl;
                    }

                cout << "Inserire il nome dell'oggetto che si desidera acquistare: ";
                cin >> nomeordini;
                cout << "inserire il numero di unita da acquistare";
                cin >> numordini;
                sprintf(query, "INSERT INTO ordini (nome,numero,data) VALUES ('%s','%f','%s');", nomeordini , numordini, data);
                printf("%s",query);
            }
            break;

        case 'A':
            do {
                cout << "Effettuare il login" << endl;
                cout << "Inserire il nome utente: ";
                scanf("%s",verificaut);
                cout << "Inserire la password: ";
                scanf("%s",verificapass);

                sprintf(query, "SELECT * FROM utenti WHERE username='%s' AND password='%s';", verificaut , verificapass);
                q = db.getTable(query);


            } while (q.numRows()==0);

            userId = q.fieldValue(0);
            userName = q.fieldValue(1);
            userTipo = q.fieldValue(3);
            cout << userTipo;

            if (userTipo=="1") {
                cout << "Benvenuto nella pagina dedicata ai venditori";
                cout<<"Inserire il nome del prodotto \n";
                scanf("%s",nomeprodotto);
                cout<<"Inserire il prezzo unitario del prodotto \n";
                scanf("%f",&prezzo);
                cout<<"Inserire il peso unitario del prodotto \n";
                scanf("%s", unita);
                sprintf(query, "INSERT INTO prodotti (nome,prezzo,unita) VALUES ('%s','%f','%s');", nomeprodotto , prezzo , unita);
                printf("%s",query);
                db.execDML(query);
                cout << " primary key: " << db.lastRowId() << endl;
                esciProgramma();
            }
            else {
                cout << "Benvenuto nella pagina dedicata agli acquirenti" << endl;
                q = db.getTable("SELECT * FROM prodotti;");

                for (int row = 0; row < q.numRows(); row++)
                    {
                        q.setRow(row);
                        for (int fld = 0; fld < q.numFields(); fld++)
                        {
                            if (!q.fieldIsNull(fld))
                                cout <<q.fieldValue(fld) << "|";
                            else
                                cout << "NULL" << "|";
                        }
                        cout << endl;
                    }

                cout << "Inserire il nome dell'oggetto che si desidera acquistare: ";
                cin >> nomeordini;
                cout << "inserire il numero di unita da acquistare";
                cin >> numordini;
                sprintf(query, "INSERT INTO ordini (nome,numero,data) VALUES ('%s','%f','%s');", nomeordini , numordini, data);
                printf("%s",query);
            }
            break;

        case 'a': clear_screen();
            do {
                cout << "Effettuare il login" << endl;
                cout << "Inserire il nome utente: ";
                scanf("%s",verificaut);
                cout << "Inserire la password: ";
                scanf("%s",verificapass);

                sprintf(query, "SELECT * FROM utenti WHERE username='%s' AND password='%s';", verificaut , verificapass);
                q = db.getTable(query);


            } while (q.numRows()==0);

            userId = q.fieldValue(0);
            userName = q.fieldValue(1);
            userTipo = q.fieldValue(3);
            cout << userTipo;

            if (userTipo=="1") {
                cout << userName << ": Benvenuto nella pagina dedicata ai venditori";
                do {
                    cout<<"Inserire il nome del prodotto (x per terminare inserim.)\n";
                    scanf("%s",nomeprodotto);
                    if (nomeprodotto=="x") break;
                    cout<<"Inserire il prezzo unitario del prodotto \n";
                    scanf("%f",&prezzo);
                    cout<<"Inserire il peso unitario del prodotto \n";
                    scanf("%s", unita);
                    sprintf(query, "INSERT INTO prodotti (nome,prezzo,unita,idvenditore) VALUES ('%s','%f','%s',%u);", nomeprodotto , prezzo , unita, userId);
                    printf("%s",query);
                    db.execDML(query);
                    cout << " primary key: " << db.lastRowId() << endl;
                } while (true);
                esciProgramma();
            }
            else {
                cout << userName << ": benvenuto nella pagina dedicata agli acquirenti" << endl;
                q = db.getTable("SELECT p.id, p.nome, p.prezzo, p.unita, u.username FROM prodotti p, utenti u WHERE p.idvenditore=u.id AND u.tipo=1;");

                for (int row = 0; row < q.numRows(); row++)
                    {
                        q.setRow(row);
                        for (int fld = 0; fld < q.numFields(); fld++)
                        {
                            if (!q.fieldIsNull(fld))
                                cout <<q.fieldValue(fld) << "|";
                            else
                                cout << "NULL" << "|";
                        }
                        cout << endl;
                    }

                cout << "Inserire l'ID dell'oggetto che si desidera acquistare: ";
                scanf("%u", &nomeordini);
                cout << "inserire il numero di unita da acquistare: ";
                scanf("%f", &numordini);

                std::time_t t = std::time(0);   // get time now
                std::tm* now = std::localtime(&t);

                char today[20];
                sprintf (today,"%4d-%02d-%02d", (now->tm_year + 1900), (now->tm_mon + 1), now->tm_mday);

                sprintf(query, "INSERT INTO ordini (idacquirente,idprodotto,quantita,importo,data) VALUES (%u,%u,%f,0.0,'%s');", userId , nomeordini, numordini, today);
                printf("%s",query);
            }

    }

}






