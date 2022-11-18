#include <iostream>
#include <type_traits>

// A 2-es jegyert keszitse el az alabbi osztalyokat:
// 
// Oltas osztaly - absztrakt ososztaly
// - ennek az osztalynak van egy const std::string&-et varo konstruktora, ami beallitja az Oltas nevet!
// - ennek az osztalynak van egy getName() metodusa ami visszaadja az oltas nevet
// - ennek az osztalynak van egy getType() nevu pure virtual metodusa is, ami std::string-et ad vissza, de nincs kifejtve!

// Pfizer osztaly, amely publikus modon szarmazik az Oltas osztalybol
// Ez egy singleton osztaly, vagyis:
// - konstruktora meghivja ugyan az ososztaly konstruktorat (inicializalo listaban), de a konstruktor maga privat!
// - copy constructora vagy privat, vagy le van tiltva! ( = delete;)
// - copy assignment operatora vagy privat, vagy le van tiltva! ( = delete;)
// - van egy public, static Oltas* GetInstance() metodusa, amely egy static pointert ad vissza
// - megvalositja az ososztaly getType() metodusat is, es azt a stringet adja vissza, hogy "mRNA"
// Singleton osztalyokrol hatteranyag: https://u.pcloud.link/publink/show?code=XZMR4rXZsHduf1qXGq4bAzr2cNPaCX5friLV (8-9. oldal)


// elvart kimenet:
//Igen, pfizer es pfizer2 cime ugyanaz!
//Pfizer neve es tipusa : Pfizer, mRNA

int main() {
    static_assert(std::is_abstract<Oltas>(), "Oltas-nak absztrakt osztalynak kell lennie!");
    Oltas* pfizer = Pfizer::GetInstance();
    Oltas* pfizer2 = Pfizer::GetInstance();

    if (pfizer == pfizer2) {
        std::cout << "Igen, pfizer es pfizer2 cime ugyanaz!" << std::endl;
    }

    std::cout << "Pfizer neve es tipusa: " << pfizer->getName() << ", " << pfizer->getType() << std::endl;
}