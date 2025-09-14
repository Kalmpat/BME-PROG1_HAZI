# Elektronikus Telefonkönyv 
## 1. Bevezetés

A program „Elektronikus Telefonkönyv”, programozási nyelve, ’C’ nyelv.  
Felépítése: menüvezérelt, adatkezelésen alapul, egy elképzelt elektronikus telefonkönyv kezelését valósítja meg.  
Adatrendszere: rekordokban tárolja az egyedeket, a következő egyedtulajdonságokkal (mezőkben): személyek neve, foglalkozása, címe, és kora valamint az egyén telefonszámát. 

## 2. Funkciók  

### 2.1 Rekordok hozzáadása, módosítása, törlése 
  
A felhasználónak lehetősége van új egyedek, rekordok létrehozására, egyedek törlésére az egyedtulajdonságok módosítására. 

A rekordok felépítése (mezők): 
• *Vezetéknév: (szöveges, legfeljebb 15 karakter)* 

• *Keresztnév: (szöveges, legfeljebb 15 karakter)*

• *Cím: (szöveges, legfeljebb 20 karakter)*

• *Foglalkozás: (szöveges, legfeljebb 15 karakter)* 

*Név: (szöveges, legfeljebb 30 karakter)* 

• *Kor: (szám, legfeljebb háromjegyű egész szám)* 

• *Telefonszám: (szöveges, legfeljebb 11 karakter)*

A program képes a vezetéknevet és a keresztnevet egybe venni, az adatrendszer nem tartalmaz egyedi azonosítót, elsődleges kulcsot. 
Rekordszintű funkciók a következőek:

• **Rekord létrehozása:** A felhasználó új rekordot hozhat létre a szükséges adatok megadásával 
(vezetéknév, keresztnév. cím, foglalkozás, kor, telefonszám).  

• **Rekord módosítása:** A felhasználó kiválaszthatja a módosítani kívánt rekordot, majd a program megjeleníti az összes mezőt, ahol a felhasználó kiválaszthatja, hogy mely mezőt szeretné módosítani.  

• Rekord törlése: A felhasználó kiválasztja a törölni kívánt egyedet, rekordot. 

### 2.2  Keresés; név, foglalkozás és telefonszám alapján 
  
A felhasználónak lehetősége van a rekordok keresésére név, foglalkozás és telefonszám mezők alapján. A keresés eredményeként megjelenítésre kerülnek a talált rekordok. A név (vezetéknév, keresztnév) esetén egy darab *-ot tartalmazó helyettesítés (wildcard) kezelésére van lehetőség (pl. a "Nagy" N*y, "*István" I*ván keresősztringek valamelyikét használva, megtalálja Nagy
Istvánt a telefonkönyvben).  

*Egyedi találat:* Amennyiben a keresés során csak egyetlen rekord egyezik meg a megadott kritériumokkal (név, foglalkozás, telefonszám alapján), a program megjelenítt az adott rekord összes adatát. 

*Több találat:* Ha a keresési feltételek alapján több rekord is megfelel, a program mindegyik rekordot kilistázza. Az eredmények közö琀琀 a felhasználó kiválaszthatja, hogy melyik rekordot szeretné részletesebben megtekinteni vagy további műveleteket végrehajtani rajta (pl. módosítás, törlés).  

*Nincs találat:* Ha a keresés nem ad találatot, a program kiírja, hogy "Nincs találat ", és visszatér a keresési lehetőségekhez. 
  
 ### 2.3 Az adatok fájlba mentése 
  
A felhasználónak lehetősége van az összes rekord mentésére egy adatállományba, fájlba. Így 
alkalmassá tehető arra, hogy adatbázis kialakítás valósuljon meg. 
 
### 2.4 vCard létrehozás 
  
A vCard létrehozásával lehetőség van arra, hogy ezt a vCard-ot fájlba mentsük, vagy tetszőleges 
export formába hozzuk. (Csak azokat a mezőket használjuk, amiket a programom ismer, amely a 
rekordban szerepel). A program képes vCard fájl létrehozására a rekordokból, amely a következő 
mezőket tartalmazhatja:  

➢ *Név (legfeljebb 30 karakter)*  

➢ *Foglalkozás (legfeljebb 15 karakter)* 

➢ *Telefonszám (legfeljebb 11 karakter)* 

## 3. A program menüvezérelt rendszere:
 
### 3.1 Hogyan jelenik meg a menü, hogyan lehet menüpontot választani? 
  
A program indulásakor egy főmenüt jelenít meg a képernyőn. A menü különböző lehetőségeket tartalmaz.   

o "Rekord létrehozás"  
o "Rekord módosítása," ("Rekord mentése,") 
o "Rekord törlése,"  
o "Keresés,"  
o "vCard export," és  
o "Kilépés." 

### 3.2 Hogyan jelennek meg az egyes funkciók? 
  
A felhasználó a főmenüben a menüpontok között navigálhat, és a kívánt funkciót 
kiválaszthatja. Ehhez a felhasználónak a menüpontnál látható számot kell beírnia, a rossz 
választást a program kezeli. Az egyes funkciók végrehajtása után a program kiírja a megfelelő 
üzeneteket, a rekordok sikeres mentéséről, törléséről, vagy amikor a módosítás sikeresen 
megtörtént. "Rekord létrehozva"; "Rekord törölve"; "Rekord módosítva". 

### 3.3 Hogyan lehet visszakerülni a főmenübe, mikor van vagy nincs rá mód? 
  
A program alapértelmezett működése, hogy minden funkció végrehajtása után visszatér a 
főmenübe, és a felhasználó új funkciót választhat. Az almenüknél pedig meg kell adnia, hogy 
„Visszatérés a főmenübe”. 

A "Kilépés" funkcióval a program befejezi futását, visszaadja a vezérlést az operációs 
rendszernek. 

### 3.4 Hogyan, milyen sorrendben kér be a program adatokat? 
  
Adatrögzítés, rekord létrehozás esetén a program a rekordban szereplő mezők sorrendjében 
kéri be az adatokat a megfelelő formában, a megfelelő mező 琀pusban. Módosítás során a 
rekordok teljes kijelzése után a felhasználó választja ki, mely adatot, mely mezőt kívánja 
módosítani, módosítás után a teljes rekord rögzítésre kerül.   

### 3.5 Milyen formában várja a program az egyes adatokat? (pl. ÉÉÉÉ/HH/NN?) 
  
Az adatok bekérése a fent 2.1 alatt ismertetett formában történik. 

### 3.6 Vállalkozik-e a program hibás bemenet (pl. rossz formátumú adat) lekezelésére? Ha igen, milyen hibákat tud kezelni, hogyan jelzi a hibát? (hibaüzenet stb.) 
  
A program foglalkozik a hibás bemenetekkel, ekkor a program kiírja, menü esetén, hogy 
„érvénytelen válasz” vagy „hibás bemenet” és lehetőségünk lesz új választ adnunk, 
adatbevitel esetén (felvétel módosítás) csak a megfelelő formátumot fogadja el, a 
felhasználónak külön jelzés nélkül kell kijavítani a hibásan beírt adatot. 

### 3.7 Milyen az elvárt kimenete az egyes funkcióknak? 
  
Bevitel, módosítás esetén a „kimenet” fájlszintű, lekérdezés esetén képernyőre történő listázás 
valósul meg. 
A vCard elkészítése után megjelenitett a program az általam formázott „vCard”-ot, további 
lehetőségként egy rekordszintű változóba rögzítt, azokkal az adatokkal, amelyek a vCard-ban 
szerepelnek, és lehetőséget ad arra, hogy ezeket az elkészített vCard-okat rekordszervezésű 
fájlba mentsük, vagy tetszőleges export formában tároljuk. 

## 4 Összegzés 

A tervezett programom fekete-fehér képernyőn jelenítt meg az adatokat, szövegszerűen, azonos betűtípussal. A megjelenítés során színeket nem alkalmazok. 
A vCard megjelenítése során keretet rajzolok körré. 
A programom kezelése külön kezelési utasítást, felhasználói kézikönyvet nem igényel, a program indítása során a szükséges magyarázatokat kiírja.
