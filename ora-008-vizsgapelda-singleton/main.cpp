#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <type_traits>

// A 2-es jegyert keszitse el az alabbi osztalyokat:
// 
// Oltas osztaly - absztrakt ososztaly
// - ennek az osztalynak van egy const std::string&-et varo konstruktora, ami beallitja az Oltas nevet!
// - ennek az osztalynak van egy getName() metodusa ami visszaadja az oltas nevet
// - ennek az osztalynak van egy getType() nevu pure virtual metodusa is, ami std::string-et ad vissza, de nincs kifejtve!

class Oltas {
    std::string name;
public:
    Oltas(const std::string& name) : name(name) {}
    std::string getName() { return name; }
    virtual std::string getType() = 0;
};

// Pfizer osztaly, amely publikus modon szarmazik az Oltas osztalybol
// Ez egy singleton osztaly, vagyis:
// - konstruktora meghivja ugyan az ososztaly konstruktorat (inicializalo listaban), de a konstruktor maga privat!
// - copy constructora vagy privat, vagy le van tiltva! ( = delete;)
// - copy assignment operatora vagy privat, vagy le van tiltva! ( = delete;)
// - van egy public, static Oltas* GetInstance() metodusa, amely egy static pointert ad vissza
// - megvalositja az ososztaly getType() metodusat is, es azt a stringet adja vissza, hogy "mRNA"
// Singleton osztalyokrol hatteranyag: https://u.pcloud.link/publink/show?code=XZMR4rXZsHduf1qXGq4bAzr2cNPaCX5friLV (8-9. oldal)

class Pfizer : public Oltas {
    Pfizer(const std::string& name) : Oltas(name) {}
    Pfizer(Pfizer& other) = delete;
    Pfizer& operator=(Pfizer& other) = delete;
public:
    static Oltas* GetInstance() {
        static Pfizer instance("Pfizer");
        return &instance;
    }
    std::string getType() {
        return "mRNA";
    }
};

class Sinovac : public Oltas {
    Sinovac(const std::string& name) : Oltas(name) {}
    Sinovac(Sinovac& other) = delete;
    Sinovac& operator=(Sinovac& other) = delete;
public:
    static Oltas* GetInstance() {
        static Sinovac instance("Sinovac");
        return &instance;
    }
    std::string getType() {
        return "adenovirus";
    }
};

class OltasiIgazolas {
    std::vector<Oltas*> oltasok;
public:
    OltasiIgazolas(const std::vector<Oltas*>& oltasok) : oltasok(oltasok) {}
    int getCount(Oltas* whichOltas) {
        /*int count = 0;
        for (Oltas* op : oltasok) {
            if (op == whichOltas) {
                count++;
            }
        }
        return count;*/

        // a fenti mukodik, de meg egyszerubb:
        return std::count(oltasok.begin(), oltasok.end(), whichOltas);

        // itt egy un. predicate fuggvenyt adunk meg, ez is jo, de
        // itt feleslegesen bonyolult:
        /*return std::count_if(
            oltasok.begin(), oltasok.end(),
            [whichOltas](Oltas* current) {
                return current == whichOltas;
            }
        );*/
    }
};


// elvart kimenet:
//Igen, pfizer es pfizer2 cime ugyanaz!
//Pfizer neve es tipusa : Pfizer, mRNA
//Igen, sinovac es sinovac2 cime ugyanaz!
//Sinovac neve es tipusa : Sinovac, adenovirus


int main() {
    static_assert(std::is_abstract<Oltas>(), "Oltas-nak absztrakt osztalynak kell lennie!");
    Oltas* pfizer = Pfizer::GetInstance();
    Oltas* pfizer2 = Pfizer::GetInstance();

    if (pfizer == pfizer2) {
        std::cout << "Igen, pfizer es pfizer2 cime ugyanaz!" << std::endl;
    }

    std::cout << "Pfizer neve es tipusa: " << pfizer->getName() << ", " << pfizer->getType() << std::endl;

    Oltas* sinovac = Sinovac::GetInstance();
    Oltas* sinovac2 = Sinovac::GetInstance();

    if (sinovac == sinovac2) {
        std::cout << "Igen, sinovac es sinovac2 cime ugyanaz!" << std::endl;
    }

    std::cout << "Sinovac neve es tipusa: " << sinovac->getName() << ", " << sinovac->getType() << std::endl;

    // 4-es jegyert:
    std::vector<Oltas*> oltasok1 = { Sinovac::GetInstance(), Sinovac::GetInstance(), Pfizer::GetInstance() };
    std::vector<Oltas*> oltasok2 = { Pfizer::GetInstance(), Sinovac::GetInstance(), Pfizer::GetInstance() };

    OltasiIgazolas oltasiig1(oltasok1);
    OltasiIgazolas oltasiig2(oltasok2);

    std::cout << "Elso delinkvens ennyi Pfizer oltast kapott: " << oltasiig1.getCount(Pfizer::GetInstance()) << std::endl;
    std::cout << "Masodik delinkvens ennyi Pfizer oltast kapott: " << oltasiig2.getCount(Pfizer::GetInstance()) << std::endl;
    std::cout << "Masodik delinkvens ennyi Sinovac oltast kapott: " << oltasiig2.getCount(Sinovac::GetInstance()) << std::endl;

}