#include <iostream>		//richiama libreria standard di input-output
#include <windows.h>	//richiama libreria di windows
#include <string.h>		//richiama libreria gestione stringhe
#include <fstream>		//richiama libreria gestione file
using namespace std;

class html{		//dichiara classi
	public:
		void titleparagrafo(char nome1[100]);
		void paragrafo(char nome2[100]);
		void immagine(char nome3[100]);
		void link(char nome4[100]); 
		void video(char nome5[100]);
		void audio(char nome6[100]);
		void elenco(char nome7[100]);
		void elenconum(char nome8[100]);
		void table(char nome9[100]);
};


void SetColor(unsigned short color)			//api windows per la funzione modifica colori
{
    HANDLE nomecambiabile= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(nomecambiabile,color);
}


int main()
{
	html oggetto;		//oggetto della classe html è oggetto
	char title[100], titolo[100], background[100], icon[10000], sfondo2[1000];			//dichiara variabili titolo, title, fine, nomefile e scelta
	int fine=6, sfondo;
	char nomefile[100]={"\\Createfilehtml.html"};
	int scelta=0;
	cout<<"prima di usare il prodotto leggere le faq"<<endl;
	cout<<"scrivi il percorso dove vuoi salvare il file html"<<endl;		//l'utente sceglie dove salvare il file
	cin.getline(title, sizeof(title));
	strcat(title, nomefile);
	ofstream fp(title, ios::out);		//apri file in scrittura
	fp<<"<!DOCTYPE html>"<<endl<<"<html lang=\"it\">"<<endl<<"<head>"<<endl;
	cout<<"inserisci il nome del titolo che comparira sopra la scheda del file html"<<endl;		//l'utente sceglie come nominare la scheda
	cin.getline(titolo, sizeof(titolo));
	fp<<"<title> "<<titolo<<" </title>"<<endl<<"<meta charset=\"UTF-8\">"<<endl;		//scivi codice html titolo
	cout<<"inserisci il nome dell'immagine se vuoi aggiugere un icona"<<endl;
	cin.getline(icon, sizeof(icon));
	fp<<"<link rel=\"icon\""<<" href=\""<<icon<<"\"/>"<<endl;
	cout<<"cosa vuoi mettere come sfondo?\n1=colore semplice\n2=immaggine"<<endl;
	cin>>sfondo;
	if (sfondo == 1)
	{
		cout<<"scrivi il colore";
		SetColor(4);
		cout<<"(in inglese)";
		SetColor(15);
		cout<<"dello sfondo della pagina html"<<endl;
		cin>>background;
		fp<<"</head>\n<body style=\"background-color:"<<background<<"\">";
	}
	else
	{
		getchar();
		cout<<"scrivi nome dell'immagine che vuoi come sfondo"<<endl;
		cin.getline(sfondo2, sizeof(sfondo2));
		fp<<"</head>\n<body style=\"background-image: url("<<sfondo2<<")\">";
	}
	fp.close();		//chiudi file
	while (fine==6)
	{
		cout<<"quale operazione vuoi effettuare?"<<endl<<"digita 1 per inserire un titolo di paragrafo"<<endl<<"digita 2 per inserire un paragrafo"<<endl;
		cout<<"digita 3 per inserire un immagine"<<endl<<"digita 4 per inserire un link"<<endl;
		cout<<"digita 5 per inserire un video"<<endl<<"digita 6 per inserire file audio"<<endl;
		cout<<"digita 7 per inserire elenco non numerato"<<endl<<"digita 8 per inserire elenco numerato"<<endl;
		cout<<"digita 9 per inserire una tabella(nota premere due volte invio per visualizzare)"<<endl;
		cin>>scelta;		//l'utente sceglie quale opzione vuole scegliere
		getchar();
		switch(scelta)
		{
			case 1:		//se 1 sceglie titolo paragrafo
				oggetto.titleparagrafo(title);
				break;
			case 2:
				oggetto.paragrafo(title);		//se 2 sceglie testoparagrafo
				break;
			case 3:
				oggetto.immagine(title);		//se 3 sceglie immagine
				break;
			case 4:
				oggetto.link(title);		//se 4 sceglie link
				break;
			case 5:
				oggetto.video(title);		//se 5 sceglie video
				break;
			case 6:
				oggetto.audio(title);		//se 6 sceglie audio
				break;
			case 7:
				oggetto.elenco(title);		//se 7 sceglie elenco
				break;
			case 8:
				oggetto.elenconum(title);		//se 8 sceglie elenco numerato
				break;
			case 9:
				oggetto.table(title);		//se 9 sceglie tabella
				break;
			default:
				cout<<"comando non valido<<endl";
				exit(1);
				break;
		}
		fine=MessageBox(0,"vuoi continuare?","Terminare", MB_YESNO | MB_ICONINFORMATION);		
	}
	FILE *fpg;		//apri file in appened e scrivi seguente codice html
	fpg=fopen(title, "a");
	if (strcmp(background, "red")!=0)
	{
		fprintf(fpg, "\n<br>\n<br>\n<br>\n<p style=\"color:red\"> file html creato con html & css <p>");
	}
	else
	{
		fprintf(fpg, "\n<br>\n<br>\n<br>\n<p style=\"color:black\"> file html creato con html & css <p>");
	}
	fprintf(fpg, "\n</body>\n</html>");
	fclose(fpg);		//chiudi file
	getchar();
}





void html::titleparagrafo(char nome1[100])		//funzione in html per scrivere titoli paragrafi
{
	FILE *fp1;		//apri file e scrivi seguente codice html
	fp1=fopen(nome1, "a");
	char nome[100], color1[100], posizione1[100];
	int font1;
	cout<<"inserisci nome del titolo del paragrafo"<<endl;
	cin.getline(nome, sizeof(nome));
	cout<<"che colore lo vuoi il titolo del paragrafo? scrivi il nome in";
	SetColor(4);
	cout<<"(in inglese)"<<endl;
	SetColor(15);
	cin>>color1;
	cout<<"indica a numeri la dimensione del testo"<<endl;
	cin>>font1;
	cout<<"in che posizione vuoi il testo? center left o right"<<endl;
	cin>>posizione1;
	fprintf(fp1, "\n<h1 style=\"color: %s; font-size: %dpx; text-align: %s\"> %s </h1>", color1, font1,  posizione1, nome);
	fclose(fp1);		//chiudi file
}






void html::paragrafo(char nome2[100])		//funzione in html per scrivere testi paragrafi
{
	FILE *fp2;		//apri file e scrivi seguente codice html
	fp2=fopen(nome2, "a");
	char nomeA[10000], color2[100], posizione2[100];
	int font2;
	cout<<"inserisci testo paragrafo"<<endl;
	cin.getline(nomeA, sizeof(nomeA));
	cout<<"che colore lo vuoi il paragrafo? scrivi il nome in";
	SetColor(4);
	cout<<"(in inglese)"<<endl;
	SetColor(15);
	cin>>color2;
	cout<<"indica a numeri la dimensione del testo"<<endl;
	cin>>font2;
	cout<<"in che posizione vuoi il testo? center left o right"<<endl;
	cin>>posizione2;
	fprintf(fp2, "\n<p style=\"color: %s; font-size: %dpx; text-align: %s\"> %s </p>", color2, font2, posizione2, nomeA);
	fclose(fp2);
}






void html::immagine(char nome3[100])			//funzione in html per caricare immagini
{
	FILE *fp3;			//apri file e scrivi seguente codice html
	fp3=fopen(nome3, "a");
	char nomeB[10000];
	cout<<"inserisci il nome dell'immagine"<<endl;
	cin.getline(nomeB, sizeof(nomeB));
	fprintf(fp3, "\n<br>\n<img src=\"%s\" alt=\"%s non risponde\" width=\"1000\" height=\"600\">\n<br>", nomeB, nomeB);
	fclose(fp3);		//chiudi file
}





void html::link(char nome4[100])		//funzione in html per immettere link
{
	FILE *fp4;			//apri file e scrivi seguente codice html
	fp4=fopen(nome4, "a");
	char nomeC[10000], nomelink[100];
	cout<<"inserisci il nome del link"<<endl;
	cin.getline(nomeC, sizeof(nomeC));
	cout<<"inserisci il nome che verra' visualizzato quando si clicchera' sul link"<<endl;
	cin.getline(nomelink, sizeof(nomelink));
	fprintf(fp4, "\n<a href=\"%s\"> %s </a>", nomeC, nomelink);
	fclose(fp4);			//chiudi file
}





void html::video(char nome5[100])			//funzione in html per immettere video
{
	FILE *fp5;				//apri file e scrivi seguente codice html
	fp5=fopen(nome5, "a");
	char nomevideo[10000];
	cout<<"inserisci nome del video, assicurati che l'estenzione e' mp4"<<endl;
	cin.getline(nomevideo, sizeof(nomevideo));
	fprintf(fp5, "\n<video controls height=\"600\" width=\"1000\">\n<source src=\"%s\" type=\"video/mp4\">\n</video>", nomevideo);
	fclose(fp5);		//chiudi file
}





void html::audio(char nome6[100])		//funzione in html per immettere file audio
{
	FILE *fp6;			//apri file e scrivi seguente codice html
	fp6=fopen(nome6, "a");
	char nomeaudio[10000];
	cout<<"inserisci nome audio, solo estenzioni in formato mp3"<<endl;
	cin.getline(nomeaudio, sizeof(nomeaudio));
	fprintf(fp6, "\n<audio controls>\n<source src=\"%s\" type=\"audio/mp3\">\n</audio>", nomeaudio);
	fclose(fp6);			//chiudi file
}





void html::elenco(char nome7[100])		//funzione in html per immettere elenco non numerato
{
	FILE *fp7;		//apri file e scrivi seguente codice html
	fp7=fopen(nome7, "a");
	int elencoscelta=0, font7;
	char nomeelenco[10000], color7[100], posizione7[100], anto;
	cout<<"inserisci prima frase dell'elenco"<<endl;		//prima volta
	cin.getline(nomeelenco, sizeof(nomeelenco));
	cout<<"che colore vuoi la prima frase dell'elenco? scrivi il nome in";		//formatta testo
	SetColor(4);
	cout<<"(in inglese)"<<endl;
	SetColor(15);
	cin>>color7;
	cout<<"indica a numeri la dimensione del testo"<<endl;
	cin>>font7;
	cout<<"in che posizione vuoi il testo? center left o right"<<endl;
	cin>>posizione7;
	cout<<"vuoi mantenere lo stesso formato anche per il resto dell'elenco? s/n"<<endl;
	cin>>anto;
	getchar();
	if (anto == 's')		//se tutto uguale
	{
		fprintf(fp7, "\n<ul style=\"color: %s; font-size: %dpx; text-align: %s\">", color7, font7, posizione7);
		fprintf(fp7, "\n<li> %s </li>", nomeelenco);
		elencoscelta=MessageBox(0,"vuoi continuare l'elenco?","elenco", MB_YESNO);
		while (elencoscelta==6)
		{
			cout<<"inserisci prossima frase"<<endl;		//seconda volta
			cin.getline(nomeelenco, sizeof(nomeelenco));
			fprintf(fp7, "\n<li> %s </li>", nomeelenco);
			elencoscelta=MessageBox(0,"vuoi continuare l'elenco?","elenco", MB_YESNO);
		}
	}
	else		//se diverso
	{
		fprintf(fp7, "\n<ul>");
		fprintf(fp7, "\n<li style=\"color: %s; font-size: %dpx; text-align: %s\"> %s </li>", color7, font7, posizione7, nomeelenco);
		elencoscelta=MessageBox(0,"vuoi continuare l'elenco?","elenco", MB_YESNO);
		while (elencoscelta==6)
		{
			cout<<"inserisci prossima frase"<<endl;		//seconda volta
			cin.getline(nomeelenco, sizeof(nomeelenco));
			cout<<"che colore vuoi la frase dell'elenco? scrivi il nome in";
			SetColor(4);
			cout<<"(in inglese)"<<endl;
			SetColor(15);
			cin>>color7;
			cout<<"indica a numeri la dimensione del testo"<<endl;
			cin>>font7;
			cout<<"in che posizione vuoi il testo? center left o right"<<endl;
			cin>>posizione7;
			getchar();
			fprintf(fp7, "\n<li style=\"color: %s; font-size: %dpx; text-align: %s\"> %s </li>", color7, font7, posizione7, nomeelenco);
			elencoscelta=MessageBox(0,"vuoi continuare l'elenco?","elenco", MB_YESNO);
		}
	}
	fprintf(fp7, "\n</ul>");
	fclose(fp7);		//chiudi file
}





void html::elenconum(char nome8[100])		//funzione in html per immettere elenco numerato
{
	FILE *fp8;		//apri file e scrivi seguente codice html
	fp8=fopen(nome8, "a");
	int elencosceltanum=0, font8;
	char nomeelenconum[10000], color8[100], posizione8[100], antonum;
	cout<<"inserisci prima frase dell'elenco"<<endl;		//prima volta
	cin.getline(nomeelenconum, sizeof(nomeelenconum));
	cout<<"che colore vuoi la prima frase dell'elenco? scrivi il nome in";		//formatta testo
	SetColor(4);
	cout<<"(in inglese)"<<endl;
	SetColor(15);
	cin>>color8;
	cout<<"indica a numeri la dimensione del testo"<<endl;
	cin>>font8;
	cout<<"in che posizione vuoi il testo? center left o right"<<endl;
	cin>>posizione8;
	cout<<"vuoi mantenere lo stesso formato anche per il resto dell'elenco? s/n"<<endl;
	cin>>antonum;
	getchar();
	if (antonum == 's')		//se tutto uguale
	{
		fprintf(fp8, "\n<ol style=\"color: %s; font-size: %dpx; text-align: %s\">", color8, font8, posizione8);
		fprintf(fp8, "\n<li> %s </li>", nomeelenconum);
		elencosceltanum=MessageBox(0,"vuoi continuare l'elenco?","elenco", MB_YESNO);
		while (elencosceltanum==6)
		{
			cout<<"inserisci prossima frase"<<endl;		//seconda volta
			cin.getline(nomeelenconum, sizeof(nomeelenconum));
			fprintf(fp8, "\n<li> %s </li>", nomeelenconum);
			elencosceltanum=MessageBox(0,"vuoi continuare l'elenco?","elenco", MB_YESNO);
		}
	}
	else			//se diverso
	{
		fprintf(fp8, "\n<ol>");
		fprintf(fp8, "\n<li style=\"color: %s; font-size: %dpx; text-align: %s\"> %s </li>", color8, font8, posizione8, nomeelenconum);
		elencosceltanum=MessageBox(0,"vuoi continuare l'elenco?","elenco", MB_YESNO);
		while (elencosceltanum==6)
		{
			cout<<"inserisci prossima frase"<<endl;		//seconda volta
			cin.getline(nomeelenconum, sizeof(nomeelenconum));
			cout<<"che colore vuoi la frase dell'elenco? scrivi il nome in";
			SetColor(4);
			cout<<"(in inglese)"<<endl;
			SetColor(15);
			cin>>color8;
			cout<<"indica a numeri la dimensione del testo"<<endl;
			cin>>font8;
			cout<<"in che posizione vuoi il testo? center left o right"<<endl;
			cin>>posizione8;
			getchar();
			fprintf(fp8, "\n<li style=\"color: %s; font-size: %dpx; text-align: %s\"> %s </li>", color8, font8, posizione8, nomeelenconum);
			elencosceltanum=MessageBox(0,"vuoi continuare l'elenco?","elenco", MB_YESNO);
		}
	}
	fprintf(fp8, "\n</ol>");
	fclose(fp8);		//chiudi file
}




void html::table(char nome9[100])		//funzione per creare tabelle
{
	FILE *fp9;		//apri file e scrivi seguente codice html
	fp9=fopen(nome9, "a");
	int font9, table=6;
	char linea1[1000], linea2[1000], color9[100];
	fprintf(fp9, "\n<table>");
	while (table == 6)
	{
		getchar();
		cout<<"inserisci testo prima riga"<<endl;		//inizio formattazione prima riga
		cin.getline(linea1, sizeof(linea1));
		cout<<"che colore il testo della tabella? scrivi il nome in";
		SetColor(4);
		cout<<"(in inglese)"<<endl;
		SetColor(15);
		cin>>color9;
		cout<<"indica a numeri la dimensione del testo"<<endl;
		cin>>font9;			//fine formattazione riga uno
		fprintf(fp9, "\n<tr> <td style=\"color: %s; font-size: %dpx\"> %s </td> ", color9, font9, linea1); //riga uno scrittura nel file
		getchar();
		cout<<"inserisci testo seconda riga"<<endl;		//inizio formattazione seconda riga
		cin.getline(linea2, sizeof(linea2));
		cout<<"che colore il testo della tabella? scrivi il nome in";
		SetColor(4);
		cout<<"(in inglese)"<<endl;
		SetColor(15);
		cin>>color9;
		cout<<"indica a numeri la dimensione del testo"<<endl;
		cin>>font9;			//fine formattazione seconda uno
		fprintf(fp9, "<td style=\"color: %s; font-size: %dpx\"> %s </td> </tr>", color9, font9, linea2); //riga seconda scrittura nel file
		table=MessageBox(0,"vuoi continuare la tabella?","Tabella", MB_YESNO);
	}
	fprintf(fp9, "\n</table>");
	fclose(fp9);			//chiudi file
}
