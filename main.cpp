#include <iostream>
#include <string>
struct mhs{
	int nilai;
	std::string nama; 
};
const int NMAX = 100;
typedef mhs arrMhs[NMAX];
void input(int n, arrMhs* mahasiswa){
	for(int i = 0; i < n; i++){
		std::string name;
		int grade;
		std::cout << "Nama mahasiswa ke-" << i+1 <<": ";
		std::cin >> name;
		std::cout << "Nilai mahasiswa ke-" << i+1 << ": ";
		std::cin >> grade;
		(*mahasiswa)[i].nama = name;
		(*mahasiswa)[i].nilai = grade;
	}
}
int mhsLulus(int n, arrMhs mahasiswa){
	int lulus = 0;
	for (int i = 0; i < n; i++){
		if (mahasiswa[i].nilai >= 60){
			lulus++;
		}
	}
	return lulus;
}
int nilaiMax(int n, arrMhs mahasiswa){
	int max = mahasiswa[0].nilai;
	int index;
	for (int i = 0; i < n; i++){
		if (mahasiswa[i].nilai > max){
			max = mahasiswa[i].nilai;
			index = i;
		}
	}
	return index;
}	
int main(){
	int n, lulus, max;
	arrMhs mahasiswa;
	std::cout << "Masukan jumlah mahasiswa: ";
	std::cin >> n;
	input(n, &mahasiswa);
	lulus = mhsLulus(n, mahasiswa);
	max = nilaiMax(n, mahasiswa);
	
	std::cout<<"Daftar Nilai Mahasiswa: \n";
	for (int i = 0; i < n; i++){
		std::cout << i+1 << mahasiswa[i].nama << " - " << mahasiswa[i].nilai << "\n";
	}
	std::cout << "Jumlah mahasiswa yang lulus: "<< lulus << "\n";
	std::cout << "Nilai tertinggi: "<< mahasiswa[max].nilai << "(" << mahasiswa[max].nama << ")";
}