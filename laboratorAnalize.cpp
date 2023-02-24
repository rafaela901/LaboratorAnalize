#include<iostream>
#include<cstring>
#include<fstream>
#include<string>
#include<map>
#include<set>
#include<vector>
#include<list>
using namespace std;
#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS

class check {
private:
	string nume;
	string id;
public:
	virtual void afisareDateImportante()
	{
		cout << "Numele persoanei este " << this->nume << "\n";
		cout << "Id-ul persoanei este " << this->id << "\n";

	}
	virtual void valid()
	{
		if (this->nume == "Necunoscut" || this->id == "000000" || this->id == "necunoscut")

			cout << "Nu avem date valide despre persoana/ Persoana nu este inregistrata";
		else
			cout << "Datele persoanei nu prezinta erori.";

	}
};

class fisierBinar {
public:
	virtual void writeToFile(fstream& f) = 0;
	virtual void readFromFile(fstream& f) = 0;

};

class angajat :public check
{
private:
	const string idAngajat;
	string numeAngajat;
	float salariu;
	string idFunctie;
	string numarDeTelefon;
	int numarZileLucrate;
	int* oreLucratePeZi;
public:

	angajat() :idAngajat("000000")
	{

		numeAngajat = "Necunoscut";
		salariu = 0;
		idFunctie = "000000";
		numarDeTelefon = "Necunoscut";
		numarZileLucrate = 0;
		oreLucratePeZi = NULL;


	}
	angajat(string idAngajat, string numeAngajat, string idFunctie) :idAngajat(idAngajat)
	{

		if (numeAngajat.length() > 0)
			this->numeAngajat = numeAngajat;
		else
			this->numeAngajat = "Anonim";
		if (idFunctie.length() > 0)
			this->idFunctie = idFunctie;
		else
			this->idFunctie = "000000";

	}
	angajat(string idAngajat, const string numeAngajat, float salariu, string idFunctie, string numarDeTelefon, int numarZileLucrate, int* oreLucratePeZi) :idAngajat(idAngajat)
	{

		if (numeAngajat.length() > 0)
			this->numeAngajat = numeAngajat;
		else
			this->numeAngajat = "Necunoscut";
		if (salariu > 0)
			this->salariu = salariu;
		else
			this->salariu = 0;
		this->idFunctie = idFunctie;
		if (numarDeTelefon.length() > 0)
			this->numarDeTelefon = numarDeTelefon;
		else
			this->numarDeTelefon = "Necunoscut";
		if (numarZileLucrate > 0)
		{
			this->numarZileLucrate = numarZileLucrate;
			this->oreLucratePeZi = new int[this->numarZileLucrate];
			for (int i = 0; i < this->numarZileLucrate; i++)
				this->oreLucratePeZi[i] = oreLucratePeZi[i];
		}
		else {
			this->numarZileLucrate = 0;
			this->oreLucratePeZi = NULL;
		}
	}

	angajat(const angajat& a) :idAngajat(a.idAngajat)
	{

		this->numeAngajat = a.numeAngajat;
		this->salariu = a.salariu;
		this->idFunctie = a.idFunctie;
		this->numarDeTelefon = a.numarDeTelefon;
		this->numarZileLucrate = a.numarZileLucrate;
		this->oreLucratePeZi = new int[a.numarZileLucrate];
		for (int i = 0; i < a.numarZileLucrate; i++)
			this->oreLucratePeZi[i] = a.oreLucratePeZi[i];

	}
	~angajat()
	{
		delete[] this->oreLucratePeZi;
	}
	angajat& operator=(const angajat& a)
	{
		if (this != &a)
		{
			delete[]this->oreLucratePeZi;
			this->numeAngajat = a.numeAngajat;
			this->salariu = a.salariu;
			this->idFunctie = a.idFunctie;
			this->numarDeTelefon = a.numarDeTelefon;
			this->numarZileLucrate = a.numarZileLucrate;
			this->oreLucratePeZi = new int[a.numarZileLucrate];
			for (int i = 0; i < a.numarZileLucrate; i++)
				this->oreLucratePeZi[i] = a.oreLucratePeZi[i];

		}
		return *this;
	}
	friend ostream& operator<<(ostream& out, const angajat& a)
	{
		out << endl;
		out << "\nId-ul angajatului este: " << a.idAngajat;
		out << "\nNumele angajatului este: " << a.numeAngajat;
		out << "\nSalariul angajatului este: " << a.salariu;
		out << "\nId-ul functiei angajatului este: " << a.idFunctie;
		out << "\nNr de telefon al angajatului este: " << a.numarDeTelefon;
		out << "\nNumarul de zile lucrate pe luna este: " << a.numarZileLucrate;
		out << "\nNumarul de ore lucrate pe luna este: ";
		for (int i = 0; i < a.numarZileLucrate; i++)
			out << a.oreLucratePeZi[i] << " ";
		return out;

	}
	friend istream& operator>>(istream& in, angajat& a)
	{
		cout << endl;
		delete[] a.oreLucratePeZi;
		cout << "\nId-ul angajatului este: ";
		in >> a.idFunctie;
		cout << "\nNumele angajatului este: ";
		in >> a.numeAngajat;
		cout << "\nSalariul angajatului este: ";
		in >> a.salariu;
		cout << "\nId-ul functiei angajatului este: ";
		in >> a.idFunctie;
		cout << "\nNr de telefon al angajatului este: ";
		in >> a.numarDeTelefon;
		cout << "\nNumarul de zile lucrate pe luna este: ";
		in >> a.numarZileLucrate;
		cout << "\nNumarul de ore lucrate pe luna este ";
		a.oreLucratePeZi = new int[a.numarZileLucrate];
		for (int i = 0; i < a.numarZileLucrate; i++)
		{
			in >> a.oreLucratePeZi[i];
		}
		return in;
	}

	string getidAngajat()
	{
		return this->idAngajat;
	}
	string getnume()
	{
		return this->numeAngajat;
	}
	void setnume(string numeAngajat)
	{
		if (numeAngajat.length() > 0)
		{
			this->numeAngajat = numeAngajat;
		}

	}
	float getsalariu()
	{
		return this->salariu;
	}
	void setsalariu(float salariu)
	{
		if (salariu > 0)
			this->salariu = salariu;
	}
	string getidFunctie()
	{
		return this->idFunctie;
	}
	void setidfunctie(string idFunctie)
	{
		if (idFunctie.length() > 1)
			this->idFunctie = idFunctie;

	}

	string gettelefon()
	{
		return this->numarDeTelefon;
	}
	void settelefon(string numarDeTelefon)
	{
		if (numarDeTelefon.length() > 1)
			this->numarDeTelefon = numarDeTelefon;
	}
	int getzilelucratelunar()
	{
		return this->numarZileLucrate;
	}
	void setzilelucrate(int numarZileLucrate)
	{
		if (this->numarZileLucrate > 0)
			this->numarZileLucrate = numarZileLucrate;
	}
	int* getorelucrate()
	{
		return this->oreLucratePeZi;

	}
	void setOreLucratePeZi(int* oreLucrate)
	{
		if (oreLucrate != NULL)
		{
			delete[] this->oreLucratePeZi;
			this->oreLucratePeZi = new int[this->numarZileLucrate];
			for (int i = 0; i < this->numarZileLucrate; i++)
				this->oreLucratePeZi[i] = oreLucrate[i];
		}

	}

	angajat& operator+(int x) {
		if (x > 0)
		{
			this->salariu = this->salariu + x;
		}

		return *this;
	}
	int operator[](int i)
	{
		if (i >= 0 && i < this->numarZileLucrate)
			return this->oreLucratePeZi[i];
	}
	bool operator==(angajat& a)
	{
		if (this->idAngajat != a.idAngajat || this->numeAngajat != a.numeAngajat || this->salariu != a.salariu || this->idFunctie != a.idFunctie || this->numarDeTelefon != a.numarDeTelefon || this->numarZileLucrate != a.numarZileLucrate)
			return false;
		for (int i = 0; i < this->numarZileLucrate; i++)
			if (this->oreLucratePeZi[i] != a.oreLucratePeZi[i])
				return false;
		return true;

	}
	/*bool operator<(angajat a)
	{
		return this->numarZileLucrate < a.numarZileLucrate;
	}*/
	friend bool operator<(const angajat& a1, const angajat& a2) {
		return a1.numarZileLucrate < a2.numarZileLucrate;
	}
	bool operator!()
	{
		if (this->numarZileLucrate <= 0)
			return false;
		return true;

	}
	angajat& operator++()
	{
		this->salariu++;
		return *this;

	}
	angajat& operator++(int)
	{
		angajat vn = *this;
		this->salariu++;
		return vn;

	}
	operator int()
	{
		int totalOre = 0;
		for (int i = 0; i < this->numarZileLucrate; i++)
			totalOre += oreLucratePeZi[i];
		return totalOre;

	}
	void afisare()
	{
		cout << endl;
		cout << "\nId-ul angajatului este: " << this->idAngajat;
		cout << "\nNumele angajatului este: " << this->numeAngajat;
		cout << "\nSalariul angajatului este: " << this->salariu;
		cout << "\nId-ul functiei angajatului este: " << this->idFunctie;
		cout << "\nNr de telefon al angajatului este: " << this->numarDeTelefon;
		cout << "\nNumarul de zile lucrate pe luna este: " << this->numarZileLucrate;
		cout << "\nNumarul de ore lucrate pe luna este: ";
		for (int i = 0; i < this->numarZileLucrate; i++)
			cout << this->oreLucratePeZi[i] << " ";

	}

	void writeToFile(fstream& f) {
		size_t lg = this->idAngajat.length() + 1;
		f.write((char*)&lg, sizeof(int));
		f.write(this->idAngajat.data(), lg * sizeof(char));

		size_t lg1 = this->numeAngajat.length() + 1;
		f.write((char*)&lg1, sizeof(int));
		f.write(this->numeAngajat.data(), lg1 * sizeof(char));

		size_t lg2 = this->idFunctie.length() + 1;
		f.write((char*)&lg2, sizeof(int));
		f.write(this->idFunctie.data(), lg2 * sizeof(char));

		size_t lg3 = this->numarDeTelefon.length() + 1;
		f.write((char*)&lg3, sizeof(int));
		f.write(this->numarDeTelefon.data(), lg3 * sizeof(char));

		f.write((char*)&this->salariu, sizeof(float));

		f.write((char*)&this->numarZileLucrate, sizeof(int));

		for (int i = 0; i < this->numarZileLucrate; i++)
		{
			f.write((char*)&this->oreLucratePeZi[i], sizeof(int));
		}


	}
	void readFromFile(fstream& f) {


		int lg;
		f.read((char*)&lg, sizeof(int));
		char* buffer = new char[lg];
		f.read(buffer, lg);
		this->numeAngajat = buffer;
		delete[] buffer;

		int lg1;
		f.read((char*)&lg1, sizeof(int));
		char* buffer1 = new char[lg1];
		f.read(buffer1, lg1);
		this->idFunctie = buffer1;
		delete[] buffer1;


		int lg3;
		f.read((char*)&lg3, sizeof(int));
		char* buffer2 = new char[lg3];
		f.read(buffer2, lg3);
		this->numarDeTelefon = buffer2;
		delete[] buffer2;

		f.read((char*)&this->salariu, sizeof(float));

		f.read((char*)&this->numarZileLucrate, sizeof(int));

		delete[] this->oreLucratePeZi;
		this->oreLucratePeZi = new int[this->numarZileLucrate];
		for (int i = 0; i < this->numarZileLucrate; i++)
		{
			f.read((char*)&this->oreLucratePeZi[i], sizeof(int));
		}



	};

	void scriereInFisier(string myFile)
	{
		fstream fout;
		fout.open(myFile, ios::out);
		if (fout.is_open())
		{
			cout << "nume angajat ";
			cin >> this->numeAngajat;
			fout << this->numeAngajat << "\n";

			cout << "salariul ";
			cin >> this->salariu;
			fout << this->salariu << "\n";

			fout << this->idAngajat << "\n";

			cout << "id functie ";
			cin >> this->idFunctie;
			fout << this->idFunctie << "\n";

			cout << "nr telefon ";
			cin >> this->numarDeTelefon;
			fout << this->numarDeTelefon << "\n";

			cout << "zile lucrate ";
			cin >> this->numarZileLucrate;
			fout << this->numarZileLucrate << "\n";

			cout << "ore lucrate ";
			this->oreLucratePeZi = new int[this->numarZileLucrate];
			for (int i = 0; i < this->numarZileLucrate; i++)
			{
				cin >> this->oreLucratePeZi[i];
				fout << this->oreLucratePeZi[i] << " ";
			}

			fout.close();
		}



	}

	void citireDinFisier(string myFile)
	{
		fstream fin;
		fin.open(myFile, ios::in);
		if (fin.is_open())
		{
			string line;
			while (getline(fin, line))
			{
				cout << line << endl;
			}
			fin.close();
		}

	}


	void scriereCsv(string myFile)
	{
		fstream fout;
		fout.open(myFile, ios::out);

		int i, salariul;
		string nume, idF, id, nrTlf;
		fout << "Nume" << "," << "Id angajat" << "," << "Id functie" << "," << "Nr. telefon" << "," << "Salariul" << "\n";

		for (i = 0; i < 1; i++) {
			cout << "nume " << i << " ";
			cin >> nume;
			cout << "id " << i << " ";
			cin >> id;
			cout << "idFunctie  " << i << " ";
			cin >> idF;
			cout << "nr tlf " << i << " ";
			cin >> nrTlf;
			cout << "salariul " << i << " ";
			cin >> salariul;
			cin.ignore();

			fout << nume << ", " << id << ", " << idF << ", " << nrTlf << ", " << salariul << ", " << "\n";
		}
		fout.close();
	}
	void citire(string myFile)
	{
		fstream fin;
		string data;
		fin.open(myFile, ios::in);
		for (int i = 0; i < 2; i++)
		{
			getline(fin, data);
			cout << data << "\n";


		}
		fin.close();
	}
	virtual void afisareDateImportante()
	{
		cout << "Numele persoanei este " << this->numeAngajat << "\n";
		cout << "Id-ul persoanei este " << this->idAngajat << "\n";

	}
	virtual void valid()
	{
		if (this->numeAngajat == "Necunoscut" || this->idAngajat == "000000" || this->idAngajat == "necunoscut")

			cout << "Nu avem date valide despre persoana/ Persoana nu este inregistrata";
		else
			cout << "Datele persoanei nu prezinta erori.";

	}

	/*void afisareDateImportante() {
		cout << "Id-ul angajatului este: " << this->idAngajat << "\n";
		cout << "Numele angajatului este: " << this->numeAngajat << "\n";

	}
	void valid() {
		if (this->idAngajat == "000000" || this->numeAngajat == "Necunoscut")
			cout << "Nu avem date valide despre angajat/Persoana nu este angajata";
		else
			cout << "Date angajatului nu prezinta erori.";

	}*/



};

class angajatActualizare :public angajat {
	int varsta = 0;
	vector<int> zileLiberePeLuna;
public:
	angajatActualizare()
	{
		this->varsta = 0;
		for (int i = 0; i < 12; i++)
			this->zileLiberePeLuna.push_back(0);
	}
	angajatActualizare(string idAngajat, string numeAngajat, float salariu, string idFunctie, string numarDeTelefon,
		int numarZileLucrate, int* oreLucratePeZi, int varsta, vector<int> zileLiberePeLuna) :angajat(idAngajat, numeAngajat, salariu, idFunctie, numarDeTelefon, numarZileLucrate, oreLucratePeZi)
	{
		this->varsta = varsta;
		this->zileLiberePeLuna = zileLiberePeLuna;

	}
	angajatActualizare(const angajatActualizare& aa) :angajat(aa)
	{
		this->varsta = aa.varsta;
		this->zileLiberePeLuna = aa.zileLiberePeLuna;

	}
	friend ostream& operator<<(ostream& out, const angajatActualizare& aa)
	{
		out << (angajat)aa;
		out << "Varsta angajatului este de: " << aa.varsta << " ani." << "\n";
		out << "Numarului de zile libere pe luna este: ";
		if (aa.zileLiberePeLuna.size() < 12)
		{
			for (int i = 0; i < aa.zileLiberePeLuna.size(); i++)
				cout << "luna " << i + 1 << " : " << aa.zileLiberePeLuna[i] << " zile" << "\n";

			for (int i = aa.zileLiberePeLuna.size(); i < 12; i++)
				cout << "luna " << i + 1 << " : " << "nr. necunoscut de zile" << "\n";
		}
		else
		{
			for (int i = 0; i < aa.zileLiberePeLuna.size(); i++)
				cout << "luna " << i + 1 << " : " << aa.zileLiberePeLuna[i] << " zile" << "\n";

		}

		return out;
	}
	~angajatActualizare()
	{

	}

};

class medic : public angajat
{
private:
	string specializare;
	string grad;
public:
	medic()
	{
		this->specializare = "necunoscuta";
		this->grad = "necunoscut";
	}
	medic(string idAngajat, string numeAngajat, float salariu, string idFunctie, string numarDeTelefon,
		int numarZileLucrate, int* oreLucratePeZi, string specializare, string grad) :angajat(idAngajat, numeAngajat, salariu, idFunctie, numarDeTelefon, numarZileLucrate, oreLucratePeZi)
	{
		this->specializare = specializare;
		this->grad = grad;
	}
	medic(const medic& m) :angajat(m)
	{
		this->specializare = m.specializare;
		this->grad = m.grad;
	}
	friend ostream& operator<<(ostream& out, const medic& m)
	{
		out << (angajat)m;
		out << "Specializarea medicului este: " << m.specializare << "\n";
		out << "Gradul medicului este: " << m.grad << "\n";
		return out;
	}
	~medic()
	{

	}
};

class asistent : public angajat
{
private:
	string* listaAtributii;
	int nrAtributii;

public:
	asistent()
	{
		this->listaAtributii = NULL;
		this->nrAtributii = 0;
	}
	asistent(string idAngajat, string numeAngajat, float salariu, string idFunctie, string numarDeTelefon,
		int numarZileLucrate, int* oreLucratePeZi, string* listaAtributii, int nrAtributii) :angajat(idAngajat, numeAngajat, salariu, idFunctie, numarDeTelefon, numarZileLucrate, oreLucratePeZi)
	{
		this->nrAtributii = nrAtributii;
		this->listaAtributii = new string[this->nrAtributii];
		for (int i = 0; i < this->nrAtributii; i++)
			this->listaAtributii[i] = listaAtributii[i];
	}
	asistent(const asistent& as) :angajat(as)
	{
		this->nrAtributii = as.nrAtributii;
		this->listaAtributii = new string[as.nrAtributii];
		for (int i = 0; i < as.nrAtributii; i++)
			this->listaAtributii[i] = as.listaAtributii[i];

	}
	friend ostream& operator<<(ostream& out, const asistent& as)
	{
		out << (angajat)as;
		out << "Numarul de atributii ale asistentului este: " << as.nrAtributii << "\n";
		out << "Atributiile asistentului sunt " << "\n";
		for (int i = 0; i < as.nrAtributii; i++)
			out << i + 1 << " " << as.listaAtributii[i] << "\n";
		return out;
	}
	~asistent()
	{
		delete[] this->listaAtributii;
	}
};

class colectie {
private:
	int nrAngajati = 0;
	angajat** angajati{};
public:
	colectie()
	{

	}
	colectie(int nrAngajati, angajat** angajati)
	{
		this->nrAngajati = nrAngajati;
		this->angajati = new angajat * [this->nrAngajati];
		for (int i = 0; i < this->nrAngajati; i++)
			this->angajati[i] = angajati[i];
	}
	~colectie()
	{
		delete[] this->angajati;
	}
};

class Contact {
private:
	string nrDeTelefon;
	string adresa;
	string email;
public:
	Contact() {
		nrDeTelefon = "necunoscut";
		adresa = "necunoscuta";
		email = "necunoscut";
	}
	Contact(string nrTelefon, string adresa, string email)
	{
		this->nrDeTelefon = nrTelefon;
		this->adresa = adresa;
		this->email = email;
	}

	friend ostream& operator<<(ostream& out, const Contact& c)
	{
		out << "\nnrTelefon: " << c.nrDeTelefon;
		out << "\nadresa: " << c.adresa;
		out << "\nemail: " << c.email;
		return out;
	}
	friend istream& operator>>(istream& in, Contact& c)
	{
		cout << "\nnr telefon:";
		in >> c.nrDeTelefon;
		cout << "\nadresa: ";
		in >> c.adresa;
		cout << "\nemail:";
		in >> c.email;
		return in;
	}
	bool operator==(Contact& c)
	{
		if (this->nrDeTelefon == c.nrDeTelefon && this->adresa == c.adresa && this->email == c.email)
			return true;
		return false;

	}
};

class pacient :public check {
private:
	char* numePacient;
	const string cnp;
	int varsta;
	Contact dateDeContact{};
	int lunaCurenta;
	int ConsultatiiPeParcursulAnului[12];
public:

	pacient() :cnp("necunoscut")
	{
		numePacient = new char[strlen("Necunoscut") + 1];
		strcpy(numePacient, "Necunoscut");
		for (int i = 0; i < lunaCurenta; i++)
			ConsultatiiPeParcursulAnului[i] = 0;

		varsta = 0;
		lunaCurenta = 0;

	}
	pacient(string cnp, const char* numePacient, Contact dateDeContact, int lunaCurenta) :cnp(cnp)
	{
		if (strlen(numePacient) > 1)
		{
			this->numePacient = new char[strlen(numePacient) + 1];
			strcpy(this->numePacient, numePacient);
		}
		this->dateDeContact = dateDeContact;
		if (lunaCurenta > 0 && lunaCurenta <= 12)
			this->lunaCurenta = lunaCurenta;
	}
	pacient(string cnp, const char* numePacient, int ConsultatiiPeParcursulAnului[12], Contact dateDeContact, int varsta, int lunaCurenta) :cnp(cnp)
	{
		if (strlen(numePacient) > 1)
		{
			this->numePacient = new char[strlen(numePacient) + 1];
			strcpy(this->numePacient, numePacient);
		}
		if (lunaCurenta > 0 && lunaCurenta <= 12)
		{
			this->lunaCurenta = lunaCurenta;
		}
		for (int i = 0; i < this->lunaCurenta; i++)
		{
			if (ConsultatiiPeParcursulAnului[i] > 0)
				this->ConsultatiiPeParcursulAnului[i] = ConsultatiiPeParcursulAnului[i];
			else
				this->ConsultatiiPeParcursulAnului[i] = 0;
		}
		this->dateDeContact = dateDeContact;
		this->varsta = varsta;

	}
	pacient(const pacient& p) :cnp(p.cnp)
	{
		this->numePacient = new char[strlen(p.numePacient) + 1];
		strcpy(this->numePacient, p.numePacient);
		for (int i = 0; i < p.lunaCurenta; i++)
			this->ConsultatiiPeParcursulAnului[i] = p.ConsultatiiPeParcursulAnului[i];
		this->dateDeContact = p.dateDeContact;
		this->varsta = p.varsta;
		this->lunaCurenta = p.lunaCurenta;
	}
	pacient& operator=(const pacient& p)
	{
		if (this != &p)
		{
			this->numePacient = new char[strlen(p.numePacient) + 1];
			strcpy(this->numePacient, p.numePacient);
			for (int i = 0; i < p.lunaCurenta; i++)
				this->ConsultatiiPeParcursulAnului[i] = p.ConsultatiiPeParcursulAnului[i];
			this->dateDeContact = p.dateDeContact;
			this->varsta = p.varsta;
			this->lunaCurenta = p.lunaCurenta;
		}
		return *this;

	}
	~pacient()
	{
		delete[] this->numePacient;
	}
	friend ostream& operator<<(ostream& out, const pacient& p)
	{
		out << endl;
		out << "\nNume pacient: " << p.numePacient;
		out << "\ncnp: " << p.cnp;
		out << "\nVarsta pacient: " << p.varsta;
		out << "\nDate de contact: " << p.dateDeContact;
		out << "\nLuna curenta: " << p.lunaCurenta;
		out << "\nNr. consultatii pe an: ";
		for (int i = 0; i < p.lunaCurenta; i++)
			out << "\nluna " << i + 1 << " " << p.ConsultatiiPeParcursulAnului[i];
		return out;
	}
	friend istream& operator>>(istream& in, pacient& p)
	{
		cout << "\nIntroduceti numele pacientului: ";
		in >> p.numePacient;
		cout << "\nIntroduceti varsta: ";
		in >> p.varsta;
		cout << "\nIntroduceti date de contact: ";
		in >> p.dateDeContact;
		cout << "\nIntroduceti luna curenta";
		in >> p.lunaCurenta;
		cout << "\nIntroduceti consultatii pe an: ";
		for (int i = 0; i < p.lunaCurenta; i++)
			in >> p.ConsultatiiPeParcursulAnului[i];

		return in;
	}
	char* getnume() {
		return this->numePacient;
	}
	string getcnp() {
		return this->cnp;
	}
	int getlunacurenta()
	{
		return this->lunaCurenta;
	}
	int getnrconsultatii(int index) {

		return this->ConsultatiiPeParcursulAnului[index];
	}
	Contact getcontact()
	{
		return this->dateDeContact;
	}
	int getvarsta()
	{
		return this->varsta;
	}
	void setnume(const char* nume)
	{
		if (strlen(nume) > 0)
		{
			delete[] this->numePacient;
			this->numePacient = new char[strlen(nume) + 1];
			strcpy(this->numePacient, nume);
		}
	}
	void setlunacurenta(int lunaCurenta)
	{
		if (lunaCurenta > 0 && lunaCurenta <= 12)
			this->lunaCurenta = lunaCurenta;
	}
	void setcontact(Contact c)
	{
		this->dateDeContact = c;
	}
	void setnrconsultatii(int ConsultatiiPeParcurusulAnului[], int nr)
	{
		for (int i = 0; i < nr; i++)
			this->ConsultatiiPeParcursulAnului[i] = ConsultatiiPeParcurusulAnului[i];
		for (int j = nr; j < 12; j++)
			this->ConsultatiiPeParcursulAnului[j] = 0;

	}
	void setvarsta(int varsta)
	{
		if (varsta >= 0)
			this->varsta = varsta;
	}

	int operator[](int i)
	{
		if (i > 0 && i < this->lunaCurenta)
			return this->ConsultatiiPeParcursulAnului[i];
	}
	bool operator==(pacient& p)
	{
		for (int i = 0; i < this->lunaCurenta; i++)
			if (this->ConsultatiiPeParcursulAnului[i] != p.ConsultatiiPeParcursulAnului[i])
				return false;
		if (*this->numePacient == *p.numePacient && this->cnp == p.cnp && this->dateDeContact == p.dateDeContact && this->varsta != p.varsta)
			return true;

		return true;

	}
	bool operator>(pacient p)
	{
		return this->varsta > p.varsta;
	}
	operator int& ()
	{
		int totalConsultatii = 0;
		for (int i = 0; i < this->lunaCurenta; i++)
			totalConsultatii += ConsultatiiPeParcursulAnului[i];
		return totalConsultatii;

	}
	bool operator!()
	{
		for (int i = 0; i < this->lunaCurenta; i++)
			if (ConsultatiiPeParcursulAnului[i] = 0)
				return false;
		return true;
	}
	pacient& operator++() {

		this->varsta++;
		return *this;
	}
	pacient operator++(int)
	{
		pacient aux = *this;
		this->varsta++;
		return aux;

	}

	int operator+ (int x) {
		this->varsta = this->varsta + x;

		return this->varsta;
	}


	void afisare() {
		cout << endl;
		cout << "\nNume pacient: " << this->numePacient;
		cout << "\ncnp: " << this->cnp;
		cout << "\nVarsta pacient: " << this->varsta;
		cout << "\nDate de contact: " << this->dateDeContact;
		cout << "\nLuna curenta: " << this->lunaCurenta;
		cout << "\nNr. consultatii pe an: ";
		for (int i = 0; i < this->lunaCurenta; i++)
			cout << "\nluna " << i + 1 << " " << this->ConsultatiiPeParcursulAnului[i];

	}
	void writeToFile(fstream& f) {
		size_t lg = this->cnp.length() + 1;
		f.write((char*)&lg, sizeof(int));
		f.write(this->cnp.data(), lg * sizeof(char));

		size_t lg1 = strlen(this->numePacient) + 1;
		f.write((char*)&lg1, sizeof(int));
		f.write(this->numePacient, lg1 * sizeof(char));

		f.write((char*)&this->varsta, sizeof(int));

		f.write((char*)&this->lunaCurenta, sizeof(int));

		for (int i = 0; i < this->lunaCurenta; i++)
		{
			f.write((char*)&this->ConsultatiiPeParcursulAnului[i], sizeof(int));
		}

		f.write((char*)&this->dateDeContact, sizeof(Contact));

	}
	void readFromFile(fstream& f) {
		int lg;
		f.read((char*)&lg, sizeof(int));
		char* buffer = new char[lg];
		f.read(buffer, lg);
		this->numePacient = buffer;
		delete[] buffer;

		f.read((char*)&this->varsta, sizeof(int));

		f.read((char*)&this->lunaCurenta, sizeof(int));

		for (int i = 0; i < this->lunaCurenta; i++) {
			f.read((char*)&this->ConsultatiiPeParcursulAnului[i], sizeof(int));
		}
		f.read((char*)&this->dateDeContact, sizeof(Contact));
	}
	void scriereInFisier(string myFile)
	{
		fstream fout;
		fout.open(myFile, ios::out);
		if (fout.is_open())
		{
			cout << "nume pacient ";
			cin >> this->numePacient;
			fout << this->numePacient << "\n";

			fout << this->cnp << "\n";

			cout << "varsta pacient ";
			cin >> this->varsta;
			fout << this->varsta << "\n";

			cout << "date de contact ";
			cin >> this->dateDeContact;
			fout << this->dateDeContact << "\n";

			cout << "luna curenta ";
			cin >> this->lunaCurenta;
			fout << this->lunaCurenta << "\n";

			cout << "nr consultatii ";

			for (int i = 0; i < this->lunaCurenta; i++)
			{
				cin >> this->ConsultatiiPeParcursulAnului[i];
				fout << this->ConsultatiiPeParcursulAnului[i] << " ";
			}

			fout.close();
		}

	}
	void citireDinFisier(string myFile)
	{
		fstream fin;
		fin.open(myFile, ios::in);
		if (fin.is_open())
		{
			string line;
			while (getline(fin, line))
			{
				cout << line << endl;
			}
			fin.close();
		}

	}

	void citire(string myFile)
	{
		fstream fin;
		string data;
		fin.open(myFile, ios::in);
		for (int i = 0; i < 2; i++)
		{
			getline(fin, data);
			cout << data << "\n";


		}
		fin.close();
	}
	void raportPacient(string fisier)
	{
		fstream fout;
		fout.open(fisier, ios::out);
		cout << "Numele pacientului este " << this->numePacient << " iar varsta acestuia este de " << this->varsta << " ani. Acesta poate fi contactat la urmatoarea adresa : " << this->dateDeContact << "\n";
		cout << "La data curenta ne aflam in luna " << this->lunaCurenta << " iar vizitele medicale ale pacientului sunt: " << "\n";
		for (int i = 0; i < this->lunaCurenta; i++)
			cout << "in luna " << i + 1 << " " << this->ConsultatiiPeParcursulAnului[i] << " consultatii" << "\n";


		fout << "Numele pacientului este " << this->numePacient << " iar varsta acestuia este de " << this->varsta << " ani. Acesta poate fi contactat la urmatoarea adresa : "
			<< this->dateDeContact << "\n";
		fout << "La data curenta ne aflam in luna " << this->lunaCurenta << " iar vizitele medicale ale pacientului sunt: " << "\n";
		for (int i = 0; i < this->lunaCurenta; i++)
			fout << "in luna " << i + 1 << " " << this->ConsultatiiPeParcursulAnului[i] << " consultatii" << "\n";



		fout.close();
	}
	void afisareDateImportante()
	{
		cout << "Numele persoanei este " << this->numePacient << "\n";
		cout << "Id-ul persoanei este " << this->cnp << "\n";

	}
	virtual void valid()
	{
		if (this->numePacient == "Necunoscut" || this->cnp == "000000" || this->cnp == "necunoscut")

			cout << "Nu avem date valide despre persoana/ Persoana nu este inregistrata";
		else
			cout << "Datele persoanei nu prezinta erori.";

	}
	/*void afisareDateImportante() {

		cout << "Numele pacientului este: " << this->numePacient << "\n";
		cout << "Cnp-ul pacientului este: " << this->cnp << "\n";
		cout << "Varsta pacientului este: " << this->varsta << "\n";
	}*/
	/*void valid() {
		if (this->numePacient == "Necunoscut" || this->cnp == "necunoscut" || this->varsta == 0)
			cout << "Nu avem date valide despre pacient/ Pacientul nu este inregistrat";
		else
			cout << "Date pacientului nu prezinta erori.";

	}*/
};

class produs {
private:
	string denumireProdus;
	float pret;
public:
	produs()
	{
		denumireProdus = "necunoscuta";
		pret = 0;
	}
	produs(string denumireProdus, float pret)
	{
		this->denumireProdus = denumireProdus;
		this->pret = pret;
	}
	produs(const produs& p)
	{
		this->denumireProdus = p.denumireProdus;
		this->pret = p.pret;
	}
	produs& operator=(const produs& p)
	{
		this->denumireProdus = p.denumireProdus;
		this->pret = p.pret;
		return *this;
	}
	friend ostream& operator<<(ostream& out, const produs& p)
	{
		out << "\ndenumire: " << p.denumireProdus;
		out << "\npret: " << p.pret;
		return out;

	}
	friend istream& operator>>(istream& in, produs& p)
	{
		cout << "Introduceti denumire: ";
		in >> p.denumireProdus;
		cout << "Introduceti pret: ";
		in >> p.pret;
		return in;
	}
	bool operator==(produs& p)
	{
		if (this->denumireProdus == p.denumireProdus && this->pret == p.pret)
			return true;
		return false;
	}

};

class Furnizor :public fisierBinar {
private:
	string idFurnizor = "necunoscut";
	produs** listaProduseFurnizate = NULL;
	int nrProduseFurnizate = 0;
	float* cantitateFurnizataDinFiecareProdus = NULL;
public:
	Furnizor()
	{
		idFurnizor = "necunoscut";
		nrProduseFurnizate = 0;
		listaProduseFurnizate = NULL;
		cantitateFurnizataDinFiecareProdus = NULL;

	}
	Furnizor(string idFurnizor, produs** listaProduseFurnizate, int nrProduseFurnizate, float* cantitateFurnizataDinFiecareProdus)
	{
		if (idFurnizor.length() > 1)
			this->idFurnizor = idFurnizor;
		else
			this->idFurnizor = "necunoscut";
		if (nrProduseFurnizate > 0 && listaProduseFurnizate != NULL)
		{
			this->nrProduseFurnizate = nrProduseFurnizate;
			this->listaProduseFurnizate = new produs * [this->nrProduseFurnizate];
			for (int i = 0; i < this->nrProduseFurnizate; i++)
			{
				this->listaProduseFurnizate[i] = new produs(*listaProduseFurnizate[i]);
			}
		}

		if (cantitateFurnizataDinFiecareProdus != NULL)
		{
			this->cantitateFurnizataDinFiecareProdus = new float[this->nrProduseFurnizate];
			for (int i = 0; i < this->nrProduseFurnizate; i++)
				this->cantitateFurnizataDinFiecareProdus[i] = cantitateFurnizataDinFiecareProdus[i];
		}

	}
	Furnizor(string idFurnizor, int nrProduseFurnizate)
	{
		if (idFurnizor.length() > 1)
			this->idFurnizor = idFurnizor;
		if (nrProduseFurnizate > 0)
		{
			this->nrProduseFurnizate = nrProduseFurnizate;

		}
	}

	Furnizor(const Furnizor& f)
	{
		this->idFurnizor = f.idFurnizor;
		this->nrProduseFurnizate = f.nrProduseFurnizate;

		this->listaProduseFurnizate = new produs * [f.nrProduseFurnizate];
		for (int i = 0; i < f.nrProduseFurnizate; i++)
		{
			this->listaProduseFurnizate[i] = new produs(*f.listaProduseFurnizate[i]);
		}
		this->cantitateFurnizataDinFiecareProdus = new float[f.nrProduseFurnizate];
		for (int i = 0; i < f.nrProduseFurnizate; i++)
			this->cantitateFurnizataDinFiecareProdus[i] = f.cantitateFurnizataDinFiecareProdus[i];
	}
	Furnizor& operator=(const Furnizor& f)
	{
		if (this != &f)
		{

			for (int i = 0; i < this->nrProduseFurnizate; i++)
				delete this->listaProduseFurnizate[i];
			delete[] this->listaProduseFurnizate;
			delete[] cantitateFurnizataDinFiecareProdus;

			this->idFurnizor = f.idFurnizor;
			if (f.listaProduseFurnizate != NULL && f.nrProduseFurnizate > 0)
			{
				this->nrProduseFurnizate = f.nrProduseFurnizate;
				this->listaProduseFurnizate = new produs * [this->nrProduseFurnizate];
				for (int i = 0; i < this->nrProduseFurnizate; i++)
				{
					this->listaProduseFurnizate[i] = new produs(*f.listaProduseFurnizate[i]);

				}
			}
			else
			{
				this->listaProduseFurnizate = NULL;
				this->nrProduseFurnizate = 0;
			}
			this->cantitateFurnizataDinFiecareProdus = new float[f.nrProduseFurnizate];
			for (int i = 0; i < f.nrProduseFurnizate; i++)
				this->cantitateFurnizataDinFiecareProdus[i] = f.cantitateFurnizataDinFiecareProdus[i];

		}

		return *this;
	}
	string getid()
	{
		return this->idFurnizor;
	}
	void setid(string idFurnizor)
	{
		if (idFurnizor.length() > 0)
			this->idFurnizor = idFurnizor;
	}
	int getnrprodusefurnizate()
	{
		return this->nrProduseFurnizate;
	}
	void setnrprodusefurnizate(int nrProduseFurnizate)
	{
		if (nrProduseFurnizate > 0)
			this->nrProduseFurnizate = nrProduseFurnizate;
	}

	produs** getlistaproduse() {
		return this->listaProduseFurnizate;
	}
	void setlistaproduse(produs** listaProduse)
	{
		for (int i = 0; i < this->nrProduseFurnizate; i++)
			delete this->listaProduseFurnizate[i];
		delete[] this->listaProduseFurnizate;


		this->listaProduseFurnizate = new produs * [this->nrProduseFurnizate];
		for (int i = 0; i < this->nrProduseFurnizate; i++)
		{
			this->listaProduseFurnizate[i] = new produs();
			this->listaProduseFurnizate[i] = listaProduse[i];

		}

	}
	float* getcantitateaFurnizata()
	{
		return this->cantitateFurnizataDinFiecareProdus;
	}
	void setcantitateaFurnizata(float* cantitateFurnizataDinFiecareProdus)
	{
		delete[] this->cantitateFurnizataDinFiecareProdus;
		this->cantitateFurnizataDinFiecareProdus = new float[this->nrProduseFurnizate];
		for (int i = 0; i < this->nrProduseFurnizate; i++)
			this->cantitateFurnizataDinFiecareProdus[i] = cantitateFurnizataDinFiecareProdus[i];
	}
	~Furnizor()
	{
		delete[] this->listaProduseFurnizate;
		delete[] this->cantitateFurnizataDinFiecareProdus;
	}
	friend ostream& operator<<(ostream& out, const Furnizor& f)
	{
		out << "\nId-ul furnizorului este: " << f.idFurnizor;
		out << "\nNr. de produse furnizate: " << f.nrProduseFurnizate;
		out << "\nLista de produse frunizate : ";
		for (int i = 0; i < f.nrProduseFurnizate; i++)
			out << *f.listaProduseFurnizate[i] << " " << endl;
		out << "\nCantitatea furnizata din fiecare produs: " << endl;
		for (int i = 0; i < f.nrProduseFurnizate; i++)
			out << "\ndin produsul " << i + 1 << ": " << f.cantitateFurnizataDinFiecareProdus[i] << " bucati";
		return out;

	}

	friend istream& operator>>(istream& in, Furnizor& f) {
		for (int i = 0; i < f.nrProduseFurnizate; i++)
			delete f.listaProduseFurnizate[i];
		delete[] f.listaProduseFurnizate;
		cout << "\nIntroduceti id-ul furnizorului: ";
		in >> f.idFurnizor;
		cout << "\nIntroduceti nr. de produse furnizate";
		in >> f.nrProduseFurnizate;

		if (f.nrProduseFurnizate > 0)
		{
			f.listaProduseFurnizate = new produs * [f.nrProduseFurnizate];
			for (int i = 0; i < f.nrProduseFurnizate; i++)
			{
				f.listaProduseFurnizate[i] = new produs();
				in >> *f.listaProduseFurnizate[i];
			}

		}
		cout << "\nIntroduceti cantitatea furnizata din fiecare produs: ";
		delete[] f.cantitateFurnizataDinFiecareProdus;
		f.cantitateFurnizataDinFiecareProdus = new float[f.nrProduseFurnizate];
		for (int i = 0; i < f.nrProduseFurnizate; i++)
			in >> f.cantitateFurnizataDinFiecareProdus[i];
		return in;
	}

	float operator[](int i)
	{
		if (i >= 0 && i < this->nrProduseFurnizate)
			return this->cantitateFurnizataDinFiecareProdus[i];
	}
	bool operator==(const Furnizor& f)
	{
		if (this->idFurnizor != f.idFurnizor || this->nrProduseFurnizate != f.nrProduseFurnizate)
			return false;
		for (int i = 0; i < this->nrProduseFurnizate; i++)
		{
			if (this->listaProduseFurnizate[i] != f.listaProduseFurnizate[i] || this->cantitateFurnizataDinFiecareProdus[i] != f.cantitateFurnizataDinFiecareProdus[i])
				return false;
		}

		return true;

	}
	Furnizor& operator++() {

		float* vn = new float[this->nrProduseFurnizate + 1];
		for (int i = 0; i < this->nrProduseFurnizate; i++)
		{
			vn[i] = this->cantitateFurnizataDinFiecareProdus[i];
		}
		vn[this->nrProduseFurnizate] = 1;
		delete[] this->cantitateFurnizataDinFiecareProdus;

		this->cantitateFurnizataDinFiecareProdus = vn;
		this->nrProduseFurnizate++;

		return *this;
	}
	Furnizor operator++(int)
	{
		Furnizor copie = *this;
		float* vn = new float[this->nrProduseFurnizate + 1];
		for (int i = 0; i < this->nrProduseFurnizate; i++) {
			vn[i] = this->cantitateFurnizataDinFiecareProdus[i];
		}
		vn[this->nrProduseFurnizate] = 0;
		delete[] this->cantitateFurnizataDinFiecareProdus;

		this->cantitateFurnizataDinFiecareProdus = vn;
		this->nrProduseFurnizate++;

		return copie;
	}

	bool operator>(Furnizor& f)
	{
		return this->nrProduseFurnizate > f.nrProduseFurnizate;
	}
	bool operator!()
	{
		if (this->listaProduseFurnizate == NULL)
			return false;
		return true;
	}
	int operator+(int x)
	{
		if (x > 0)
		{
			this->nrProduseFurnizate = this->nrProduseFurnizate + x;
		}
		return this->nrProduseFurnizate;
	}
	operator float()
	{
		float cantitateTotala = 0;
		for (int i = 0; i < this->nrProduseFurnizate; i++)
			cantitateTotala += cantitateFurnizataDinFiecareProdus[i];
		return cantitateTotala;

	}
	void afisare()
	{
		cout << "\nId-ul furnizorului este: " << this->idFurnizor;
		cout << "\nNr. de produse furnizate: " << this->nrProduseFurnizate;
		cout << "\nLista de produse frunizate : ";
		for (int i = 0; i < this->nrProduseFurnizate; i++)
			cout << *this->listaProduseFurnizate[i] << " " << endl;
		cout << "\nCantitatea furnizata din fiecare produs: " << endl;
		for (int i = 0; i < this->nrProduseFurnizate; i++)
			cout << "\ndin produsul " << i + 1 << ": " << this->cantitateFurnizataDinFiecareProdus[i] << " bucati";



	}
	void writeToFile(fstream& f) {
		size_t lg = this->idFurnizor.length() + 1;
		f.write((char*)&lg, sizeof(int));
		f.write(this->idFurnizor.data(), lg * sizeof(char));

		f.write((char*)&this->nrProduseFurnizate, sizeof(int));

		for (int i = 0; i < this->nrProduseFurnizate; i++)
		{
			f.write((char*)&this->cantitateFurnizataDinFiecareProdus[i], sizeof(float));
		}

		f.write((char*)&this->listaProduseFurnizate, sizeof(produs));

	}
	void readFromFile(fstream& f) {
		int lg;
		f.read((char*)&lg, sizeof(int));
		char* buffer = new char[lg];
		f.read(buffer, lg);
		this->idFurnizor = buffer;
		delete[] buffer;

		f.read((char*)&this->listaProduseFurnizate, sizeof(produs));

		f.read((char*)&this->nrProduseFurnizate, sizeof(int));

		delete[]this->cantitateFurnizataDinFiecareProdus;
		f.read((char*)&this->cantitateFurnizataDinFiecareProdus, sizeof(float));
		this->cantitateFurnizataDinFiecareProdus = new float[this->nrProduseFurnizate];
		for (int i = 0; i < this->nrProduseFurnizate; i++) {
			f.read((char*)&cantitateFurnizataDinFiecareProdus[i], sizeof(float));

		}
	}
	void scriereInFisier(string myFile)
	{
		fstream fout;
		fout.open(myFile, ios::out);
		if (fout.is_open())
		{
			cout << "id-ul furnizorului ";
			cin >> this->idFurnizor;
			fout << this->idFurnizor << "\n";

			cout << "nr.de produse furnizate ";
			cin >> this->nrProduseFurnizate;
			fout << this->nrProduseFurnizate << "\n";

			cout << "lista produse furnizate: ";


			this->listaProduseFurnizate = new produs * [this->nrProduseFurnizate];
			for (int i = 0; i < this->nrProduseFurnizate; i++)
			{
				this->listaProduseFurnizate[i] = new produs();
				cin >> *this->listaProduseFurnizate[i];
				fout << *this->listaProduseFurnizate[i];
			}

			cout << "cantitatea furnizata din fiecare produs : ";
			delete[] this->cantitateFurnizataDinFiecareProdus;
			this->cantitateFurnizataDinFiecareProdus = new float[this->nrProduseFurnizate];
			for (int i = 0; i < this->nrProduseFurnizate; i++)
			{
				cin >> this->cantitateFurnizataDinFiecareProdus[i];
				fout << this->cantitateFurnizataDinFiecareProdus[i];
			}

			fout.close();
		}

	}
	void citireDinFisier(string myFile)
	{
		fstream fin;
		fin.open(myFile, ios::in);
		if (fin.is_open())
		{
			string line;
			while (getline(fin, line))
			{
				cout << line << endl;
			}
			fin.close();
		}

	}
	void citire(string myFile)
	{
		fstream fin;
		string data;
		fin.open(myFile, ios::in);
		for (int i = 0; i < 2; i++)
		{
			getline(fin, data);
			cout << data << "\n";


		}
		fin.close();
	}

};

class Consultatie {
private:
	string* listaServicii{};
	int nrServicii = 0;
	float listaPreturi[40]{};
	float durata = 0;
public:
	Consultatie()
	{
		listaServicii = NULL;
		nrServicii = 0;
		for (int i = 0; i < this->nrServicii; i++)
			listaPreturi[i] = 0;
		durata = 0;
	}
	Consultatie(string* listaServicii, int nrServicii)
	{
		if (nrServicii > 0 && listaServicii != NULL)
		{
			this->nrServicii = nrServicii;
			this->listaServicii = new string[this->nrServicii];
			for (int i = 0; i < this->nrServicii; i++)
			{
				this->listaServicii[i] = listaServicii[i];

			}
		}
	}
	Consultatie(string* listaServicii, int nrServicii, float listaPreturi[40], float durata)
	{
		if (nrServicii > 0 && listaServicii != NULL)
		{
			this->nrServicii = nrServicii;
			this->listaServicii = new string[this->nrServicii];
			for (int i = 0; i < this->nrServicii; i++)

				this->listaServicii[i] = listaServicii[i];
		}
		for (int i = 0; i < this->nrServicii; i++)
			this->listaPreturi[i] = listaPreturi[i];
		if (durata > 0)
			this->durata = durata;


	}
	Consultatie(const Consultatie& c)
	{
		if (c.nrServicii > 0 && c.listaServicii != NULL)
		{
			this->nrServicii = c.nrServicii;
			this->listaServicii = new string[c.nrServicii];
			for (int i = 0; i < c.nrServicii; i++)
			{
				this->listaServicii[i] = c.listaServicii[i];
			}
		}
		for (int i = 0; i < c.nrServicii; i++)
			this->listaPreturi[i] = c.listaPreturi[i];
		if (durata > 0)
			this->durata = c.durata;

	}
	Consultatie& operator=(const Consultatie& c)
	{
		if (this != &c)
		{
			delete[] this->listaServicii;
			this->nrServicii = c.nrServicii;
			this->listaServicii = new string[c.nrServicii];
			for (int i = 0; i < c.nrServicii; i++)
			{
				this->listaServicii[i] = c.listaServicii[i];
			}

			for (int i = 0; i < c.nrServicii; i++)
				this->listaPreturi[i] = c.listaPreturi[i];
			this->durata = c.durata;
		}
		return *this;
	}
	int getnrservicii()
	{
		return this->nrServicii;
	}
	string* getlistaservicii()
	{
		return this->listaServicii;
	}
	float getlistapreturi(int i)
	{
		return this->listaPreturi[i];
	}
	float getdurata()
	{
		return this->durata;
	}
	void setnrservicii(int nrServicii)
	{
		if (nrServicii > 0)
			this->nrServicii = nrServicii;
	}
	void setlistaservicii(string* listaServicii)
	{
		if (listaServicii != NULL)
		{
			delete[] this->listaServicii;
			this->listaServicii = new string[this->nrServicii];
			for (int i = 0; i < this->nrServicii; i++)
				this->listaServicii[i] = listaServicii[i];
		}
	}
	void setlistapreturi(float listaPreturi[])
	{

		for (int i = 0; i < this->nrServicii; i++)
			this->listaPreturi[i] = listaPreturi[i];
	}
	void setdurata(float durata)
	{
		if (durata > 0 && durata < 120)
			this->durata = durata;
	}
	friend ostream& operator<<(ostream& out, const Consultatie& c)
	{
		out << endl;
		out << "\nNr de servicii este: " << c.nrServicii;
		out << "\nLista de servicii este: " << endl;
		for (int i = 0; i < c.nrServicii; i++)
		{
			out << i + 1 << ": " << c.listaServicii[i] << endl;

		}
		out << "\nLista de preturi este: ";
		for (int i = 0; i < c.nrServicii; i++)
			out << c.listaServicii[i] << " pret: " << c.listaPreturi[i] << endl;
		out << "\nDurata consultatiei este: " << c.durata;
		return out;

	}
	friend istream& operator>>(istream& in, Consultatie& c)
	{

		cout << "\nIntroduceti nr de servicii: ";
		in >> c.nrServicii;
		delete[] c.listaServicii;
		c.listaServicii = new string[c.nrServicii];
		cout << "\nIntroduceti lista de servicii: ";
		for (int i = 0; i < c.nrServicii; i++)
		{
			cout << i + 1 << ": ";
			in >> c.listaServicii[i];
		}
		cout << "\nIntroduceti lista de preturi: ";
		for (int i = 0; i < c.nrServicii; i++)
		{

			cout << c.listaServicii[i] << ": ";
			in >> c.listaPreturi[i];
		}
		cout << "\nIntroduceti durata consultatiei: ";
		in >> c.durata;
		return in;


	}
	float operator[](int index)
	{
		if (index >= 0 && index < this->nrServicii)
			return this->listaPreturi[index];
	}
	/*bool operator<(Consultatie c)
	{
		return this->durata < c.durata;
	}*/
	friend bool operator<(const Consultatie& c1, const Consultatie& c2) {
		return c1.durata < c2.durata;
	}
	bool operator!()
	{
		if (this->nrServicii <= 0)
			return false;
		return true;

	}
	bool operator==(Consultatie& c)
	{

		if (this->nrServicii != c.nrServicii || this->durata != c.durata)
			return false;
		for (int i = 0; i < this->nrServicii; i++)
		{
			if (this->listaServicii[i] != c.listaServicii[i] || this->listaPreturi[i] != c.listaPreturi[i])
				return false;
		}
		return true;
	}
	float operator+(float x) {
		if (x > 0)
			this->durata = this->durata + x;

		return this->durata;
	}
	Consultatie& operator++()
	{
		this->nrServicii++;
		return*this;
	}
	Consultatie operator++(int)
	{
		Consultatie rez = *this;
		this->nrServicii++;
		return rez;

	}

	operator float()
	{
		float pretTotal = 0;
		for (int i = 0; i < this->nrServicii; i++)
			pretTotal += listaPreturi[i];
		return pretTotal;

	}
	~Consultatie()
	{
		delete[] this->listaServicii;
	}
	void afisare() {
		cout << endl;
		cout << "\nNr de servicii este: " << this->nrServicii;
		cout << "\nLista de servicii este: ";
		for (int i = 0; i < this->nrServicii; i++)
		{
			cout << i + 1 << ": " << this->listaServicii[i];

		}
		cout << "\nLista de preturi este: ";
		for (int i = 0; i < this->nrServicii; i++)
			cout << this->listaServicii[i] << " pret: " << this->listaPreturi[i];
		cout << "\nDurata consultatiei este: " << this->durata;

	}
	void writeToFile(fstream& f) {

		for (int i = 0; i < this->nrServicii; i++)
		{
			f.write((char*)&this->listaServicii[i], sizeof(char));
		}

		f.write((char*)&this->nrServicii, sizeof(int));

		f.write((char*)&this->durata, sizeof(float));

		for (int i = 0; i < this->nrServicii; i++)
		{
			f.write((char*)&this->listaPreturi[i], sizeof(float));
		}



	}
	void readFromFile(fstream& f) {

		f.read((char*)&this->nrServicii, sizeof(int));

		int lg;
		delete[]this->listaServicii;
		f.read((char*)&this->listaServicii, sizeof(int));
		this->listaServicii = new string[this->nrServicii];
		for (int i = 0; i < this->nrServicii; i++) {
			f.read((char*)&lg, sizeof(int));
			char* buffer = new char[lg];
			f.read(buffer, lg);
			this->listaServicii[i] = buffer;
			delete[] buffer;
		}


		for (int i = 0; i < this->nrServicii; i++) {
			f.read((char*)&listaPreturi[i], sizeof(float));

		}
		f.read((char*)&this->durata, sizeof(float));
	}


	void scriereInFisier(string myFile)
	{
		fstream fout;
		fout.open(myFile, ios::out);
		if (fout.is_open())
		{
			cout << "nr de servicii ";
			cin >> this->nrServicii;
			fout << this->nrServicii << "\n";

			cout << "lista de servicii ";
			this->listaServicii = new string[this->nrServicii];
			for (int i = 0; i < this->nrServicii; i++)
			{
				cout << i + 1 << ": ";
				cin >> this->listaServicii[i];
				fout << this->listaServicii[i];
			}

			cout << "lista de preturi: ";
			for (int i = 0; i < this->nrServicii; i++)
			{
				fout << this->listaServicii[i] << ": ";
				cin >> this->listaPreturi[i];
				fout << this->listaPreturi[i];
			}

			cout << "durata consultatiei ";
			cin >> this->durata;
			fout << this->durata << "\n";



			fout.close();
		}



	}
	void citireDinFisier(string myFile)
	{
		fstream fin;
		fin.open(myFile, ios::in);
		if (fin.is_open())
		{
			string line;
			while (getline(fin, line))
			{
				cout << line << endl;
			}
			fin.close();
		}

	}
	void citire(string myFile)
	{
		fstream fin;
		string data;
		fin.open(myFile, ios::in);
		for (int i = 0; i < 2; i++)
		{
			getline(fin, data);
			cout << data << "\n";


		}
		fin.close();
	}
	void raportConsultatii(string fisier)
	{
		fstream fout;
		fout.open(fisier, ios::out);
		cout << "Numarul de servicii efectuate in cadrul consultatiei este  " << this->nrServicii << " iar durata consultatiei a fost de " << this->durata << " minute." << "\n";
		cout << "Mai jos se regaseste lista de servicii efectuate si pretul corespunzator fiecaruia: " << "\n";
		for (int i = 0; i < this->nrServicii; i++)
			cout << "Pentru  " << this->listaServicii[i] << " trebuie achitata suma de " << this->listaPreturi[i] << " RON." << "\n";


		fout << "Numarul de servicii efectuate in cadrul consultatiei este  " << this->nrServicii << " iar durata consultatiei a fost de " << this->durata << " minute." << "\n";
		fout << "Mai jos se regaseste lista de servicii efectuate si pretul corespunzator fiecaruia: " << "\n";
		for (int i = 0; i < this->nrServicii; i++)
			fout << "Pentru  " << this->listaServicii[i] << " trebuie achitata suma de " << this->listaPreturi[i] << " RON." << "\n";



		fout.close();
	}
};

class consultatieActualizare :public Consultatie
{
	int zileDeAstPtRez = 0;

public:
	consultatieActualizare()
	{
		this->zileDeAstPtRez = 0;

	}
	consultatieActualizare(string* listaServicii, int nrServicii, float listaPreturi[40], float durata, int zileDeAstRez)
		:Consultatie(listaServicii, nrServicii, listaPreturi, durata)
	{
		this->zileDeAstPtRez = zileDeAstPtRez;

	}
	consultatieActualizare(const consultatieActualizare& ca) : Consultatie(ca)
	{
		this->zileDeAstPtRez = ca.zileDeAstPtRez;

	}
	friend ostream& operator<<(ostream& out, const consultatieActualizare& ca)
	{
		out << (Consultatie)ca;
		out << "Numarului de zile de asteptare pana la sosirea rezultatelor este : " << ca.zileDeAstPtRez << "\n";

		return out;
	}
	~consultatieActualizare()
	{

	}

};

class Laborator :public fisierBinar {
	string nume{};
	string locatie{};
	static int nrLaboratoare;
	int nrAngajati{};
	angajat* angajati{};


public:
	Laborator()
	{
		nrLaboratoare++;
		nume = "Necunoscut";
		locatie = "N/A";
		nrAngajati = 0;
		angajati = NULL;


	}
	Laborator(string nume, string locatie)
	{
		nrLaboratoare++;
		if (nume.length() > 1)
			this->nume = nume;
		if (locatie.length() > 1)
			this->locatie = locatie;
	}

	Laborator(string nume, string locatie, int nrAngajati, angajat* angajati)
	{
		nrLaboratoare++;
		if (nume.length() > 1)
			this->nume = nume;
		if (locatie.length() > 1)
			this->locatie = locatie;
		if (nrAngajati > 0 && angajati != NULL)
		{
			this->nrAngajati = nrAngajati;
			this->angajati = new angajat[this->nrAngajati];
			for (int i = 0; i < this->nrAngajati; i++)
				this->angajati[i] = angajati[i];
		}

	}
	Laborator(const Laborator& l)
	{
		nrLaboratoare++;
		this->nume = l.nume;
		this->locatie = l.locatie;
		this->nrAngajati = l.nrAngajati;
		this->angajati = new angajat[l.nrAngajati];
		for (int i = 0; i < l.nrAngajati; i++)
			this->angajati[i] = l.angajati[i];
	}
	Laborator& operator=(const Laborator& l)
	{
		if (this != &l)
		{
			this->nrLaboratoare++;
			delete[] this->angajati;
			this->nume = l.nume;
			this->locatie = l.locatie;
			this->nrAngajati = l.nrAngajati;
			this->angajati = new angajat[l.nrAngajati];
			for (int i = 0; i < l.nrAngajati; i++)
				this->angajati[i] = l.angajati[i];
		}
		return *this;
	}
	~Laborator()
	{

		nrLaboratoare--;
		delete[] this->angajati;

	}
	friend ostream& operator<<(ostream& out, const Laborator& l)
	{
		out << endl;
		out << "\nNume:" << l.nume;
		out << "\nLocatie: " << l.locatie;
		out << "\nNr laboratoare: " << l.nrLaboratoare;
		out << "\n Nr angajati: " << l.nrAngajati;
		out << "\nLista angajati: ";
		for (int i = 0; i < l.nrAngajati; i++)
			out << l.angajati[i];
		return out;

	}
	friend istream& operator>>(istream& in, Laborator& l)
	{
		delete[] l.angajati;
		cout << "\nIntroduceti nume: ";
		in >> l.nume;
		cout << "\nIntroduceti locatie: ";
		in >> l.locatie;
		cout << "\nIntroduceti nr de angajati: ";
		in >> l.nrAngajati;
		cout << "\nIntroduceti lista de angajati: ";
		if (l.nrAngajati > 0)
		{
			l.angajati = new angajat[l.nrAngajati + 1];

			for (int i = 0; i < l.nrAngajati; i++)
			{

				in >> l.angajati[i];
			}

		}
		else
		{
			l.nrAngajati = 0;
			l.angajati = NULL;
		}
		return in;

	}
	string getnume()
	{
		return this->nume;
	}
	void setnume(string nume)
	{
		if (nume.length() > 1)
			this->nume = nume;
	}
	string getlocatie()
	{
		return this->locatie;
	}
	void setlocatie(string locatie)
	{
		if (locatie.length() > 1)
			this->locatie = locatie;
	}
	int getnrlaboratoare()
	{
		return this->nrLaboratoare;
	}
	int getnrangajati()
	{
		return this->nrAngajati;
	}
	void setnrangajati(int nrAngajati)
	{
		if (nrAngajati > 0)
			this->nrAngajati = nrAngajati;
	}
	angajat* getlistaangajati()
	{
		return this->angajati;
	}
	void setangajat(angajat* angajati)
	{
		if (angajati != NULL)
		{
			delete[] this->angajati;
			this->angajati = new angajat[this->nrAngajati];
			for (int i = 0; i < this->nrAngajati; i++)
				this->angajati[i] = angajati[i];
		}
	}

	int operator[](int i)
	{
		if (i >= 0 && i < this->nrAngajati)
			return this->angajati[i];
	}
	bool operator==(const Laborator& l)
	{
		if (this->nume != l.nume || this->locatie != l.locatie || this->nrAngajati != l.nrAngajati)
			return false;
		for (int i = 0; i < this->nrAngajati; i++)
		{
			if (this->angajati[i] != l.angajati[i])
				return false;
		}

		return true;

	}
	bool operator>(Laborator& l)
	{
		return this->nrAngajati > l.nrAngajati;
	}
	bool operator!()
	{
		if (this->angajati == NULL)
			return false;
		return true;
	}
	string operator+(string completare)
	{
		if (completare.length() > 0)
		{
			this->locatie = this->locatie + completare;
		}
		return this->locatie;
	}
	int operator++()
	{
		this->nrAngajati++;
		return this->nrAngajati;

	}
	int operator++(int)
	{
		int nrVechi = this->nrAngajati;
		this->nrAngajati++;
		return nrVechi;

	}
	void afisare()
	{
		cout << endl;
		cout << "\nNume:" << this->nume;
		cout << "\nLocatie: " << this->locatie;
		cout << "\nNr laboratoare: " << this->nrLaboratoare;
		cout << "\n Nr angajati: " << this->nrAngajati;
		cout << "\nLista angajati: ";
		for (int i = 0; i < this->nrAngajati; i++)
			cout << this->angajati[i];
	}
	void writeToFile(fstream& f) {
		size_t lg = this->nume.length() + 1;
		f.write((char*)&lg, sizeof(int));
		f.write(this->nume.data(), lg * sizeof(char));

		size_t lg1 = this->locatie.length() + 1;
		f.write((char*)&lg1, sizeof(int));
		f.write(this->locatie.data(), lg1 * sizeof(char));

		f.write((char*)&this->nrLaboratoare, sizeof(int));

		f.write((char*)&this->nrAngajati, sizeof(int));


		f.write((char*)&this->angajati, sizeof(angajat));
	}
	void readFromFile(fstream& f) {
		int lg;
		f.read((char*)&lg, sizeof(int));
		char* buffer = new char[lg];
		f.read(buffer, lg);
		this->nume = buffer;
		delete[] buffer;

		f.read((char*)&lg, sizeof(int));
		char* buffer1 = new char[lg];
		f.read(buffer1, lg);
		this->locatie = buffer1;
		delete[] buffer1;

		f.read((char*)&this->angajati, sizeof(angajat));

		f.read((char*)&this->nrAngajati, sizeof(int));

		f.read((char*)&this->nrLaboratoare, sizeof(int));


	}

	void scriereInFisier(string myFile)
	{
		fstream fout;
		fout.open(myFile, ios::out);
		if (fout.is_open())
		{
			cout << "nume ";
			cin >> this->nume;
			fout << this->nume << "\n";

			cout << "locatie ";
			cin >> this->locatie;
			fout << this->locatie << "\n";

			fout << this->nrLaboratoare << "\n";

			cout << "nr angajati ";
			cin >> this->nrAngajati;
			fout << this->nrAngajati << "\n";

			cout << "lista angajati ";
			this->angajati = new angajat[this->nrAngajati];
			for (int i = 0; i < this->nrAngajati; i++)
			{
				cin >> this->angajati[i];
				fout << this->angajati[i];
			}

			fout.close();
		}
	}


	void citireDinFisier(string myFile)
	{
		fstream fin;
		fin.open(myFile, ios::in);
		if (fin.is_open())
		{
			string line;
			while (getline(fin, line))
			{
				cout << line << endl;
			}
			fin.close();
		}

	}


	void citire(string myFile)
	{
		fstream fin;
		string data;
		fin.open(myFile, ios::in);
		for (int i = 0; i < 2; i++)
		{
			getline(fin, data);
			cout << data << "\n";


		}
		fin.close();
	}
	void raport(string fisier)
	{
		fstream fout;
		fout.open(fisier, ios::out);
		cout << "Numarul de laboratoare de analize infiintate este " << this->nrLaboratoare << "\n";
		cout << "Laboratorul " << this->nume << " are un numar " << this->nrAngajati << " angajati " << "\n";
		cout << "Locatia laboratorului de analize este " << this->locatie << "\n";

		fout << "Numarul de laboratoare infiintate este " << this->nrLaboratoare;
		fout << "Laboratorul " << this->nume << " are un numar " << this->nrAngajati << " angajati ";
		fout << "Locatia laboratorului de analize este " << this->locatie << "\n";

		fout.close();
	}



};
int Laborator::nrLaboratoare = 0;

/*====================FISIERE DE INTRARE PRIN ARGUMENTELE FUNCTIEI MAIN========================
int main(int argc, char* argv[])
{
	angajat a;
	Furnizor f;

	for (int i = 1; i < argc; i++){

		string fn = argv[i];
		cout << fn;
		fstream fin;
		fin.open(fn,ios::in);
		if (fin.is_open())
		{
			string line;
			while (getline(fin, line))
			{
				cout << line << endl;
			}
			fin.close();
		}
		fin.close();
	}
	return 0;

	}*/
	//===========================MENIU=======================
	/*string st[20];
	int itemcount = 0;
	afisareMeniu();
	int raspuns;
	string next;
	do
	{
		cout << "Introduceti raspunsul(1-5):";
		cin >> raspuns;
		switch (raspuns)
		{
		case 1: adaugaAngajat(); break;
		case 2: adaugaPacient(); break;
		case 3: adaugaFurnizor(); break;
		case 4: adaugaConsultatie(); break;
		case 5: adaugaLaborator(); break;
		default: cout << "invalid"; break;
		}
		cout << "Apasa n sau N pentru a continua:";
		cin >> next;
	} while (next == "n" || next == "N");
	*/

int main()
{
	cout << "VECTOR DE POINTERI LA CLASA DE BAZA";
	angajat** v = new angajat * [2];
	v[0] = new medic;
	v[1] = new asistent;
	colectie c(2, v);

	cout << "\n VERIFICARE VRITUALIZARE\n";
	check* ch;
	angajat a5;
	angajat a7("123", "Alina", 1400, "005", "07666666669", 4, new int[4]{ 7,7,4,5 });
	ch = &a7;
	ch->afisareDateImportante();
	ch->valid();




	cout << "\n============VECTOR============\n";
	vector<int> vec;
	for (int i = 0; i < 11; i++)
		vec.push_back(i);
	angajatActualizare a("123", "Alina", 1400, "005", "07666666669", 4, new int[4]{ 7,7,4,5 }, 25, vec);
	cout << a;

	cout << "\n==============MAP=================";
	angajat a1;
	angajat a2("123", "Alina", 1400, "005", "07666666669", 4, new int[4]{ 7,7,4,5 });
	angajat a3;

	map<int, angajat>mapev;
	mapev[0] = a1;
	mapev[1] = a2;
	mapev[2] = a3;

	map<int, angajat>::iterator i;
	for (i = mapev.begin(); i != mapev.end(); i++)
		cout << "\n" << i->first << " " << i->second << "\n";

	cout << "\n===============SET=================";

	Consultatie co;
	string listaServicii[2] = { "test covid","test alergii" };
	Consultatie co2(listaServicii, 2, new float[2]{ 12,50 }, 30);


	set<Consultatie>setev;
	setev.insert(co);
	setev.insert(co2);


	set<Consultatie>::iterator it;
	for (it = setev.begin(); it != setev.end(); it++)
		cout << *it;

	cout << "\n=============LIST==============\n";

	list<int> lint;
	Laborator l;

	angajat ang2("123456", "Mihnea", 1400, "000005", "076888888", 4, new int[4]{ 7,7,4,5 });
	angajat ang3("9999", "Alin", 1400, "000005", "0765000000", 2, new int[2]{ 2,3 });

	angajat lista[2] = { ang2,ang3 };
	Laborator l1("Clinmed", "BD.Iuliu Maniu", 2, lista);
	Laborator l2("Medica", "str.nordului");


	lint.push_back(l.getnrangajati());
	lint.push_back(l1.getnrangajati());


	list<int>::iterator itList;
	for (itList = lint.begin(); itList != lint.end(); itList++)
		cout << *itList << " ";
	cout << "\n";
	list<int>::reverse_iterator rItList;
	for (rItList = lint.rbegin(); rItList != lint.rend(); rItList++)
		cout << *rItList << " ";

	///*=====================RAPORT========================*/
	//string listaServicii[2] = { "test covid","test alergii" };
	//Consultatie co2(listaServicii, 2, new float[2]{ 12,50 }, 30);
	///*co2.raportConsultatii("consultatie.txt");*/


	//Contact c2("076444666", "str.sudului", "pacient2@gmail.com");
	//pacient pa1("12345678", "Ioana", new int[2]{ 3,1 }, c2, 19, 3);
	///*pa1.raportPacient("pacient.txt");*/


	//angajat an2("123456", "Mihnea", 1400, "000005", "076888888", 4, new int[4]{ 7,7,4,5 });
	//angajat an3("9999", "Alin", 1400, "000005", "0765000000", 2, new int[2]{ 2,3 });
	//   angajat lista[2] = { an2,an3 };
	//Laborator l1("Clinmed", "BD.Iuliu Maniu", 2, lista);
	///*l1.raport("laborator.txt");*/
	//

	//=====================TESTARE FISIERE CSV SI TEXT==========================
//angajat a;
///*a.scriereCsv("fisnou.csv");*/
//a.scriereInFisier("angajat.txt");
//a.citireDinFisier("angajat.txt");
//pacient p;
///*p.scriereInFisier("pacient.txt");*/
//p.citireDinFisier("pacient.txt");
//
//Furnizor f;
///*f.scriereInFisier("fisier.txt");*/
//f.citireDinFisier("fisier.txt");

//Consultatie c;
///*c.scriereInFisier("consultatie.txt");*/
//c.citireDinFisier("consultatie.txt");

//Laborator l;
///*l.scriereInFisier("laborator.txt");*/
//l.citireDinFisier("laborator.txt");

	//===========================MENIU=======================
/*string st[20];
int itemcount = 0;
afisareMeniu();
int raspuns;
string next;
do
{
	cout << "Introduceti raspunsul(1-5):";
	cin >> raspuns;
	switch (raspuns)
	{
	case 1: adaugaAngajat(); break;
	case 2: adaugaPacient(); break;
	case 3: adaugaFurnizor(); break;
	case 4: adaugaConsultatie(); break;
	case 5: adaugaLaborator(); break;
	default: cout << "invalid"; break;
	}
	cout << "Apasa n sau N pentru a continua:";
	cin >> next;
} while (next == "n" || next == "N");
*/

//int main()   ================== DE LA FAZA 1====================
//{//ANGAJAT
//	angajat a1;
//	a1.afisare();
//	cout << a1;
//	angajat a2("123", "Alina", 1400, "005", "07666666669", 4, new int[4]{ 7,7,4,5 });
//
//	cout << a2;
//	angajat a5("478", "George", "001");
//	cout << a5;
//	angajat a6(a2);
//	angajat a3;
//	/* cin >> a3;*/
//	a3 = a2;
//	cout << "\noperator []:" << a2[3];
//
//	cout << "\noperator+:" << a2 + 1400;;
//	cout << "\noperator==:";
//	if (a3 == a2)
//
//		cout << "\nsunt la fel";
//	else
//		cout << "\nnu sunt la fel";
//	cout << "\noperator <:";
//	if (a3 < a2)
//		cout << "\nmai putine zile lucrate";
//	else
//		cout << "\nmai multe zile lucrate";
//	cout << "\noperator !:";
//	if (!a2)
//		cout << "\nAngajat vechi";
//	else
//		cout << "\nAngajat nou";
//	cout << "\noperator ++ postincrementare: ";
//	a1++;
//	cout << a1;
//	cout << "\noperator ++ preincrementare: ";
//	++a1;
//	cout << a1;
//	cout << "\noperator cast:";
//	int totalOre = a2;
//	cout << totalOre << endl;
//	cout << a2.getidAngajat() << endl;;
//	cout << a2.getidFunctie() << endl;
//	cout << a2.getnume() << endl;
//	cout << a2.getsalariu() << endl;
//	cout << a2.gettelefon() << endl;
//	cout << a2.getzilelucratelunar() << endl;
//	for (int i = 0; i < a2.getzilelucratelunar(); i++)
//		cout << a2.getorelucrate()[i] << " ";
//	a2.setOreLucratePeZi(new int[3]{ 9,8,7 });
//
//	//PACIENT
//
//	Contact c1("076666666", "str.nordului", "pacient@gmail.com");
//	Contact c2("076444666", "str.sudului", "pacient2@gmail.com");
//	pacient pa("9999999", "Iulia", c1, 2);
//	pa.afisare();
//	cout << pa;
//	pacient pa1("12345678", "Ioana", new int[2]{ 3,1 }, c2, 19, 3);
//	pacient pa2(pa);
//	cout << pa1;
//	pacient pa3(pa1);
//	pa3 = pa;
//	cout << pa3;
//	/*cin >> p3;*/
//	++pa3;
//	cout << pa3;
//	pa3 + 15;
//	cout << pa3;
//	if (pa == pa2)
//		cout << "\nsunt la fel";
//	else
//		cout << "\n sunt diferite";
//	cout << pa1.getcnp() << endl;
//	cout << pa1.getlunacurenta() << endl;
//	cout << pa1.getnrconsultatii(2) << endl;
//	cout << pa1.getnume() << endl;
//	cout << pa1.getvarsta() << endl;
//
//
//	//FURNIZOR
//
//
//	Furnizor f;
//	f.afisare();
//	cout << f;
//	produs p1("apa oxigenata", 100);
//	produs p2("dezinfectant", 30);
//	produs p3("plasturi", 60);
//	produs* listaProduseFurnizate1[3] = { &p1,&p2,&p3 };
//	Furnizor f1("123456", listaProduseFurnizate1, 3, new float[3]{ 12,3,9 });
//	cout << f1;
//	Furnizor f4(f1);
//	cout << f4;
//	f4 = f;
//	cout << f4;
//
//	f1.setcantitateaFurnizata(new float[3]{ 80,76,50 });
//	cout << f1;
//	for (int i = 0; i < f1.getnrprodusefurnizate(); i++)
//		cout << "\n" << f1.getcantitateaFurnizata()[i] << " ";
//
//	cout << "\n********************************";
//	for (int i = 0; i < f1.getnrprodusefurnizate(); i++)
//		cout << *f1.getlistaproduse()[i] << " ";
//
//	if (f4 == f1)
//		cout << "\nsunt la fel";
//	else
//		cout << "\n sunt diferite";
//
//	cout << f4.getid() << endl;
//	cout << f4.getnrprodusefurnizate() << endl;
//	for (int i = 0; i < f4.getnrprodusefurnizate(); i++)
//		cout << f4.getlistaproduse() << " ";
//
//	//CONSULTATIE
//
//	Consultatie co;
//	co.afisare();
//	string listaServicii[2] = { "test covid","test alergii" };
//	Consultatie co2(listaServicii, 2, new float[2]{ 12,50 }, 30);
//	co2.afisare();
//	Consultatie co3(listaServicii, 2);
//	co3.afisare();
//	cout << "\n*********************";
//	Consultatie co4(co2);
//	cout << co4;
//	cout << "\n*************";
//	co3 = co4;
//	cout << co3;
//	co3.setdurata(20);
//	cout << "\n*************";
//	float pret = co3;
//	cout << pret;
//	if (co2 == co3)
//		cout << "\n sunt la fel";
//	else
//		cout << "\n sunt diferite";
//	cout << co2.getdurata();
//	cout << co2.getnrservicii();
//
//	//LABORATOR
//
//	Laborator l;
//	cout << l;
//	angajat an2("123456", "Mihnea", 1400, "000005", "076888888", 4, new int[4]{ 7,7,4,5 });
//	angajat an3("9999", "Alin", 1400, "000005", "0765000000", 2, new int[2]{ 2,3 });
//
//	angajat lista[2] = { an2,an3 };
//	Laborator l1("Clinmed", "BD.Iuliu Maniu", 2, lista);
//	/*cin >> l;*/
//	cout << l1;
//	Laborator l2("Medica", "str.nordului");
//	cout << l2;
//	Laborator l3(l2);
//	cout << l3;
//	l = l1;
//	cout << l;
//	/*cin >> l;*/
//	angajat an4("003", "Radu", "105");
//	angajat an5("222", "Liviu", "200");
//	angajat lista2[2] = { an4,an5 };
//
//
//	cout << "\n********************";
//	l.setangajat(lista2);
//	cout << l;
//	cout << "\n***********************";
//	for (int i = 0; i < l1.getnrangajati(); i++)
//		cout << l1.getlistaangajati()[i] << " ";
//
//	cout << "\n*******************";
//	if (l3 == l)
//		cout << "\n suntla fel";
//	else
//		cout << "\n sunt diferite";
//	if (!l1)
//
//		cout << " \nsunt angajati";
//	else
//		cout << "\nnu sunt angajati";
//
//	cout << l + " la parter";
//	cout << l;
//
//	return 0;


}
