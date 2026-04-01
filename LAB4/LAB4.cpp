#include <string>
#include <iostream>
#define MAXSIZE 5
struct Package {
	std::string PackageID="";
	std::string DestinationCity = "";
	int Dimensions[3];
	Package* Next;
};
struct Courier {
	std::string CourirerName = "";
	std::string VehicleType = "";

};
Package* Top = nullptr;

Courier Queue[MAXSIZE];
int Front = -1;
int Rear = -1;

void Push(std::string TempId, std::string TempCity, int Dimension[]);
void Pop();
void Enqueue(std::string Tname, std::string Ttype);
void Dequeue();
void Dispatch();
void Display();
int main()
{
	int d1[3] = { 10, 10, 10 };
	int d2[3] = { 20, 20, 20 };

	Push("1231241", "Bursa", d1);
	Push("53242124", "Ankara", d2);

	Enqueue("Eren", "Car");
	Enqueue("Rıdvan", "Motorcycle");

	Display();
	Dispatch();
	Display();
   

	return 0;
}
void Push(std::string TempId, std::string TempCity, int Dimension[]) {
	Package* NewPack = new Package();
	NewPack->PackageID = TempId;
	NewPack->DestinationCity = TempCity;
	
	for (int i = 0; 3 > i; i++) {
		NewPack->Dimensions[i] = Dimension[i];
	}
	
	NewPack->Next = Top;
	Top = NewPack;

}
void Pop() {
	if (Top == nullptr) {
		std::cout << "There is nothing to delete!" << std::endl;
		return;
	}
	Package* ToDelete = Top;
	Top = Top->Next;
	delete ToDelete;
	ToDelete = nullptr;
}
void Enqueue(std::string Tname, std::string Ttype) {
	if ((Rear + 1) % MAXSIZE == Front) {
		std::cout << "The list is FULL!" << std::endl;
		return;
	}
	if (Front == -1) {
		Front = 0;
	}
	Rear = (Rear + 1) % MAXSIZE;
	Queue[Rear].CourirerName = Tname;
	Queue[Rear].VehicleType = Ttype;
}
void Dequeue() {
	if (Front == -1) {
		std::cout << "There is nothing in the queue!!" << std::endl;
		return;
	}
	if (Front == Rear) {
		Front = Rear = -1;
		return;
	}
	Front = (Front + 1) % MAXSIZE;

}
void Dispatch() {
	if (Top == nullptr || Front == -1) {
		std::cout << "The deliver cant go because Top nullptr or Front -1 // it means that either top is empty or array is empty!" << std::endl;
		return;
	}
	Pop();
	Dequeue();
}
void Display() {
	Package* Temp = Top;
	if (Top == nullptr) {
		std::cout << "The stack is empty!" << std::endl;
		return;
	}
	else {
		while (Temp != nullptr) {
			static int Counter= 1;
			std::cout << Counter << " . packet ID : " << Temp->PackageID << std::endl;
			std::cout << Counter << " . packet Destination : " << Temp->DestinationCity << std::endl;
			for (int i = 0; 3 > i; i++) {
				std::cout << Counter << " .Packet Dimension : " << Temp->Dimensions[i] << std::endl;
			}
			std::cout << "################################" << std::endl;
			Temp = Temp->Next;
			Counter++;
		}
	}

	if (Front == -1) {
		std::cout << "The Queue is empty!!!" << std::endl;
		return;
	}
	int i = Front;
	while (1) {
		std::cout << "Courirer Name : " << Queue[i].CourirerName << std::endl;
		std::cout << "Vehicle Type : " << Queue[i].VehicleType << std::endl;
		if (i == Rear) break;
		i = (i + 1) % MAXSIZE;
	}

}