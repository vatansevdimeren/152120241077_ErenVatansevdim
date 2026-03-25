#include <string>
#include <iostream>
//152120241077
struct Song {
	std::string Title = "";
	std::string Artist = "";
	int Ratings[3];
	Song* Prev= nullptr;
	Song* Next=nullptr;
};
void MovePrev(Song*& Current);
void MoveNext(Song*& Current);
void DisplayAllList(Song* Head,Song* CurrentSong);
void AddSong(Song*& Head,std::string TempTitle,std::string TempArtist,int TempRatings[3]);
void RemoveCurrent(Song*& Head, Song*& Current);
int main() {
	//Hocam Burada Head i kendim olusturucam

	Song* Head = nullptr;
	Song* Current = nullptr;

	int choice = 0;

	while (choice != 6) {
		std::cout << "1. Add Song\n2. Next Song\n3. Previous Song\n4. Remove Current\n5. Display All\n6. Exit" << std::endl;
		std::cout << "Choice: ";
		std::cin >> choice;

		if (choice == 1) {
			std::string t, a;
			int r[3];
			std::cout << "Title: "; std::cin >> t;
			std::cout << "Artist: "; std::cin >> a;
			std::cout << "3 Ratings : ";
			for (int i = 0; i < 3; i++) std::cin >> r[i];
			AddSong(Head, t, a, r);
			if (Current == nullptr) Current = Head; 
		}
		else if (choice == 2) MoveNext(Current);
		else if (choice == 3) MovePrev(Current);
		else if (choice == 4) RemoveCurrent(Head, Current);
		else if (choice == 5) DisplayAllList(Head, Current);
	}

	

	return 0;
}
void AddSong(Song*& Head, std::string TempTitle, std::string TempArtist, int TempRatings[3]) {
	Song* Eklenecek = new Song();
	Eklenecek->Next = nullptr;
	Eklenecek->Title = TempTitle;
	Eklenecek->Artist = TempArtist;
	for (int i = 0; 3 > i; i++) {
		Eklenecek->Ratings[i] = TempRatings[i];
	}

	if (Head == NULL) {
		Head = Eklenecek;
		return;
	}

	Song* TempNode = Head;

	while (TempNode->Next != nullptr) {
		TempNode = TempNode->Next;
	}
	TempNode->Next = Eklenecek;
	Eklenecek->Prev = TempNode;


}
void RemoveCurrent(Song*& Head, Song*& Current) {
	if (Current == nullptr) return;
	
	Song* Silinecek = Current;

	if (Current->Prev != nullptr) {
		Current->Prev->Next = Current->Next;
	}
	else {
		Head = Current->Next;
	}
	if (Current->Next != nullptr) {
		Current->Next->Prev = Current->Prev;
		Current = Current->Next;
	}
	else {
		Current = Current->Prev;
	}
	delete Silinecek;
	//hocam burada sildim ama silinecek i yazdırmaya kalarsam bu dangling pointer olarak kalıcak o yüzden bunu nullptr ye atiyom
	Silinecek = nullptr;
	

}
void DisplayAllList(Song* Head, Song* CurrentSong) {
	Song* Temp = Head; 
	while (Temp != nullptr) {
		if (Temp == CurrentSong) {
			std::cout << "-> "; 
		}
		else {
			std::cout << "   "; 
		}

		std::cout << "Title : " << Temp->Title << " Artist : " << Temp->Artist << std::endl;
		for (int i = 0; 3 > i; i++) {
			std::cout << i + 1 << ". Rating : " << Temp->Ratings[i] << std::endl; 
		}
		std::cout << "#######################################" << std::endl;
		Temp = Temp->Next; 
	}
}
void MoveNext(Song*& Current) {
	if (Current != nullptr && Current->Next != nullptr) {
		Current = Current->Next;
	}
}
void MovePrev(Song*& Current) {
	if (Current != nullptr && Current->Prev != nullptr) {
		Current = Current->Prev;
	}
}