#include <iostream>
#define UKURAN 9

int sudoku[UKURAN][UKURAN] {
  {9,0,0,0,0,0,0,0,5},
  {0,3,0,2,0,0,0,0,0},
  {0,1,5,3,4,0,0,7,0},
  {6,0,0,1,3,0,0,4,9},
  {7,0,0,0,0,0,6,0,0},
  {2,0,0,0,0,4,0,0,0},
  {0,0,0,0,0,0,1,0,3},
  {0,0,0,9,1,0,0,0,0},
  {0,7,9,0,8,0,0,0,0}
};

bool cek_kolom(int kolom, int angka){
  for(int i{0}; i<UKURAN; ++i){
    if(sudoku[i][kolom] == angka){
    	return true;
    }
  }
  return false;
}

bool cek_baris(int baris, int angka){
  for(int i{0}; i<UKURAN; ++i){
    if(sudoku[baris][i] == angka){
    	return true;
    }
  } 
  return false;
}

//cek 3 kotak parsial
bool cek_parsial(int baris, int kolom, int angka){
  int baris_x = baris - baris % 3;
  int kolom_x = kolom - kolom % 3;
  for(int i{0}; i<3; ++i){
    for(int j{0}; j<3; ++j){
      if(sudoku[i+baris_x][j+kolom_x] == angka){
      	return true;
      }
    }
  }
  return false;
}

//cek penempatan angka sesuai/tidak
bool isi_cell(int baris, int kolom, int angka){
  return !cek_kolom(kolom,angka) && !cek_baris(baris,angka) && !cek_parsial(baris,kolom,angka);
}

//cek jika ada cell yang kosong (angka 0)
bool cek_kotak_kosong(int &baris, int &kolom){
  for(baris = 0; baris<UKURAN; ++baris)
    for(kolom = 0; kolom<UKURAN; ++kolom)
      if(sudoku[baris][kolom] == 0)
        return true;
      return false;
}

bool sudoku_solver(){
  for(int baris{0}; baris < UKURAN; ++baris){
    for(int kolom{0}; kolom < UKURAN; ++kolom){
    	//jika ada angka 0 (kotak belum terisi)
      if(sudoku[baris][kolom] == 0){
      	//isi dari angka 1 - 9
        for(int coba{1}; coba <= 9; ++coba){
        	//jika berhasil (cek dulu mulai dari kolom, baris dan kotak parsial)
          if(isi_cell(baris, kolom, coba)){
          	//isi kotak tersebut dengan angka
            sudoku[baris][kolom] = coba;

            if(sudoku_solver()){
              return true;
            }else{
              sudoku[baris][kolom] = 0;
            }
          }
        }
          return false;
      }
    }
  }
  return true;
}


void print_sudoku(){
	for(int baris{0}; baris<UKURAN; ++baris){
		if(baris % 3 == 0 && baris != 0){
			std::cout<<"-----------------------";
			std::cout<<std::endl;
		}
		for(int kolom{0}; kolom<UKURAN; ++kolom){
			if(kolom % 3 == 0 && kolom != 0){
				std::cout<<" | ";
			}
			std::cout<<sudoku[baris][kolom]<<' ';
		}
		std::cout<<std::endl;
	}
}

void show_index(){
  for(int i{0}; i<UKURAN; ++i){
    for(int j{0}; j<UKURAN; ++j){
      std::cout<<'['<<i<<j<<']';
    }
    std::cout<<std::endl;
  }
}


int main(int argc, char const *argv[])
{
	print_sudoku();
	printf("\n\n\n");
  	if(sudoku_solver() == true){
	    print_sudoku();
  	}else{
	    std::cout<<":)"<<std::endl;
  	}
	  // show_index();
}
