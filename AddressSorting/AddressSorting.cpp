#include <fstream>

int main() {
    std :: string* city;  std::string* street;
    int* numberHouse,* numberAppartament;
    int sizeArray; 
    std::string s,s2; 
    std::ifstream finIn("in.txt");

    finIn >> sizeArray;

    city = new std::string[sizeArray];
    street = new std::string[sizeArray];
    numberHouse = new int[sizeArray];
    numberAppartament = new int[sizeArray];

    for (int i = 0; i < sizeArray;i++) {
        finIn >> city[i];
        finIn >> street[i];
        finIn >> numberHouse[i];
        finIn >> numberAppartament[i];
    }
    finIn.close();
    for (int i = 0; i < sizeArray - 1;i++) {
        for (int j = i; j >= 0;j--) {
            if (city[j] > city[j + 1])
            {
                s = city[j];
                s2 = street[j];
                city[j] = city[j + 1];
                city[j + 1] = s;
                street[j] = street[j + 1];
                street[j + 1] = s2;
            }
        }
    }

    std::ofstream finOut("out.txt");
    finOut << sizeArray;
    finOut << std::endl;

    for (int i = 0; i < sizeArray;i++) {
        finOut << city[i];
        finOut << " ";
        finOut << street[i];
        finOut << " ";
        finOut << numberHouse[i];
        finOut << " ";
        finOut << numberAppartament[i];
        finOut << std :: endl;
    }

    finOut.close();
    delete[] city, street, numberHouse, numberAppartament;
    return 0;
}
