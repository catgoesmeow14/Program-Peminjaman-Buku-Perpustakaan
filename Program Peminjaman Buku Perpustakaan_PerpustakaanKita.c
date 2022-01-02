//PROGRAM PEMINJAMAN BUKU PERPUSTAKAAN_PERPUSTAKAANKITA
/*
Nama Anggota :
    Vidya Chandradev	 (1905551067)
    I Komang Dana Aryasa (1905551074)
Kelas : Pemrograman D

Pilihan Menu Pada Program :
 1. Membuat Kartu Member Perpustakaan
    Menu ini berfungsi  untuk membuat kartu member dan menyimpan data member tersebut ke file .txt.
    Data member ini terdiri dari nama, tanggal lahir, pekerjaan, dan alamat.

 2. Melihat Daftar Member
    Menu ini berfungsi membaca atau memanggil data dari data base file.txt.

 3. Pinjam Buku
    Jika memilih menu ini, user disuruh untuk memasukan nama dan jumlah peminjaman.
    Selanjutnya, disuruh untuk memasukan jumlah buku dan kode buku yang akan dipinjam.
    Lalu user diminta memasukan tanggal, bulan dan tahun peminjaman  serta tanggal, bulan, dan tahun pengembalian.
    Data-data tersebut digunakan untuk menentukan tanggal jatuh tempo dari peminjaman, lama peminjaman,
     keterlambatan pengembalian buku dan proses penghitungan denda apa bila terjadi keterlambatan saat
     pengembalian buku.
    Penghitungan jatuh tempo itu dari tanggal peminjaman di tambah 7 hari. Jadi maksimal peminjaman hanya 7 hari.
     Jika melebihi dari hari yang ditentukan maka akan dikenakan denda.
    Program akan menampilkan data buku yang di pinjam, dan juga menampilkan tanggal pinjam, tanggal pengembalian,
     tanggal jatuh tempo, lama peminjaman, lama keterlambatan, dan juga denda.

 4. Exit
    Menu ini berfungsi untuk keluar dari program ketika tidak ada lagi yang ingin dilakukan oleh user.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "BukuModel.h"
// Tempat menyimpan daftar buku yang tersedia (Lihat function [loaddatabukutersedia])
    struct BukuModel bukutersedia[6];

// Prosedur untuk membantu menambahkan buku ke daftar [bukuTersedia]
void tambahbukutersedia(int index, char id[3], char jenis[50], char judul[50]){
    struct BukuModel buku;
    strcpy(buku.id, id);
    strcpy(buku.jenis, jenis);
    strcpy(buku.judul, judul);

    bukutersedia[index] = buku;
}

// Function untuk mengisi daftar [bukutersedia]
void loaddatabukutersedia(){
    tambahbukutersedia(0, "A1", "Pemrograman", "Trick for C++");
    tambahbukutersedia(1, "A2", "Sastra Jepang", "Katakana & Kanji 2");
    tambahbukutersedia(2, "A3", "Teknologi", "Cisco Networking");
    tambahbukutersedia(3, "A4", "Matematika", "Statistika jilid 2");
    tambahbukutersedia(4, "A5", "Sains & physics", "Anatomi Tubuh  Manusia");
    tambahbukutersedia(5, "A6", "sejarah", "perkembangan islam");
}


// Function untuk mencari index buku di [bukuTersedia] jika yang diketahui hanya [id] bukunya saja
/* Misal mencari index untuk buku dengan id A3
   ubahidjadiindex("A3") akan me-return index 2
   Function ini akan me-return -1 jika id yang diminta ternyata tidak ditemukan  */

int  ubahidjadiindex(char id[3]){
    for (int i = 0; i < 6; i++){
        if (strcmp(id, bukutersedia[i].id) == 0){
            return i;
        }
    }
    return -1;
}

// Function untuk mencari apakah sebuah buku dengan id tertentu ada di daftar [bukutersedia]
/*Misal mengecek apakah buku dengan id A5 ada
  cekidsudahada("A5") akan me-return true karena ada di daftar buku (Lihat [loaddatabukutersedia])
  Akan me-return false jika id yang dicari tidak ada
  cekidSudahAda("C9") akan me-return false */
bool cekidsudahada(char id[3]){
    // Function ini memakai function  ubahidjadiindex
    int index =  ubahidjadiindex(id);

    if (index == -1){
        return false;
    }else{
        return true;
    }
}
//prosedur untuk menampilkan data buku yang tersedia
void printsemuabukutersedia(){
    printf("INDEX\tKODE\tJENIS\tJUDUL\n");

    for (int i = 0; i < 6; i++){
        struct BukuModel buku = bukutersedia[i];
        printf("%d \t%s \t%s \t%s \n", i, buku.id, buku.jenis, buku.judul);
    }
}
//prosedur menampilkan syarat ketentuan
void printsyaratketentuan(){
    printf("\t\t\t\t\t\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb\n");
    printf("\t\t\t\t\t\xba                     \xb0Syarat Dan Ketentuan\xb0                   \xba\n");
    printf("\t\t\t\t\t\xc7\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xf9\xf9\xf9\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xb6\n");
    printf("\t\t\t\t\t\xba 1. Diharap Mengisi Data Peminjaman Buku                      \xba\n");
    printf("\t\t\t\t\t\xba 2. Apabila Terlambat Mengembalikan Buku Akan Dikenakan Denda \xba\n");
    printf("\t\t\t\t\t\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc\n");
}
//prosedur untuk menampilkan pilihan menu
void printdaftarmenu(){
    system("color f3");
    printf("\n\t\t\t\t\t\t\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb\n");
    printf("\t\t\t\t\t\t\xba        Selamat Datang Di Menu         \xba\n");
    printf("\t\t\t\t\t\t\xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xb9\n");
    printf("\t\t\t\t\t\t\xc7\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xfe\xfe\xfePerpustakaan\xfe\xfe\xfe\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xb6\n");
    printf("\t\t\t\t\t\t\xba 1. Membuat Kartu Member Perpustakaan  \xba\n");
    printf("\t\t\t\t\t\t\xba 2. Melihat Daftar Member              \xba\n");
    printf("\t\t\t\t\t\t\xba 3. Pinjam Buku                        \xba\n");
    printf("\t\t\t\t\t\t\xba 4. Exit                               \xba\n");
    printf("\t\t\t\t\t\t\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc\n\n");
    printf("\t\t\t\t\t\t\xf4Silahkan masukan nomor menu pilihan anda\xf5\n");
}

int main(){
    // Sebelum melakukan apapun dengan daftar buku, load dulu buku yang tersedia ke [bukutersedia]
    int menu;
    int denda=0;
    int tanggal_jt, bulan_jt, tahun_jt;
    int tahun_kembali, bulan_kembali, tanggal_kembali;
    int tahun_pinjam, bulan_pinjam, tanggal_pinjam;

    char nama_penyewa_buku[20];
    char member[2];
    char ulang[2];
    char nama_member[20], alamat_member[20], pekerjaan_member[20];
    int tanggal_lahir_member, tahun_lahir_member;
    char bulan_lahir_member[20];

    do{
        loaddatabukutersedia();
        printsyaratketentuan();
        printdaftarmenu();
        scanf("%d", &menu);
        system("cls");
    system("color b0");
    //menu untuk membuat member
    if(menu == 1){
        printf("\n\t\t\t\t\t\xdb\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xdb\n");
        printf("\t\t\t\t\t\xb3      \xfe\xf7\xf7\xf7Membuat Member Baru\xf7\xf7\xf7\xfe      \xb3\n");
        printf("\t\t\t\t\t\xdb\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xdb\n");

        printf("Nama      : ");
        fflush(stdin);
        scanf("%[^\n]s", &nama_member);

        printf("\nAlamat    : ");
        fflush(stdin);
        scanf("%[^\n]s", &alamat_member);

        printf("\nPekerjaan : ");
        fflush(stdin);
        scanf("%[^\n]s", &pekerjaan_member);

        printf("\nTanggal Lahir      : ");
        fflush(stdin);
        scanf("%d", &tanggal_lahir_member);

        printf("\nBulan Lahir      : ");
        fflush(stdin);
        scanf("%s", &bulan_lahir_member);

        printf("\nTahun Lahir      : ");
        fflush(stdin);
        scanf("%d", &tahun_lahir_member);


        FILE *simpandatamember = fopen("data_member.txt", "a");
        fprintf(simpandatamember, "%s#%s#%s#%d#%s#%d\n", nama_member, alamat_member, pekerjaan_member, tanggal_lahir_member, bulan_lahir_member, tahun_lahir_member);
        fclose(simpandatamember);

        printf("\nSukses menambah data member.\n\n");
        getch();
        system("cls");
        //menampilkan kartu member perpustakaan
        system("color b");
        printf("\t\t\t\t\t\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb\n");
        printf("\t\t\t\t\t\xc7\xc4\xc4\xc4\xc4 * Kartu Member Perpustakaan * \xc4\xc4\xc4\xc4\xb6\n");
        printf("\t\t\t\t\t\xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xb9\n");
        printf("\t\t\t\t\t       Nama      : %s       ", nama_member);
        printf("\n\t\t\t\t\t      Alamat    : %s       ", alamat_member);
        printf("\n\t\t\t\t\t      TTL       : %d%s%d   ", tanggal_lahir_member, bulan_lahir_member, tahun_lahir_member);
        printf("\n\t\t\t\t\t      Pekerjaan : %s       ", pekerjaan_member);
        printf("\n\t\t\t\t\t\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc\n");
        printf("\t\t\t\t\t\xf9\xaf Terima kasih %s Telah Bergabung   \xae\xf9\n", nama_member);
        printf("\t\t\t\t\t\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    }

    // menu untuk melihat daftar member
    system("color b");
    if(menu == 2){
        printf("\t\t\t\t\t\xdb\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xdb\n");
        printf("\t\t\t\t\t\xb3      \xb0\xb0\xb0 Daftar Anggota Member \xb0\xb0\xb0    \xb3\n");
        printf("\t\t\t\t\t\xdb\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xdb\n\n");

        FILE *panggildata = fopen("data_member.txt", "r");
        if (!panggildata){
            printf("tidak ada file");
        }else{
            int i = 0;
            while (!feof(panggildata)){
                fscanf(panggildata, "%[^#]#%[^#]#%[^#]#%d#%[^#]#%d\n", &nama_member, &alamat_member, &pekerjaan_member, &tanggal_lahir_member, &bulan_lahir_member, &tahun_lahir_member);
                fflush(stdin);
                printf("%d. Nama      : %s", i + 1, nama_member);
                printf("\n   Alamat    : %s", alamat_member);
                printf("\n   Pekerjaan : %s", pekerjaan_member);
                printf("\n   TTL       : %d %s %d\n\n", tanggal_lahir_member, bulan_lahir_member, tahun_lahir_member);

                i++;
        }fclose(panggildata);
         printf("Jumlah Member : %d\n", i);
        }
    }
    // menu untuk meminjam buku
    system("color e2");
    if (menu == 3){
        printf("\t\t\t\t\t===============================================================\n");
        printf("\t\t\t\t\t=                                                             =\n");
        printf("\t\t\t\t\t=                  DAFTAR BUKU PERPUSTAKAAN                   =\n");
        printf("\t\t\t\t\t=                                                             =\n");
        printf("\t\t\t\t\t===============================================================\n\n");
        printf("\t\t\t\t   -------------------------------------------------------------------------\n");
        printf("\t\t\t\t   |   KODE BUKU   |     JENIS BUKU        |          JUDUL BUKU           |\n");
        printf("\t\t\t\t   -------------------------------------------------------------------------\n");

        for (int i = 0; i < 6; i++){
            struct BukuModel buku = bukutersedia[i];
            printf("\t\t\t\t   |\t   %s\t   |\t%s\t   |\t%s\t   |\n", buku.id, buku.jenis, buku.judul);
        }
        printf("\t\t\t\t   -------------------------------------------------------------------------\n\n");
        printf("Nama Penyewa Buku    : ");
        fflush(stdin);
        scanf("%[^\n]s", &nama_penyewa_buku);

        int jumlah_peminjaman;
        do{
         printf("Jumlah Jenis Buku yang Ingin Dipinjam [max 6]    : ");
         scanf("%d", &jumlah_peminjaman);
         if ((jumlah_peminjaman > 6) || (jumlah_peminjaman < 1)){
            printf("Jumlah jenis buku maximal 6. Silahkan ulangi kembali\n");
         }
        }while ((jumlah_peminjaman > 6) || (jumlah_peminjaman < 1));

        char kode[5][3];
        int jumlah[5]; // Menyimpan jumlah buku per judul buku yang dipinjam
        if ((jumlah_peminjaman <= 6) && (jumlah_peminjaman >= 1)){
            int i = 0;
            while (i < jumlah_peminjaman){
                if(jumlah_peminjaman>6) {
                    break;
                }
                printf("\n=======================================\n");
                printf("| buku ke-%d \n", i + 1);
                printf("| Kode Buku                 : ");
                scanf("%s", &kode[i]);

                if (cekidsudahada(kode[i]) == true){
                    printf("| Jumlah Buku yang Dipinjam : ");
                    scanf("%d", &jumlah[i]);
                    printf("=======================================\n");
                    i++;
                }else{
                    printf("Kode buku salah. Perhatikan penulisan dan silahkan ulangi kembali!");
                 }
            }
        }
        //input tanggal, bulan, dan tahun peminjaman
        printf("\nTanggal Pinjam\n");
        while (1){
            printf("Tanggal [DD]   : ");
            scanf("%d", &tanggal_pinjam);
            if (tanggal_pinjam < 1 || tanggal_pinjam > 31){
                printf("masukan ulang data..\n");
            }else{
                break;
             }
        }while (1){
            printf("Bulan [MM]     : ");
            scanf("%d", &bulan_pinjam);
            if (bulan_pinjam < 1 || bulan_pinjam > 12){
                printf("masukan ulang data..\n");
            }else{
                break;
            }
        }while (1){
            printf("Tahun [YYYY]   : ");
            scanf("%d", &tahun_pinjam);
            if (tahun_pinjam < 2000){
                printf("masukan ulang data..\n");
            }else{
                break;
            }
        }
        //input tanggal, bulan, dan tahun pengembalian
        printf("\nTanggal Kembali\n");
        while(1){
        printf("Tanggal [DD]   : ");
        scanf("%d", &tanggal_kembali);
        if(tanggal_kembali<1||tanggal_kembali>31){
            printf("masukan ulang data..\n");
        }else{
            break;
         }
        }while(1){
         printf("Bulan [MM]     : ");
         scanf("%d", &bulan_kembali);
         if(bulan_kembali<1||bulan_kembali>12){
            printf("masukan ulang data..\n");
         }else{
            break;
          }
         }while(1){
          printf("Tahun [YYYY]   : ");
          scanf("%d", &tahun_kembali);
          if(tahun_kembali<2000){
          printf("masukan ulang data..\n");
          }else{
            break;
           }

          }system("cls");

        system("color 0");

    //proses perhitungan denda
    int lama_peminjaman=(tanggal_kembali-tanggal_pinjam)+((bulan_kembali-bulan_pinjam)*30)+((tahun_kembali-tahun_pinjam)*360);
    int terlambat=lama_peminjaman-7;

    if (lama_peminjaman>7){
        denda=terlambat*1000;
    }else if(terlambat<=7){
        terlambat=0;
     }
      printf("\nApakah Anda Punya Member ? (y/n)");
        scanf("%s", &member);
     if(strcmp(member, "y") == 0){
        denda=terlambat*500;
    }
    //perhitungan jatuh tempo pengembalian
    tanggal_jt = tanggal_pinjam+7;
    bulan_jt = bulan_pinjam+(tanggal_jt/30);
    tahun_jt = tahun_pinjam+(bulan_jt/12);
    if(tanggal_jt>30){
        tanggal_jt-=30;
    }if(bulan_jt>12){
        bulan_jt-=12;
     }
        getch();
        system("cls");
        /*
          memunculkan list buku yang dipinjam, tanggal pinjam, tanggal kembali, tanggal jatuh tempo,
          lama peminjaman, lama keterlambatan dan jumlah denda
        */
        system("color b0");
        printf("\nNama Penyewa Buku    : %s", nama_penyewa_buku);
        printf("\nJumlah Buku          : %d\n\n", jumlah_peminjaman);

        printf("-----------------------------------------------------------------\n");
        printf("| KODE BUKU |   JENIS BUKU   |     JUDUL BUKU     |  JUMLAH BUKU|\n");
        printf("-----------------------------------------------------------------\n");

        if (jumlah_peminjaman > 0){
            int i = 0;
            while (i < jumlah_peminjaman){
                int index = ubahidjadiindex(kode[i]);
                struct BukuModel buku;
                buku = bukutersedia[index];
                printf("  %s         %s         %s        %d  \n\n", kode[i], buku.jenis, buku.judul, jumlah[i]);
                i++;
            }
        }
        printf("\n Tanggal Pinjam       : %d - %d - %d", tanggal_pinjam, bulan_pinjam, tahun_pinjam);
        printf("\n Tanggal Kembali      : %d - %d - %d", tanggal_kembali, bulan_kembali, tahun_kembali);
        printf("\n Tanggal Jatuh tempo  : %d - %d - %d", tanggal_jt, bulan_jt, tahun_jt);
        printf("\n Lama Peminjaman      : %d hari", lama_peminjaman);
        printf("\n Lama Keterlambatan   : %d hari", terlambat);
        printf("\n Denda                : Rp. %d", denda);

        printf("\n\n\n\t\t*****Terima Kasih  %s Atas Kunjungan Anda!***** \n", nama_penyewa_buku);
    }
    // menu untuk exit
    if (menu == 5){
        exit(0);
    }

    //mengulang program
     printf("\n\n--------------------------------\n");
     printf(" Apakah ingin mengulang program ? (y/n)");
     printf("\n--------------------------------\n");
     scanf("%s", &ulang);
     system("cls");
	}while(strcmp(ulang, "y") == 0);
    return 0;
}
