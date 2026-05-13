#include <string>
#include <iostream>
#include <fstream>
struct Sensor {
    int Sensor_Id;
    float Sicaklik;
};

int main()
{
    short int firstDegree = 0;
    short int LastDegree = 0;
    std::string StudentNumber = "";
    Sensor TempSensor;
    unsigned long int ID = 0;
    std::cout << "Please enter your  student ID :";
    std::getline(std::cin, StudentNumber);
    ID = std::stoull(StudentNumber);
    unsigned short int N = 0;
    N = ID % 50;
    unsigned short int E = 0;
    E = ID % 100;

    std::fstream Data("sensors.bin", std::ios::binary | std::ios::in |std::ios::out);
    if (!Data.is_open()) {
        std::cerr << "The Sensors binary file was not oppened!!" << std::endl;
        exit(-1);
    }
    Data.seekg(N* sizeof(Sensor), std::ios::beg);
    Data.read((char*)&TempSensor, sizeof(Sensor));
    firstDegree = TempSensor.Sicaklik;

    TempSensor.Sicaklik += E;
    Data.seekp(-N * sizeof(Sensor), std::ios::cur);
    LastDegree = TempSensor.Sicaklik;
    Data.write((char*)&TempSensor, sizeof(Sensor));
    Data.close();

    std::ofstream MyFile(StudentNumber + "_Quiz5.txt");
    MyFile << "Number : " << StudentNumber << std::endl;
    MyFile << "Sensor Index I Used in the process is : " << N << std::endl;
    MyFile << "First Temprature " << firstDegree << "\n"
        << "The Last Temprature  : " << LastDegree << std::endl;
 
    std::cout << "everything has done!" << std::endl;

    return 0;
}
